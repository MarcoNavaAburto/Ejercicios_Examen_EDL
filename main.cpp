#include<iostream>
#include "ListaEnlazadaSimple.h"
//#include "Nodo.h"

using namespace std;

//Función para trasladar una lista a otra
void trasladarListas(ListaEnlazadaSimple &lista1, ListaEnlazadaSimple &lista2)
{
    int elemento;

    while(lista2.getNumElementos() > 0)
    {
        elemento = lista2.obtenerPrimero(); //Se obtiene el primer elemento de la segunda lista
        lista2.borrarCabeza(); // Se elimina la cabeza de la lista, para poder pasar al siguiente elemento de la lista
        lista1.insertarElemento(elemento); //El elemento que se obtuvo en la línea anterior se agrega a la segunda lista
    }

}


int main()
{
    //Creación de un objeto de tipo ListaEnlazadaSimple
    ListaEnlazadaSimple lista;
    ListaEnlazadaSimple l1, l2; //Creación de más objetos de tipo ListaEnlazadaSimple
    ListaEnlazadaSimple l3;

    //EJERCICIOS DE LA PRIMERA PARTE DEL EXAMEN (Ejercicios correspondientes al archivo EJERCICIOS TIPO EXAMEN)

    cout<<"\nEjercicios del archivo Ejercicios tipo examen"<<endl;

    //Se insertan elementos en la lista
    lista.insertarElemento(1);
    lista.insertarElemento(1);
    lista.insertarElemento(3);
    lista.insertarElemento(3);
    lista.insertarElemento(5);
    lista.insertarElemento(6);

    //Se imprimen los elementos de la lista
    lista.imprimirElementos();

    cout<<endl;

    //Método para determinar el valor que se encuentra en la posición P de la lista (Ejercicio 1 de la lista de Ejercicios tipo examen)
    lista.obtenerElemento();

    cout<<endl;

    //Método para contar las ocurrencias de un numero en la lista (Ejercicio 2 de la lista de Ejercicios tipo examen)
    lista.contarOcurrencias();

    cout<<endl;
    //Se eliminan los elementos de la lista
    lista.~ListaEnlazadaSimple();


    //INFORMACIÓN CORRESPONDIENTE A LA SEGUNDA PARTE DEL EXAMEN(EJERCICIOS DEL ARCHIVO EXAMEN PARCIAL PRACTICO)

    cout<<"\n\n\n\nEjercicios del archivo examen parcial practico"<<endl;

    //Se insertan elementos en la primera lista
    l1.insertarElemento(1);
    l1.insertarElemento(2);
    l1.insertarElemento(3);
    l1.insertarElemento(4);
    l1.insertarElemento(5);

    //Se insertan elementos en la segunda lista
    l2.insertarElemento(6);
    l2.insertarElemento(7);
    l2.insertarElemento(8);
    l2.insertarElemento(9);


    cout<<"\nAmbas listas antes de hacer el traslado"<<endl;

    //Ambas listas antes de hacer el traslado
    l1.imprimirElementos();
    l2.imprimirElementos();


    //Se invoca a la función que sirve para trasladar una lista hacia otra lista
    trasladarListas(l1, l2);

    cout<<"\nListas despues de hacer el traslado"<<endl;

    cout<<"\nLista 1\n"<<endl;
    l1.imprimirElementos();

    cout<<"\nLista 2\n"<<endl;
    l2.imprimirElementos();


    //Se borran los nodos de ambas listas, para liberar el espacio de memoria y este no se pierda
    l1.~ListaEnlazadaSimple();
    l2.~ListaEnlazadaSimple();

    cout<<"\nTodo bien en la primera parte"<<endl;


    cout<<"\n\nEjercicios del archivo Examen Parcial Practico"<<endl;

    //Se insertan los elementos en l3 (la tercera lista)
    l3.insertarElemento(10);
    l3.insertarElemento(11);
    l3.insertarElemento(12);
    l3.insertarElemento(13);
    l3.insertarElemento(14);
    l3.insertarElemento(15);

    cout<<"\nSe imprime la lista antes de invertirla"<<endl;
    //Se imprimen los elementos de la tercera lista
    l3.imprimirElementos();

    //Se invierten los elementos de la tercera lista
    l3.invertirLista();

    cout<<"\nSe imprime la lista despues de invertirla"<<endl;
    //Se imprime la lista después de invertirla
    l3.imprimirElementos();

    //Se borran los elementos de la lista 3
    l3.~ListaEnlazadaSimple();

    system("pause");
    return EXIT_SUCCESS;
}
