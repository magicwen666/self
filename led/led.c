#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    int fd = 0;
    unsigned int cmd = 0;
    
    fd = open("/dev/MINI2440_LED", 0);
    if (-1 == fd) {
        printf("open the LED error!\n");
        return 1;
    }
    
    while(1) {
        
        cmd = cmd ? 0 : 1;
        ioctl(fd, !cmd, 0);
        ioctl(fd, !cmd, 1);
        ioctl(fd, !cmd, 2);
        ioctl(fd, !cmd, 3);
        sleep(1);
    }
    
    close(fd);
    
    return 0;
}
