#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "nodo.h"

//¡El PRIMERO EN ENTRAR, OSEA EL PRIMERO DE LA COLA, ES EL PRIMERO EN SALIR!
struct Cola {
    NodoPtr primero;
    NodoPtr ultimo; //La cola no se puede recorrer, x eso agregamos el ultimo, en la cola solo interesan el primero y ultimo
};

ColaPtr crearCola() {

    ColaPtr cola = malloc(sizeof(struct Cola));

    if(!cola) {
        printf("\nNo se pudo reservar memoria para la cola\n");
        return NULL;
    }

    cola->primero = NULL;
    cola->ultimo = NULL;

    return cola;
};

void encolar(ColaPtr cola, void * dato) { //ENCOLAR == INSERTAR ULTIMO

    NodoPtr n = crearNodo(dato);

    if(cola->primero == NULL) {
        cola->primero = n; //Si la cola esta vacia, el primero y ultimo son el mismo
        cola->ultimo = n;
    } else {

        setSiguiente(cola->ultimo, n); //El que antes era el ultimo ahora apunta al nuevo nodo

        cola->ultimo = n; //Seteamos como ultimo al nuevo nodo

    }

};

NodoPtr desencolar(ColaPtr cola) { //DESENCOLAR == REMOVER INICIO

    if(cola->primero == NULL) {
        printf("\nLa cola ya esta vacia\n");
        return NULL;
    }

    NodoPtr seg = getSiguiente(cola->primero); //Guardamos el segundo nodo para luego setearlo como primero

    void * dato = getDato(cola->primero); //Guardamos el dato antes de eliminar el nodo

    destruirNodo(cola->primero); //Eliminamos el nodo

    cola->primero = seg; //Seteamos como primero al que antes era el segundo

    return dato;

};

void destruirCola(ColaPtr cola) {

    if(cola->primero != NULL) {
        printf("\nQuedan elementos en la cola, no se puede eliminar la cola!\n");
    } else {
        free(cola);
    }

};


