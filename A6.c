#include <stdio.h>

int
main(void)
{
    unsigned short n;
    unsigned int m;
    unsigned int k;
    scanf("%hx", &n);
    m = n;
    k = m & 1;
    m = m >> 4;
    m = m << 4;
    m = (m ^ (1 << 12));
    m = (m ^ (1 << 13));
    m = (m ^ (1 << 14));
    m = (m ^ (1 << 15));
    m = m | k;
    printf("%d %04x %08x", (n&32)>>5, m, (m << 16) + n);
    return 0;
} 
