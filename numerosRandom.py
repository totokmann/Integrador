import random

# Generar 100 números aleatorios
numeros = [random.randint(1, 1000) for _ in range(100)]

# Crear el archivo y escribir los números
with open('C:\Users\Alejo\Desktop\"Integrador Primer Semestre"\numeros.txt', 'w') as archivo:
    for numero in numeros:
        archivo.write(str(numero) + '\n')

print("Archivo 'numeros.txt' creado con éxito.")