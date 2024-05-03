/*
TADPilaDin.h
V 1.0 Abril 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro

Archivo de cabecera que declara los tipos de datos boolean, 
las estrcturas de la pila y las funciones para manejar la
misma (prototipos)
*/

//DEFINICIONES DE CONSTANTES
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


//Definir un nodo que será utilizado para almacenar una posicióm de la pila (Nodo), lo que
//incluira a un elemento y a un apuntador al siguiente nodo
typedef struct nodo{
	
	elemento e;    //Elemento a almacenar en cada nodo de la pila
	struct nodo *abajo; //Apuntador al elemento de debajo
}nodo;


//Definir una pila (Se modela con una estructura que unicamente incluye un puntero a "elemento")
typedef struct pila{
	
	int size;
	nodo *tope; //Apuntador al elemento en el tope de la fila
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
nodo *Pointer(pila *s, int n); //Operación de consulta (Retorna el apuntador del elemento n en la pila)
void Flip(pila *s); //Operación modificadora (Invierte la pila que se recibe)

