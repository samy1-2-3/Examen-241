#include <stdio.h>

int suma(int *a, int *b) {
    return (*a) + (*b);
}

int resta(int *a, int *b) {
    return (*a) - (*b);
}

int multiplicacion(int *a, int *b) {
    int c = 0;
    for (int i = 0; i < (*b); i++) {
        c = suma(&c, a);
    }
    return c;
}

int division(int *a, int *b) {
    if ((*b) == 0) {
        printf("No hay división entre 0.\n");
        return 0;
    }

    int co = 0;
    while ((*a) >= (*b)) {
        *a = resta(a, b);
        co++;
    }
    return co;
}

int main() {
    int a, num2;
    char operacion;

    printf("Ingrese el primer numero: ");
    scanf("%d", &a);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    printf("Seleccione la operacion a realizar:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    scanf(" %c", &operacion);

    switch (operacion) {
        case '1':
            printf("Respuesta = %d\n", suma(&a, &num2));
            break;
        case '2':
            printf("Respuesta = %d\n", resta(&a, &num2));
            break;
        case '3':
            printf("Respuesta = %d\n", multiplicacion(&a, &num2));
            break;
        case '4':
            printf("Respuesta = %d\n", division(&a, &num2));
            break;
        default:
            printf("Error de operacion.\n");
    }

    return 0;
}
