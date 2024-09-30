#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int n1, n2, i, index_otr, index_poloz;
    double first_otriz = 1.0;
    double last_polozh = -1.0;
    double a;
    index_otr = 0;
    index_poloz = 0;
    scanf("%d", &n1);
    double *array_1 = (double*) calloc(n1,sizeof(double)); 
    for (i = 0; i < n1; i++){
        scanf("%lf", &a);
        array_1[i] = a;
        if ((first_otriz > 0.0) && (a < 0)){
            first_otriz = a;
            index_otr = i;
        }
    }
    scanf("%d", &n2);
    double *array_2 = (double*) calloc(n2,sizeof(double)); 
    for (i = 0; i < n2; i++){
        scanf("%lf", &a);
        array_2[i] = a;
        if ((a > 0)){
            last_polozh = a;
            index_poloz = i;
        }
    }

    if ((last_polozh > 0.0) && (first_otriz < 0.0)){
        array_1[index_otr] = last_polozh;
        array_2[index_poloz] = first_otriz;
    }

    for (i = 0; i< n1; i++){
        printf("%.1f ", array_1[i]);
    }
    printf("\n");

    for (i = 0; i< n2; i++){
        printf("%.1f ", array_2[i]);
    }

    free(array_1);
    free(array_2);
    return 0;
}
