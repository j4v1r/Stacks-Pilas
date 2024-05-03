/*
TADPilaEst.c
V 1.0 Abril 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro

Programa que define las funciones que fueron declaradas en "TADPilaEst.h"

Compilaci�n:
gcc Main.c TADPilaEst.c -o prog
prog
*/

#include <stdlib.h>
#include <stdio.h>
#include "TADPilaEst.h"

/*
Inicializar pila (Initialize): recibe<- pila (s); 
Initialize(s);
Efecto: Recibe una pila y la inicializa para su trabajo normal.
*/
void Initialize(pila *s)
{
	(*s).tope=-1; //s->tope=-1;
	return;
}

/*
Empilar (Push): recibe<- pila (s); recibe<- elemento (e) 
Push(s,e);
Efecto: Recibe la pila y aumenta su tamaño, poniendo el elemento en la cima de la pila.
*/
void Push(pila *s,elemento e)
{
	if(s->tope<MAX_ELEMENT-1)
	{
		s->tope++;
		s->arreglo[s->tope]=e; //(*s).A[(*s).tope]=e;
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
Excepción: si la pila esta vacía, produce error.
*/
elemento Pop(pila *s)
{
	elemento r;
	if(s->tope!=-1)
	{
		r=s->arreglo[s->tope];
		s->tope--;
	}
	else //Subdesbordamiento de la pila
	{
		printf("\nERROR e=Pop(s):\"Subdesbordamiento de pila\"");
		exit(1);			
	}
	
	return r;
}

/*
Es vacía (Empty): recibe<- pila (s); retorna -> boolean
b=Empty(s);
Efecto: Recibe una pila y devuelve true si esta vacía y false en caso contrario.
*/
boolean Empty(pila *s)
{
	boolean r;
	if(s->tope!=-1)
		r=FALSE;
	else
		r=TRUE;
	
	return r;
}


/*
Tope pila (Top): recibe<- pila (s); retorna -> elemento
e=Top(s);
Efecto: Devuelve el elemento cima de la pila.
Excepción: si la pila esta vacía produce error
*/
elemento Top(pila *s)
{
	elemento r;
	if(s->tope!=-1)
	{
		r=s->arreglo[s->tope];
	}
	else //Subdesbordamiento de la pila
	{
		printf("\nERROR e=Top(s):\"Subdesbordamiento de pila\"");
		exit(1);			
	}
	
	return r;
}


/*
Tamaño pila (size): recibe<- pila (s); retorna -> tamaño de la pila (entero)
n=size(s);
Efecto: Devuelve el número de elementos que contiene la pila (Altura de la pila).
*/
int Size(pila *s)
{
	int r;
	r=s->tope+1;
	return r;
}

/*
Eliminar pila (Destroy): recibe<- pila (s)
Destroy(s);
Efecto: Recibe una pila y la libera completamente
*/
void Destroy(pila *s)
{
	Initialize(s);
	return;
}

/*
Elemento n de pila (Element): recibe <- pila (s); recibe <- numero n
Element(s, n);
Efecto: Regresa el elemento en la posici�n n de la pila 
*/
elemento Element(pila *s, int n){
	elemento r;
	r=s->arreglo[n-1];
	return r;
}

/*
Invertir la pila (Flip): recibe <- pila (s);
Flip(s);
Efecto: Invierte los elementos de la pila de tal manera que el �ltimo se
convierte en el primero y el primero en el �ltimo
*/
void Flip(pila *s){
	elemento aux;
	int i, j;
	int tam = Size(s);
	for(i=0, j=tam-1; i<tam/2; i++, j--){
		aux=s->arreglo[i];
		s->arreglo[i]=s->arreglo[j];
		s->arreglo[j]=aux;
	}
}
