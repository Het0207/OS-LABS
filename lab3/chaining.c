#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
// #include <sys/wait.h>
int main()
{

    printf("hello");
    int pid = fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();

    if (pid == 0)
    {
        printf(" from child\n");
    }

    if (pid > 0)
    {
        wait(NULL);
        printf(" from parent\n");
    }
}
