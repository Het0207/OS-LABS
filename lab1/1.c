#include <unistd.h>
#include<stdio.h>

int main(){
int a[100];
int m = read(0,a,sizeof(a));
int n = write(1,a,m);
printf("%d",n);
return 0;
}




#include <unistd.h>
#include<stdio.h>
#include<stdbool.h>

int main(){
int a[100];
while(true){
int m = read(0,a,sizeof(a));
int n = write(1,a,m);
}

return 0;
}





#include <unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(int sc, char *c[]){

char str[1];

int fd = open(c[1],O_RDONLY);
ssize_t r;
while( (r = read(fd,str,sizeof(str))) > 0){
ssize_t w = write(1,str,r);

}

close(fd);

return 0;
}






#include <unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(int sc, char *c[]){
char str[1];
for(int i = 1; i<sc; i++){
int fd = open(c[i],O_RDONLY);


ssize_t r;


while( (r = read(fd,str,sizeof(str))) > 0){
ssize_t w = write(1,str,r);


}




close(fd);
}


return 0;
}