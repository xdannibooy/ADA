# Multiplicación de dos números grandes usando el algoritmo de la primaria

# Entrada de datos
num1 = input("Ingresa el primer numero: ")
num2 = input("Ingresa el segundo numero: ")

len1 = len(num1)
len2 = len(num2)

# Arreglo para almacenar el resultado
resultado = [0] * (len1 + len2)

# Algoritmo de la primaria (multiplicación dígito por dígito)
for i in range(len1 - 1, -1, -1):
    for j in range(len2 - 1, -1, -1):
        dig1 = ord(num1[i]) - ord('0')
        dig2 = ord(num2[j]) - ord('0')
        resultado[i + j + 1] += dig1 * dig2

# Manejo de acarreos
for i in range(len1 + len2 - 1, 0, -1):
    resultado[i - 1] += resultado[i] // 10
    resultado[i] %= 10

# Mostrar resultado
i = 0
while i < len(resultado) and resultado[i] == 0:
    i += 1

print("\nResultado: ", end="")

if i == len(resultado):
    print("0")
else:
    for k in range(i, len(resultado)):
        print(resultado[k], end="")
    print()
