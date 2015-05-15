#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	int fd = 0;
	int len = 0;
	unsigned char wbuf[] = "Magic Wen is your father";
	unsigned char rbuf[32] = {0};
	
	fd = open("file.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (-1 == fd) {
		printf("open the file error!\n");
		exit(1);
	}
	
	if (strlen(wbuf) != write(fd, wbuf, strlen(wbuf))) {
		printf("write data to file error!\n");
		close(fd);
		exit(1);
	}
	lseek(fd, 0, SEEK_SET);
	len = read(fd, rbuf, strlen(wbuf));
	if (len != strlen(wbuf)) {
		printf("read data from file error! : %d\n", len);
		close(fd);
		exit(1);
	}
	printf("Read Buffer : %s\n", rbuf);
	printf("File Size : %d\n", lseek(fd, 0, SEEK_END));
	close(fd);
	
	return 0;
}