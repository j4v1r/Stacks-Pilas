/*
TADPilaEst.h
V 1.0 Abril 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro

Archivo de cabecera que declara los tipos de datos boolean, 
el tamaño máximo de la pila, sus estrcturas y funciones para 
manejar la misma (prototipos)
*/

//DEFINICIONES DE CONSTANTES
#define MAX_ELEMENT 1000
#define TRUE 1
#define FALSE 0

//DEFINCIONES DE TIPO DE DATO
//Definir un boolean (Se modela con un "char")
typedef unsigned char boolean;

//Definir un elemento(Se modelo con una estructura "elemento")
typedef struct elemento{
	//Variables de la estructura "elemento" (El usuario puede modificar)
	int c;
}elemento;


//Definir una pila (Se modela con una estructura que unicamente incluye un puntero a "elemento")
typedef struct pila{
	elemento arreglo[MAX_ELEMENT];//La pila es un arreglo estático de MAX_ELEMENT
	int tope; //El tope es un entero (Indice del arreglo de elementos)
}pila;


//DECLARACIÓN DE FUNCIONES
void Initialize(pila *s); //Inicializar pila (Iniciar una pila para su uso)
void Push(pila *s, elemento e); //Empilar(Introducir un elemento a la pila)
elemento Pop(pila *s); //Desempilar (Extraer un elemento de la pila)
boolean Empty(pila *s); //Vacía (Preguntar si la pila está vacía)
elemento Top(pila *s); //Tope (Obtener el "elemento" del tope de la pila sin extraerlo de la pila)
int Size(pila *s); //Tamaño de la pila (Obtener el número de elementos de la pila)
void Destroy(pila *s); //Elimina pila (Borra a todos los elementos y a la pila de la memoria)
elemento Element(pila *s, int n); //Operación de consulta (Retorna el elemento n en la pila)
void Flip(pila *s); //Operación modificadora (Invierte la pila que se recibe)
