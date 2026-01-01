#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_DEFINIDO 10000

void burbuja(int a[], int n){
    int aux;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
}

void arregloDefinido(int a[]){
    for(int i = 0; i < N_DEFINIDO; i++)
        a[i] = rand() % (N_DEFINIDO * 10);
}

void imprimirArreglo(int a[], int n){
    printf("\nArreglo ordenado:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int opcion, n;
    int *a;
    clock_t ini, fin;
    double tiempo;
    int memoria;

    srand(time(NULL));

    do{
        printf("\nORDENAMIENTO POR BURBUJA\n");
        printf("1. Proporcionar arreglo para ordenar\n");
        printf("2. Usar arreglo definido (10,000 elementos)\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        if(opcion == 3) break;

        if(opcion == 1){
            printf("Cantidad de elementos: ");
            scanf("%d", &n);

            a = (int*)malloc(n * sizeof(int));
            memoria = n * sizeof(int);

            for(int i = 0; i < n; i++){
                printf("N%d = ", i + 1);
                scanf("%d", &a[i]);
            }
        }
        else if(opcion == 2){
            n = N_DEFINIDO;
            a = (int*)malloc(n * sizeof(int));
            memoria = n * sizeof(int);
            arregloDefinido(a);
        }
        else{
            printf("Opcion invalida\n");
            continue;
        }

        printf("\nOrdenando...\n");

        ini = clock();
        burbuja(a, n);
        fin = clock();

        tiempo = (double)(fin - ini) / CLOCKS_PER_SEC;

        imprimirArreglo(a, n);

        printf("\nRESULTADOS:\n");
        printf("Tamanio del arreglo: %d\n", n);
        printf("Tiempo de ejecucion: %f segundos\n", tiempo);
        printf("Memoria usada: %d bytes\n", memoria);

        printf("\nTabla comparativa:\n");
        printf("n\tTiempo(s)\tMemoria(bytes)\n");
        printf("%d\t%f\t%d\n", n, tiempo, memoria);

        free(a);
        system("pause");

    }while(1);

    return 0;
}
