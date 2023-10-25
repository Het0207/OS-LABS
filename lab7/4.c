#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
//4. Write a program to implement ls | sort functionality.
int main(){
int pipefd[2];

int a =pipe(pipefd);

if(a == -1){
 printf("pipe not created");
 }
 
else{

int p = fork();

if ( p >0){
close(pipefd[0]);
dup2(pipefd[1],1);
execl("/bin/ls","ls",NULL);
}

else if(p == 0){
close(pipefd[1]);
dup2(pipefd[0],0);
execl("/bin/sort","sort",NULL);
}

else{
printf("Fork not successful");
}
}
}

