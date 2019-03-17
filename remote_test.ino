/* This code is used to see what protocol is used  Par exemple ( "NEC" , "SONY" ) 
 *  And get the HEX code of each button on the IR remote 
 */


#include <IRremote.h>        // import IRreote lib
const int RECV_PIN = 10;     // Connect the IR receiver to pin-10
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
Serial.begin(9600);
irrecv.enableIRIn();
irrecv.blink13(true);
}

// Start the IR receiver
// Blink the on-board LED to confirm
void loop() {
if (irrecv.decode(&results)) {
// Attempt to detect the type of remote controller used
if (results.decode_type == NEC) {
Serial.print("NEC: ");
} else if (results.decode_type == SONY) {
Serial.print("SONY: ");
} else if (results.decode_type == RC5) {
Serial.print("RC5: ");
} else if (results.decode_type == RC6) {
Serial.print("RC6: ");
} else if (results.decode_type == UNKNOWN) {
Serial.print("UNKNOWN: ");
}
Serial.println(results.value, HEX);
irrecv.resume(); // Receive the next value
}
}
