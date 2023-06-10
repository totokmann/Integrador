import random

# Generar 100 números aleatorios
numeros = [random.randint(1, 1000) for _ in range(100)]

# Crear el archivo y escribir los números
with open('./numeros.txt', 'w') as archivo:
    for numero in numeros:
        numero_str = str(numero).zfill(3)  # Agregar ceros a la izquierda si es necesario
        archivo.write(numero_str + '\n')

print("Archivo 'numeros.txt' creado con éxito.")