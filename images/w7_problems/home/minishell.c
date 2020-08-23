#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    printf("Hello! These are my arguments:\n");
    int i;
    for(i = 0; i < argc; i++) {
        printf("argv[%d] =\t\"%s\"\n", i, argv[i]);
    }
}
