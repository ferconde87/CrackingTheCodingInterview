#include <iostream>
#include "./../5BitManipulation/BitManipulation.h"

using namespace std;

//1era aproximación
//~ void* aligned_malloc(size_t required_bytes, size_t alignment){
	//~ int offset = alignment - 1;
	//~ void* p = (void*) malloc(required_bytes + offset);
	//~ void* q = (void*) (((size_t)(p) + offset) &  ~(alignment - 1));
	//~ return q;
//~ }

//solución guardandonos el inicio del bloque de memoria pedida
//para posteriormente liberar toda la memoria

/* to guarantee both an aligned address and space for this pointer, we will need to allocate an addi­
tional alignment - 1 + sizeof(void*) bytes. */
void* aligned_malloc(size_t required_bytes, size_t alignment){
	void * p1; //initial block
	void * p2; //aligned block inside intial block
	int offset = alignment - 1 + sizeof(void*);
	if((p1 = (void*)malloc(required_bytes + offset)) == NULL){
		return NULL;
	}
	p2 = (void*) (((size_t)(p1) + offset) &  ~(alignment - 1));
	((void**)p2)[-1] = p1; //guardamos el inicio del bloque de memoria original pedido	
	return p2;
}

void aligned_free(void *p2){
	/* for consistency, we use the same names as aligned_malloc */
	void *p1 = ((void**)p2)[0];
	free(p1);
}

void * p1; //initial block
void * p2; //aligned block inside intial block

void* aligned_malloc2(size_t required_bytes, size_t alignment){
	int offset = alignment - 1 + sizeof(void*);
	if((p1 = (void*)malloc(required_bytes + offset)) == NULL){
		return NULL;
	}
	p2 = (void*) (((size_t)(p1) + offset) &  ~(alignment - 1));
	((void**)p2)[-1] = p1; //guardamos el inicio del bloque de memoria original pedido	
	return p2;
	
}


int main(){
	///ejemplo: 
	//posición de memoria: 100
	//offset 15
	//entre 100 y 115 va a haber una posición de memoria multiplo de 16
	int num = 100;
	int offset = 15;
	for(int i = 0; i <= offset; i++){
		printBits(num+i);
	}
	//00000000000000000000000001110000 memoria multiplo de 16
	
	//original
	void* p = aligned_malloc(100, 16);
	aligned_free(p);
	
	//recuperando el inicio del bloque a mano
	void* p4 = aligned_malloc(100, 16);
	void* p3 = ((void**)p4)[-1];//acá recupero donde empezó el pedido a malloc
	free(p3);//libero ;)
	
	//lo mismo con variables globales
	p2 = aligned_malloc2(100, 16);
	free(p1);
}
