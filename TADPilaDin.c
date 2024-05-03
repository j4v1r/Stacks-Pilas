/*
TADPilaDin.c
V 1.0 Abril 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro

Programa que define las funciones que fueron declaradas en "TADPilaDin.h"

CompilaciÛn:
gcc MainDin.c TADPilaDin.c -o prog
prog
*/

#include <stdlib.h>
#include <stdio.h>
#include "TADPilaDin.h"

/*
Inicializar pila (Initialize): recibe<- pila (s); 
Initialize(s);
Efecto: Recibe una pila y la inicializa para su trabajo normal.
*/
void Initialize(pila *s)
{
	s->size=0;
	(*s).tope=NULL;
	return;
}

/*
Empilar (Push): recibe<- pila (s); recibe<- elemento (e) 
Push(s,e);
Efecto: Recibe la pila y aumenta su tama√±o, poniendo el elemento en la cima de la pila.
*/
void Push(pila *s,elemento e)
{
	nodo *aux;
	
	aux=malloc(sizeof(nodo));
	
	if(aux!=NULL)
	{
		s->size++;
		aux->e=e;
		aux->abajo=s->tope;
		s->tope=aux;
	}
	else //Desbordamiento de pila
	{
		printf("\nERROR Push(s,e):\"Desbordamiento de pila\"");
		exit(1);	
	}
	return;
}

/*
Desempilar (Pop): recibe<- pila (s); retorna -> elemento
e=Pop(s);
Efecto: Recibe la pila, remueve el elemento tope y lo retorna.
Excepci√≥n: si la pila esta vac√≠a, produce error.
*/
elemento Pop(pila *s)
{
	elemento r;
	nodo* aux;
	if(s->tope!=NULL)
	{
		r=s->tope->e;
		aux=s->tope;
		s->tope=s->tope->abajo; //s->tope=aux->abajo
		free(aux);
		s->size--;
	}
	else //Subdesbordamiento de la pila
	{
		printf("\nERROR e=Pop(s):\"Subdesbordamiento de pila\"");
		exit(1);			
	}
	
	return r;
}

/*
Es vac√≠a (Empty): recibe<- pila (s); retorna -> boolean
b=Empty(s);
Efecto: Recibe una pila y devuelve true si esta vac√≠a y false en caso contrario.
*/
boolean Empty(pila *s)
{
	boolean r;
	if(s->tope!=NULL)
		r=FALSE;
	else
		r=TRUE;
	
	return r;
}


/*
Tope pila (Top): recibe<- pila (s); retorna -> elemento
e=Top(s);
Efecto: Devuelve el elemento cima de la pila.
Excepci√≥n: si la pila esta vac√≠a produce error
*/
elemento Top(pila *s)
{
	elemento r;
	if(s->tope!=NULL)
	{
		r=s->tope->e;
	}
	else //Subdesbordamiento de la pila
	{
		printf("\nERROR e=Top(s):\"Subdesbordamiento de pila\"");
		exit(1);			
	}
	
	return r;
}


/*
Tama√±o pila (size): recibe<- pila (s); retorna -> tama√±o de la pila (entero)
n=size(s);
Efecto: Devuelve el n√∫mero de elementos que contiene la pila (Altura de la pila).
*/
int Size(pila *s)
{
	int r=s->size;
	
	return r;
}

/*
Eliminar pila (Destroy): recibe<- pila (s)
Destroy(s);
Efecto: Recibe una pila y la libera completamente
*/
void Destroy(pila *s)
{
	nodo *aux;
	if(s->tope!=NULL)
	{
		do
		{
			aux=s->tope->abajo;
			free(s->tope);
			s->tope=aux;	
		}while(aux!=NULL);
	}
	s->size=0;
	return;
}

/*
Elemento n de pila (Element): recibe <- pila (s); recibe <- numero n
Element(s, n);
Efecto: Regresa el elemento en la posiciÛn n de la pila 
*/
elemento Element(pila *s, int n){
	nodo *aux;
	elemento r;
	int i, size=Size(s);
	//printf("Pasa a element");
	
	for(i=0; i<=size-n; i++){
		//printf("\tEntra a for y i=%i", i);
		if(i==0){
			//printf("\tEntra al tope\n");
			aux=s->tope;
		}else{
			//printf("\tEntra al debajo del tope\n");
			aux=aux->abajo;
		}
	}
	
	
	//printf("\nEl pointer del elemento %i es: %p", n, aux);
	//printf("Acaba for\n");
	r=aux->e;
	
	return r;
}

/*
Apuntador del nodo donde est· el elemento n de pila (*Pointer): 
recibe <- pila (s); recibe <- numero n
*Pointer(s, n);
Efecto: Regresa el nodo del elemento en la posiciÛn n de la pila 
*/
nodo* Pointer(pila *s, int n){
	nodo *r;
	int i, size=Size(s);
	//printf("Pasa a element");
	
	for(i=0; i<=size-n; i++){
		//printf("\tEntra a for y i=%i", i);
		if(i==0){	
			//printf("\tEntra al tope\n");
			r=s->tope;
		}else{
			//printf("\tEntra al debajo del tope\n");
			r=r->abajo;
		}
	}
	
	return r;
}

/*
Invertir la pila (Flip): recibe <- pila (s);
Flip(s);
Efecto: Invierte los elementos de la pila de tal manera que el ˙ltimo se
convierte en el primero y el primero en el ˙ltimo
*/
void Flip(pila *s){
	elemento aux;
	int i, j;
	int tam = Size(s);
	//printf("------------------Pasa a pila y tamano--------------");
	for(i=0, j=tam; i<tam/2; i++, j--){
		aux=Element(s, i+1);
		//printf("\nEl elemento %i es %i",i+1, aux);
		//printf("\n%p", Pointer(s, i+1));
		
		Pointer(s, i+1)->e=Element(s, j);
		Pointer(s, j)->e=aux;
	}
}


