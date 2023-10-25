#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
char c[6]="f1.txt";

printf("Hello\n");
int fd = open(c,O_RDWR);

int newfd = dup2(fd,1);
printf("HELLO FROM FILE");
		
}

