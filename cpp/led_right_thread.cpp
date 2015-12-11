//*********************************************************************//
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/18/2015                                            //
//        File:  led_right_thread.cpp                                  //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is used to set a right warning LED.   //
//                     This LED is used to indicate when an obstruction//
//                     is too close to the right sonar sensor.         //
//                                                                     //
//*********************************************************************//

#include "led_right_thread.h"

 void SetLedRight(int pulsewidth)
 {
	 if (wiringPiSetupGpio() == -1)
	 {
		 fprintf(stderr, "Can't initialize wiring Pi right warning LED: %s\n", strerror (errno));
		 return;
	 }
	 
	 pinMode(LED_RIGHT_PIN, OUTPUT);
	 
	 if(pulsewidth < MINIMAL_SAFE_PULSEWIDTH)
	 {
		 digitalWrite(LED_RIGHT_PIN, HIGH);
	 }
	 else
	 {
		 digitalWrite(LED_RIGHT_PIN, LOW);
	 }
	 
 }