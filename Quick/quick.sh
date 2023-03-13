#!/bin/bash

# Array de tamaños de entrada
n=(1000 2000 3000 4000 5000 8000 10000 50000 100000 150000 200000 300000 400000 500000 600000 700000 800000 900000 1000000 1500000 2000000)

# Nombre del archivo de entrada
entrada="numeros10millones.txt"

# Nombre del archivo de salida
salida="quick.txt"

# Compilar el código fuente
gcc quick.c tiempo.c -o quick

# Ejecutar el programa para cada tamaño de entrada
for n in "${n[@]}"
do
    echo "Ejecutando insercion para $n elementos"
    ./quick $size < $entrada >> $salida
done

echo "Terminado"
exit 0
