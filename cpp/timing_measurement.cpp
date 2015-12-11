#include "timing_measurement.h"
std::vector<long> left_sonar_start_timings;
std::vector<long> left_sonar_end_timings;

std::vector<long> right_sonar_start_timings;
std::vector<long> right_sonar_end_timings;

std::vector<long> front_sonar_start_timings;
std::vector<long> front_sonar_end_timings;

std::vector<long> back_sonar_start_timings;
std::vector<long> back_sonar_end_timings;

std::vector<long> robot_controller_start_timings;
std::vector<long> robot_controller_end_timings;

void start_robot_controller_timer()
{
  long int start_time;
        long int time_difference;
        struct timespec gettime_now;

        clock_gettime(CLOCK_REALTIME, &gettime_now);
        start_time = gettime_now.tv_nsec;               //Get nS value
        robot_controller_start_timings.push_back(start_time);
}

void end_robot_controller_timer()
{
long int start_time;
        long int time_difference;
        struct timespec gettime_now;

        clock_gettime(CLOCK_REALTIME, &gettime_now);
        start_time = gettime_now.tv_nsec;               //Get nS value
        robot_controller_end_timings.push_back(start_time);

}


void start_left_sonar_timer()
{
	long int start_time;
        long int time_difference;
        struct timespec gettime_now;

        clock_gettime(CLOCK_REALTIME, &gettime_now);
        start_time = gettime_now.tv_nsec;               //Get nS value
	left_sonar_start_timings.push_back(start_time);

}
void end_left_sonar_timer()
{
  long int start_time;
        long int time_difference;
        struct timespec gettime_now;

        clock_gettime(CLOCK_REALTIME, &gettime_now);
        start_time = gettime_now.tv_nsec;               //Get nS value
        left_sonar_end_timings.push_back(start_time);

}
void start_right_sonar_timer()
{
        long int start_time;
        long int time_difference;
        struct timespec gettime_now;

        clock_gettime(CLOCK_REALTIME, &gettime_now);
        start_time = gettime_now.tv_nsec;               //Get nS value
        right_sonar_start_timings.push_back(start_time);
}

void end_right_sonar_timer()
{
  long int start_time;
        long int time_difference;
        struct timespec gettime_now;

        clock_gettime(CLOCK_REALTIME, &gettime_now);
        start_time = gettime_now.tv_nsec;               //Get nS value
        right_sonar_end_timings.push_back(start_time);

}
void start_back_sonar_timer()
{
        long int start_time;
        long int time_difference;
        struct timespec gettime_now;

        clock_gettime(CLOCK_REALTIME, &gettime_now);
        start_time = gettime_now.tv_nsec;               //Get nS value
        back_sonar_start_timings.push_back(start_time);
}
void end_back_sonar_timer()
{
  long int start_time;
        long int time_difference;
        struct timespec gettime_now;

        clock_gettime(CLOCK_REALTIME, &gettime_now);
        start_time = gettime_now.tv_nsec;               //Get nS value
        back_sonar_end_timings.push_back(start_time);

}
void start_front_sonar_timer()
{
        long int start_time;
        long int time_difference;
        struct timespec gettime_now;

        clock_gettime(CLOCK_REALTIME, &gettime_now);
        start_time = gettime_now.tv_nsec;               //Get nS value
        front_sonar_start_timings.push_back(start_time);
}
void end_front_sonar_timer()
{
  long int start_time;
        long int time_difference;
        struct timespec gettime_now;

        clock_gettime(CLOCK_REALTIME, &gettime_now);
        start_time = gettime_now.tv_nsec;               //Get nS value
        front_sonar_end_timings.push_back(start_time);

}
