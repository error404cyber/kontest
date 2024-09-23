#include <stdio.h>

int
main(void)
{
    long long int a = 0;
    int i = 0;
    unsigned long long int bi = 1;
    scanf ("%lld", &a);
    while (bi != 0){
        i = ((a & bi) == 0)? i: i + 1;
        bi = bi << 1;
    }
    printf ("%d", i);
    return 0;
} 
