#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int busquedaBinaria(int a[], int n, int x){
    int izq = 0, der = n - 1, medio;

    while(izq <= der){
        medio = (izq + der) / 2;

        if(a[medio] == x)
            return medio;
        else if(a[medio] < x)
            izq = medio + 1;
        else
            der = medio - 1;
    }
    return -1;
}

void llenarOrdenado(int a[]){
    for(int i = 0; i < N; i++)
        a[i] = i + 1;
}

int main(){
    int opcion, x;
    int *a = (int*)malloc(N * sizeof(int));
    clock_t ini, fin;
    double tiempo;
    int pos;
    int memoria = N * sizeof(int);

    do{
        printf("\nBUSQUEDA BINARIA DEL 1 AL 1,000,000\n");
        printf("1. Busqueda binaria (lista ordenada)\n");
        printf("2. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if(opcion == 2) break;

        if(opcion != 1){
            printf("Opcion invalida\n");
            continue;
        }

        printf("Numero a buscar: ");
        scanf("%d", &x);

        system("cls");

        llenarOrdenado(a);
        printf("LISTA ORDENADA\n");

        ini = clock();
        pos = busquedaBinaria(a, N, x);
        fin = clock();

        tiempo = (double)(fin - ini) / CLOCKS_PER_SEC;

        if(pos != -1)
            printf("Elemento %d encontrado en la posicion %d del arreglo\n", x, pos);
        else
            printf("Elemento no encontrado\n");

        printf("Tiempo de ejecucion: %f segundos\n", tiempo);
        printf("Memoria usada: %d bytes\n", memoria);

        printf("\nTabla comparativa:\n");
        printf("Tamanio\tTiempo(s)\tMemoria(bytes)\n");
        printf("%d\t%f\t%d\n", N, tiempo, memoria);

        system("pause");

    }while(1);

    free(a);
    return 0;
}