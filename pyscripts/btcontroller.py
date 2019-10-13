import bluetooth

from robotcontrol import *


def serve_client():
        server_sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
        port = 0
        server_sock.bind(("",port))
        server_sock.listen(port)
        uuid ="1e0ca4ea-299d-4335-93eb-27fcfe7fa848"
        bluetooth.advertise_service(server_sock,"FooBar Service",uuid)
        client_sock,address = server_sock.accept()
        print("Accepted from ",address)
        while True:
                try:
                        data = client_sock.recv(1024)
                        #print(data)
                        action=data.split()
                        print(action)
                        doAction(action[0].decode("utf-8"),int(action[1].decode("utf-8"))) 			
                        if data == "CLOSE 0":
                                break
                except:
                        print('Disconnected, listening again')
                        server_sock.close()
                        serve_client()

print('starting bt controller')


serve_client()

#server_sock.listen(1)

#client_sock,address = server_sock.accept()

#print("Accepted from ",address)
#while True:
#	data = client_sock.recv(1024)
#	print data
# 	action=data.split()
#	doAction(action[0],action[1]) 			
#	if data == "CLOSE 0":
#		break


#client_sock.close()
#server_sock.close()


