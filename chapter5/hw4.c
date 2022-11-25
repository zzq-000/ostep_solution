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
        char* file = "/bin/ls";
        execl(file,file,"./",NULL);
    


        printf("hello, world\n");
        
    }
    else {
        printf("goodbye\n");
    }
    return 0;
}