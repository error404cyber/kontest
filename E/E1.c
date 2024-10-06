#include <stdio.h>
#include <stdlib.h>

enum { MAX_LEN = 80 };

char *findchar(const char *str, char c) {
    while (*str){
        if (*str == c)
            return (char *)str;
        str++;
    }
    return NULL;
}

int main(void) {
    char s[MAX_LEN + 2];
    char *first;

    if ((fgets(s, MAX_LEN + 2, stdin) == NULL)) {
        exit(0);
    }

    if (findchar(s, '\n')){
        first = findchar(s, '\n');
        *first = '\0';
    }

    while(findchar(s, 'Q')){
        first = findchar(s, 'Q');
        *first = 'R';
    }

    printf("%s", s);
    return 0;
}
