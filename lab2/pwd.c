#include<stdio.h>
#include<unistd.h>

int main(){
    char curr[100];
    getcwd(curr, sizeof(curr));
    printf("%s", curr);
}