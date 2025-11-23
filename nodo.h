#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

///Estructura y tipo de dato del NODO
struct NodoE;
typedef struct NodoE * NodoPtr;

///Funciones primitivas del NODO
NodoPtr crearNodo(void * dato);
void destruirNodo(NodoPtr nodo);

void * getDato(NodoPtr nodo);
void setDato(NodoPtr nodo, void * dato);

NodoPtr getSiguiente(NodoPtr nodo);
void setSiguiente(NodoPtr nodo, NodoPtr sigNodo);

#endif // NODO_H_INCLUDED
