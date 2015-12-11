all: timing_measurement end_program_hander sonar_back_thread sonar_front_thread sonar_right_thread sonar_left_thread robot_thread_control busy.exe robot.exe

robot.exe:  robot_thread_control.cpp
	g++ -std=c++0x -pthread -lwiringPi timing_measurement.o end_program_handler.o robot_thread_control.o sonar_back_thread.o sonar_front_thread.o sonar_right_thread.o sonar_left_thread.o  -o robot -lrt

robot_thread_control: robot_thread_control.cpp  
	g++ -std=c++0x -pthread -c robot_thread_control.cpp 	

sonar_back_thread: sonar_back_thread.cpp
	g++ -std=c++0x -pthread -lsonar_back_thread -c sonar_back_thread.cpp

sonar_front_thread: sonar_front_thread.cpp
	g++ -std=c++0x -pthread -lsonar_front_thread -c sonar_front_thread.cpp

sonar_right_thread: sonar_right_thread.cpp
	g++ -std=c++0x -pthread -lsonar_right_thread -c sonar_right_thread.cpp

sonar_left_thread: sonar_left_thread.cpp
	g++ -std=c++0x -pthread -lsonar_left_thread -c sonar_left_thread.cpp

end_program_hander: end_program_handler.cpp
	g++ -std=c++0x -pthread -lend_program_handler -lshared_constants -c	end_program_handler.cpp 

timing_measurement: timing_measurement.cpp
	g++ -std=c++0x -pthread -lrt -c	timing_measurement.cpp

busy.exe: Busy.cpp
	g++ -o Busy Busy.cpp

clean:
	rm -rf *o robot Busy
