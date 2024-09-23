#include <stdio.h>
#include <assert.h>
#include <math.h>


int is_simple(int n){
    //double k;
    int i = 2;
    //k = sqrt(n);
    if (n <= 1)
        return 0;
    if ((n == 2) || (n == 3))
        return 1;
    while (i<= sqrt(n)) { //n >= 4
        if (n % i == 0)
            return 0;
        i ++;
    }
    return 1;
}

