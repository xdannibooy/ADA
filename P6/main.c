#include <stdio.h>
#include <string.h>
#include "huffman.h"
#include "utils.h"

int main() {
    char texto[1024];
    int freq[MAX] = {0};
    char codigos[MAX][MAX] = {{0}};
    char codigoTemp[MAX];

    printf("Introduce el texto:\n> ");
    fgets(texto, 1024, stdin);
    texto[strcspn(texto, "\n")] = '\0';

    for (int i = 0; i < strlen(texto); i++)
        freq[(unsigned char)texto[i]]++;

    imprimirFrecuencias(freq);

    Nodo* raiz = construirArbol(freq);

    generarCodigos(raiz, codigoTemp, 0, codigos);

    printf("\n=== Codigos ===\n");
    for (int i = 0; i < MAX; i++) {
        if (freq[i] > 0)
            printf("'%c' : %s\n", i, codigos[i]);
    }

    codificarTexto(texto, codigos);

    tasaCompresion(texto, codigos);

    return 0;
}
