#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>

int main() {
    int rc = fork();
    if (rc < 0) {
        printf("create child process failed!");
    }
    else if (rc == 0) {
        printf("hello\n");
        
    }
    else {
        sleep(1);
        printf("goodbye\n");
    }
    return 0;
}