#include <stdio.h>

int
main(void)
{
    unsigned int n = 0;
    int q = 0;
    unsigned long long int s = 0;
    int i = 1;
    scanf ("%d", &n);
    scanf ("%d", &q);
    while (n >= q){
        s = i * (n % q) + s; 
        i *= 10;
        n /= q;
    }
    s = i * n + s; 
    printf("%llu", s);
    return 0;
} 
