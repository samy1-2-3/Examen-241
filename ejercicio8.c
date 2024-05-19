#include <stdio.h>
#include <omp.h>

int main() {
    int n;

    printf("Cantidad de numeros de la serie: ");
    scanf("%d", &n);

    int serie[n];

    #pragma omp parallel for num_threads(M)
    for (int i = 0; i < n; ++i) {
        serie[i] = (i + 1) * 2;
    }

    printf("Serie generada: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", serie[i]);
    }
    printf("\n");

    return 0;
}
