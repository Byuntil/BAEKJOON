#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<time.h>
#include<sys/ioctl.h>
#include<net/if.h>

#define BUFFSIZE 1024
#define SERVERPORT 7799
int main(void){
    int s_sock;
    struct sockaddr_in server_addr;
    char buf[BUFFSIZE]={0};
    //socket 할당
    s_sock = socket(AF_INET,SOCK_STREAM,0);
    bzero(&server_addr,sizeof(server_addr));

    printf("[+]Server socket created successfully.\n");

    server_addr.sin_family= AF_INET;
    server_addr.sin_port = htons(SERVERPORT);

    //시스템 IP 받아오는 곳
    int fd;
    struct ifreq ifr;
    char ipBuf[15];
    fd = socket(AF_INET,SOCK_DGRAM,0);
    ifr.ifr_addr.sa_family = AF_INET;
    memcpy(ifr.ifr_name, "ens3", IFNAMSIZ - 1);
    ioctl(fd, SIOCGIFADDR, &ifr);
    strcpy(ipBuf, inet_ntoa(((struct sockaddr_in*)&ifr.ifr_addr)->sin_addr));
    close(fd);

    server_addr.sin_addr.s_addr = inet_addr(ipBuf);
    //bind
    if(bind(s_sock,(struct sockaddr *) &server_addr,sizeof(server_addr))==-1){
        perror("[-]Socket Bind Error.\n");
        exit(1);
    }
    printf("[+]Binding successfull\n");
    printf("Check : // Server ip : %s // Server port : %d\n",inet_ntoa(server_addr.sin_addr),SERVERPORT);
    //listen
    if(listen(s_sock,1)==0){
        printf("[+]This server is Listening....\n");
    }else{
        perror("[-]Error listening");
        exit(1);
    }

    int c_sock;
    struct sockaddr_in client_addr;
    socklen_t c_addr_size;

    c_addr_size = sizeof(struct sockaddr);
    //accept
    c_sock = accept(s_sock, (struct sockaddr *) &client_addr, &c_addr_size);
    if(c_sock==-1){
        perror("[-]Can't accept a connection\n");
        exit(1);
    }
    //어떤 파일을 보내야 하는지 client로부터 받는 부분
    printf("[+]Connected to Client [ip : %s] [port : %d]\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
    if(recv(c_sock,buf,BUFFSIZE,0)<=0){
        perror("[-]Can't receive message\n");
        exit(1);
    }
    printf("Client request : %s\n", buf);
    sleep(1);
    printf("\n[+]Start send file...\n");
    sleep(1);

    FILE *fp;
    unsigned long fileSize;//파일 전체 사이즈
    size_t sendByte;//파일을 읽어와서 사이즈 저장
    char sendBuf[BUFFSIZE];//파일 데이터 저장할 버퍼
    char fileNotExist[] = "N";
    char fileExist[]="Y";
    fp = fopen(buf,"rb");
    //파일의 존재 여부 메세지를 보내는 부분
    if(fp==NULL){
        printf("[-]File not exist\n");
        if(send(c_sock,fileNotExist,sizeof(fileNotExist)+1,0)<=0){
            perror("[-]Can't send message\n");
            exit(1);
        }
        exit(1);
    }else{
        if(send(c_sock,fileExist,sizeof(fileExist)+1,0)<=0){
            perror("[-]Can't send message\n");
            exit(1);
        }
    }

    fseek(fp,0,SEEK_END);
    fileSize = ftell(fp);
    fseek(fp,0,SEEK_SET);

    //파일 보내는 부분
    time_t start,end;
    double result;
    printf("[+]In progress...\n");
    start = time(NULL);
    while((sendByte = fread(sendBuf,1,sizeof(sendBuf),fp))>0){
        if((send(c_sock,sendBuf,sendByte,0))<=0){
            perror("[-]Can't send File\n");
            exit(1);
        }
        printf("[sendByte : %ld]\n", sendByte);
    }
    end = time(NULL);
    result = (double)(end-start);

    printf("[fileSize : %ld]\n",fileSize);
    printf("Done! [time: %f]\n",result);

    fclose(fp);
    close(c_sock);
    close(s_sock);

    return 0;
}