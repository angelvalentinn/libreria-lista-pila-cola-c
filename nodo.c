#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

struct NodoE {
    void * dato; //Dato almacenado, puede ser por ej un INT, CHAR, FLOAT, STRUCT
    NodoPtr sig; //Puntero al siguiente Nodo
};

NodoPtr crearNodo(void * dato) {

    NodoPtr n = malloc(sizeof(struct NodoE));

    if(!n)  {
        printf("\nNo se pudo reservar memoria para el nodo\n");
        return NULL; //Manejo de error, por si no se pudo reservar memoria
    }

    n->dato = dato;
    n->sig = NULL;

    return n;

};

void destruirNodo(NodoPtr nodo) {
    free(nodo);
};

void * getDato(NodoPtr nodo){
    return nodo->dato;
};

NodoPtr getSiguiente(NodoPtr nodo) {
    return nodo->sig;
};

void setDato(NodoPtr nodo, void * dato) {
    nodo->dato = dato;
};

void setSiguiente(NodoPtr nodo, NodoPtr sigNodo) {
    nodo->sig = sigNodo;
};
