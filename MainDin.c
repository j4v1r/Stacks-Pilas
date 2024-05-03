/*
MainDin.c
V 1.0 Abril 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro

Programa que implementa la pila dinámica y sus distintos métodos

Compilación:
gcc MainDin.c TADPilaDin.c -o prog
prog
*/

#include<stdio.h>
#include<stdlib.h>
#include "TADPilaDin.h"

int main(){
	
	int i;
	
	pila mi_pila;
	elemento e1={5};
	elemento e2={6};
	elemento e3={7};
	elemento e4={8};
	elemento e5={9};
	
	Initialize(&mi_pila);
	Push(&mi_pila, e1);
	Push(&mi_pila, e2);
	Push(&mi_pila, e3);
	Push(&mi_pila, e4);
	Push(&mi_pila, e5);
	
	
	int tamano = Size(&mi_pila);
	
	printf("El tamano de la pila es: %i\n", tamano);
	
	for(i=1; i<=tamano; i++){
		printf("El elemento %i de la pila es: %i\n", i, Element(&mi_pila, i));
	}
	
	printf("Se remueve un elemento\n");
	Pop(&mi_pila);
	
	printf("La pila es vacia: %i\n", Empty(&mi_pila));
	
	printf("El elemento top es: %i\n", Top(&mi_pila));
	
	printf("------------Se voltea la pila--------------------\n");
	
	Flip(&mi_pila);
	
	for(i=1; i<=tamano; i++){
		printf("El elemento %i de la pila es: %i\n", i, Element(&mi_pila, i));
	}
	
	
	return 0;
}
