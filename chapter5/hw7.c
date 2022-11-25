#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
    int rc = fork();
    if (rc < 0) {
        printf("create child process fialed!\n");
    }
    else if (rc == 0){
        close(STDOUT_FILENO);
        printf("lalalal");
        printf("I'm child\n");
    }
    else {

        printf("I'm parent\n");

    }
    return 0;
}