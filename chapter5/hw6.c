#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() {
    int rc = fork();
    if (rc < 0) {
        printf("create child process fialed!\n");
    }
    else if (rc == 0){
        printf("child pid is %d\n",getpid());
        printf("I'm child\n");
    }
    else {
        // 不能直接将waitpid替换wait，waitpid用于获取已知子进程的信息
        sleep(1);
        int x;
        int child_pid = waitpid(rc,&x,4);
        printf("child pid is %d\n",child_pid);
        printf("I'm parent\n");

    }
    return 0;
}