import socket

hostMacAddress = 'B8:27:EB:C8:F5:28'

port = 3

backlog = 1
size = 1024
s = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)
s.bind((hostMacAddress,port))

s.listen(backlog)

try:
    client,address = s.accept()
    while 1:
        data = client.recv(size)
        if data:
            print(data)

except:
    print("closing socket")
    client.close()
    s.close()
