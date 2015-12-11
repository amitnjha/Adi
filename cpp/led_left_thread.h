//*********************************************************************//
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/18/2015                                            //
//        File:  led_left_thread.h                                      //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is used to set a left warning LED.    //
//                     This LED is used to indicate when an obstruction//
//                     is too close to the left sonar sensor.          //
//                                                                     //
//*********************************************************************// 

#ifndef LED_LEFT_THREAD
#define LED_LEFT_THREAD


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>

#include <wiringPi.h>
#include "shared_constants.h"

void SetLedLeft(int pulsewidth);

#endif
