import math
import time
import random

def dist(p1, p2):
    """Calcula la distancia euclidiana entre dos puntos (tuplas)."""
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

def brute_force(P):
    """Caso base: Fuerza bruta para listas pequeñas."""
    min_dist = float('inf')
    for i in range(len(P)):
        for j in range(i + 1, len(P)):
            d = dist(P[i], P[j])
            if d < min_dist:
                min_dist = d
    return min_dist

def strip_closest(strip, d):
    """
    Encuentra la distancia mínima en la franja.
    Este es el paso O(N log N) en la combinación.
    """
    min_dist = d
    
    # Ordenar la franja por 'y'
    strip_y = sorted(strip, key=lambda p: p[1])
    
    for i in range(len(strip_y)):
        for j in range(i + 1, len(strip_y)):
            # Optimización: si la distancia en 'y' ya es mayor que min_dist,
            # no es necesario seguir comparando con puntos más lejanos.
            if (strip_y[j][1] - strip_y[i][1]) >= min_dist:
                break
            d_pair = dist(strip_y[i], strip_y[j])
            if d_pair < min_dist:
                min_dist = d_pair
                
    return min_dist

def closest_util(Px):
    """Función recursiva principal de Divide y Vencerás."""
    n = len(Px)
    
    # Caso base
    if n <= 3:
        return brute_force(Px)
    
    # Dividir
    mid = n // 2
    mid_point = Px[mid]
    
    # Vencer (Recursión)
    # Nota: El slicing en Python crea copias O(N), lo cual es ineficiente.
    # Una mejor implementación pasaría índices [start:end]
    dl = closest_util(Px[:mid])
    dr = closest_util(Px[mid:])
    
    d = min(dl, dr)
    
    # Combinar (Construir la franja)
    strip = []
    for p in Px:
        if abs(p[0] - mid_point[0]) < d:
            strip.append(p)
            
    # Encontrar el mínimo en la franja
    d_strip = strip_closest(strip, d)
    
    return min(d, d_strip)

def closest(P):
    """Función principal (Wrapper)."""
    
    # 1. Pre-ordenamiento por x
    Px = sorted(P, key=lambda p: p[0])
    
    # 2. Llamada recursiva
    return closest_util(Px)

# --- Main y Pruebas ---
if __name__ == "__main__":
    N_VALUES = [10, 100, 1000, 100000]

    for N in N_VALUES:
        # Generar N puntos aleatorios (tuplas (x, y))
        # Aumentamos el rango para N grande para evitar puntos duplicados
        max_coord = 100000
        P = [(random.uniform(0, max_coord), random.uniform(0, max_coord)) for _ in range(N)]
        
        start_time = time.perf_counter()
        min_dist = closest(P)
        end_time = time.perf_counter()
        
        time_taken = end_time - start_time
        
        print(f"N = {N:<7} | Dist. Minima: {min_dist:<10.6f} | Tiempo (s): {time_taken:<10.6f}")