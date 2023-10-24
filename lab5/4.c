#include <pthread.h>
#include <stdio.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

void *fun(void* arg) {
    pthread_mutex_lock(&m);
    count++;
    printf("%d\n", count);
    pthread_mutex_unlock(&m);
}

int main() {
    pthread_t t[5];

    for (int i = 0; i < 5; i++)
        pthread_create(&t[i], NULL, fun, NULL);

    for (int i = 0; i < 5; i++)
        pthread_join(t[i], NULL);

    return 0;
}
