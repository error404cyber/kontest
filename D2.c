#include <stdio.h>
#include <stdlib.h>

enum { MAX_LEN_1 = 80};
enum { MAX_LEN_2 = 20};

int strfind(const char *str, const char *symbols) {

    const char *stroka = str;
    const char *ishem = symbols;

    int count = 0;

    if (*stroka == '\0'){
        return -1;
    }

    if ((*stroka == '\n') && (*ishem == '\n')){
        return -1;
    }

    while ((*stroka) &&  (*stroka != '\n')){
        ishem = symbols;
        while (*ishem){
            if (*stroka == *ishem)
                return count;
            ishem++;
        }
        count++;
        stroka++;
    }

    return -1;
}

int main(void) {
    char s1[MAX_LEN_1 + 2];
    char s2[MAX_LEN_2 + 2];

    if ((fgets(s1, MAX_LEN_1 + 2, stdin) == NULL)) {
        exit(0);
    }

    if ((fgets(s2, MAX_LEN_2 + 2, stdin) == NULL)) {
        exit(0);
    }
    printf("%d", strfind(s1, s2));
    return 0;
}
