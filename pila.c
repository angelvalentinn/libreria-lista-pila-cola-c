#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

///¡El primer elemento de la pila es el de arriba de todo!

struct Pila {
    NodoPtr primero;
};

PilaPtr crearPila() {

    PilaPtr p = malloc(sizeof(struct Pila));

    if(!p) {
        printf("\nNo se pudo reservar memoria para pila\n");
        return NULL;
    }

    p->primero = NULL;

    return p;

};

///Se inserta en la cima de la pila
void apilar(PilaPtr pila, void * dato) { //APILAR == INSERTAR INICIO (Por que es la cima de la pila)

    NodoPtr n = crearNodo(dato); //Nodo que va a pasar a ser el primero

    setSiguiente(n, pila->primero); //Hacemos que el siguiente del nuevo nodo sea el que antes era el primero

    pila->primero = n; //Ahora setamos como primero al nuevo nodo

};

///¡SE DESAPILA DESDE ARRIBA DE TODO, EL ULTIMO QUE ENTRO, OSEA EL PRIMERO DE LA PILA!
void * desapilar(PilaPtr pila) { //DESAPILAR == REMOVER INICIO (Remueve el elemento de mas arriba)

    if(pila->primero == NULL) {
        printf("\nLa pila ya esta vacia!\n");
        return NULL;
    }

    NodoPtr seg = getSiguiente(pila->primero); //Guardamos el puntero al segundo nodo, que va a pasar a ser el primero

    void * datoADesapilar = getDato(pila->primero); //Guardamos el dato del ultimo que entro antes de destruirlo

    destruirNodo(pila->primero); //Eliminamos el ultimo nodo que entro (El que esta en la cima de la pila)

    pila->primero = seg; //Seteamos como primer nodo al que antes era el segundo nodo

    return datoADesapilar;

};



