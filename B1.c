#include <stdio.h>

#define MAX_LEN 100 // 1

int
main(void)
{
    int mass[MAX_LEN]; //3
    int len = 0; // 2
    int i, c;
    scanf ("%d", &len); //4
    for (i = 0; i < len; i++){
        scanf("%d", &c);
        mass[i] = c;
        if ((c % 2) == 0)
            printf("%d ", c); //6
    }
    for (i = len - 1; i >= 0; i-=1){
        c = mass[i];
        c = c<0?-c:c;
        if ((c % 2) != 0)
            printf("%d ", mass[i]);
    }
    return 0;
} 
