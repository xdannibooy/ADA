import time
import random
import os
import sys

N_DEFINIDO = 10_000

def merge(lista, izq, medio, der):
    temp = []
    i, j = izq, medio + 1

    while i <= medio and j <= der:
        if lista[i] <= lista[j]:
            temp.append(lista[i])
            i += 1
        else:
            temp.append(lista[j])
            j += 1

    while i <= medio:
        temp.append(lista[i])
        i += 1

    while j <= der:
        temp.append(lista[j])
        j += 1

    lista[izq:der + 1] = temp

def merge_sort(lista, izq, der):
    if izq < der:
        medio = (izq + der) // 2
        merge_sort(lista, izq, medio)
        merge_sort(lista, medio + 1, der)
        merge(lista, izq, medio, der)

def arreglo_definido():
    return [random.randint(0, N_DEFINIDO * 10) for _ in range(N_DEFINIDO)]

def memoria_usada(n):
    return sys.getsizeof([0]) * n  # aproximación

while True:
    print("\nORDENAMIENTO POR MERGE SORT")
    print("1. Proporcionar arreglo para ordenar")
    print("2. Usar arreglo definido (10,000 elementos)")
    print("3. Salir")

    opcion = input("Opcion: ")

    if opcion == "3":
        break

    if opcion == "1":
        n = int(input("Cantidad de elementos: "))
        lista = []
        for i in range(n):
            lista.append(int(input(f"N{i+1} = ")))
    elif opcion == "2":
        lista = arreglo_definido()
        n = N_DEFINIDO
    else:
        print("Opcion invalida")
        continue

    memoria = memoria_usada(n)

    os.system("cls" if os.name == "nt" else "clear")
    print("Ordenando...")

    inicio = time.perf_counter()
    merge_sort(lista, 0, n - 1)
    fin = time.perf_counter()

    tiempo = fin - inicio

    print("\nArreglo ordenado:")
    for x in lista:
        print(x, end=" ")
    print()

    print("\nRESULTADOS:")
    print(f"Tamanio del arreglo: {n}")
    print(f"Tiempo de ejecucion: {tiempo:.6f} segundos")
    print(f"Memoria aproximada usada: {memoria} bytes")

    print("\nTabla comparativa:")
    print("n\tTiempo(s)\tMemoria(bytes)")
    print(f"{n}\t{tiempo:.6f}\t{memoria}")

    input("\nPresiona Enter para continuar...")