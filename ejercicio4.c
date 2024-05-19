#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void multiplica(int **m, int *v, int *r, int n) {
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        r[i] = 0;
        for (int j = 0; j < n; j++) {
            r[i] += m[i][j] * v[j];
        }
    }
}

void mostrar(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Tamaño de la matriz y el vector: ");
    scanf("%d", &n);

    int **matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    int *vector = (int *)malloc(n * sizeof(int));
    int *resultado = (int *)malloc(n * sizeof(int));

    printf("Llena la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Llena el vector:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }

    printf("Matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nVector:\n");
    mostrar(vector, n);

    multiplica(matriz, vector, resultado, n);

    printf("Multiplicacion de la matriz y el vector:\n");
    mostrar(resultado, n);

    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
    free(vector);
    free(resultado);

    return 0;
}
