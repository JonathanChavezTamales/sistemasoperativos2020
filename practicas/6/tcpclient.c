#include <netdb.h>
#include <stdio.h>

extern int h_errno;

int main(int argc, char **argv){
    char *hostname = argv[1];
    struct hostent *hostInfo = gethostbyname(hostname);

    printf("official name %s, ipaddress %s\n", hostInfo->h_name, hostInfo->h_addr);
}