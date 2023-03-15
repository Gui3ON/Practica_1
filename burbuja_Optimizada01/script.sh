#!/bin/bash

gcc main_Burbuja_Optimizada01.c tiempo.c -o main_BO01

./main_BO01 1000 < numeros10millones.txt > salida.txt
./main_BO01 2000 < numeros10millones.txt >> salida.txt
./main_BO01 3000 < numeros10millones.txt >> salida.txt
./main_BO01 4000 < numeros10millones.txt >> salida.txt
./main_BO01 5000 < numeros10millones.txt >> salida.txt
./main_BO01 8000 < numeros10millones.txt >> salida.txt
./main_BO01 10000 < numeros10millones.txt >> salida.txt
./main_BO01 50000 < numeros10millones.txt >> salida.txt
./main_BO01 100000 < numeros10millones.txt >> salida.txt
./main_BO01 150000 < numeros10millones.txt >> salida.txt
./main_BO01 200000 < numeros10millones.txt >> salida.txt
./main_BO01 300000 < numeros10millones.txt >> salida.txt
./main_BO01 400000 < numeros10millones.txt >> salida.txt
./main_BO01 500000 < numeros10millones.txt >> salida.txt
./main_BO01 600000 < numeros10millones.txt >> salida.txt
./main_BO01 700000 < numeros10millones.txt >> salida.txt
./main_BO01 800000 < numeros10millones.txt >> salida.txt
./main_BO01 900000 < numeros10millones.txt >> salida.txt
./main_BO01 1000000 < numeros10millones.txt >> salida.txt
./main_BO01 1500000 < numeros10millones.txt >> salida.txt
./main_BO01 2000000 < numeros10millones.txt >> salida.txt