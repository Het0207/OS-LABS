#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
char c[6]="f1.txt";
char buff[100]={""};
int pipefd1[2];
int pipefd2[2];

int a = pipe(pipefd1);
int b = pipe(pipefd2);

if(a==-1 || b==-1){
printf("Error");
}

else{

int p = fork();

if(p>0){

close(pipefd1[0]);
write(pipefd1[1],c,sizeof(c));
wait(NULL);

char str[100]={""};
close(pipefd2[1]);
read(pipefd2[0],buff,sizeof(buff));


printf("\nFrom parent:\n");
write(1,buff,sizeof(buff));

}


else if(p==0){

char str[100]={""};

close(pipefd1[1]);
read(pipefd1[0],buff,sizeof(buff));

write(1,buff,sizeof(buff));
printf(" filename passed from parent to child.\n \n");
int fd = open(buff,O_RDONLY);


printf("From child:\n");
read(fd,str,sizeof(str));
write(1,str,sizeof(str));

close(pipefd2[0]);
write(pipefd2[1],str,sizeof(str));

}

else{
  printf("Fork not successful");
  }

}
}