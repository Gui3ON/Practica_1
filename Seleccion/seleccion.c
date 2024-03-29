//*****************************************************************
/*
	ORDENAMIENTO POR SELECCIÓN
	Este programa muestra el algoritmo de ordenación por selección y hace la medición de tiempos
	con distinta cantidad de numeros a ordenar
	Fecha: 13/03/2023
	Version: 1.0
	Autores:
			-Ojeda Navarro Guillermo
*/
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void llenarArreglo(int *arreglo, int n);
void imprimirArreglo(int *arreglo, int n);
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int argc, char *argv[])
{
	//******************************************************************	
	//Variables del main
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int i, k; //Variables para loops
	int *arreglo; //Variable donde se guardará el arreglo de números
	int p; // Variable que siempre representa el número más pequeño en cada iteración de k
	int temp; // Variable que ayuda a hacer la conmutaicón de números


	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************
	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)	
	if (argc != 2)
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n", argv[0]);
		exit(1);
	}
	// Si se introduce un número mayor a 10 millones
	else if (atoi(argv[1]) > 10000000)
	{
		printf("\nIngrese un número menor a 10,000,000\n");
		exit(1);
	}
	//Tomar el segundo argumento como tamaño del arreglo
	else
	{
		n = atoi(argv[1]);
	}

	//Establecemos el tamaño del arreglo de acuerdo al tamaño n dado por argumento al ejecutar
	arreglo = malloc(n * sizeof(int));

	//mandamos a llamar a la función que llena el arreglo pasando por referencia el arreglo y por valor la n
	llenarArreglo(arreglo, n);

	//lo imprimimos para verificar que se lleno correctamente
	//imprimirArreglo(arreglo, n);

	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************

	//Algoritmo de ordenamiento por selección
	/*
		Este algoritmo funciona por recorrer todo el arreglo de números
		y comparar cada uno de los números con el resto de números para 
		encontrar el más pequeño, después deja ese pequeño en la primera
		posición y avanza a la siguiente posición, también encontrando el
		segundo más pequeño para dejarlo en la segunda posicisión y así
		sucesivamente hasta que llega la penúltima posición y sólo realiza
		una última comparación.
	*/
	//******************************************************************
	
	for (k = 0; k <= n - 2; k++)
	{
		p = k;
		for (i = k + 1; i <= n - 1; i++)
		{
			if (arreglo[i] < arreglo[p])
			{
				p = i;
			}
		}
		temp = arreglo[p];
		arreglo[p] = arreglo[k];
		arreglo[k] = temp;
	}

	//******************************************************************


	//******************************************************************
	//Evaluar los tiempos de ejecución
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);

	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	//Mostrar los tiempos en formato exponecial
	   printf("\n");
	   printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	   printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	   printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	   printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	   printf("\n");
	//******************************************************************


	//mandamos a llamar la funcion para imprimir solo para verificar que este el arreglo ordenado
	//imprimirArreglo(arreglo, n);

	//Terminar programa normalmente
	exit(0);
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES
//************************************************************************

/*
	Esta función llena nuestro arreglo con n números tomados del archivo que contiene 10 millones de numeros o de la terminal en su defecto. 
	Recibe el arreglo y una n, no devuelve nada pues solo llena el arreglo.
*/
void llenarArreglo(int *arreglo, int n)
{

	int i = 0; // Variable para ciclo

	// Llenamos el arreglo gracias al for que va de 0 hasta antes de la n indicada por parametros al ejecutar
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arreglo[i]);
	}
}

/*
	Funcion para imprimir el arreglo y verificar su correcto ordenamiento
	Recibe el arreglo a imprimir y una n, no devuelve nada, solo imprime en pantalla
	los valores que tiene almacenados el arreglo
*/
void imprimirArreglo(int *arreglo, int n)
{
	int i = 0; //variable para ciclo

	// for para imprimir cada elemento del arreglo mas una variable k que nos diga la posicion del elemento
	for (i = 0; i < n; i++)
		printf("%d: %d\n", i + 1, arreglo[i]);
}
