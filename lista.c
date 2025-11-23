#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct ListaE {
    NodoPtr primero;
};

///Funciones primitivas de la LISTA
ListaPtr crearLista() {

    ListaPtr l = malloc(sizeof(struct ListaE));

    l->primero = NULL; //Primer nodo inicializamos como NULL

    return l;

}

void destruirLista(ListaPtr lista) {

    if(longitudLista(lista) == 0 || lista->primero == NULL) return;

    NodoPtr aux = lista->primero;
    NodoPtr aux2;

    while(aux != NULL) {

        aux2 = getSiguiente(aux); //Guardamos el nodo siguiente en un auxiliar
        destruirNodo(aux); //Liberamos el nodo
        aux = aux2; //Asignamos el siguiente auxiliar iterador

    }

    free(lista); //Por ultimo liberamos la lista

};


void insertarInicio(ListaPtr lista, void * dato) {

    NodoPtr n = crearNodo(dato);

    //2 6 7 3         5

    setSiguiente(n, lista->primero); //El nodo que queremos insertar va apuntar como siguiente nodo al que antes era el primero

    lista->primero = n; //Seteamos como el primero al nuevo nodo que creamos

};

void insertarFinal(ListaPtr lista, void * dato){

    if(longitudLista(lista) == 0) insertarInicio(lista, dato); // Si el tam es 0 es lo mismo insertar inicio o final
    else {

        NodoPtr n = crearNodo(dato); //El nuevo nodo que sera el ultimo apunta a NULL

        NodoPtr ult = getUltimo(lista);

        setSiguiente(ult, n); //Ahora teniendo el ultimo nodo hacemos que apunte como siguiente al nuevo nodo que creamos

    }

};

void insertarPosicion(ListaPtr lista, void * dato, int pos) {

    if(pos < 0 || pos > longitudLista(lista))  {
        printf("\nError: Posicion no valida, no se pudo insertar el dato!!\n");
        return; //Manejo de error, por si alguien ingresa una posicion no valida

    }

    if(pos == 1) insertarInicio(lista, dato); //Si es 1 quiere decir que el dato debe quedar primero, insertar al inicio
    else if (pos == longitudLista(lista)) insertarFinal(lista, dato);
    else {

        NodoPtr n = crearNodo(dato);
        NodoPtr aux = getPrimero(lista);

        for(int i=1; i<pos-1; i++) { //Nos paramos un nodo antes de la posicion a la que queremos ubicar al nuevo nodo
            aux = getSiguiente(aux);
        }

        setSiguiente(n, getSiguiente(aux)); //El siguiente del nuevo nodo es al que apunta aux
        setSiguiente(aux, n); //Y ahora el siguiente de aux es el nuevo nodo

    }


};


void removerInicio(ListaPtr lista) {

    if(longitudLista(lista) == 0) {
        printf("\nLa lista ya esta vacia\n");
        return;
    }

    NodoPtr sigte = getSiguiente(lista->primero);

    destruirNodo(lista->primero); //Libero el primero, por eso guarde el siguiente del primero antes

    lista->primero = sigte; //Ahora la lista va apuntar al siguiente del que antes era el primero pasando a ser el nuevo primero

};

void removerFinal(ListaPtr lista) {

    if(longitudLista(lista) == 0) {
        printf("\nLa lista ya esta vacia\n");
        return;
    }

    if(longitudLista(lista) == 1) removerInicio(lista);
    else {

        NodoPtr aux = lista->primero;

        for(int i=1; i<longitudLista(lista)-1; i++) { //Para seleccionar el anteultimo nodo
            aux = getSiguiente(aux);
        }

        destruirNodo(getUltimo(lista)); //Elimino el ultimo

        setSiguiente(aux, NULL); //El que antes era anteultimo pasa a ser ultimo apuntando a NULL

    }

};

void removerPosicion(ListaPtr lista, int pos) {

    if(pos < 0 || pos > longitudLista(lista))  {
        printf("\nError: Posicion no valida, no se pudo remover el dato!!\n");
        return; //Manejo de error, por si alguien quiere eliminar una posicion no valida
    }

    if(longitudLista(lista) == 0 || pos == 1) removerInicio(lista);
    else if(pos == longitudLista(lista)) removerFinal(lista);
    else {

        NodoPtr nodoAnterior = getPosicion(lista, pos-1); //Traemos el nodo anterior al que queremos eliminar
        NodoPtr nodoEliminar = getPosicion(lista, pos); //Traemos el nodo que queremos eliminar

        setSiguiente(nodoAnterior, getSiguiente(nodoEliminar)); //Enganchamos la lista, el sig del anterior que queremos eliminar ahora apunta al siguiente del que queremos eliminar

        destruirNodo(nodoEliminar); //Liberamos la memoria del nodo

    }

};


NodoPtr getPrimero(ListaPtr lista) {
    return lista->primero;
};

NodoPtr getUltimo(ListaPtr lista) {

    NodoPtr aux = lista->primero;

    while(getSiguiente(aux) != NULL) { //Con este while llegamos hasta el ultimo nodo de la lista
        aux = getSiguiente(aux);
    }

    return aux;

};

NodoPtr getPosicion (ListaPtr lista, int pos) {

    if(pos <= 0 || pos > longitudLista(lista))  {
        printf("\nError: Posicion no valida, no se pudo obtener el dato!!\n");
        return NULL; //Manejo de error, por si alguien quiere obtener una posicion no valida
    }

    if(longitudLista(lista) == 1) return getPrimero(lista);
    else if(longitudLista(lista) == pos) return getUltimo(lista);
    else {

        NodoPtr aux = lista->primero;

        for(int i=1; i<pos; i++) { //Recorremos hasta un nodo antes del que queremos
            aux = getSiguiente(aux);
        }

        return aux;

    }

    return NULL;

};


void setPrimero(ListaPtr lista, NodoPtr nodo) {
    lista->primero = nodo;
};

int longitudLista(ListaPtr lista) {

    NodoPtr aux = lista->primero;
    int tam = 0;

    while(aux != NULL) {
        tam++;
        aux = getSiguiente(aux);
    }

    return tam;
};

void mostrarListaGenerico(ListaPtr lista, void (*mostrarFuncionPtr)(void *) ) {

    NodoPtr actual = lista->primero;

    while(actual != NULL) {
        (*mostrarFuncionPtr)(getDato(actual)); //Desreferenciamos el ptr a funcion que viene por parametro y la llamamos
        actual = getSiguiente(actual);
    }

};

void ordenarLista(ListaPtr lista, int(*funcionComparar)(void *, void *) ) {

    int permutacion;
    NodoPtr nodo;
    NodoPtr ultimo = NULL;

    if(longitudLista(lista) < 2) return; //Ya esta ordenada, no hago nada

    do {

        permutacion = 0;
        nodo = lista->primero;

        while(getSiguiente(nodo) != ultimo) {

            if( funcionComparar( getDato(nodo), getDato(getSiguiente(nodo)) ) ) {

                void * aux = getDato(nodo);
                setDato(nodo, getDato(getSiguiente(nodo)));
                setDato(getSiguiente(nodo), aux);
                permutacion = 1;

            }

            nodo = getSiguiente(nodo);
        }

        ultimo = nodo;

    } while(permutacion != 0);

};

void ordenarLista2(ListaPtr lista, int(*funcionComparar)(void *, void *)) {

    NodoPtr actual;

    for(int i=0; i<longitudLista(lista); i++) {

        actual = lista->primero; //Cada vez que entro en una interacion de i, vuelvo al primer elemento para comparar toda la lista

        for(int j=0; j<longitudLista(lista)-1; j++) {

            if( funcionComparar( getDato(actual), getDato(getSiguiente(actual)) ) ) {

                void * aux = getDato(actual);
                setDato(actual, getDato(getSiguiente(actual)));
                setDato(getSiguiente(actual), aux);

            }

            actual = getSiguiente(actual);
        }

    }
}

ListaPtr duplicarLista(ListaPtr lista) {

    if(!lista) return NULL;

    ListaPtr listaDuplicado = crearLista();

    NodoPtr actual = lista->primero;

    while(actual != NULL) {

        insertarFinal(listaDuplicado, getDato(actual));

        actual = getSiguiente(actual);
    }

    return listaDuplicado;

};

void mostrarInt(void * dato) {

    int d = *(int*) dato;

    printf("%d | ", d);

};

int compararInt(void * d1, void * d2) {

    int entero1 = *(int*)d1;
    int entero2 = *(int*)d2;

    return entero1 > entero2;

};














