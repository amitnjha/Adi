//*********************************************************************//
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/14/2015                                            //
//        File:  sonar_front_thread.h                                  //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is header file which handles          //
//termination of program                                               //
//*********************************************************************//
#include <iostream>
#include <vector>
#include "timing_measurement.h"
void endProgram();
void getLeftSensorReadings();
void getRightSensorReadings();
void getBackSensorReadings();
void getFrontSensorReadings();
void getRobotControllerReadings();

void printTimings(std::vector<long>::iterator riter, std::vector<long>::iterator liter, std::ofstream& sensorReadings);

