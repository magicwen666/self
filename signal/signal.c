#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

void intput_handler(int signo) {
    
    char data[128] = {0};
    int len = 0;
    
    len = read(STDIN_FILENO, &data, 128);
    data[len] = 0;
    
    printf("input : %s\n", data);
}

int main (int argc, char *argv[]) {
    
    int oflags = 0;
    
    signal(SIGIO, intput_handler);
    fcntl(STDIN_FILENO, F_SETOWN, getpid());
    oflags = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL, oflags | FASYNC);
    
    while (1);
    
    return 0;
}