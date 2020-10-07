#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char c;
    char buffer[64];
    char prev = ' ';

    unsigned words = 0;
    unsigned lines = 0;
    unsigned chars = 0;

    while(read(STDIN_FILENO, &c, 1) != 0) {
        if (c == ' ' && prev != '\n')
            words++;
        else if (c == '\n'){
            words++;
            lines++;
        }

        prev = c;
        chars++;
    }

    printf("%u %u %u\n", lines, words, chars);
    return 0;
}