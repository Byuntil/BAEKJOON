#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<time.h>

#define BUFFSIZE 1024

int main(int argc, char* argv[]){
    int c_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t c_addr_size;

    if(argc!=4){
        printf("Usage : %s [ip address] [port] [file name]\n", argv[0]);
        exit(1);
    }
    //socket 할당
    c_sock = socket(AF_INET,SOCK_STREAM,0);
    bzero(&server_addr, sizeof(server_addr));

    printf("[+]Client socket created successfully.\n");

    server_addr.sin_family= AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    //connect
    if(connect(c_sock,(struct sockaddr *) &server_addr,sizeof(server_addr))==-1){
        perror("[-]Can't connect to a server\n");
        exit(1);
    }
    printf("[+]Connected to Server\n");

    //무슨 파일 요청하는지 메시지 전송
    int len = strlen(argv[3])+1;
    if(send(c_sock,argv[3],len,0)<=0){
        perror("[-]Can't send message\n");
        exit(1);
    }
    printf("[+]Client send message\n");

    sleep(1);
    printf("\nStart receive file...\n");
    sleep(1);


    unsigned long fileSize;//파일 전체 사이즈
    size_t readByte;//다운 받은 데이터의 크기
    char readBuf[BUFFSIZE];//파일 데이터 저장할 버퍼
    time_t start,end;
    double result;
    char fileName[80];
    FILE *fp;
    char fileStateMessage[20];
    //파일이 존재여부 메세지 받는 부분
    if(recv(c_sock,fileStateMessage,sizeof(fileStateMessage),0)<=0){
        perror("[-]Can't receive message\n");
        exit(1);
    }
    if(!strcmp(fileStateMessage,"N")){
        printf("[-]File not exist\n");
        exit(1);
    }else if(!strcmp(fileStateMessage, "Y")){
        printf("[+]File(%s) exist\n", argv[3]);
    }

    //파일 받는 부분
    fp = fopen(argv[3],"wb");
    printf("[+]In progress...\n");
    start = time(NULL);

    while(1){
        readByte = recv(c_sock,readBuf,BUFFSIZE,0);
        if(readByte<=0){
            break;
        }
        printf("[readByte : %ld]\n",readByte);

        fwrite(readBuf,sizeof(char),readByte,fp);
        if(readByte == SO_ERROR){
            printf("[-]File Receive Error\n");
            exit(1);
        }
    }
    end = time(NULL);
    result = (double)(end-start);
    fseek(fp,0,SEEK_END);
    fileSize = ftell(fp);
    fseek(fp,0,SEEK_SET);

    printf("[filesize : %ld]\n",fileSize);
    printf("Done! [time : %f]\n",result);
    fclose(fp);
    close(c_sock);
    return 0;
}