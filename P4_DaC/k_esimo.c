#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funcion para intercambiar dos elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funcion de particion (usa el pivote al final)
// Mueve los elementos menores al pivote a la izquierda
// y los mayores a la derecha. Devuelve la posicion final del pivote.
int partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l;
    for (int j = l; j < r; j++) {
        if (a[j] < pivot) {
            swap(&a[i], &a[j]);
            i++;
        }
    }
    swap(&a[i], &a[r]);
    return i; // posicion final del pivote
}

// Selecciona un pivote aleatorio para reducir el peor caso
int randomized_partition(int a[], int l, int r) {
    int p = l + rand() % (r - l + 1);
    swap(&a[p], &a[r]);
    return partition(a, l, r);
}

// Algoritmo Quickselect: encuentra el k-esimo menor elemento (k es 0-index)
// Usa el paradigma Divide and Conquer
int quickselect(int a[], int l, int r, int k) {
    while (l <= r) {
        int p = randomized_partition(a, l, r);
        if (p == k) {
            return a[p]; // el pivote esta en la posicion correcta
        } else if (p > k) {
            r = p - 1; // buscar en la parte izquierda
        } else {
            l = p + 1; // buscar en la parte derecha
        }
    }
    return 0; // solo por seguridad
}

int main() {
    int n;

    // Leer cantidad de elementos
    printf("Ingrese el numero de elementos: ");
    scanf("%d", &n);

    int *a = (int*)malloc(sizeof(int) * n);

    // Leer los elementos del arreglo
    printf("Ingrese los elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int k;
    // Leer la posicion k (1-index)
    printf("Ingrese la posicion k del elemento menor que desea encontrar: ");
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("Error: k fuera de rango.\n");
        free(a);
        return 1;
    }

    srand((unsigned)time(NULL));

    // Llamada al algoritmo (k-1 porque el arreglo es 0-index)
    int resultado = quickselect(a, 0, n - 1, k - 1);

    printf("El %d-esimo menor elemento es: %d\n", k, resultado);

    free(a);
    return 0;
}
