//*********************************************************************//
//        CSE 520S Real Time Robot Project                             //
//        Date:  10/14/2015                                            //
//        File:  shared_constants.h                                    //
//        Developers:  Vinaya Sheni                                    //
//                     Amit Jha                                        //
//                     Michael Williams                                //
//                                                                     //
//        Description: This code is used as a repository for constants //
//                     to be used by the various parts of the robot    //
//                     code to facilitate readability                  //
//                                                                     //
//*********************************************************************// 


#ifndef SHARED_CONSTANTS
#define SHARED_CONSTANTS

#define TRIGGER_PIN_FRONT 13
#define ECHO_PIN_FRONT    21

#define TRIGGER_PIN_BACK  20
#define ECHO_PIN_BACK     26

#define TRIGGER_PIN_LEFT  16
#define ECHO_PIN_LEFT     19

#define TRIGGER_PIN_RIGHT  6
#define ECHO_PIN_RIGHT    12

#define LED_FRONT_PIN      4

#define LED_BACK_PIN      25

#define LED_RIGHT_PIN     24

#define LED_LEFT_PIN      27

/////////////Motor Control Pins - start

#define RIGHT_FORWARD_PIN 18

#define RIGHT_REVERSE_PIN 17

#define LEFT_FORWARD_PIN 23

#define LEFT_REVERSE_PIN 22
////////////Motor Control Pins - end

const int WAIT_TIMER = 100;
const int MINIMAL_SAFE_PULSEWIDTH = 1000;

const int ECO_TIME_OUT=1000;

#define TIMEOUT 999 /* any value other than LOW or HIGH */

const int NUMBER_OF_SONAR_READINGS_TO_TAKE = 10;

#include <thread>
#include <chrono>

using namespace std;
extern int FRONT_READING_;
extern int BACK_READING_;
extern int LEFT_READING_;
extern int RIGHT_READING_;

enum movementStateEnum : short
{
   NOT_MOVING      = 0,
   MOVING_FORWARD  = 1,
   MOVING_BACKWARD = 2,
   MOVING_RIGHT    = 3,
   MOVING_LEFT     = 4
};

enum robotMovementInstruction : short
{
   STOP     = 0,
   FORWARD  = 1,
   BACKWARD = 2,
   RIGHT    = 3,
   LEFT     = 4
};

enum sensorStates : short
{
   NONE             = 0,
   LEFT_ONLY        = 1,
   RIGHT_ONLY       = 2,
   RIGHT_LEFT       = 3,
   BACK_ONLY        = 4,
   BACK_LEFT        = 5,
   BACK_RIGHT       = 6,
   BACK_RIGHT_LEFT  = 7,
   FRONT_ONLY       = 8,
   FRONT_LEFT       = 9,
   FRONT_RIGHT      = 10,
   FRONT_SIDES      = 11,
   FRONT_BACK       = 12,
   FRONT_BACK_LEFT  = 13,
   FRONT_BACK_RIGHT = 14,
   ALL              = 15
};

const int VERBOSITY = 0;
#endif
