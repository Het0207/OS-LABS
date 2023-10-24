#include <pthread.h>
#include <stdio.h>
struct number{

int op1;
int op2;
int ope;

};
void fun1(void s1){
struct number* n = (struct number*)s1;
int answer = n->op1 + n->op2;
printf("Answer of addition is: %d",answer);
}

void fun2(void s1){
struct number* n = (struct number*)s1;
int answer = n->op1 - n->op2;
printf("Answer of subtraction is: %d",answer);
}

void fun3(void s1){
struct number* n = (struct number*)s1;
int answer = n->op1 * n->op2;
printf("Answer of multiplication is: %d",answer);
}

void fun4(void s1){
struct number* n = (struct number*)s1;
int answer = n->op1 / n->op2;
printf("Answer of division is: %d",answer);
}


void main(){

pthread_t t1;
struct number s1;

int operand1, operand2, operation;
printf("Enter operands and operation: 1 for addition\n 2 for subtraction\n 3 for multiplication\n 4 for division\n");
scanf("%d %d %d",&operand1,&operand2,&operation);
s1.op1 = operand1;
s1.op2 = operand2;
s1.ope = operation;
if(operation == 1)
 pthread_create(&t1,NULL,fun1,(void*)&s1);
 
else if(operation ==2)
   pthread_create(&t1,NULL,fun2,(void*)&s1);
   
else if(operation ==3)
   pthread_create(&t1,NULL,fun3,(void*)&s1);
   
else
   pthread_create(&t1,NULL,fun4,(void*)&s1);
   
 pthread_join(t1,NULL);
}

