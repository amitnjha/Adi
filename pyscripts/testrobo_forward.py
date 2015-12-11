import RPi.GPIO as GPIO
import time
import picamera
import subprocess
GPIO.cleanup()
GPIO.setmode(GPIO.BCM)
GPIO.setup(18,GPIO.OUT)
GPIO.setup(17, GPIO.OUT)
GPIO.setup(23,GPIO.OUT)
GPIO.setup(22, GPIO.OUT)

#camera = picamera.PiCamera()

def getReading():
        sonar = subprocess.Popen(['./sonar_my'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        out, err = sonar.communicate()
        split_output = out.split('\n')
        results_list = []
        for line in split_output:
                if line.startswith('echo') and not line.startswith('echo ti'):
			#print(line)
                        results_list.append(int(line.split()[2].strip()))
        #print "Results : %s" % results_list
        #print "avg : %d" % (sum(results_list)/10)
        return sum(results_list)/10


i = 0

while i< 3:
	#reading = getReading()
        #if reading > 2000:	
       	GPIO.output(18, True)
	GPIO.output(17, False)
       	GPIO.output(23, True)

	GPIO.output(22, False)
	time.sleep(2)
	GPIO.output(18, False)
        GPIO.output(17, False)	
       	GPIO.output(23, False)
	GPIO.output(22, False) 
	time.sleep(2)
	i = i  + 1
	#camera.capture(`i`+".jpg")




GPIO.cleanup()

 
