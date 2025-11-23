#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pila.h"
#include "cola.h"

int main()
{
    ListaPtr lista = crearLista();

    int a=25, b=52, c=71, d=8, e=5, f=4, g=3;

    insertarInicio(lista, &a); //5 71 52 25 3 8 4
    insertarInicio(lista, &b);
    insertarInicio(lista, &c);
    insertarFinal(lista, &d);
    insertarInicio(lista, &e);
    insertarFinal(lista, &f);
    insertarPosicion(lista, &g, 5);

    //removerFinal(lista);
    //removerInicio(lista);
    //removerPosicion(lista, 4);

    printf("\nLongitud de la lista: %d", longitudLista(lista));
    printf("\nEl ultimo de la lista es: %d\n\n",  *(int *)getDato( getUltimo(lista) ) );

    ordenarLista2(lista, &compararInt);

    mostrarListaGenerico(lista, &mostrarInt); //No enviamos los parametros porque no queremos llamarla, solo enviarle la referencia de la funcion

    ListaPtr listaDuplicada = duplicarLista(lista);

    printf("\n");
    mostrarListaGenerico(listaDuplicada, &mostrarInt);

    destruirLista(lista);
    destruirLista(listaDuplicada);

    printf("\n\n---------------------------------------------------------------------\n");

    PilaPtr pila = crearPila();

    int aa=2, bb=3, cc=4;

    apilar(pila, &aa);
    apilar(pila, &bb);
    apilar(pila, &cc);

    printf("\nDesapilo el %d", *(int*)desapilar(pila) );
    printf("\nDesapilo el %d", *(int*)desapilar(pila) );
    printf("\nDesapilo el %d", *(int*)desapilar(pila) );

    printf("\n\n---------------------------------------------------------------------\n");

    ColaPtr cola = crearCola();

    int aaa=22, bbb=31, ccc=41;

    encolar(cola, &aaa);
    encolar(cola, &bbb);
    encolar(cola, &ccc);

    printf("\nDesencolo el %d", *(int*)desencolar(cola) );
    printf("\nDesencolo el %d", *(int*)desencolar(cola) );
    printf("\nDesencolo el %d", *(int*)desencolar(cola) );
    printf("\nDesencolo el %d", *(int*)desencolar(cola) );

    destruirCola(cola);


    return 0;
}









