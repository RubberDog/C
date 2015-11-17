#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    int ind = 0;
    int sum = 0;

    for(i = 0; i < 1000; i++) {
        if(i % 3 == 0) {
            sum = sum + i;
            ind++;
        } else if(i % 5 == 0 && i % 3 != 0) {
            sum = sum + i;
            ind++;
        }
    }

    printf("Die Summe beträgt: %d\n", sum);

    return 0;
}
