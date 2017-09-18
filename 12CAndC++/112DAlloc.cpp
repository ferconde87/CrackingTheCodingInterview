#include <iostream>

using namespace std;

/* Primer solución: hacemos un pedido a malloc de un array de memoria (filas)
 * y por cada posición en la fila, un malloc para las columnas*/
int** my2DAlloc(int rows, int cols){
	int ** rowptr;
	rowptr = (int**)malloc(rows * sizeof(int*));
	for(int i = 0; i < rows; i++){
		rowptr[i] = (int*)malloc(cols * sizeof(int*));
	}
	return rowptr;
}

void free2DAlloc(int** rowptr, int rows){
	for(int i = 0; i < rows; i++){
		free((rowptr[i]));
	}
	free(rowptr);
}

/* Segunda solución: haciendo un solo malloc
 */
 //~ 
int** my2DAlloc2(int rows, int cols){
	int header = (rows * sizeof(int*));//punteros al principio de las columnas
	int data = (rows * cols * sizeof(int));	//espacio para cada columna
	int** rowptr = (int**)malloc(header + data);
	if(rowptr == NULL) return NULL;
	
	int * buf = (int*)(rowptr + rows); //primera posición de memoria reservada para datos
	for(int i = 0; i < rows; i++){
		rowptr[i] = buf + i * cols;
	}
	return rowptr;
}

int main(){
	int ** matrix = my2DAlloc(5, 6);
	free2DAlloc(matrix, 5);
	
	int ** matrix2 = my2DAlloc2(5, 6);
	free(matrix2);

}
