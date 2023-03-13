//*****************************************************************
/*
INSERCIÓN
	Este programa muestra la implementación del ordenamiento por inserción 
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
void llenarArreglo(int* arreglo, int n);
void mostrarArreglo(int* arreglo, int n);
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
	  int n; 	// Variable que determina la cantidad de números a ordenar 
	  int i, j; //Variables para loops
	  int *arreglo; //Apuntador del arreglo
	  int temp = 0; //varibale auxiliar para el algoritmo de ordenamiento
	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	  if (argc!=2) 
	  {
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	  } 
	//Tomar el segundo argumento como tamaño del arreglo
	  else
	  {
	  	n=atoi(argv[1]);
	  }

	//Establecemos el tamaño del arreglo, determinado por el argumento n dado al ejecutar
	  arreglo = malloc(n*sizeof(int)); 
	//Lamado a la función llenarArreglo, a la cual se pasa por referencia el arreglo y por valor la n
	  llenarArreglo(arreglo, n);
	//Mostrar el arreglo por pantalla, para verificar que se lleno correctamente
	  mostrarArreglo(arreglo, n);

	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	  uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	// Algoritmo inserción
	/*
	   Cuando hay k elementos en una lista, se toma el elemento k+1 y 
	   se compara con todos los elementos a su derecha, de modo que cuando 
	   encuentra uno menor o cuando ya no 
       se encuentran elementos, se inserta el elemento.
    */
	//******************************************************************	
	
      for(i=0; i<=n-1; i++){
          j = i;
          temp = arreglo[i];
          while((j > 0) && (temp < arreglo[j-1])){
              arreglo[j] = arreglo[j-1];
              j--;
          }
          arreglo[j] = temp;
      }

	//******************************************************************

	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	  uswtime(&utime1, &stime1, &wtime1);
	
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
	//mandamos a llamar la funcion para imprimir solo para verificar que este el arreglo ordenado
	//imprimirArreglo(arreglo, n); 
	//Terminar programa normalmente	
	  mostrarArreglo(arreglo, n);
	  exit (0);	
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************
/*
	Esta función llena el arreglo con n números tomados del archivo que 
	contiene 10 millones de numeros.
	Recibe el arreglo y una n; no devuelve nada.
*/
void llenarArreglo(int* arreglo, int n)
{
	int i; 

	//el arreglo gracias al for que va de 0 hasta la n indicada por parametros al ejecutar
	for(i=0;i<n;i++)
	{
		scanf("%d", &arreglo[i]);
	}

}

/*
	Funcion para imprimir el arreglo y verificar su correcto ordenamiento
	Recibe el arreglo a imprimir y una n, no devuelve nada, solo imprime en pantalla
	los valores que tiene almacenados el arreglo
*/
void mostrarArreglo(int* arreglo, int n)
{
	int i, k;
	//for para imprimir cada elemento del arreglo mas una variable k que nos diga la posicion del elemento
	k=1;
	for(i=0;i<n;i++)
		printf("%d: %d\n", ++k, arreglo[i]);

}
