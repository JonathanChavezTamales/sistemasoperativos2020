#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void signalHandler(int signum){
    int status;
    printf("fin del hijo");
    wait(&status);
}


int main(int argc, char **argv){
    signal(17, signalHandler);
    int pid = fork();
    if(pid == 0){
        printf("hijo comienza\n");
        sleep(5);
        printf("hijo acaba\n");
        return 10;
    }
    else{
        printf("soy el padre de %d\n", pid); 
        while(1){
            printf("este es el loop escuchando\n");
            sleep(1);
        }
    }
}