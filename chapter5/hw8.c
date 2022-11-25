#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main() {
    int fd[2];
    if (pipe(fd) < 0) {
        printf("create pipe failed");
    }
    int id = fork();
    if (id < 0) {
        printf("create child process fialed!\n");
    }
    else if (id == 0){
        close(fd[0]);
        char * user_string = "hello, my sibling";
        write(fd[1], user_string, strlen(user_string));
        close(fd[1]);
        printf("I'm child one, my pid: %d\n", getpid());
    }
    else {
        id = fork();
        if (id < 0) {
            printf("create child process failed");
        }
        else if (id == 0) {
            close(fd[1]);
            char s[100];
            read(fd[0],s,20);
            printf("string from my sibling: %s\n",s);
            printf("I'm child two, my pid: %d\n", getpid());

        }
        else {
            printf("I'm parent, my pid: %d\n", getpid());
        }

    }
    
    return 0;
}