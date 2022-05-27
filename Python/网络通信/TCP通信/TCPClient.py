# coding=UTF-8
from socket import *   
#与服务器建立连接
serverName='127.0.0.1'#服务器主机名
serverPort=12000#服务器的端口号
clientSocket=socket(AF_INET,SOCK_STREAM)#协议族 协议
clientSocket.connect((serverName,serverPort))#与指定服务器建立连接

#与服务器通信
sentence=raw_input('Input lowercase sentence:')
clientSocket.send(sentence.encode())#以默认的编码格式编码字符串
modifiedSentence=clientSocket.recv(1024)#接收服务器发送来的数据
print("From Server:",modifiedSentence.decode())#以默认的编码格式解码字符串

clientSocket.close()

