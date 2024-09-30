#include <stdio.h>
#include <stdlib.h>

enum { MAX_LEN = 80 };

int my_strlen(const char* str1) {
    if (str1 == NULL) {
        return 0;
    }
    const char *ptr = str1;
    int count = 0;

    while (*ptr != '\0') {
        count++;
        ptr++;
    }
    if (*(--ptr) =='\n')
        count--;
    return (count);
}

int main(void) {
    char s[MAX_LEN + 1];

    if ((fgets(s, MAX_LEN + 1, stdin) == NULL)) {
        printf("EMPTY INPUT");
        exit(0);
    }

    printf("%d", my_strlen(s));
    return 0;
}
