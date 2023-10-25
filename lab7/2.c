#include <unistd.h>
#include <stdio.h>


int main(){

printf("before ls\n");

execl("/bin/ls","ls",NULL);

printf("after ls");

}

