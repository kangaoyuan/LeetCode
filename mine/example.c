#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

// Signal handler for timer
void timer_signal_handler(int sig, siginfo_t *info, void *context) {
    printf("Timer signal received (Signal: %d)\n", sig);
    printf("Signal sent by kernel\n");
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = timer_signal_handler;   // Use detailed handler
    sa.sa_flags = SA_SIGINFO;                 // Enable SA_SIGINFO
    sigemptyset(&sa.sa_mask);

    // Set up the signal handler for SIGALRM (timer signal)
    //if (sigaction(SIGALRM, &sa, NULL) == -1) {
    if (sigaction(SIGVTALRM, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Set up a timer to fire every 2 seconds
    struct itimerval timer;
    timer.it_value.tv_sec = 2;         // First expiration in 2 seconds
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 2;      // Interval of 2 seconds
    timer.it_interval.tv_usec = 0;

    //if (setitimer(ITIMER_REAL, &timer, NULL) == -1) {
    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("setitimer");
        return 1;
    }

    // Loop indefinitely to allow the timer to trigger
    while (1) {
        pause();  // Wait for signal
    }

    return 0;
}

