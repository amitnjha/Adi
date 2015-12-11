import bluetooth

from robotcontrol import *


print 'starting bt controller'

server_sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)

port = 1
server_sock.bind(("",port))

server_sock.listen(1)

client_sock,address = server_sock.accept()

print("Accepted from ",address)
while True:
	data = client_sock.recv(1024)
	print data
 	action=data.split()
	doAction(action[0],action[1]) 			
	if data == "CLOSE 0":
		break


client_sock.close()
server_sock.close()


