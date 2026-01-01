#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int busquedaLineal(int a[], int n, int x){
    for(int i = 0; i < n; i++){
        if(a[i] == x)
            return i;
    }
    return -1;
}

void llenarOrdenado(int a[]){
    for(int i = 0; i < N; i++)
        a[i] = i + 1;
}

void llenarDesordenado(int a[]){
    for(int i = 0; i < N; i++)
        a[i] = i + 1;

    for(int i = 0; i < N; i++){
        int j = rand() % N;
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}

int main(){
    int opcion, x;
    int *a = (int*)malloc(N * sizeof(int));
    clock_t ini, fin;
    double tiempo;
    int pos;
    int memoria = N * sizeof(int);

    srand(time(NULL));

    do{
        printf("\nBUSQUEDA LINEAL DEL 1 AL 1,000,000\n");
        printf("1. Busqueda en lista ordenada\n");
        printf("2. Busqueda en lista desordenada\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if(opcion == 3) break;

        printf("Numero a buscar: ");
        scanf("%d", &x);

        system("cls"); // Limpia pantalla

        if(opcion == 1){
            llenarOrdenado(a);
            printf("LISTA ORDENADA\n");
        }
        else if(opcion == 2){
            llenarDesordenado(a);
            printf("LISTA DESORDENADA\n");
        }
        else{
            printf("Opcion invalida\n");
            continue;
        }

        ini = clock();
        pos = busquedaLineal(a, N, x);
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