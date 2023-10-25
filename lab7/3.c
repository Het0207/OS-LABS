#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

//Write a program to create a child process that should run pwd command and the parent process should run ls command.

int main(){
int p = fork();

if ( p >0){
wait(NULL);
printf("from parent : \n");

execl("/bin/ls","",NULL);

}

else if(p == 0){
printf("from child : \n");

execl("/bin/pwd","",NULL);

}
else{

printf("Fork not successful");
}
}

