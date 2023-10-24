
 #include <pthread.h>
#include <stdio.h>
void fun1(void str){
printf("%s",(char*)str);
}

void main(){
pthread_t t1;
char str[]="hello from thread";
 pthread_create(&t1,NULL,fun1,(void*)str);
 pthread_join(t1,NULL);
}

