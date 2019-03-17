
#include <IRremote.h>       // import IRreote lib
#define arry_on_size  10    // length of code_on arry 
#define arry_off_size 11    // lenght of code_off arry
const int RECV_PIN = 10;    // connect the IR receiver to pin-10
const int myLED = 12;       // LED connected to pin 12
IRrecv irrecv(RECV_PIN);    // create a obeject called irrecv
decode_results results;     // create a object called results conatins codes

// Symboles in the IR Remote are used to off ( I used "NEC" Protocol ) 
float code_off[] = {0xFD00FF, 0xFD807F, 0xFD40BF , 0xFD20DF, 0xFDA05F  ,0xFD609F  , 0xFD10EF   , 0xFD906F   , 0xFD50AF , 0xFDB04F , 0xFD708F};

// codes (HEX) of { 0      ,  1       ,  2         ,  3        ,   4     ,  5       , 6        , 7       , 8       ,  9    }
float code_on[]   = {0xFD30CF, 0xFD08F7 , 0xFD8877  , 0xFD48B7  , 0xFD28D7,  0xFDA857, 0xFD6897, 0xFD18E7 , 0xFD9867 , 0xFD58A7 }; 
    
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);         // start Serial commucation at 9600
  irrecv.enableIRIn();        // start the receiver
  pinMode(myLED, OUTPUT);     // set LED as OUT
  digitalWrite(myLED, LOW);   // start the LED off
  Serial.println("This is For 'NEC' Only Please Check your Remote Control Protocol");
  Serial.println("----------------------------------------------------------------");
  Serial.println("To Allumate The LED Press Any Number [ 0 , 1 , ..., 9]\n");
    
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {               // receive and decode the received data
    for (int n = 0; n < arry_on_size ; n++){   // traverce all the arry
      if (results.value == code_on[n]) {       // check if the value exist in code_on arry 
        digitalWrite(myLED, HIGH);             // if yes LED -> ON
        
        switch (results.value) {               // Convert DEC value of results.value to msg 
        case 16593103:Serial.println(" You Have Pressed '0' ");  break;
        case 16582903:Serial.println(" You Have Pressed '1' ");  break;
        case 16615543:Serial.println(" You Have Pressed '2' ");  break;
        case 16599223:Serial.println(" You Have Pressed '3' ");  break;
        case 16591063:Serial.println(" You Have Pressed '4' ");  break;
        case 16623703:Serial.println(" You Have Pressed '5' ");  break;
        case 16607383:Serial.println(" You Have Pressed '6' ");  break;
        case 16586983:Serial.println(" You Have Pressed '7' ");  break;
        case 16619623:Serial.println(" You Have Pressed '8' ");  break;
        case 16603303:Serial.println(" You Have Pressed '9' ");  break;
        }
        //Serial.println(results.value, HEX);
        
      }
    }

    for (int n = 0; n < arry_off_size ; n++){    // traverce all the arry
      if (results.value == code_off[n]) {        // check if the value exist in code_off arry 
        digitalWrite(myLED, LOW);                // if yes LED -> OFF
        Serial.println(" You Have Pressed a Symbol");
      }
  }
    irrecv.resume();  // Receive the next value
}
}
