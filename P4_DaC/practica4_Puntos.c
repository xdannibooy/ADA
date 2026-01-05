#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>

// Estructura para un punto en 2D
struct Point {
    double x, y;
};

/* --- Funciones de Comparación para qsort --- */

// Comparar por coordenada x
int compareX(const void* a, const void* b) {
    struct Point *p1 = (struct Point *)a;
    struct Point *p2 = (struct Point *)b;
    if (p1->x < p2->x) return -1;
    if (p1->x > p2->x) return 1;
    return 0;
}

// Comparar por coordenada y
int compareY(const void* a, const void* b) {
    struct Point *p1 = (struct Point *)a;
    struct Point *p2 = (struct Point *)b;
    if (p1->y < p2->y) return -1;
    if (p1->y > p2->y) return 1;
    return 0;
}

/* --- Funciones de Utilidad --- */

// Calcular distancia euclidiana
double dist(struct Point p1, struct Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

// Caso base: Fuerza bruta para n <= 3
double bruteForce(struct Point P[], int n) {
    double min_dist = DBL_MAX;
    int i,j;
    for ( i = 0; i < n; ++i)
        for ( j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min_dist)
                min_dist = dist(P[i], P[j]);
    return min_dist;
}

// Función para encontrar el mínimo de dos dobles
double min(double x, double y) {
    return (x < y) ? x : y;
}

/* --- Funciones D&V Principales --- */

// Encuentra la distancia mínima en la franja (strip)
// La franja ya está ordenada por y
double stripClosest(struct Point strip[], int size, double d) {
    double min_dist = d;
    
    // Ordenar la franja por 'y' (Este es el paso O(N log N) en la combinación)
    qsort(strip, size, sizeof(struct Point), compareY);

	int i, j;
    // Iterar y comparar con los vecinos cercanos
    for ( i = 0; i < size; ++i) {
        for ( j = i + 1; j < size && (strip[j].y - strip[i].y) < min_dist; ++j) {
            if (dist(strip[i], strip[j]) < min_dist)
                min_dist = dist(strip[i], strip[j]);
        }
    }
    return min_dist;
}

// Función recursiva principal de Divide y Vencerás
double closestUtil(struct Point Px[], int n) {
    // Caso base
    if (n <= 3)
        return bruteForce(Px, n);

    // Dividir
    int mid = n / 2;
    struct Point midPoint = Px[mid];

    // Vencer (Recursión)
    // Usamos aritmética de punteros para pasar las mitades
    double dl = closestUtil(Px, mid);
    double dr = closestUtil(Px + mid, n - mid);

    double d = min(dl, dr);

    // Combinar (Construir la franja)
    // Usamos malloc para evitar desbordamiento de pila (stack overflow) con N grande
    struct Point* strip = (struct Point*)malloc(n * sizeof(struct Point));
    if (strip == NULL) {
        fprintf(stderr, "Error de alocación de memoria\n");
        exit(1);
    }
    
    int j = 0;
    int i;
    for ( i = 0; i < n; i++)
        if (fabs(Px[i].x - midPoint.x) < d)
            strip[j] = Px[i], j++;

    // Encontrar el mínimo en la franja y liberar memoria
    double d_strip = stripClosest(strip, j, d);
    free(strip);

    return min(d, d_strip);
}

// Función principal (Wrapper)
double closest(struct Point P[], int n) {
    // 1. Pre-ordenamiento por x
    qsort(P, n, sizeof(struct Point), compareX);
    
    // 2. Llamada recursiva
    return closestUtil(P, n);
}

/* --- Main y Pruebas --- */

int main() {
    int N_values[] = {10, 100, 1000, 100000};
    int num_tests = sizeof(N_values) / sizeof(N_values[0]);

    // Inicializar semilla para números aleatorios
    srand(time(NULL));
	
	int i,j;
    for ( i = 0; i < num_tests; i++) {
        int N = N_values[i];
        struct Point* P = (struct Point*)malloc(N * sizeof(struct Point));
        if (P == NULL) {
            fprintf(stderr, "Error al alocar P\n");
            return 1;
        }

        // Generar N puntos aleatorios (entre 0 y 10000)
        for ( j = 0; j < N; j++) {
            P[j].x = (double)rand() / (double)(RAND_MAX / 10000.0);
            P[j].y = (double)rand() / (double)(RAND_MAX / 10000.0);
        }

        clock_t start = clock();
        double min_dist = closest(P, N);
        clock_t end = clock();
        
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("N = %-7d | Dist. Minima: %-10.6f | Tiempo (s): %-10.6f\n", N, min_dist, time_taken);

        free(P);
    }

    return 0;
}
