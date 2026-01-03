#ifndef HUFFMAN_H
#define HUFFMAN_H

#define MAX 256

typedef struct Nodo {
    char simbolo;
    int frecuencia;
    struct Nodo *izq, *der;
} Nodo;

Nodo* crearNodo(char simbolo, int frecuencia, Nodo* izq, Nodo* der);
Nodo* construirArbol(int freq[]);
void generarCodigos(Nodo* raiz, char *codigo, int profundidad, char codigos[MAX][MAX]);
void imprimirIteracion(Nodo* nodos[], int n);

#endif
