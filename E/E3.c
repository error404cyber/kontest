#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


enum { MAX_LEN = 80 };

void split(char* words[], char* str){
    int i = 0;
    char* slovo = str;
    while ((*slovo) &&  (*slovo != '\n')){
        while (isspace(*slovo)) {
            slovo++;
        }
        if (!(*slovo)){
            break;
        }
        words[i] = slovo;
        while (!(isspace(*slovo)) && (*slovo)){ 
            slovo ++;
        }
        if (*slovo){
            *slovo = '\0';
            slovo++;
        }

        i++;
    }
    words[i] = '\0';
}

void print3(char* words[]){
    int i = 0;
    while (words[i]){
        if (strlen(words[i]) >= 3) {
            printf("%.3s\n", words[i]);
        }
        i++;
    }
}


int main(void) {
    char s[MAX_LEN + 2];
    char* words[MAX_LEN + 2];

    if ((fgets(s, MAX_LEN + 2, stdin) == NULL)) {
        exit(0);
    }
    split(words, s);
    print3(words);
    return 0;
}
