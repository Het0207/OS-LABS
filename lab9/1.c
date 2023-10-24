#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int count = 0;
sem_t s1;

void fun(void)
{

    sem_wait(&s1);
    count++;
    printf("%d\n", count);
    sem_post(&s1);
}

void main()
{

    sem_init(&s1, 0, 1);
    pthread_t t[5];

    for (int i = 0; i < 5; i++)
    {

        pthread_create(&t[i], NULL, fun, NULL);
    }

    for (int i = 0; i < 5; i++)
        pthread_join(t[i], NULL);
}
