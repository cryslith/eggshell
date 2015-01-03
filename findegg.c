#include <unistd.h>
#include <stdio.h>

#define EGG "EGG"

int main(void) {
    printf("%s address: 0x%x\n", EGG, getenv(EGG));
    return 0;
}
