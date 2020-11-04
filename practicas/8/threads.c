#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>

unsigned saldo;
sem_t semSaldo;

void *addToSaldo(void *arg){
    sem_wait(&semSaldo);
    saldo += 500;
    // Si no se hace el post, queda un deadlock
    sem_post(&semSaldo);
    printf("El saldo actual es %d \n", saldo);
    pthread_exit(NULL);
}

int main(){
    unsigned NUM_THREADS = 10000;
    saldo = 0;
    sem_init(&semSaldo, 0, 1);
    pthread_t threads[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, addToSaldo, NULL);
    }
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("El saldo final es de %d \n", saldo);
    pthread_exit(NULL);

}