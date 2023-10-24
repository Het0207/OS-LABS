#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(int sc,char*c[]){

int pipefd[2];
int a = pipe(pipefd);

if(a==-1){
printf("Error");
}

else{
printf("%d %d ",pipefd[0],pipefd[1]);
}

printf("%d %s",sc,c[0]);
}

