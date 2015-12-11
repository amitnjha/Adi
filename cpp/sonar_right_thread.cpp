//*********************************************************************//
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/15/2015                                            //
//        File:  sonar_right_thread.cpp                                //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is used to set up constants for use   //
//                     with the reading of a sonar range finder mounted//
//                     to the right of the robot platform              //
//                                                                     //
//*********************************************************************// 



#include "sonar_right_thread.h"
#include "timing_measurement.h"

int WaitForRightPin(int pin, int level, int timeout)
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

void GetRightSensorReading(int &sonarRightAverageReading)
{
  while(1)
    {
start_right_sonar_timer();
      int pulseWidth;

      /*if (wiringPiSetupGpio () == -1)
   {
      fprintf (stderr, "Can't initialise wiringPi right sonar: %s\n", strerror (errno)) ;
      return;
      }*/

      //pinMode(TRIGGER_PIN_RIGHT, OUTPUT);
      //pinMode(ECHO_PIN_RIGHT, INPUT);
   
   sonarRightAverageReading = -1;		/*-1 is no valid readings taken */
   int sonarRightReadingTotal = 0;          
   int numberOfValidReading   = 0;
   
   for(int readCount = 0; readCount < NUMBER_OF_SONAR_READINGS_TO_TAKE; ++readCount)
   {
	   /* trigger reading */

      digitalWrite(TRIGGER_PIN_RIGHT, HIGH);
      WaitForRightPin(ECHO_PIN_RIGHT, TIMEOUT, 10); /* wait 10 microseconds */
      digitalWrite(TRIGGER_PIN_RIGHT, LOW);
	  
	  /* wait for reading to start */
      WaitForRightPin(ECHO_PIN_RIGHT, HIGH, ECO_TIME_OUT); /* 5 ms timeout */
      if (digitalRead(ECHO_PIN_RIGHT)  == HIGH)
      {
         pulseWidth = WaitForRightPin(ECHO_PIN_RIGHT, LOW, 60000L); /* 60 ms timeout */
	 if(digitalRead(ECHO_PIN_RIGHT)== LOW)
         {
	    /* valid reading code */
	    sonarRightReadingTotal += pulseWidth;          /* Add to total for averaging */
	    ++numberOfValidReading;
	    /* valid reading code */
         }
      }
	  
   }
   if(numberOfValidReading != 0)
   {
      sonarRightAverageReading = sonarRightReadingTotal / numberOfValidReading;
      if(VERBOSITY >= 1)
      {
         printf("Right Sensor = %d.\n", sonarRightAverageReading);
      }
      RIGHT_READING_ = sonarRightAverageReading;
       if(RIGHT_READING_ < MINIMAL_SAFE_PULSEWIDTH){
	//count++;	
	//	        if(count >= 3)	
			digitalWrite(LED_RIGHT_PIN, HIGH);	
			//printf("danger\n");
		}else{
			digitalWrite(LED_RIGHT_PIN, LOW);
			//	        count = 0;	
			//printf("\n");
      } 
   }
   else
   {
      printf("Right Sensor No Reading.\n");
   }
   end_right_sonar_timer();
   //return;
   std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
}
