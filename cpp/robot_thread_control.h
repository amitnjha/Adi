//*********************************************************************//
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/18/2015                                            //
//        File:  robot_thread_control.h                                //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is used to launch the individual      //
//                     threads that contorl the robot                  //
//                                                                     //
//*********************************************************************//  


#ifndef ROBOT_THREAD_CONTROL
#define ROBOT_THREAD_CONTROL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <thread>
#include <chrono>
#include <future>
#include <iostream>
#include <queue>

#include "shared_constants.h"

#include "sonar_front_thread.h"
#include "sonar_back_thread.h"
#include "sonar_right_thread.h"
#include "sonar_left_thread.h"

#include "end_program_handler.h"

long frame_;
int pulseWidthFront_;
int pulseWidthBack_;
int pulseWidthRight_;
int pulseWidthLeft_;

int FRONT_READING_;
int BACK_READING_;
int LEFT_READING_;
int RIGHT_READING_;

queue <robotMovementInstruction> robotMovementInstructions_;

movementStateEnum currentState_;
sensorStates      sensorState_;

void controlRobot();

void moveRobot();

#endif
                     
