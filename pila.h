#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "nodo.h"

struct Pila; //LIFO

typedef struct Pila * PilaPtr;

PilaPtr crearPila();

void apilar(PilaPtr pila, void * dato);

void * desapilar(PilaPtr pila);

#endif // PILA_H_INCLUDED
