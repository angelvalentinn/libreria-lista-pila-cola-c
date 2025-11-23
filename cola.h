#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include "nodo.h"

struct Cola; //FIFO

typedef struct Cola * ColaPtr;

ColaPtr crearCola();

void encolar(ColaPtr cola, void * dato);

NodoPtr desencolar(ColaPtr cola);

void destruirCola(ColaPtr cola);

#endif // COLA_H_INCLUDED
