#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/ioctl.h>
#include<net/if.h>
#include<pthread.h>

#define BUFFSIZE 1024
#define SERVERPORT 7799
#define MAX_THREADS (10)

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void* handleFile(void *arg){
    int c_sock = *((int *) arg);
    int *ret;
    char buf[BUFFSIZE]={0};

    printf("\n[+]Thread number %ld\n", pthread_self());

    pthread_mutex_lock( &mutex1 );
    if(recv(c_sock,buf,BUFFSIZE,0)<=0){
        perror("[-]Can't receive message\n");
        exit(1);
    }
    printf("Client request : %s\n", buf);
    printf("\n[+]Start send file...\n");
    pthread_mutex_unlock( &mutex1 );
    FILE *fp;
    unsigned long fileSize;//파일 전체 사이즈
    size_t sendByte;//파일을 읽어와서 사이즈 저장
    char sendBuf[BUFFSIZE];//파일 데이터 저장할 버퍼
    char fileNotExist[] = "N";
    char fileExist[]="Y";
    fp = fopen(buf,"rb");
    //파일의 존재 여부 메세지를 보내는 부분
    pthread_mutex_lock(&mutex1);
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
    pthread_mutex_unlock( &mutex1 );
    pthread_mutex_lock(&mutex1);
    //파일 보내는 부분
    printf("[+]In progress...\n");
    while((sendByte = fread(sendBuf,1,sizeof(sendBuf),fp))>0){
        if((send(c_sock,sendBuf,sendByte,0))<=0){
            perror("[-]Can't send File\n");
            exit(1);
        }
        printf("[sendByte : %ld]\n", sendByte);
    }
    fclose(fp);

    ret = (int *)malloc(sizeof(int));
    *ret = c_sock;
    close(c_sock);
    pthread_mutex_unlock( &mutex1 );
    pthread_exit(ret);
}

int main(void){
    int s_sock;
    struct sockaddr_in server_addr;
    char buf[BUFFSIZE]={0};
    //socket 할당
    s_sock = socket(AF_INET,SOCK_STREAM,0);
    bzero(&server_addr,sizeof(server_addr));
    int option = 1;
    setsockopt(s_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
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


    int tcount=0;
    int *status;
    pthread_t tid[MAX_THREADS];

    int c_sock[MAX_THREADS];
    struct sockaddr_in client_addr[MAX_THREADS];
    socklen_t c_addr_size[MAX_THREADS];


    for(int i=0; i<MAX_THREADS; i++,tcount++){
        c_addr_size[i] = sizeof(struct sockaddr);
        //accept
        c_sock[i] = accept(s_sock, (struct sockaddr *) &client_addr[i], &c_addr_size[i]);
        if(c_sock[i]==-1){
            perror("[-]Can't accept a connection\n");
            exit(1);
        }

        if(pthread_create(&tid[i],NULL,handleFile,&c_sock[i])!=0){
            perror("[-]Failed to create thread\n");
            goto exit;
        }
    }
    exit:
    for(int i=0; i<tcount; i++){
        pthread_join(tid[i], (void **) &status);
        printf("Thread no.%d ends:%d\n",i,*status);
    }
    return 0;
}