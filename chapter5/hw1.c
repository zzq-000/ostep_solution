#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


int main(){
    int x = 10;
    printf("I'm parent process, pid: %d, my local variable x = %d\n",getpid(),x);
    int child_pid = fork();
    if (child_pid < 0) {
        printf("create child process error!\n");
    }
    else if( child_pid == 0){
        x = 100;
        printf("I'm child process, pid: %d, my local variable x = %d\n",getpid(),x);

    }
    else{
        x = 1000;
        int result = wait(NULL);
        
        printf("I'm parent process, pid: %d, my local variable x = %d, and my child process id: %d\n", getpid(), x, result);
    }
}