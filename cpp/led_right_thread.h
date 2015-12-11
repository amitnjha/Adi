//*********************************************************************//
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/18/2015                                            //
//        File:  led_right_thread.h                                    //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is used to set a right warning LED.   //
//                     This LED is used to indicate when an obstruction//
//                     is too close to the right sonar sensor.         //
//                                                                     //
//*********************************************************************// 

#ifndef LED_RIGHT_THREAD
#define LED_RIGHT_THREAD


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>

#include <wiringPi.h>
#include "shared_constants.h"

void SetLedRight(int pulsewidth);

#endif
