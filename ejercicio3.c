#include <stdio.h>
#include <omp.h>

int multiplicacion(int a, int b) {
    int r = 0;
    #pragma omp parallel
    {
        #pragma omp single
        {
            for (int i = 0; i < b; i++) {
                #pragma omp task shared(r)
                {
                    #pragma omp atomic
                    r += a;
                }
            }
        }
    }
    return r;
}

int division(int a, int b) {
    int c = 0;
    int r = a;

    #pragma omp parallel
    {
        #pragma omp single
        {
            while (r >= b) {
                #pragma omp task shared(r, c)
                {
                    #pragma omp critical
                    {
                        if (r >= b) {
                            r -= b;
                            c++;
                        }
                    }
                }
            }
        }
    }
    
    #pragma omp taskwait

    return c;
}

int main() {
    int a, b;

    printf("Primer numero: ");
    scanf("%d", &a);

    printf("Segundo numero: ");
    scanf("%d", &b);

    printf("Resultado: %d\n", multiplicacion(a, b));
    printf("Resultado: %d\n", division(a, b));

    return 0;
}
