//*********************************************************************//
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/18/2015                                            //
//        File:  sonar_right_thread.h                                  //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is used to Launch the individual      //
//                     threads that control the robot                  //
//                                                                     //
//*********************************************************************//                       

#include "robot_thread_control.h"

//do reverse 1 step
void doReverse(){
  digitalWrite(RIGHT_FORWARD_PIN, LOW);
  digitalWrite(LEFT_FORWARD_PIN,LOW);
  digitalWrite(RIGHT_REVERSE_PIN, HIGH);
  digitalWrite(LEFT_REVERSE_PIN, HIGH);
  //std::this_thread::sleep_for(std::chrono::milliseconds(2));
  //digitalWrite(RIGHT_REVERSE_PIN, LOW);
  //digitalWrite(LEFT_REVERSE_PIN, LOW);
  

}

//do forward 1 step
void doForward(){
  digitalWrite(RIGHT_REVERSE_PIN, LOW);
  digitalWrite(LEFT_REVERSE_PIN, LOW);
  digitalWrite(RIGHT_FORWARD_PIN, HIGH);
  digitalWrite(LEFT_FORWARD_PIN,HIGH);
  //std::this_thread::sleep_for(std::chrono::milliseconds(2));
  //digitalWrite(RIGHT_FORWARD_PIN, LOW);
  //digitalWrite(LEFT_FORWARD_PIN, LOW);
}

// do Right 1 step
void doRight(){
  digitalWrite(RIGHT_REVERSE_PIN, HIGH);
  digitalWrite(LEFT_REVERSE_PIN, LOW);
  digitalWrite(LEFT_FORWARD_PIN,HIGH);
  digitalWrite(RIGHT_FORWARD_PIN, LOW);
  //std::this_thread::sleep_for(std::chrono::milliseconds(2));
  //digitalWrite(RIGHT_FORWARD_PIN, LOW);
  //digitalWrite(LEFT_REVERSE_PIN, LOW);

}

//do Left 1 step
void doLeft(){
  digitalWrite(RIGHT_REVERSE_PIN, LOW);
  digitalWrite(LEFT_REVERSE_PIN, HIGH);
  digitalWrite(RIGHT_FORWARD_PIN, HIGH);
  digitalWrite(LEFT_FORWARD_PIN,LOW);
  //std::this_thread::sleep_for(std::chrono::milliseconds(2));
  //digitalWrite(LEFT_FORWARD_PIN, LOW);
  //digitalWrite(RIGHT_REVERSE_PIN, LOW);
}

//Stop
void doStop()
{
  digitalWrite(LEFT_FORWARD_PIN, LOW);
  digitalWrite(LEFT_REVERSE_PIN, LOW);
  digitalWrite(RIGHT_FORWARD_PIN, LOW);
  digitalWrite(RIGHT_REVERSE_PIN, LOW);
}

void controlRobot(){

  while(1){
    start_robot_controller_timer();

    if(VERBOSITY >= 1)
    {
       cout << FRONT_READING_ << "(F)," << BACK_READING_ << "(B)," << LEFT_READING_ << "(L)," << RIGHT_READING_ <<"(R)" << endl;
    }
    bool dangerFront = ( MINIMAL_SAFE_PULSEWIDTH > FRONT_READING_ && FRONT_READING_ != 1);
    bool dangerBack  = ( MINIMAL_SAFE_PULSEWIDTH > BACK_READING_ && BACK_READING_ != 1);
    bool dangerRight = ( MINIMAL_SAFE_PULSEWIDTH > RIGHT_READING_ && RIGHT_READING_ != 1);
    bool dangerLeft  = ( MINIMAL_SAFE_PULSEWIDTH > LEFT_READING_ && LEFT_READING_ != 1);

    sensorState_ = (sensorStates)(dangerFront * 8 + dangerBack * 4 + dangerRight * 2 + dangerLeft);

   switch(currentState_)
   {
      case(NOT_MOVING):
         switch(sensorState_)
         {
            case(NONE):
               robotMovementInstructions_.push(STOP);
               break;
            case(LEFT_ONLY):
               robotMovementInstructions_.push(RIGHT);
               break;
            case(RIGHT_ONLY):
               robotMovementInstructions_.push(LEFT);
               break;
            case(RIGHT_LEFT):
               robotMovementInstructions_.push(FORWARD);
               break;
            case(BACK_ONLY):
               robotMovementInstructions_.push(FORWARD);
               break;
            case(BACK_LEFT):
               robotMovementInstructions_.push(FORWARD);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(BACK_RIGHT):
               robotMovementInstructions_.push(FORWARD);
               robotMovementInstructions_.push(LEFT);
               break;
            case(BACK_RIGHT_LEFT):
               robotMovementInstructions_.push(FORWARD);
               break;
            case(FRONT_ONLY):
               robotMovementInstructions_.push(BACKWARD);
               break;
            case(FRONT_LEFT):
               robotMovementInstructions_.push(BACKWARD);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_RIGHT):
               robotMovementInstructions_.push(BACKWARD);
               robotMovementInstructions_.push(LEFT);
               break;
            case(FRONT_SIDES):
               robotMovementInstructions_.push(BACKWARD);
               break;
            case(FRONT_BACK):
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_BACK_LEFT):
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_BACK_RIGHT):
               robotMovementInstructions_.push(LEFT);
               break;
            case(ALL):
               robotMovementInstructions_.push(STOP);
               break;
         }         
         break;
      case(MOVING_FORWARD):
         switch(sensorState_)
         {
            case(NONE):
               robotMovementInstructions_.push(STOP);
               break;
            case(LEFT_ONLY):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(RIGHT_ONLY):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(LEFT);
               break;
            case(RIGHT_LEFT):
               robotMovementInstructions_.push(FORWARD);
               break;
            case(BACK_ONLY):
               robotMovementInstructions_.push(FORWARD);
               break;
            case(BACK_LEFT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(FORWARD);
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(BACK_RIGHT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(FORWARD);
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(LEFT);
               break;
            case(BACK_RIGHT_LEFT):
               robotMovementInstructions_.push(FORWARD);
               break;
            case(FRONT_ONLY):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(BACKWARD);
               break;
            case(FRONT_LEFT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(BACKWARD);
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_RIGHT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(BACKWARD);
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(LEFT);
               break;
            case(FRONT_SIDES):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(BACKWARD);
               break;
            case(FRONT_BACK):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_BACK_LEFT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_BACK_RIGHT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(LEFT);
               break;
            case(ALL):
               robotMovementInstructions_.push(STOP);
               break;
         }         
         break;
      case(MOVING_BACKWARD):
         switch(sensorState_)
         {
            case(NONE):
               robotMovementInstructions_.push(STOP);
               break;
            case(LEFT_ONLY):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(RIGHT_ONLY):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(LEFT);
               break;
            case(RIGHT_LEFT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(FORWARD);
               break;
            case(BACK_ONLY):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(FORWARD);
               break;
            case(BACK_LEFT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(FORWARD);
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(BACK_RIGHT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(FORWARD);
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(LEFT);
               break;
            case(BACK_RIGHT_LEFT):
               robotMovementInstructions_.push(FORWARD);
               break;
            case(FRONT_ONLY):
               robotMovementInstructions_.push(BACKWARD);
               break;
            case(FRONT_LEFT):
               robotMovementInstructions_.push(BACKWARD);
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_RIGHT):
               robotMovementInstructions_.push(BACKWARD);
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(LEFT);
               break;
            case(FRONT_SIDES):
               robotMovementInstructions_.push(BACKWARD);
               break;
            case(FRONT_BACK):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_BACK_LEFT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_BACK_RIGHT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(LEFT);
               break;
            case(ALL):
               robotMovementInstructions_.push(STOP);
               break;
         }         
         break;
      case(MOVING_RIGHT):
         switch(sensorState_)
         {
            case(NONE):
               robotMovementInstructions_.push(STOP);
               break;
            case(LEFT_ONLY):
               robotMovementInstructions_.push(RIGHT);
               break;
            case(RIGHT_ONLY):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(LEFT);
               break;
            case(RIGHT_LEFT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(FORWARD);
               break;
            case(BACK_ONLY):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(FORWARD);
               break;
            case(BACK_LEFT):
               robotMovementInstructions_.push(FORWARD);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(BACK_RIGHT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(FORWARD);
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(LEFT);
               break;
            case(BACK_RIGHT_LEFT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(FORWARD);
               break;
            case(FRONT_ONLY):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(BACKWARD);
               break;
            case(FRONT_LEFT):
               robotMovementInstructions_.push(BACKWARD);
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_RIGHT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(BACKWARD);
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(LEFT);
               break;
            case(FRONT_SIDES):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(BACKWARD);
               break;
            case(FRONT_BACK):
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_BACK_LEFT):
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_BACK_RIGHT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(LEFT);
               break;
            case(ALL):
               robotMovementInstructions_.push(STOP);
               break;
         }         
         break;
      case(MOVING_LEFT):
         switch(sensorState_)
         {
            case(NONE):
               robotMovementInstructions_.push(STOP);
               break;
            case(LEFT_ONLY):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(RIGHT_ONLY):
               robotMovementInstructions_.push(LEFT);
               break;
            case(RIGHT_LEFT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(FORWARD);
               break;
            case(BACK_ONLY):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(FORWARD);
               break;
            case(BACK_LEFT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(FORWARD);
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(BACK_RIGHT):
               robotMovementInstructions_.push(FORWARD);
               robotMovementInstructions_.push(LEFT);
               break;
            case(BACK_RIGHT_LEFT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(FORWARD);
               break;
            case(FRONT_ONLY):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(BACKWARD);
               break;
            case(FRONT_LEFT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(BACKWARD);
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_RIGHT):
               robotMovementInstructions_.push(BACKWARD);
               robotMovementInstructions_.push(LEFT);
               break;
            case(FRONT_SIDES):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(BACKWARD);
               break;
            case(FRONT_BACK):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_BACK_LEFT):
               robotMovementInstructions_.push(STOP);
               robotMovementInstructions_.push(RIGHT);
               break;
            case(FRONT_BACK_RIGHT):
               robotMovementInstructions_.push(LEFT);
               break;
            case(ALL):
               robotMovementInstructions_.push(STOP);
               break;
         }         
         break;

   }
 end_robot_controller_timer(); 
     std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

}

void moveRobot()
{
   while(1)
   {
      if(!robotMovementInstructions_.empty())
      {
         switch(robotMovementInstructions_.front())
         {
            case(STOP):
               currentState_ = NOT_MOVING;
               doStop();
               break;
            case(FORWARD):
               currentState_ = MOVING_FORWARD;
               doForward();
               break;
            case(BACKWARD):
               currentState_ = MOVING_BACKWARD;
               doReverse();
               break;
            case(RIGHT):
               currentState_ = MOVING_RIGHT;
               doRight();
               break;
            case(LEFT):
               currentState_ = MOVING_LEFT;
               doLeft();
               break;
         }
         robotMovementInstructions_.pop();
      }
	  std::this_thread::sleep_for(std::chrono::milliseconds(5));
   }
}


/*void controlRobot(){

  while(1){
start_robot_controller_timer();
 
if(VERBOSITY >= 1)
    {
       cout << FRONT_READING_ << "(F)," << BACK_READING_ << "(B)," << LEFT_READING_ << "(L)," << RIGHT_READING_ <<"(R)" << endl;
    }
    //cout << FRONT_READING_ << "(F)," << BACK_READING_ << "(B)," << LEFT_READING_ << "(L)," << RIGHT_READING_ <<"(R)" << endl;
//     std::this_thread::sleep_for(std::chrono::seconds(2));
     //MINIMAL_SAFE_PULSEWIDTH   
     //check readings one by one.
     // if any one of them is less than MIN SAFE dist, move 
     // else sleep for 2 secs
     if ( MINIMAL_SAFE_PULSEWIDTH > FRONT_READING_ && FRONT_READING_ != 1){
       doReverse();
     }else if ( MINIMAL_SAFE_PULSEWIDTH > BACK_READING_ && BACK_READING_ != 1){
       doForward();
     }else if( MINIMAL_SAFE_PULSEWIDTH > LEFT_READING_ && LEFT_READING_ != 1){
       doLeft();
     }else if ( MINIMAL_SAFE_PULSEWIDTH > RIGHT_READING_ && RIGHT_READING_ != 1){
       doRight();
     }//else{
       // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // }
end_robot_controller_timer();
std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

}

*/
int main(int argc, char *argv[])
{
   frame_ = 0L;
   pulseWidthFront_ = 0;
   pulseWidthBack_  = 0;
   pulseWidthRight_ = 0;
   pulseWidthLeft_  = 0;
   currentState_    =  NOT_MOVING   ;
   sensorState_     = NONE;
   

   //begin initialize wiringPi and Pin Modes
    if (wiringPiSetupGpio () == -1)
   {
      fprintf (stderr, "Can't initialise wiringPi back sonar: %s\n", strerror (errno)) ;
      return -1;
   }

   //back
   pinMode(TRIGGER_PIN_BACK, OUTPUT);
   pinMode(ECHO_PIN_BACK, INPUT);
   pinMode(LED_BACK_PIN, OUTPUT);

   //front

   pinMode(TRIGGER_PIN_FRONT, OUTPUT);
   pinMode(ECHO_PIN_FRONT, INPUT);
   pinMode(LED_FRONT_PIN,OUTPUT);
   //right
   pinMode(TRIGGER_PIN_RIGHT, OUTPUT);
   pinMode(ECHO_PIN_RIGHT, INPUT);
   pinMode(LED_RIGHT_PIN,OUTPUT);
   //left
   pinMode(TRIGGER_PIN_LEFT, OUTPUT);
   pinMode(ECHO_PIN_LEFT, INPUT);
   pinMode(LED_LEFT_PIN,OUTPUT);

   //Motor pins
   
   pinMode(RIGHT_FORWARD_PIN, OUTPUT);
   pinMode(RIGHT_REVERSE_PIN, OUTPUT);
   pinMode(LEFT_FORWARD_PIN,OUTPUT);
   pinMode(LEFT_REVERSE_PIN,OUTPUT);


   //end initialize wiringPi and Pin Modes


   //while(1)
   //{
      ++frame_;
      //Run Thread for Front and Back Sensors
      // if((frame_ % 10 == 0) && (frame_ % 20 != 0))
      //{
         std::cout << "Launching Front Sensor" << std::endl;               
         std::thread frontSensorThread(&GetFrontSensorReading,std::ref(pulseWidthFront_));
         std::cout << "Launching Back Sensor" << std::endl;
         std::thread backSensorThread(&GetBackSensorReading, std::ref(pulseWidthBack_));
         frontSensorThread.detach();
         std::cout << "Front Sensor Join" << std::endl;
         backSensorThread.detach();
         std::cout << "Back Sensor Join" << std::endl;
	 //}
	 //else if(frame_ % 20 == 0)
	 // {
         std::cout << "Launching Right Sensor" << std::endl;
         std::thread rightSensorThread(&GetRightSensorReading, std::ref(pulseWidthRight_));
         std::cout << "Launching Left Sensor" << std::endl;
         std::thread leftSensorThread(&GetLeftSensorReading, std::ref(pulseWidthLeft_));
         rightSensorThread.detach();
         std::cout << "Right Sensor Join" << std::endl;
         leftSensorThread.detach();

	std::thread endProgramHandler(&endProgram);
	endProgramHandler.detach();	
        std::thread movement(&moveRobot);
        movement.detach();
 
	thread robotcontrol(&controlRobot);
	 robotcontrol.join();
	 
         std::cout << "Left Sensor Join" << std::endl;
	 //}

	 //if((frame_ % 10 == 0) && (frame_ % 20 != 0))
	 //{
         //std::thread frontLedThread(&SetLedFront,pulseWidthFront_);
         //std::thread backLedThread(&SetLedBack,pulseWidthBack_);
         //frontLedThread.join();
         //backLedThread.join();
	 //}
	 // else if(frame_ % 20 == 0)
	 //{
         //std::thread rightLedThread(&SetLedRight,pulseWidthRight_);
         //std::thread leftLedThread(&SetLedLeft,pulseWidthLeft_);
	 // rightLedThread.join();
         //leftLedThread.join();
	 //}
	 //}
}
