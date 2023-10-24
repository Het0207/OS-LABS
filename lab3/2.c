#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

    printf("hello ");
    int pid = fork();

    if (pid == 0)
    {
        int child_pid = getpid();
        int parent_pid = getppid();

        printf(" from child \n");
        printf("Child pid : %d \n", child_pid);
        printf("Parent pid : %d \n", parent_pid);
    }

    if (pid > 0)
    {
        int parent1_pid = getpid();
        int parent2_pid = getppid();
        printf(" from parent\n");
        printf("Child pid : %d \n", pid);
        printf("Parent pid : %d \n", parent1_pid);
    }

}
