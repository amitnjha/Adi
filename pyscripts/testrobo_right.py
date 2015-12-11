import RPi.GPIO as GPIO
import time
import picamera

GPIO.setmode(GPIO.BCM)
GPIO.setup(18,GPIO.OUT)
GPIO.setup(17, GPIO.OUT)
GPIO.setup(23,GPIO.OUT)
GPIO.setup(22, GPIO.OUT)

#camera = picamera.PiCamera()

i = 0

while i < 50:
	
	GPIO.output(18, True)
	GPIO.output(17, False)
	GPIO.output(23, False)
	GPIO.output(22, False)
	time.sleep(.250)
	GPIO.output(18, False)
        GPIO.output(17, False)	
       	GPIO.output(23, False)
	GPIO.output(22, False) 
	#time.sleep(2)
	i = i  + 1
	#camera.capture(`i`+".jpg")


GPIO.cleanup()

