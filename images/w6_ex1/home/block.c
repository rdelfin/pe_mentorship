#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int print_signal;
int sig_type;

void ignore_signal(int signal) {
    sig_type = signal;
    print_signal = 1;
}

int main() {
    // Setup signal handlers
    struct sigaction sig_action;
    sig_action.sa_handler = ignore_signal;
    sigemptyset(&sig_action.sa_mask);
    sig_action.sa_flags = 0;

    sigaction(SIGINT, &sig_action, NULL);
    sigaction(SIGTERM, &sig_action, NULL);

    while(1) {
        if (print_signal) {
            if (sig_type == SIGTERM) {
                printf("Recived SIGTERM; Ignoring...\n");
            } else {
                printf("Recived SIGINT; Ignoring...\n");
            }
            print_signal = 0;
        }
    }
}
