#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <string.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

void printUsage(){
	printf("Usage::\n");
	printf("robot_control   <direction>     <stepcount>\n");
	printf("robot_control {start crt mode by starting without any args}\n");


}


void doForward(int count){
	cout << "In do Forward " << endl;

}

void doReverse(int count){
	cout << "In do Reverse " << endl;

}

void doRight(int count){
	cout << "In do Right " << endl;

}

void doLeft(int count){
	cout << "In do Left " << endl;

}

void parseAndExecute(string str){
	//cout << str << endl;
	char* line = new char[str.size() + 1];
	copy(str.begin(), str.end(), line);
	line[str.size()] = '\0';

	char* dir = strtok(line, ",");
	char* count = strtok(NULL, ",");
	//cout << "dir is " << dir;
	
	if (!strcmp(dir,"reverse")){
		doReverse(atoi(count));
		return;
	}

	if (!strcmp(dir,"forward")){
		doForward(atoi(count));
		return;
	}

	if (!strcmp(dir,"right")){
		doRight(atoi(count));
		return;
	}

	if (!strcmp(dir,"left")){
		doLeft(atoi(count));
		return;
	}

	if (!strcmp(dir,"exit")){
		exit(0);
	}

}



int main(int argc, char* argv[]){
	printf("%d\n", argc);

	

	if (argc != 1 && argc != 3){
		printUsage();
	}
	if (argc == 3){
		//parse and execute
		string arg1 = argv[1];
		string arg2 = argv[2];
		parseAndExecute(arg1 + "," + arg2);
	}
	string str;
	while (true){
		//read line and do parse and execute

		getline(cin, str);
		parseAndExecute(str);
	}

	return 0;

}
