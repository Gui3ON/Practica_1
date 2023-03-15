//*****************************************************************
/*
	HEAP SORT
	Este programa muestra el algoritmo heap sort 
	para hacer la medición de tiempos con distinta cantidad 
    de numeros a ordenar.
	
    Fecha: 13/03/2023
	Version: 1.0
	Autores:
			-Ojeda navarro Guillermo
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
//DECLARACIÓN DE FUNCIOnES
//*****************************************************************
void llenarArreglo(int* arreglo, int n);
void imprimirArreglo(int* arreglo, int n);
void swap(int* a, int* b);
void acumular(int arreglo[], int n, int i);
void heapSort(int arreglo[], int n);
//*****************************************************************
int aux = 0; //variable auxiliar
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
	int i, j; //Variables para loops
	int *arreglo; //Variable donde se guardara el arreglo
	struct Arbol *arbol = nULL; //variable que apunta a la estructura Arbol
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

	//Establecemos el tamaño del arreglo de acuerdo al tamaño n dado por argumento al ejecutar
	arreglo = malloc(n*sizeof(int)); 
	//mandamos a llamar a la función que llena el arreglo pasando por referencia el arreglo y por valor la n
	llenarArreglo(arreglo, n);
	//lo imprimimos para verificar que se lleno correctamente
	//imprimirArreglo(arreglo, n);

	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo Heap sort
	/*
        Este algortimo requiere de dos pasos:
        1. Insertar cada uno de los número de un arreglo en el monticulo.
        2. Remplazar el arreglo en desorden por el arreglo resultante de un 
           ciclo extrayendo un elemento a la vez del monticulo.
    */
	//******************************************************************	
	
    heapSort(arreglo, n);
    
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
	exit (0);	
}

//************************************************************************
//DEFINICIÓn DE FUNCIONES 
//************************************************************************

/*
	Esta función llena nuestro arreglo con n números tomados del archivo que contiene
	10 millones de numeros.
	Recibe el arreglo y una n, no devuelve nada pues solo llena el arreglo.
*/
void llenarArreglo(int* arreglo, int n){
	
	int i = 0;//variable para ciclo

	//llenamos el arreglo gracias al for que va de 0 hasta la n indicada por parametros al ejecutar
	for(i=0;i<n;i++){
		scanf("%d", &arreglo[i]);
	}

}

/*
	Funcion para imprimir el arreglo y verificar su correcto ordenamiento
	Recibe el arreglo a imprimir y una n, no devuelve nada, solo imprime en pantalla
	los valores que tiene almacenados el arreglo
*/
void imprimirArreglo(int* arreglo, int n){
	int i = 0, k=0; //variable para ciclo

	//for para imprimir cada elemento del arreglo mas una variable k que nos diga la posicion del elemento
	for(i=0;i<n;i++)
		printf("%d: %d\n", ++k, arreglo[i]);

}

/* Función para intercambiar la posición de dos elementos */
void swap(int* a, int* b)
{

	int temp = *a;

	*a = *b;

	*b = temp;
}

/* Para acumular un subárbol enraizado con el nodo i, que es un índice en arreglo[]. 
n es el tamaño del montón */ 
void acumular(int arreglo[], int n, int i)
{
	// Encuentra el más grande entre la raíz, el hijo izquierdo y el hijo derecho

	// Inicializar el mayor como raíz
	int mas_grande = i;

	int izquierdo = 2 * i + 1;

	int derecha = 2 * i + 2;

	// En caso de que el hijo izquierdo es más grande que la raíz
	if (izquierdo < n && arreglo[izquierdo] > arreglo[mas_grande])

		mas_grande = izquierdo;

	// Si el hijo derecho es más grande que el más grande
	if (derecha < n && arreglo[derecha] > arreglo[mas_grande])

		mas_grande = derecha;

	// Intercambiar y continuar acumulando si la raíz no es mas_grande
	if (mas_grande != i) {

		swap(&arreglo[i], &arreglo[mas_grande]);

		// Acumula recursivamente 
		acumular(arreglo, n, mas_grande);
	}
}

// Función principal para ordenar el montón
void heapSort(int arreglo[], int n)
{

	// Construir montón 
	for (int i = n / 2 - 1; i >= 0; i--)

		acumular(arreglo, n, i);

	// Ordenar montones
	for (int i = n - 1; i >= 0; i--) {

		swap(&arreglo[0], &arreglo[i]);

		// acumular elemento raíz para obtener el elemento más alto en
		// enraizar de nuevo
		acumular(arreglo, i, 0);
	}
}

