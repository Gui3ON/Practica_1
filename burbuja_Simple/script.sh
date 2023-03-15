#!/bin/bash

gcc main_Burbuja_Simple.c tiempo.c -o main_BS

./main_BS 1000 < numeros10millones.txt > salida.txt
./main_BS 2000 < numeros10millones.txt >> salida.txt
./main_BS 3000 < numeros10millones.txt >> salida.txt
./main_BS 4000 < numeros10millones.txt >> salida.txt
./main_BS 5000 < numeros10millones.txt >> salida.txt
./main_BS 8000 < numeros10millones.txt >> salida.txt
./main_BS 10000 < numeros10millones.txt >> salida.txt
./main_BS 50000 < numeros10millones.txt >> salida.txt
./main_BS 100000 < numeros10millones.txt >> salida.txt
./main_BS 150000 < numeros10millones.txt >> salida.txt
./main_BS 200000 < numeros10millones.txt >> salida.txt
./main_BS 300000 < numeros10millones.txt >> salida.txt
./main_BS 400000 < numeros10millones.txt >> salida.txt
./main_BS 500000 < numeros10millones.txt >> salida.txt
./main_BS 600000 < numeros10millones.txt >> salida.txt
./main_BS 700000 < numeros10millones.txt >> salida.txt
./main_BS 800000 < numeros10millones.txt >> salida.txt
./main_BS 900000 < numeros10millones.txt >> salida.txt
./main_BS 1000000 < numeros10millones.txt >> salida.txt
./main_BS 1500000 < numeros10millones.txt >> salida.txt
./main_BS 2000000 < numeros10millones.txt >> salida.txt