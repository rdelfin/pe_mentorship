#include <stdio.h>
#include <unistd.h>

int main() {
    long cnt = 0;
    while(1) {
        printf("Hello: %d\n", cnt);
        cnt += 1;
        sleep(1);
    }
}
