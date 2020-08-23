#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int counter = 0;

int main() {
    FILE* f = fopen("/tmp/results1.txt", "w");
    setvbuf(f, NULL, _IONBF, 0);

    while(true) {
        sleep(1);
        counter++;
        printf("Writing new line to \"/tmp/results1.txt\"...\n");
        fprintf(f, "Iteration %d\n", counter);
    }
}
