//*****************************************************************
//Alfaro Alvarez Oscar Humberto
//Curso: Análisis de algoritmos
//(C) Enero 2013
//ESCOM-IPN
//Ejemplo de medición de tiempo en C y recepción de parametros en C bajo UNIX
//Compilación: "gcc main_Burbuja_simple.c tiempo.c  -o main_BS"
//Ejecución: "./main_BS n" (Linux y MAC OS)
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//********************************************************************************
//DECLARACION DE ESTRUCTURAS
//********************************************************************************

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************

void llenar_Arreglo(int * arr, int n);
void imprimir_Arreglo(int * arr, int n);
int ordenar_Arreglo(int * arr, int n);

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[])
{	
	//******************************************************************	
	//Variables del main
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int * arr;

	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=2) 
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n=atoi(argv[1]);
	}

  //Establecemos le tamaño del arreglo de manera dinámica conforme al valor de n recibido

  arr = (int *)malloc(n*sizeof(int));

  //Llamamos a la función que llena el arreglo pasando por referencia el arreglo y por valor la n

  llenar_Arreglo(arr, n);

	/*
            Llamamos a la función que nos permite imprimir el arreglo para verificar con algunos valores
            de n que se haya ordenada de forma correcta.
  */

 //imprimir_Arreglo(arr, n);
	
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo de Ordenamiento: Burbuja Simple.
	/*
						Funciona revisando cada elemento de la lista que va a ser ordenada con el siguiente, 
						intercambiándolos de posición si están en el orden equivocado. Es necesario revisar 
						varias veces toda la lista hasta que no se necesiten más intercambios, lo cual sifnifica 
						que la lista está ordenada.
	*/
	//******************************************************************

  ordenar_Arreglo(arr, n);

	//******************************************************************

	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);

	printf("\n*****Tiempos de ejecución del ordenamiento por Burbuja Optimizada 02 para n=%d*****\n", n);
	
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************
	
	/*
			Liberamos la memoria que creamos dinámicamente para el arreglo donde guardamos los números.
	*/
	
	free(arr);
	
	//Terminar programa normalmente	
	exit (0);	
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************

/*
          Función que nos permitira llenar un arreglo de n posiciones mediante un ciclo iterativo for
          que ira desde 0 hasta n-1. Los valores con los que se llenara el arreglo serán extraidos de 
          un archivo llamado "numeros10millones.txt".
          La función recibe el arreglo y el valor de n, sólo llena el arreglo, no devuelve nada. 
*/

void llenar_Arreglo(int * arr, int n){
  int i; //Variable utilizada para el ciclo for

  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
}

/*
          Función que nos permite imprimir el arreglo y verificar el ordenamiento que tiene visialmente.
          Recibe el arreglo a imprimir y una n, no devuelve nada, solo imprime los valores de n que tiene 
          alamacenado el arreglo. 
*/

void imprimir_Arreglo(int * arr, int n){
  int i; //Variable utilizada para el ciclo for

  printf("\n*****Arreglo*****\n");

  for(i=0; i<n; i++){
    printf("\t%d", arr[i]);
  }

	printf("\n");
}

/*
          Función que mediante el algoritmo de ordenamiento Burbuja Simple nos permite ordenar un arreglo con n 
          valores de menor a mayor. Recibe el arreglo a ordenar y una variable n que es el número de elementos del 
          arreglo. Devuelve el arreglo ordenado.
*/

int ordenar_Arreglo(int * arr, int n){
  int i, j; //Varibales utilizadas para los ciclos for
  int aux; //Variable aux ara el intercambio de posición
  int cambios = 1; //Variable la cual inializa el valor de cambios en 1 el cual es SI y 0 será NO

  while(i <= n && cambios != 0){
    cambios = 0;
    for(j=0; j<n-i; j++){
      if(arr[j] > arr[j+1]){
        aux = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = aux;
        cambios = 1;
      }
    }
    i = i+1;
  }
}
