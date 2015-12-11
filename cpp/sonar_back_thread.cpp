//*********************************************************************//
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/15/2015                                            //
//        File:  sonar_back_thread.cpp                                 //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is used to set up constants for use   //
//                     with the reading of a sonar range finder mounted//
//                     to the back of the robot platform.              //
//                                                                     //
//*********************************************************************// 



#include "sonar_back_thread.h"
#include "timing_measurement.h"

int WaitForBackPin(int pin, int level, int timeout)
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
     
void GetBackSensorReading(int &sonarBackAverageReading)
{
  while(1)
    {
start_back_sonar_timer();
      int pulseWidth;
   /*
   if (wiringPiSetupGpio () == -1)
   {
      fprintf (stderr, "Can't initialise wiringPi back sonar: %s\n", strerror (errno)) ;
      return;
   }

   pinMode(TRIGGER_PIN_BACK, OUTPUT);
   pinMode(ECHO_PIN_BACK, INPUT);
   pinMode(LED_BACK_PIN, OUTPUT);
   */
   sonarBackAverageReading = -1;		/*-1 is no valid readings taken */
   int sonarBackReadingTotal = 0;          
   int numberOfValidReading   = 0;
   
   for(int readCount = 0; readCount < NUMBER_OF_SONAR_READINGS_TO_TAKE; ++readCount)
   {
      /* trigger reading */

      digitalWrite(TRIGGER_PIN_BACK, HIGH);
      WaitForBackPin(ECHO_PIN_BACK, TIMEOUT, 10); /* wait 10 microseconds */
      digitalWrite(TRIGGER_PIN_BACK, LOW);
	  
      /* wait for reading to start */
      WaitForBackPin(ECHO_PIN_BACK, HIGH, ECO_TIME_OUT);
      if (digitalRead(ECHO_PIN_BACK)  == HIGH)
      {
         pulseWidth = WaitForBackPin(ECHO_PIN_BACK, LOW, 60000L); /* 60 ms timeout */
         if(digitalRead(ECHO_PIN_BACK)== LOW)
         {
            /* valid reading code */
            sonarBackReadingTotal += pulseWidth;          /* Add to total for averaging */
            ++numberOfValidReading;
	    /* valid reading code */
         }
      }	  
   }
   if(numberOfValidReading != 0)
   {
      sonarBackAverageReading = sonarBackReadingTotal / numberOfValidReading;
      if(VERBOSITY >= 1)
      {
         printf("Back Sensor = %d.\n", sonarBackAverageReading);
      }
      BACK_READING_ = sonarBackAverageReading;
       if(BACK_READING_ < MINIMAL_SAFE_PULSEWIDTH){
	//count++;	
	//	        if(count >= 3)	
			digitalWrite(LED_BACK_PIN, HIGH);	
			printf("danger\n");
		}else{
			digitalWrite(LED_BACK_PIN, LOW);
			//	        count = 0;	
			//printf("\n");
      } 
   }
   else
   {
      printf("Back Sensor No Reading.\n");
   }
   //return;
 end_back_sonar_timer();
   std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
