//*********************************************************************//
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/18/2015                                            //
//        File:  led_back_thread.cpp                                  //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is used to set a back warning LED.    //
//                     This LED is used to indicate when an obstruction//
//                     is too close to the left sonar sensor.          //
//                                                                     //
//*********************************************************************//

#include "led_left_thread.h"

 void SetLedLeft(int pulsewidth)
 {
	 if (wiringPiSetupGpio() == -1)
	 {
		 fprintf(stderr, "Can't initialize wiring Pi left warning LED: 			 %s\n", strerror (errno));
		 return;
	 }
	 
	 pinMode(LED_LEFT_PIN, OUTPUT);
	 
	 if(pulsewidth < MINIMAL_SAFE_PULSEWIDTH)
	 {
		 digitalWrite(LED_LEFT_PIN, HIGH);
	 }
	 else
	 {
		 digitalWrite(LED_LEFT_PIN, LOW);
	 }
	 
 }
