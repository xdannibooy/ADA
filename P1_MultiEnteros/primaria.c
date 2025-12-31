#include <stdio.h>
#include <string.h> //Bibliotecas

int main() {
    char num1[100], num2[100];
    int i, j;

    printf("Ingresa el primer numero: ");
    scanf("%s", num1);

    printf("Ingresa el segundo numero: ");
    scanf("%s", num2);

    int len1 = strlen(num1); //strlen calcula la longitud de una cadena
    int len2 = strlen(num2); //strlen calcula la longitud de una cadena

    int resultado[len1 + len2];

    // Inicializar el arreglo en cero
    for (i = 0; i < len1 + len2; i++) {
        resultado[i] = 0;
    }

    // Algoritmo de la primaria
    for (i = len1 - 1; i >= 0; i--) {
        for (j = len2 - 1; j >= 0; j--) {
            int dig1 = num1[i] - '0';
            int dig2 = num2[j] - '0';
            resultado[i + j + 1] += dig1 * dig2;
        }
    }

    // Manejo de acarreos
    for (i = len1 + len2 - 1; i > 0; i--) {
        resultado[i - 1] += resultado[i] / 10;
        resultado[i] %= 10;
    }

    // Mostrar resultado
    printf("\nResultado: ");
    i = 0;
    while (i < len1 + len2 && resultado[i] == 0) {
        i++;
    }

    if (i == len1 + len2) {
        printf("0");
    } else {
        for (; i < len1 + len2; i++) {
            printf("%d", resultado[i]);
        }
    }

    printf("\n");

    return 0;
}
