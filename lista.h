#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "nodo.h"

///Estructura y tipo de dato de la LISTA
struct ListaE;
typedef struct ListaE * ListaPtr;

///Funciones de la LISTA
ListaPtr crearLista();
void destruirLista(ListaPtr lista);

void insertarInicio(ListaPtr lista, void * dato);
void insertarFinal(ListaPtr lista, void * dato);
void insertarPosicion(ListaPtr lista, void * dato, int pos);

void removerInicio(ListaPtr lista);
void removerFinal(ListaPtr lista);
void removerPosicion(ListaPtr lista, int pos);

NodoPtr getPrimero(ListaPtr lista);
NodoPtr getUltimo(ListaPtr lista);
NodoPtr getPosicion (ListaPtr lista, int pos);

int longitudLista(ListaPtr lista);
void mostrarListaGenerico(ListaPtr lista, void (*mostrarFuncionPtr)(void *) );
void ordenarLista(ListaPtr lista, int(*funcionComparar)(void *, void *) ); //Por parametro un puntero a la funcion que compara
void ordenarLista2(ListaPtr lista, int(*funcionComparar)(void *, void *)); //Bubble sort
ListaPtr duplicarLista(ListaPtr lista);

void mostrarInt(void * dato); //Si esto fuera un struct por ej Persona, se coloca en el tda de la persona
int compararInt(void * d1, void * d2);

NodoPtr getPrimero(ListaPtr lista);
void setPrimero(ListaPtr lista, NodoPtr nodo);


#endif // LISTA_H_INCLUDED
