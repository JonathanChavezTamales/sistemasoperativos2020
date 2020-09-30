#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void signalHandler(int signum){
    printf("no me puedes matar");
}

int main(int argc, char **argv){
    signal(17, signalHandler);
    int x = fork();
    if(x == 0){
        printf("soy el hijo\n");
        execv(argv[1], &argv[1]);
        return 10;
    }
    else{
        int child_status;
        printf("soy el padre de %d\n", x); 
        wait(&child_status);
        printf("padre termina y el hijo termino con status %d\n", child_status);
    }
}