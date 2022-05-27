# coding=UTF-8
from cgitb import handler
from multiprocessing.dummy import connection
from socket import *
from signal import *

def handler(a,b):
    serverSocket.close()


signal(SIGINT,handler)
#建立连接
serverPort=12000#接收消息的端口号
serverSocket=socket(AF_INET,SOCK_STREAM)
serverSocket.bind(('',serverPort))#绑定服务器端口号、地址与socket
serverSocket.listen(1)#监听指定的端口号
#listen(1)排队的人数(就是那个n) + 正在就餐的人数（服务器正在处理的socket连接数) = 允许接待的总人数（socket允许的最大连接数）

print('the server is ready to receive')

while True:
    connectionSocket, addr=serverSocket.accept()#创建与用户交互的socket addr: 客户端的IP地址和端口号          
    sentence=connectionSocket.recv(1024).decode()#接收用户的输入
    capitalizedSentence=sentence.upper()#处理用户发送来的数据
    connectionSocket.send(capitalizedSentence.encode())#将处理过的数据发给用户
    connectionSocket.close()
