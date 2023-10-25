
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main()
{
    int pipefd[2];

    int a = pipe(pipefd);

    if (a == -1)
    {
        printf("pipe not created");
    }

    else
    {

        int p = fork();

        if (p > 0)
        {
            wait(NULL);
            close(pipefd[1]);

            execl("/bin/sort", "sort", NULL);
        }

        else if (p == 0)
        {
            char c[6] = "f1.txt";
            int fd = open(c, O_RDONLY);
            char buff[1];
            close(pipefd[0]);

            while (read(fd, buff, sizeof(buff)) > 0)
            {
                write(pipefd[1], buff, sizeof(buff));
            }
        }

        else
        {
            printf("Fork not successful");
        }
    }
}