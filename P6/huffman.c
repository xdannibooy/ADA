#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"

Nodo* crearNodo(char simbolo, int frecuencia, Nodo* izq, Nodo* der) {
    Nodo* n = (Nodo*)malloc(sizeof(Nodo));
    n->simbolo = simbolo;
    n->frecuencia = frecuencia;
    n->izq = izq;
    n->der = der;
    return n;
}

void imprimirIteracion(Nodo* nodos[], int n) {
    printf("\nIteracion (nodos actuales):\n");
    for (int i = 0; i < n; i++) {
        if (nodos[i]->simbolo == '\0')
            printf("[*:%d]  ", nodos[i]->frecuencia);
        else
            printf("['%c':%d]  ", nodos[i]->simbolo, nodos[i]->frecuencia);
    }
    printf("\n");
}

void ordenar(Nodo* nodos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nodos[j]->frecuencia > nodos[j + 1]->frecuencia) {
                Nodo* temp = nodos[j];
                nodos[j] = nodos[j + 1];
                nodos[j + 1] = temp;
            }
        }
    }
}

Nodo* construirArbol(int freq[]) {
    Nodo* nodos[MAX];
    int n = 0;

    for (int i = 0; i < MAX; i++) {
        if (freq[i] > 0) {
            nodos[n++] = crearNodo((char)i, freq[i], NULL, NULL);
        }
    }

    while (n > 1) {
        ordenar(nodos, n);
        imprimirIteracion(nodos, n);

        Nodo *izq = nodos[0];
        Nodo *der = nodos[1];
        Nodo* nuevo = crearNodo('\0', izq->frecuencia + der->frecuencia, izq, der);

        for (int i = 2; i < n; i++)
            nodos[i - 2] = nodos[i];

        nodos[n - 2] = nuevo;
        n -= 1;
    }

    return nodos[0];
}

void generarCodigos(Nodo* raiz, char *codigo, int profundidad, char codigos[MAX][MAX]) {
    if (!raiz) return;

    if (!raiz->izq && !raiz->der) {
        codigo[profundidad] = '\0';
        strcpy(codigos[(unsigned char)raiz->simbolo], codigo);
        return;
    }

    codigo[profundidad] = '0';
    generarCodigos(raiz->izq, codigo, profundidad + 1, codigos);

    codigo[profundidad] = '1';
    generarCodigos(raiz->der, codigo, profundidad + 1, codigos);
}
