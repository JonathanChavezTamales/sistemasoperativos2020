#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signum){
    printf("no me puedes matar");
}

int main(){
    signal(2, signalHandler);
    while(1){
        printf("trabajando\n");
        sleep(1);
    }
    return 0;
}