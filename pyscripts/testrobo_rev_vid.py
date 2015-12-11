import RPi.GPIO as GPIO
import time
import picamera

GPIO.setmode(GPIO.BCM)
GPIO.setup(18,GPIO.OUT)
GPIO.setup(17, GPIO.OUT)
GPIO.setup(23,GPIO.OUT)
GPIO.setup(22, GPIO.OUT)

camera = picamera.PiCamera()

i = 0
camera.start_recording('2.h264')
while i < 5:
	
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
camera.stop_recording()

GPIO.cleanup()

