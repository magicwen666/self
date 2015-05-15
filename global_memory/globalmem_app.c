#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	int fd = 0;
	int len = 0;
	int ret = 0;
	unsigned char rbuf[128] = {0};
	
	if (2 != argc) {
		printf("the parament number error, must be 2\n");
		return 1;
	}
	
	len = strlen(argv[1]);
	
	fd = open("/dev/global_memory", O_RDWR);
	if (-1 == fd) {
		printf("open the global memory error! : %d\n", fd);
		return 1;
	}
	
	ret = write(fd, argv[1], len);
	if (ret != len) {
		printf("write data to global memory error : %d\n", ret);
		close(fd);
		return 1;
	}
	lseek(fd, 0, SEEK_SET);
	ret = read(fd, rbuf, len);
	if (ret != len) {
		printf("read data from global memory error : %d\n", ret);
		close(fd);
		return 1;
	}
	printf("read buffer : %s\n", rbuf);
	while(1);	/* choke */
	close(fd);
	
	return 0;
}