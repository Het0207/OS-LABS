#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    char c[5] = "hello";
    char buff[100] = {""};
    int pipefd[2];

    int a = pipe(pipefd);

    if (a == -1)
    {
        printf("Error");
    }

    else
    {

        int p = fork();

        if (p > 0)
        {

            close(pipefd[0]);
            write(pipefd[1], c, sizeof(c));
            wait(NULL);
        }

        else
        {

            close(pipefd[1]);
            read(pipefd[0], buff, sizeof(buff));
        }
    }

    printf("%s", buff);
}
