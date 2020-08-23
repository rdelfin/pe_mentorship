#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

int counter = 0;

int main() {
    // Setup signal handlers
    struct sigaction sig_action;
    sig_action.sa_handler = SIG_IGN;
    sigemptyset(&sig_action.sa_mask);
    sig_action.sa_flags = 0;

    sigaction(SIGKILL, &sig_action, NULL);

    while(true) {
        printf("Working...\n");
        counter += 1;
        printf("Counter is %d\n", counter);
        sleep(1);
    }
}
