#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include <arpa/inet.h>
#include "threadpool.h"

#define BUFF_LEN 1024
#define SERVER_IP "30.225.216.188"

void HandleUDPMSG(const int& fd) {
  char buf[BUFF_LEN];  //接收缓冲区，1024字节
  socklen_t len;
  int count;
  struct sockaddr_in clent_addr;  //clent_addr用于记录发送方的地址信息
  while(1) {
    memset(buf, 0, BUFF_LEN);
    len = sizeof(clent_addr);
    count = recvfrom(fd, buf, BUFF_LEN, 0, (struct sockaddr*)&clent_addr, &len);  //recvfrom是拥塞函数，没有数据就一直拥塞
    if(count == -1) {
      printf("recieve data fail!\n");
      return;
    }
    printf("client:%s\n",buf);  //打印client发过来的信息
    memset(buf, 0, BUFF_LEN);
    sprintf(buf, "I have recieved %d bytes data!\n", count);  //回复client
    std::cout << "receive from :" << inet_ntoa(clent_addr.sin_addr) << ": " <<  ntohs(clent_addr.sin_port) << std::endl;
    printf("server:%s\n",buf);  //打印自己发送的信息给
    sendto(fd, buf, BUFF_LEN, 0, (struct sockaddr*)&clent_addr, len);  //发送信息给client，注意使用了clent_addr结构体指针
  }
}


void ServerUnit(const int& server_port) {
  int server_fd, ret;
  struct sockaddr_in ser_addr;
  std::cout << "AF_INET: " << AF_INET << std::endl;

  server_fd = socket(AF_INET, SOCK_DGRAM, 0); //AF_INET:IPV4;SOCK_DGRAM:UDP
  if(server_fd < 0) {
    std::cout << "create socket fail!\n" << std::endl ;
  }

  memset(&ser_addr, 0, sizeof(ser_addr));
  ser_addr.sin_family = AF_INET;
  ser_addr.sin_addr.s_addr = inet_addr(SERVER_IP); //IP地址，需要进行网络序转换，INADDR_ANY：本地地址
  ser_addr.sin_port = htons(server_port);  //端口号，需要网络序转换

  ret = bind(server_fd, (struct sockaddr*)&ser_addr, sizeof(ser_addr));
  std::cout << "bind ret: "<< ret
            << ", ser_addr:" << inet_ntoa(ser_addr.sin_addr) << ": " << ntohs(ser_addr.sin_port)
            << ",INADDR_ANY: " << INADDR_ANY << ",SERVER_PORT: " << server_port << std::endl;
  if(ret < 0) {
    printf("socket bind fail!\n");
  }

  HandleUDPMSG(server_fd);   //处理接收到的数据

  close(server_fd);
}

/*
    server:
            socket-->bind-->recvfrom-->sendto-->close
*/

int main(int argc, char* argv[]) {
  ThreadPool pool(2);
  while (1) {
    pool.enqueue(ServerUnit, 5000);
    pool.enqueue(ServerUnit, 5001);
  }
  return 0;
}
