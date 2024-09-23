#include <stdio.h>

int
main(void)
{
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int k = 0;
    scanf("%u", &a);
    scanf("%u", &b);
    while ((a != 0) && (b != 0)){
        if (a < b){
            k = a;
            a = b; 
            b = k;
        }
        // a - max, b - min
        a %= b;
    }

    if (a < b){
            k = a;
            a = b; 
            b = k;
        }
    if (a == 0)
        printf ("1");
    else
        printf("%u", a);
    return 0;
} 
