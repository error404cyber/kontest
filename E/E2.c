#include <stdio.h>
#include <stdlib.h>

enum { MAX_LEN = 10000 };

const double *adres_max(double *mass, int n) {
    if (n <= 0)
        return NULL;

    const double *maximum = mass;
    for (int i = 1; i < n; i ++){
        if (*maximum < *(mass + i)){
            maximum = mass + i;
        }
    }
    return (double *)maximum;
}

void my_swap(double *a, double *b){
    double c = *a;
    *a = *b;
    *b = c;
}

void my_sort(double *mass, int n){
    const double *adres;
    for (int i = 0; i < n; i++){
        adres = adres_max(mass + i, n - i);
        if (adres)
            my_swap((double *)adres, (mass + i));
        else{
            break;
        }
    }
}

int main(void) {
    double mass[MAX_LEN];
    int k;
    scanf("%d", &k);
    if ((k < 0) || (k > MAX_LEN)){
        exit(0);
    }
    for (int j = 0; j < k; j ++){
        scanf("%lf", (mass + j));
    }
    if (k > 18){
        printf("%.1lf\n", *adres_max(mass + 4, 14));
    }

    my_sort(mass, k);
    for (int i = 0; i < k; i ++){
        printf("%.1lf ", mass[i]);
    }
    return 0;
}
