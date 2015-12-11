//*********************************************************************//
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/14/2015                                            //
//        File:  sonar_front_thread.h                                  //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is used to set up constants for use   //
//                     with the reading of a sonar range finder mounted//
//                     to the front of the robot platform.             //
//                                                                     //
//*********************************************************************//                       



#ifndef SONAR_FRONT_THREAD
#define SONAR_FRONT_THREAD


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>

#include <wiringPi.h>
#include "shared_constants.h"



int WaitForFrontPin(int pin, int level, int timeout);	
void GetFrontSensorReading(int &sonarFrontAverageReading);
#endif
