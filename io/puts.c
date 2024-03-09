#include <stdio.h>
#include <string.h>
#include <internal/syscall.h>

int puts(const char *str) {
    syscall(1, 1, str, strlen(str));
    char sir_2[1];
    sir_2[0] = '\n';
    syscall(1, 1, sir_2, 1);
    return 1;
}
