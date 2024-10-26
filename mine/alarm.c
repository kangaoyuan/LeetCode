#include <stdio.h>
#include <signal.h>
#include <assert.h>
#include <unistd.h>
#include <memory.h>
#include <sys/time.h>

void alamer_handler(int signum){
    static int cnt = 0;
    // Attention! for line stream flush.
    if(!cnt)
        printf("Hello, this is the %d time %d signal\n", cnt, signum);
    else
        printf("Hello, this is the %d times %d signal\n", cnt, signum);
    cnt++;
}

void register_alamer(){
    struct sigaction s;
    memset(&s, 0, sizeof(s));
    // sigaction() is the substitute of signal(), the sturct sigaction object is to specify a sa_handler or sa_sigaction and other sa_flags, sa_mask.
    // For the void sa_sigaction(int sig, siginfo_t* info, void* context), we need specify sa.sa_flags = SA_SIGINFO.
    s.sa_flags = 0;
    sigemptyset(&s.sa_mask);
    s.sa_handler = alamer_handler;
    assert(!sigaction(SIGALRM, &s, NULL));
    //assert(!sigaction(SIGVTALRM, &s, NULL));

    // it_value and it_interval fields in struct itimerval are all struct timeval  type.
    struct itimerval i;
    memset(&i, 0, sizeof(i));
    i.it_value.tv_sec = 1;
    i.it_value.tv_usec = 77;
    i.it_interval.tv_sec = 1;
    i.it_interval.tv_usec = 5000;
    assert(!setitimer(ITIMER_REAL, &i, NULL));
    //assert(!setitimer(ITIMER_VIRTUAL, &i, NULL));
}

int main(){
    register_alamer();
    while(1){
        // We need user mode time consuming.
        /*
         *volatile long long counter = 0;
         *for (volatile long long i = 0; i < 1000000000LL; ++i) {
         *    counter += i;  // Busy CPU loop to simulate user-space activity
         *}
         */
        pause();
    }
    return 0;
}
