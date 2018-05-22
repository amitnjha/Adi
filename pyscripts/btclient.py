import socket

serverMACAddress = 'B8:27:EB:C8:F5:28'

port = 30
s = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)

s.connect((serverMACAddress, port))

while 1:
    text = input()
    if text == "quit":
        break
    s.send(bytes(text, 'UTF-8'))
s.close()
