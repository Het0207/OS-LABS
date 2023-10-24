#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void implement_ls_r( DIR * dp,char *c){

  struct dirent *d;

 while(d=readdir(dp)){

 //if(d->d_type == DT_REG){
//	printf("%s \n",d->d_name);
 }
 
if(d->d_type == DT_DIR){
 DIR *child;
 printf("%s \n",d->d_name);
   char * newpath =   strcat(c,"/"d->d_name"/");
 write(1,newpath,sizeof(newpath));
 child=opendir(newpath);
  //implement_ls_r(child,newpath);
 }  
  return;
}


int main(){
char buf[100]={""};
  DIR * dp;
 char *c= getcwd(buf,sizeof(buf));
 dp=opendir(c);
 implement_ls_r(dp,c);
 return 0;
}
