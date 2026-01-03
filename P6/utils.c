#include <stdio.h>
#include <string.h>
#include "utils.h"

#define MAX 256

void imprimirFrecuencias(int freq[]) {
    printf("\n=== Tabla de frecuencias ===\n");
    for (int i = 0; i < MAX; i++) {
        if (freq[i] > 0)
            printf("'%c' : %d\n", i, freq[i]);
    }
}

void codificarTexto(char *texto, char codigos[MAX][MAX]) {
    printf("\n=== Texto codificado ===\n");
    for (int i = 0; i < strlen(texto); i++) {
        printf("%s ", codigos[(unsigned char)texto[i]]);
    }
    printf("\n");
}

void tasaCompresion(char *texto, char codigos[MAX][MAX]) {
    int bits_original = strlen(texto) * 8;
    int bits_codificados = 0;

    for (int i = 0; i < strlen(texto); i++)
        bits_codificados += strlen(codigos[(unsigned char)texto[i]]);

    printf("\nTam original:   %d bits", bits_original);
    printf("\nTam comprimido: %d bits", bits_codificados);

    double tasa = (1 - (double)bits_codificados / bits_original) * 100.0;
    printf("\nTasa compresion: %.2f%%\n", tasa);
}
