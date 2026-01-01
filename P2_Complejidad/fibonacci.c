#include <stdio.h>
#include <time.h>

long long fibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    int n;
    clock_t ini, fin;
    double tiempo;
    int memoria;

    printf("========================================\n");
    printf(" ALGORITMO RECURSIVO DE FIBONACCI\n");
    printf("========================================\n");
    printf("Este algoritmo calcula el n-esimo numero\n");
    printf("de la sucesion de Fibonacci usando\n");
    printf("recursividad.\n\n");
    printf("Regla de Fibonacci:\n");
    printf("F(0) = 0\n");
    printf("F(1) = 1\n");
    printf("F(n) = F(n-1) + F(n-2)\n\n");
    printf("Nota: Este metodo es ineficiente para\n");
    printf("valores grandes de n debido a la\n");
    printf("repeticion de calculos.\n");
    printf("========================================\n\n");

    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    memoria = n * sizeof(long long);

    ini = clock();
    long long resultado = fibonacci(n);
    fin = clock();

    tiempo = (double)(fin - ini) / CLOCKS_PER_SEC;

    printf("\nRESULTADO:\n");
    printf("Fibonacci(%d) = %lld\n", n, resultado);

    printf("\nESTADISTICAS:\n");
    printf("Tiempo de ejecucion: %f segundos\n", tiempo);
    printf("Memoria aproximada usada: %d bytes\n", memoria);

    printf("\nTabla comparativa:\n");
    printf("n\tTiempo(s)\tMemoria(bytes)\n");
    printf("%d\t%f\t%d\n", n, tiempo, memoria);

    return 0;
}