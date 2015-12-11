//*********************************************************************//
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/14/2015                                            //
//        File:  sonar_front_thread.cpp                                //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is used to set up constants for use   //
//                     with the reading of a sonar range finder mounted//
//                     to the front of the robot platform.             //
//                                                                     //
//*********************************************************************// 



#include "sonar_front_thread.h"
#include <thread>
#include <chrono>
#include "timing_measurement.h"

using namespace std;

int WaitForFrontPin(int pin, int level, int timeout)
{
   struct timeval now, start;
   int done;
   long micros;

   gettimeofday(&start, NULL);

   micros = 0;

   done=0;

   while (!done)
   {
      gettimeofday(&now, NULL);
      if (now.tv_sec > start.tv_sec) micros = 1000000L; else micros = 0;
      micros = micros + (now.tv_usec - start.tv_usec);

      if (micros > timeout) done=1;

      if (digitalRead(pin) == level) done = 1;
 std::this_thread::sleep_for(std::chrono::microseconds(100));
   }
   return micros;
}

void GetFrontSensorReading(int &sonarFrontAverageReading)
{
   while(1) {
start_front_sonar_timer();
   int pulseWidth;
	
   /*if (wiringPiSetupGpio () == -1)
   {
      fprintf (stderr, "Can't initialise wiringPi front sonar: %s\n", strerror (errno)) ;
      return;
      }*/

   /*pinMode(TRIGGER_PIN_FRONT, OUTPUT);
   pinMode(ECHO_PIN_FRONT, INPUT);
   pinMode(LED_FRONT_PIN,OUTPUT);
   */

   sonarFrontAverageReading = -1;		/*-1 is no valid readings taken */
   int sonarFrontReadingTotal = 0;          
   int numberOfValidReading   = 0;
   
   for(int readCount = 0; readCount < NUMBER_OF_SONAR_READINGS_TO_TAKE; ++readCount)
   {
      /* trigger reading */

      digitalWrite(TRIGGER_PIN_FRONT, HIGH);
      WaitForFrontPin(ECHO_PIN_FRONT, TIMEOUT, 10); /* wait 10 microseconds */
      digitalWrite(TRIGGER_PIN_FRONT, LOW);
	  
      /* wait for reading to start */
      WaitForFrontPin(ECHO_PIN_FRONT, HIGH, ECO_TIME_OUT); /* 5 ms timeout */
      if (digitalRead(ECHO_PIN_FRONT)  == HIGH)
      {
         pulseWidth = WaitForFrontPin(ECHO_PIN_FRONT, LOW, 60000L); /* 60 ms timeout */
         if(digitalRead(ECHO_PIN_FRONT)== LOW)
         {
            /* valid reading code */
            sonarFrontReadingTotal += pulseWidth;          /* Add to total for averaging */
            ++numberOfValidReading;
            /* valid reading code */
         }
      }  
   }
   if(numberOfValidReading != 0)
   {
      sonarFrontAverageReading = sonarFrontReadingTotal / numberOfValidReading;
      if(VERBOSITY >= 1)
      {
         printf("Front Sensor = %d.\n", sonarFrontAverageReading);
      }
      FRONT_READING_ = sonarFrontAverageReading;
      if(FRONT_READING_ < MINIMAL_SAFE_PULSEWIDTH){
	//count++;	
	//	        if(count >= 3)	
			digitalWrite(LED_FRONT_PIN, HIGH);	
			//printf("danger\n");
		}else{
			digitalWrite(LED_FRONT_PIN, LOW);
			//	        count = 0;	
			//printf("\n");
      } 
   }
   else
   {
      printf("Front Sensor No Reading.\n");
   }
   //return;
end_front_sonar_timer();
   std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}


