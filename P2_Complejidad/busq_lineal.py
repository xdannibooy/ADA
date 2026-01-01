import time
import random
import os
import sys

N = 1_000_000

def busqueda_lineal(lista, x):
    for i in range(len(lista)):
        if lista[i] == x:
            return i
    return -1

def llenar_ordenado():
    return list(range(1, N + 1))

def llenar_desordenado():
    lista = list(range(1, N + 1))
    random.shuffle(lista)
    return lista

def memoria_usada():
    # Aproximacion del consumo de memoria
    return sys.getsizeof([0]) * N

while True:
    print("\nBUSQUEDA LINEAL DEL 1 AL 1,000,000")
    print("1. Busqueda en lista ordenada")
    print("2. Busqueda en lista desordenada")
    print("3. Salir")
    
    opcion = input("Opcion: ")

    if opcion == "3":
        break

    x = int(input("Numero a buscar: "))

    os.system("cls" if os.name == "nt" else "clear")

    if opcion == "1":
        lista = llenar_ordenado()
        print("LISTA ORDENADA")
    elif opcion == "2":
        lista = llenar_desordenado()
        print("LISTA DESORDENADA")
    else:
        print("Opcion invalida")
        continue

    inicio = time.perf_counter()
    pos = busqueda_lineal(lista, x)
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