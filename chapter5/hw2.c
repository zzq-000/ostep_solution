#include<stdio.h>
#include<stdlib.h>

#include<unistd.h>
#include<fcntl.h>


int main() {
    int fd = open("hello.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    int rc = fork();
    if (rc < 0) {
        printf("create child process failed!\n");
    }
    else if (rc == 0) {
        write(fd, "child\n", 6);
        close(fd);
    }
    else {
        int child = wait(NULL);
        printf("my child process is %d \n",child);
        write(fd, "parent\n", 6);
        close(fd);
    }
    return 0;
}