#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { MAX_LEN = 80 };

char *concat(const char *s1, const char *s2) {
    const char *first = s1;
    const char *second = s2;
    char *res = (char *)malloc(strlen(s1) + strlen(s2) + 1);
    char *third = res;
    while ((*first) &&  (*first != '\n')){
        *third = *first;
        first++;
        third++;
    }


    while ((*second) &&  (*second != '\n')){
        *third = *second;
        second++;
        third++;
    }
    *third = '\0';
    return res;
}

int main(void) {
    char s1[MAX_LEN + 2];
    char s2[MAX_LEN + 2];
    if ((fgets(s1, MAX_LEN + 2, stdin) == NULL)) {
        exit(0);
    }
    //printf("%d", strlen(s1));
    if ((fgets(s2, MAX_LEN + 2, stdin) == NULL)) {
        exit(0);
    }
    //printf("d");

    char *s = concat(s1, s2);
    //printf("tt");
    printf("%s", s);
    // for(int i = 0; i < strlen(s); i++){
        
    //     printf("%s", s[i]);
    // }

    free(s);
    return 0;
}
