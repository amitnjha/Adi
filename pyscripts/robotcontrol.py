#!/usr/bin/python

import RPi.GPIO as GPIO


import time
import subprocess
import sys

GPIO.setmode(GPIO.BCM)
GPIO.setup(18,GPIO.OUT)
GPIO.setup(17, GPIO.OUT)
GPIO.setup(23,GPIO.OUT)
GPIO.setup(22, GPIO.OUT)
GPIO.setup(11, GPIO.OUT)

#test count times.
def doTest(count=1):
	i = 0;
	while i < count:
		GPIO.output(11,True);
		time.sleep(2)
		i = i+1;
		GPIO.output(11,False);
		time.sleep(2)
	
	return True;


#move reverse count times.
def doReverse(count=1):
	i = 0;
	while i < count:
		GPIO.output(18,False)
		GPIO.output(17,True)
		GPIO.output(23, False)
		GPIO.output(22, True)
		time.sleep(2)
		GPIO.output(18,False)
		GPIO.output(17,False)
		GPIO.output(23,False)
		GPIO.output(22,False)
		time.sleep(2)
		i=i+1
	return;


#move forward count times.
def doForward(count=1):
	i=0 ;
	
	while i < count:
		GPIO.output(18, True)
		GPIO.output(17, False)
		GPIO.output(23, True)
		GPIO.output(22, False)
 		#sleep for 2*cout secs
		#print(time.gmtime());
		time.sleep(2); 
		GPIO.output(18, False)
        	GPIO.output(17, False)	
       		GPIO.output(23, False)
		GPIO.output(22, False) 
		time.sleep(2)
		i=i+1
		#print(time.gmtime());
	return;


#move right count times.
def doRight(count=1):
	i = 0;
	while i < count:
		GPIO.output(18, True)
		GPIO.output(17,False)
		GPIO.output(23,False)
		GPIO.output(22,False)
		time.sleep(0.5)
		GPIO.output(18,False)
		time.sleep(2)
		i = i+1


#move left count times.
def doLeft(count=1):
	i = 0;
	while i < count:
		GPIO.output(18,False)
		GPIO.output(17,False)
		GPIO.output(23,True)
		GPIO.output(22,False)
		time.sleep(0.5)
		GPIO.output(23,False)
		time.sleep(2)
		i=i+1 

def doHalt(count=1):
	#halt the system
			
	#print 'halting'
	subprocess.call(["sudo","halt"])



def doAction(action,count):
	if action == "forward":
		doForward(int(count))
	elif action == "reverse":
		doReverse(int(count))
	elif action == "left":
		doLeft(int(count))
	elif action == "right":
		doRight(int(count))
	elif action == "test":
		doTest(int(count))
	elif action == "halt":
		doHalt(1)

		
def main():

	action = sys.argv[1];
	count = sys.argv[2];
	#print action
	#print count

	if action == "forward":
        	doForward(int(count))
	elif action == "reverse":
        	doReverse(int(count))
	elif action == "left":
        	doLeft(int(count))
	elif action == "right":
        	doRight(int(count))
	elif action == "test":
        	doTest(int(count))
	elif action == "halt":
		doHalt(1)



	GPIO.cleanup() 

if __name__ == "__main__":
	main()

