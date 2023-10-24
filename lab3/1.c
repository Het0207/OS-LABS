#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> 
int main()
{

    printf("hello");
    int pid = fork();

    if (pid == 0)
    {
        printf(" from child");
    }

    if (pid > 0)
    {
        printf(" from parent\n");
    }
}
