#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10000000       // tamaño del arreglo para búsqueda binaria (10 millones)
#define MOD 1000000007   // módulo para potencia
#define REP 1000         // repeticiones para medir tiempo

// ------------------ Suma de dígitos ------------------
long long sumaIterativaCadena(char *num) {  //--long long = int más grande para bits
    long long suma = 0;
    for(long long i = 0; num[i] != '\0'; i++)
        suma += num[i] - '0';
    return suma;
}

long long sumaRecursivaCadena(char *num, long long i) {
    if(num[i] == '\0') return 0; // caso base
    return (num[i]-'0') + sumaRecursivaCadena(num, i+1); // llamada recursiva
}

// ------------------ Invertir cadena ------------------
void invertirIterativo(char *cadena) {
    long long i = 0, j = strlen(cadena)-1; //strlen(cadena)-1 (última posición del string)
    while(i < j) {
        char temp = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = temp;
        i++; j--;
    }
}

void invertirRecursivo(char *cadena, long long inicio, long long fin) {
    if(inicio >= fin) return; // caso base
    char temp = cadena[inicio]; 
    cadena[inicio] = cadena[fin];
    cadena[fin] = temp;
    invertirRecursivo(cadena, inicio+1, fin-1); // llamada recursiva
}

// ------------------ Búsqueda binaria ------------------
long long busquedaBinariaIterativa(long long arr[], long long n, long long x) {
    long long inicio = 0, fin = n-1;
    while(inicio <= fin) {
        long long mid = inicio + (fin-inicio)/2;
        if(arr[mid] == x) return mid;
        else if(arr[mid] < x) inicio = mid+1;
        else fin = mid-1;
    }
    return -1;
}

long long busquedaBinariaRecursiva(long long arr[], long long inicio, long long fin, long long x) {
    if(inicio > fin) return -1; 
    long long mid = inicio + (fin-inicio)/2; // índice medio
    if(arr[mid] == x) return mid; // caso base
    else if(arr[mid] < x) return busquedaBinariaRecursiva(arr, mid+1, fin, x); // llamada recursiva
    else return busquedaBinariaRecursiva(arr, inicio, mid-1, x);
}

// ------------------ Potenciación modular ------------------
long long potenciaIterativaMod(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod; 
    while(exp > 0) { // mientras exp > 0
        if(exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long potenciaRecursivaMod(long long base, long long exp, long long mod) {
    if(exp == 0) return 1; // caso base
    long long res = potenciaRecursivaMod(base, exp/2, mod); // llamada recursiva
    res = (res * res) % mod; // cuadrado
    if(exp % 2 == 1) res = (res * base) % mod; // si exp es impar
    return res; // retorna resultado
}

// ------------------ MAIN ------------------
int main() {
    int opcion;
    clock_t inicio, fin;
    double tiempo;
    char *cadena = malloc(200000); // cadena grande dinámica

    // arreglo grande predefinido para búsqueda binaria
    static long long arr[N];
    for (long long i = 0; i < N; i++)
        arr[i] = i; // arreglo ordenado 0..N-1

    do {
        printf("\n--- MENU ---\n");
        printf("1. Sumar digitos\n");
        printf("2. Invertir cadena\n");
        printf("3. Busqueda binaria\n");
        printf("4. Potenciacion\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar(); // limpia buffer

        switch(opcion) {
            case 1: {
                printf("Numero: ");
                scanf("%s", cadena);

                long long resultado = 0;

                // --- Iterativa ---
                inicio = clock();
                for(int r=0; r<REP; r++)
                    resultado = sumaIterativaCadena(cadena);
                fin = clock();
                tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
                printf("Iterativa: %lld\n", resultado); //lld es un especificador de formato para numeros grandes
                printf("Tiempo iterativo (x1000 repeticiones): %.8f s\n", tiempo);

                // --- Recursiva ---
                resultado = 0;
                inicio = clock();
                for(int r=0; r<REP; r++)
                    resultado = sumaRecursivaCadena(cadena, 0);
                fin = clock();
                tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
                printf("Recursiva: %lld\n", resultado);
                printf("Tiempo recursivo (x1000 repeticiones): %.8f s\n", tiempo);
                break;
            }
            case 2: {
                printf("Cadena (solo caracteres): ");
                fgets(cadena, 200000, stdin);
                cadena[strcspn(cadena, "\n")] = '\0';

                // Crear copias para cada versión
                char *copia_iterativa = malloc(strlen(cadena)+1);
                char *copia_recursiva = malloc(strlen(cadena)+1);
                strcpy(copia_iterativa, cadena);
                strcpy(copia_recursiva, cadena);

                printf("Original: %s\n", cadena);

                // --- Iterativa ---
                // Primero invertir una vez para mostrar resultado correcto
                invertirIterativo(copia_iterativa);
                inicio = clock();
                // Luego medir tiempo con 1000 repeticiones (invertir y desinvertir)
                for(int r=0; r<REP; r++) {
                    invertirIterativo(copia_iterativa);
                    invertirIterativo(copia_iterativa);
                }
                fin = clock();
                tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
                printf("Iterativa: %s (%.8f s)\n", copia_iterativa, tiempo);

                // --- Recursiva ---
                // Primero invertir una vez para mostrar resultado correcto
                invertirRecursivo(copia_recursiva, 0, strlen(copia_recursiva)-1);
                inicio = clock();
                // Luego medir tiempo con 1000 repeticiones (invertir y desinvertir)
                for(int r=0; r<REP; r++) {
                    invertirRecursivo(copia_recursiva, 0, strlen(copia_recursiva)-1);
                    invertirRecursivo(copia_recursiva, 0, strlen(copia_recursiva)-1);
                }
                fin = clock();
                tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
                printf("Recursiva: %s (%.8f s)\n", copia_recursiva, tiempo);

                free(copia_iterativa);
                free(copia_recursiva);
                break;
            }
            case 3: {
                    long long x;
                    printf("Numero a buscar (0..%lld): ", N-1LL); // N-1LL para forzar a ser long long
                    scanf("%lld", &x);

                long long pos;

                // --- Iterativa ---
                inicio = clock();
                for(int r=0; r<REP; r++)
                    pos = busquedaBinariaIterativa(arr, N, x);
                fin = clock();
                tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
                printf("Iterativa -> Pos: %lld (%.8f s)\n", pos, tiempo);

                // --- Recursiva ---
                inicio = clock();
                for(int r=0; r<REP; r++)
                    pos = busquedaBinariaRecursiva(arr, 0, N-1, x);
                fin = clock();
                tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
                printf("Recursiva -> Pos: %lld (%.8f s)\n", pos, tiempo);

                break;
            }
            case 4: {
                long long base, exp;
                printf("Base: ");
                scanf("%lld", &base);
                printf("Exponente: ");
                scanf("%lld", &exp);

                long long resultado;

                // --- Iterativa ---
                inicio = clock();
                for(int r=0; r<REP; r++)
                    resultado = potenciaIterativaMod(base, exp, MOD);
                fin = clock();
                tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
                printf("Iterativa: %lld\n", resultado);
                printf("Tiempo iterativo (1000 repeticiones): %.8f s\n", tiempo);

                // --- Recursiva ---
                inicio = clock();
                for(int r=0; r<REP; r++)
                    resultado = potenciaRecursivaMod(base, exp, MOD);
                fin = clock();
                tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
                printf("Recursiva: %lld\n", resultado);
                printf("Tiempo recursivo (1000 repeticiones): %.8f s\n", tiempo);

                break;
            }
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while(opcion != 5);

    free(cadena);
    return 0;
}