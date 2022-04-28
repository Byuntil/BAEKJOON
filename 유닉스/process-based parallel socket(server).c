#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/ioctl.h>
#include<net/if.h>
#include<sys/types.h>
#include<sys/wait.h>

#define SERVERPORT 7799
#define BUFFSIZE 4096

int main(void){
    int s_sock;
    struct sockaddr_in server_addr;

    //socket 할당
    s_sock = socket(AF_INET,SOCK_STREAM,0);
    bzero(&server_addr,sizeof(server_addr));
    int option = 1;
    setsockopt(s_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVERPORT);
    server_addr.sin_addr.s_addr = inet_addr("10.0.0.174");

    //bind
    if(bind(s_sock,(struct sockaddr *) &server_addr,sizeof(server_addr))==-1){
        perror("[-]Socket Bind Error.\n");
        exit(1);
    }

    //listen
    if(listen(s_sock,3)==0){

    }else{
        perror("[-]Error listening");
        exit(1);
    }

    int c_sock;
    struct sockaddr_in client_addr;
    socklen_t c_addr_size;

    c_addr_size = sizeof(struct sockaddr);

    pid_t pid;
    char hello[]="Hello~I am Server!\n";
    char buf[BUFFSIZE]={0};
    int wstatus;

    for(int i=0; i<3;i++){
        printf("[+]Waiting for a client ...#%02d\n",i);
        c_sock = accept(s_sock,(struct sockaddr *) &client_addr, &c_addr_size);
        printf("[+]Connected: client IP addr=%s port=%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        pid = fork();
        if(pid<0){
            perror("[-]fork error");
            close(c_sock);
            exit(1);
        }
        if(pid==0){
            close(s_sock);
            printf("[++]Service: I am your child! pid=%d\n",getpid());
            if(send(c_sock,hello,sizeof(hello)+1,0)<=0){
                perror("[--]Can't send message");
                exit(1);
            }
            printf("[++]I said Hello to Client\n");

            if(recv(c_sock,buf,BUFFSIZE,0)<=0){
                printf("[++]Client says:\n");
                exit(1);
            }
            printf("[++]Client says: %s\n",buf);
            close(c_sock);
            return 0;
        }else{
            close(c_sock);
            continue;
        }
    }
    for(int i=0;i<3;i++){
        wait(&wstatus);
        printf("[+]Child #%02d is finished with %d\n",i,wstatus);
    }
    close(s_sock);
    return 0;
}