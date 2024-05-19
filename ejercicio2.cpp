#include <iostream>

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
        std::cout << "No hay división entre 0." << std::endl;
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

    std::cout << "Ingrese el primer numero: ";
    std::cin >> a;
    std::cout << "Ingrese el segundo numero: ";
    std::cin >> num2;

    std::cout << "Seleccione la operacion a realizar:\n";
    std::cout << "1. Suma\n";
    std::cout << "2. Resta\n";
    std::cout << "3. Multiplicacion\n";
    std::cout << "4. Division\n";
    std::cin >> operacion;

    switch (operacion) {
        case '1':
            std::cout << "Respuesta = " << suma(&a, &num2) << std::endl;
            break;
        case '2':
            std::cout << "Respuesta = " << resta(&a, &num2) << std::endl;
            break;
        case '3':
            std::cout << "Respuesta = " << multiplicacion(&a, &num2) << std::endl;
            break;
        case '4':
            std::cout << "Respuesta = " << division(&a, &num2) << std::endl;
            break;
        default:
            std::cout << "Error de operacion." << std::endl;
    }

    return 0;
}
