#include "armduino.h"							//include ARMduino defs

#define LED			10							//LED attached to pin 8/9/10 (=P2.0RED/1GREEN/2BLUE on TI MSP432 Launchpad)
#define LED_DLY		50							//waste some time, in ms

//user setup
void setup(void) {
	pinMode(LED, OUTPUT);						//set LED as output
}

//user loop
void loop(void) {
	digitalWrite(LED, !digitalRead(LED));		//flip LED
	delay(LED_DLY);								//waste some time
}
