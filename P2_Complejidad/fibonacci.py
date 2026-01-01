import time
import sys

def fibonacci(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)

print("=" * 40)
print(" ALGORITMO RECURSIVO DE FIBONACCI")
print("=" * 40)
print("Este algoritmo calcula el n-esimo numero")
print("de la sucesion de Fibonacci usando")
print("recursividad.\n")
print("Regla de Fibonacci:")
print("F(0) = 0")
print("F(1) = 1")
print("F(n) = F(n-1) + F(n-2)\n")
print("Nota: Este metodo es ineficiente para")
print("valores grandes de n debido a la")
print("repeticion de calculos.")
print("=" * 40)

n = int(input("\nIngrese el valor de n: "))

memoria = n * sys.getsizeof(0)

inicio = time.perf_counter()
resultado = fibonacci(n)
fin = time.perf_counter()

tiempo = fin - inicio

print("\nRESULTADO:")
print(f"Fibonacci({n}) = {resultado}")

print("\nESTADISTICAS:")
print(f"Tiempo de ejecucion: {tiempo:.6f} segundos")
print(f"Memoria aproximada usada: {memoria} bytes")

print("\nTabla comparativa:")
print("n\tTiempo(s)\tMemoria(bytes)")
print(f"{n}\t{tiempo:.6f}\t{memoria}")