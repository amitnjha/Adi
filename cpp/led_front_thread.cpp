//*********************************************************************//
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/18/2015                                            //
//        File:  led_front_thread.cpp                                  //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is used to set a front warning LED.   //
//                     This LED is used to indicate when an obstruction//
//                     is too close to the front sonar sensor.         //
//                                                                     //
//*********************************************************************//

#include "led_front_thread.h"

void SetLedFront(int pulsewidth)
{
   if (wiringPiSetupGpio() == -1)
   {
      fprintf(stderr, "Can't initialize wiring Pi front warning LED: %s\n", strerror (errno));
      return;
   }
	 
   pinMode(LED_FRONT_PIN, OUTPUT);
	 
   if(pulsewidth < MINIMAL_SAFE_PULSEWIDTH)
   {
      digitalWrite(LED_FRONT_PIN, HIGH);
   }
   else
   {
      digitalWrite(LED_FRONT_PIN, LOW);
   }	 
 }