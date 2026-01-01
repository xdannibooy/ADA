import time
import os
import sys

N = 1_000_000

def busqueda_binaria(lista, x):
    izq = 0
    der = len(lista) - 1

    while izq <= der:
        medio = (izq + der) // 2

        if lista[medio] == x:
            return medio
        elif lista[medio] < x:
            izq = medio + 1
        else:
            der = medio - 1
    return -1

def llenar_ordenado():
    return list(range(1, N + 1))

def memoria_usada():
    return sys.getsizeof([0]) * N  # aproximación

while True:
    print("\nBUSQUEDA BINARIA DEL 1 AL 1,000,000")
    print("1. Busqueda binaria (lista ordenada)")
    print("2. Salir")

    opcion = input("Opcion: ")

    if opcion == "2":
        break

    if opcion != "1":
        print("Opcion invalida")
        continue

    x = int(input("Numero a buscar: "))

    os.system("cls" if os.name == "nt" else "clear")

    lista = llenar_ordenado()
    print("LISTA ORDENADA")

    inicio = time.perf_counter()
    pos = busqueda_binaria(lista, x)
    fin = time.perf_counter()

    tiempo = fin - inicio
    memoria = memoria_usada()

    if pos != -1:
        print(f"Elemento {x} encontrado en la posicion {pos} de la lista")
    else:
        print("Elemento no encontrado")

    print(f"Tiempo de ejecucion: {tiempo:.6f} segundos")
    print(f"Memoria aproximada usada: {memoria} bytes")

    print("\nTabla comparativa:")
    print("Tamanio\tTiempo(s)\tMemoria(bytes)")
    print(f"{N}\t{tiempo:.6f}\t{memoria}")

    input("\nPresiona Enter para continuar...")
