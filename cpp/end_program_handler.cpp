/*********************************************************************///
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/14/2015                                            //
//        File:  sonar_front_thread.h                                  //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is handles  termination of program    //
//                                                                     //
//*********************************************************************//
#include "end_program_handler.h"
#include <fstream>
void endProgram()
{
	std::cin.get();
getLeftSensorReadings();	
getRightSensorReadings();
getBackSensorReadings();
getFrontSensorReadings();
getRobotControllerReadings();
exit(0);
}
void getRobotControllerReadings()
{
std::vector<long>::iterator liter=robot_controller_start_timings.begin();
        std::vector<long>::iterator riter=robot_controller_end_timings.begin();
        std::cout<<"Robot controller timings "<<std::endl;
        std::ofstream sensorReadings;
        sensorReadings.open ("robotcontroller.txt");
        printTimings(riter,liter,sensorReadings);
        sensorReadings.close();

}
void getLeftSensorReadings()
{
	std::vector<long>::iterator liter=left_sonar_start_timings.begin();
	std::vector<long>::iterator riter=left_sonar_end_timings.begin();
        std::cout<<"left senor timings "<<std::endl;
	std::ofstream sensorReadings;
  	sensorReadings.open ("leftsonarr.txt");
 	printTimings(riter,liter,sensorReadings);
	sensorReadings.close();
}

void getRightSensorReadings()
{
        std::vector<long>::iterator liter=right_sonar_start_timings.begin();
        std::vector<long>::iterator riter=right_sonar_end_timings.begin();
 	std::ofstream sensorReadings;
        sensorReadings.open ("rightsonarr.txt");
        std::cout<<"Right senor timings "<<std::endl;
        printTimings(riter,liter,sensorReadings);
	sensorReadings.close();
}

void getBackSensorReadings()
{
        std::vector<long>::iterator liter=back_sonar_start_timings.begin();
        std::vector<long>::iterator riter=back_sonar_end_timings.begin();
        std::cout<<"Back senor timings "<<std::endl;
	std::ofstream sensorReadings;
        sensorReadings.open ("backsonarr.txt");
	printTimings(riter,liter,sensorReadings);
	sensorReadings.close();
}

void getFrontSensorReadings()
{
        std::vector<long>::iterator liter=front_sonar_start_timings.begin();
        std::vector<long>::iterator riter=front_sonar_end_timings.begin();
        std::cout<<"Front senor timings "<<std::endl;
        std::ofstream sensorReadings;
        sensorReadings.open ("frontsonarr.txt");
        printTimings(riter,liter,sensorReadings);
	sensorReadings.close();
}

void printTimings(std::vector<long>::iterator riter, std::vector<long>::iterator liter, std::ofstream& sensorReadings)
{
	long endTime;
        long executionTime;
        long startTime;
  	while(liter!=left_sonar_start_timings.end())
        {
                startTime=*liter;
                endTime=*riter;
                if(endTime==0)
                        break;

                if(endTime<startTime)
                {
                        endTime=endTime+1000000000;
                }
//                std::cout<<"start time "<<startTime<<" end time "<<endTime<<" execution time "<<(endTime-startTime)<<std::endl;
//		std::cout<<(endTime-startTime)<<std::endl;
		sensorReadings<<(endTime-startTime)<<std::endl;
                ++riter;
		++liter;

	}	
}
