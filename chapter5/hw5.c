#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main() {
    int rc = fork();
    if (rc < 0) {
        printf("create child process fialed!\n");
    }
    else if (rc == 0){
        int child_pid = wait(NULL);
        printf("child pid is %d\n",child_pid);
        printf("I'm child\n");
    }
    else {
        int child_pid = wait(NULL);
        printf("child pid is %d\n",child_pid);
        printf("I'm parent\n");

    }
    return 0;
}