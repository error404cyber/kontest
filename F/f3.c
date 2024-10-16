#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node * next;
    int value;
};
          
struct List {
    struct Node * first;
    struct Node * last;
    size_t size;
};

int main(void) {
    int n = 0;
    int length = 1;
    int kol = 0;
    int i  = 0;
    int *mass = calloc(100, sizeof(int));

    while (scanf("%d", &n) == 1){
        if (length == kol){
            length *=2;
            mass = (int*)realloc(mass, length * sizeof(int));
        }
        mass[kol++] = n;
    }

    for (i = kol - 1; i>=0; i--){
        printf("%d ", mass[i]);
    }
    free(mass);
    return 0;
}
