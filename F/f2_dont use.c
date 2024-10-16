#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *mass = NULL;
    int n = 0;
    int razm = 0;  // Current capacity
    int kol = 0;   // Number of elements

    while (scanf("%d", &n) == 1) {
        // Expand the array if necessary
        if (kol == razm) {
            razm = (razm == 0) ? 1 : razm * 2;
            int *flag = realloc(mass, razm * sizeof(int));
            if (flag == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                free(mass);
                return 1;
            }
            mass = flag;
        }
        mass[kol] = n;
        kol++;
    }

    // Print the array in reverse order
    for (int i = kol - 1; i >= 0; i--) {
        printf("%d ", mass[i]);
    }
    printf("\n");  // Output a newline at the end

    // Free the allocated memory
    free(mass);
    return 0;
}
