#include <pthread.h>
#include <stdio.h>

void *fun1(void *arg) {
    printf("Hello from thread1\n");
    return NULL;
}

void *fun2(void *arg) {
    printf("Hello from thread2\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, fun1, NULL);
    pthread_create(&t2, NULL, fun2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}