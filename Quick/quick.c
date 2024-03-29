//*****************************************************************
/*
	QUICK SORT
	Este programa muestra el algoritmo de ordenación rapida para hacer la medición de tiempos
	con distinta cantidad de N a ordenar
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
void imprimirArreglo(int* arreglo, int n);
void quickSort(int *arreglo, int p, int r);
int pivot(int *arreglo, int p, int r);
void intercambiar(int *arreglo, int i, int j);
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
	int *arreglo; //Variable donde se guardara el arreglo
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
	// imprimirArreglo(arreglo, n);

	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo de ordenacion rapida
	/*
		Este algoritmo de ordenacion toma un pivote, de esta forma quedan dos listas, una a la derecha del pivote
		y otra a la izquierda de este. A partir de aqui va disminuyendo los indices de la derecha y aumenta los de
		izquierda para ir encontrando y comparando elementos para así intercambiarlos.
		Si los indices se cruzan, se retorna el de la derecha y se hace lo mismo que se planteo anteriormente
		llamando a la función haciendo uso de la recursividad, dicha recursividad se cumple siempre y cuando
		la parte de la izquierda sea menor que la derecha.
		
	*/
	//******************************************************************	
	
	quickSort(arreglo, 0, n-1); //mandamos a llamar a la funcion que iniciara con el ordenamiento

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
	// imprimirArreglo(arreglo, n);
	//Terminar programa normalmente	
	exit (0);	
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
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

/*
	Funcion quickSort
	ESta función recibe el arreglo, la parte izquierda (p) y derecha (r). 
	No retorna nada, pero con esta inicia la ordenacion

*/
void quickSort(int *arreglo, int p, int r){
	int j=0; //variables que guardara el pivote
	
	//si la parte izquierda es menor que la derecha se hace el algoritmo
	if(p < r){
		j = pivot(arreglo, p, r); //asignamos a j el valor resultante de la funcion pivot
		quickSort(arreglo, p, j); //hacemos uso de la recursividad
		quickSort(arreglo, j+1, r); //hacemos uso de la recursividad
	}
}

/*
	Funcion pivot
	Esta funcion recibe al arreglo, la parte izquierda (p) y la derecha (r)
	Retorna el valor del pivote (j)
	Esta es la función que se encarga de ordenar el arreglo con ayuda de una funcion mas llamada intercambiar
*/ 

int pivot(int *arreglo, int p, int r){

	//aqui asignamos el pivote, i sera la parte izquierda y r la derecha
	int piv = arreglo[p], i = p, j = r;

	/*hacemos un ciclo infinito que acabara cuando la parte izquierda sea mayor o igual al pivote, es decir,
	que los elementos esten ordenados*/
	while(1){

		while(arreglo[i] < piv ) i++; //aumenta el indice de la izquieda si es menor que el pivote, es decir, este ordenado
		while(arreglo[j] > piv) j--; //disminuye el indice de la derecha si es mayor al pivote, es decir, este ordenado

		/*
		aqui hacemos un if, si la parte izquierda es mayor al pivote significa que ya estan en orden los elementos en 
		la iteracion en curso y devolvemos el pivote para hacer la division de nuevo
		En caso contrario intercambiamos los elementos pues estos no estaban en orden
		*/
		if(i >= j )
			return j;
		else{
			intercambiar(arreglo, i, j); //Aqui llamamos a intercambiar para hacer el intercambio
			i++; //avanzamos en la izquierda
			j--; //retrocedemos en la derecha
		}
	}
}

/*
	Funcion intercambiar
	Esta funcion recibe el arreglo, la parte izquierda (i) y la derecha (j)
	no devuelve nada, pues solo intercambiamos valores dentro del arreglo.
	Para hacer el intercambio nos ayudamos de una variable auxiliar llamada temp
*/

void intercambiar(int *arreglo, int i, int j){
	int temp = arreglo[j];

	arreglo[j] = arreglo[i];
	arreglo[i] = temp;
}
