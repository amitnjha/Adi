//*********************************************************************//
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/14/2015                                            //
//        File:  sonar_left_thread.h                                   //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is used to set up constants for use   //
//                     with the reading of a sonar range finder mounted//
//                     to the left of the robot platform.              //
//                                                                     //
//*********************************************************************//                       



#ifndef SONAR_LEFT_THREAD
#define SONAR_LEFT_THREAD


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>

#include <wiringPi.h>

#include "shared_constants.h"

int WaitForLeftPin(int pin, int level, int timeout);

void GetLeftSensorReading(int &sonarLeftAverageReading);

#endif
