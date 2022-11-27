#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define MEGA (1024 * 1024)

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage ./memory-user size_of_use_memory\n");
    }
    long byte_size = atoi(argv[1]) * (long)(MEGA);
    long array_size = byte_size / sizeof(int);

    int * array = (int*)malloc(sizeof(int) * array_size);
    printf("use memory: %ld, int size: %lu", byte_size, sizeof(int));
    // strdup()
    char *src = "hello";
    char *dst = (char *) malloc(strlen(src)); // too small!
    strcpy(dst, src); // work properly
    printf("copied str: %s \n", dst);
    return 0;
}