#include <stdio.h>

int
main(void)
{
    unsigned int n = 0;
    scanf("%u", &n);
    while ((n != 255) && (n != 0)){
        switch (n){
            case 255: printf("Fatal error\n"); break;
            case 0: printf("Ok\n"); break;
            case 20:
            case 21: 
            case 22: printf("Memory access error\n"); break;
            case 6: printf("Rejected\n"); break;
            case 7: printf("Timeout\n"); break;
            case 1: 
            case 2:
            case 3:
            case 4:
            case 5: printf("Permission denied\n"); break;
            default: printf("Unknown error\n"); break;
        }
        scanf("%u", &n);
    }
    switch (n){
            case 255: printf("Fatal error\n");  break;
            case 0: printf("Ok\n");  break;
            default: printf("Unknown error\n"); break;
    }
    return 0;
} 
