#!/bin/bash

# Compilar el programa antes de ejecutarlo
make

chmod 777 "push_swap"
chmod 777 "checker_linux"
# Lista de números a ordenar
ARG="4 67 3 87 23"
# Ejecutar push_swap y contar el número de operaciones
echo "Número de operaciones:"
./push_swap $ARG | tee output.txt | wc -l

# Verificar si el resultado es correcto
echo "Resultado de checker_OS:"
./push_swap $ARG | ./checker_linux $ARG

# Limpiar salida intermedia
rm output.txt
