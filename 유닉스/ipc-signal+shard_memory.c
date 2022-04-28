#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<signal.h>
#include<stdlib.h>


#define BUFSIZE (80)

void parentHandler(int signo){
    printf("== Parent process : Waiting for signal %d (SIGUSR2)....\n", SIGUSR2);
    psignal(signo, "수정이 완료되었습니다!" );
}
void childHandler(int signo){
    printf("== Child process : Waiting for signal %d (SIGUSR1)....\n", SIGUSR1);
    psignal(signo, "Shared memory 공간 할당 되었습니다!" );
}

int main(int argc, char* argv[]){
    pid_t pid, ppid;
    int i;
    struct sigaction childAction, parentAction;
    sigset_t set_to_block;
    int wstatus;

    pid=fork();

    if(pid<0){
        perror("Fork Failed");
        return 1;
    }else if(pid==0){ //child
        FILE *fp;
        key_t key;
        int shmid, size;
        char buf[BUFSIZE];
        void *shmaddr;

        //child handler 등록
        sigemptyset(&childAction.sa_mask);
        sigaddset(&childAction.sa_mask, SIGUSR1);
        childAction.sa_flags = 0;
        childAction.sa_handler = childHandler;

        //SIGUSR1 들어오면 childHandler 실행
        if(sigaction(SIGUSR1, &childAction,(struct sigaction *) NULL)<0){
            perror("sigaction ");
            return 3;
        }

        //SIGUSR1 을 대기 / 다른 모든 시그널은 블록
        sigfillset(&set_to_block);
        sigdelset(&set_to_block, SIGUSR1);
        sigsuspend(&set_to_block);

        //공유 메모리 공간을 연결하고
        key=ftok("./keyfile",1);
        size=sysconf(_SC_PAGESIZE); //4KB
        shmid = shmget(key,size,IPC_CREAT|0666);
        shmaddr = shmat(shmid,NULL,0);

        //공유 메모리를 할당할 때 사용한 키 파일의 내용을 공유 메모리 공간에 복사
        if((fp = fopen("./keyfile", "r"))==NULL){
            perror("Open");
            exit(1);
        }

        while(fgets(buf, BUFSIZE, fp) != NULL){
            memcpy(shmaddr, buf, BUFSIZE);
        }
        fclose(fp);
        printf("(수정 중...)\n");
        //Parent 에게 SIGUSR2 를 보내어 수정이 완료되었음을 알림
        if(kill(getppid(), SIGUSR2)!=0){
            perror("SIGUSR2 send error");
            return 1;
        }
        //공유메모리 연결 해제
        shmdt(shmaddr);
    }else{//parent
        key_t key;
        int shmid, size;
        char buf[BUFSIZE];
        void *shmaddr;

        //parent handler 등록
        sigemptyset(&parentAction.sa_mask);
        sigaddset(&parentAction.sa_mask, SIGUSR2);
        parentAction.sa_flags = 0;
        parentAction.sa_handler = parentHandler;

        //SIGUSR2 들어오면 parentHandler 실행
        if(sigaction(SIGUSR2, &parentAction,(struct sigaction *) NULL)<0){
            perror("sigaction ");
            return 3;
        }
        //4KB 의 공유 메모리 공간을 할당
        key=ftok("./keyfile",1);
        size=sysconf(_SC_PAGESIZE); //4KB
        shmid = shmget(key,size,IPC_CREAT|0666);
        //공유 메모리 연결
        shmaddr = shmat(shmid,NULL,0);

        //공간 0으로 초기화
        memset(shmaddr,0,size);
        memcpy(buf,shmaddr,BUFSIZE);

        printf("==============Start=============\n");
        printf("수정 전 : [ %s ]\n", buf);
        printf("(공간 할당 중...)\n");
        //Child 에게 SIGUSR1 을 보내 공간이 할당되었음을 알림
        if(kill(pid, SIGUSR1)!=0){
            perror("SIGUSR1 send error");
            return 1;
        }

        //SIGUSR2 를 대기. 다른 모든 시그널은 블록
        sigfillset(&set_to_block);
        sigdelset(&set_to_block, SIGUSR2);
        sigsuspend(&set_to_block);


        //공유 메모리 공간에서 초반 80 B 영역을 문자열로 출력
        memcpy(buf,shmaddr,BUFSIZE);
        printf("수정 후 : [ %s ]\n", buf);

        //공유 메모리 공간 할당 해제
        shmctl(shmid, IPC_RMID,NULL);
        printf("==============Finish=============\n");
        wait(&wstatus);
    }
    return 0;
}