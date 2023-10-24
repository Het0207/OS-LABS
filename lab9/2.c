#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdbool.h>

const int size_of_buff = 5;
int buff[5];
int in = 0;
int out = 0;
sem_t n, s, e;

void append(int item)
{

    while ((in + 1) % size_of_buff == out)
    {
    };

    buff[in] = item;
    printf("Item %d placed on buffer at index %d\n", item, in);

    in = (in + 1) % size_of_buff;
}

void Producer(void)
{
    int i = 1;
    while (true)
    {
        int item = i;
        printf("Item %d produced\n", item);
        sem_wait(&e);
        sem_wait(&s);
        append(item);
        i++;
        sem_post(&s);
        sem_post(&n);
    }
}

int take()
{
    while (in == out)
    {
    };
    int w = buff[out];
    out = (out + 1) % size_of_buff;
    return w;
}

void *Consumer(void *)
{

    while (true)
    {
        sem_wait(&n);
        sem_wait(&s);
        int item = take();
        sem_post(&s);
        sem_post(&e);
        printf("Item %d consumed\n", item);
    }
}

void main()
{

    sem_init(&n, 0, 0);
    sem_init(&s, 0, 1);
    sem_init(&e, 0, size_of_buff);

    pthread_t producer, consumer;

    pthread_create(&producer, NULL, Producer, NULL);
    pthread_create(&consumer, NULL, Consumer, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
}