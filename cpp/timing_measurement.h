#ifndef TIMING_MEASUREMENT
#define TIMING_MEASUREMENT
#include <time.h>
#include <vector>
void start_left_sonar_timer();
void end_left_sonar_timer();
void start_right_sonar_timer();
void end_right_sonar_timer();
void start_back_sonar_timer();
void end_back_sonar_timer();
void start_front_sonar_timer();
void end_front_sonar_timer();
void start_robot_controller_timer();
void end_robot_controller_timer();
extern std::vector<long> left_sonar_start_timings;
extern std::vector<long> left_sonar_end_timings;
extern std::vector<long> right_sonar_start_timings;
extern std::vector<long> right_sonar_end_timings;
extern std::vector<long> back_sonar_start_timings;
extern std::vector<long> back_sonar_end_timings;
extern std::vector<long> front_sonar_start_timings;
extern std::vector<long> front_sonar_end_timings;
extern std::vector<long> robot_controller_start_timings;
extern std::vector<long> robot_controller_end_timings;

#endif
