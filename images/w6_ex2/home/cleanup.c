#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

bool running = true;
int counter = 0;

void cleanup_exit(int signal) {
    running = false;
}

int main() {
    // Setup signal handlers
    struct sigaction sig_action;
    sig_action.sa_handler = cleanup_exit;
    sigemptyset(&sig_action.sa_mask);
    sig_action.sa_flags = 0;

    sigaction(SIGINT, &sig_action, NULL);
    sigaction(SIGTERM, &sig_action, NULL);

    while(running) {
        printf("Working...\n");
        counter += 1;
        printf("Counter is %d\n", counter);
        sleep(1);
    }

    printf("Cleaning up...\n");
    printf("Writing result to \"results.txt\"\n", counter);
    FILE* f = fopen("results.txt", "w");
    fprintf(f, "Iterations: %d\n", counter);
    fclose(f);
    printf("Cleanup finished! Exiting\n", counter);

    return 0;
}
