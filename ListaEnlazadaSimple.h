#include "Nodo.h"
#include<iostream>
#include <string>

using namespace std;

class ListaEnlazadaSimple{
    private:
        Nodo *cabeza;//Primer elemento de la lista
        Nodo *cola;//�ltimo elemento de la lista
        int numElementos;//Variable que contara el numero de elementos  de la lista

    public:
       ListaEnlazadaSimple(); //Constructor
       ~ListaEnlazadaSimple(); //Destructor
       void imprimirElementos(); //M�todo que sirve para imprimir los elementos de la lista
       void insertarElemento(int numero); // M�todo que sirve para agregar un elemento a la lista
       void contarOcurrencias(); //M�todo que sirve para contar el n�mero de ocurrencias de un elemento en la lista
       void obtenerElemento(); //M�todo para obtener el valor de un nodo que se encuentra en la posicion P
       void borrarCabeza(); //M�todo que sirve para borrar el nodo cabeza de una lista
       void invertirLista(); //M�todo que invierte los elementos de una lista, a partir de un �ndice dado
       int obtenerPrimero(); // M�todo para obtener el valor del primer elemento de la lista
       int getNumElementos(); //Funci�n que retorna el n�mero de elementos de la lista
};

//Constructor
ListaEnlazadaSimple::ListaEnlazadaSimple()
{
    cabeza = nullptr;
    cola = nullptr;
    numElementos = 0;
}

//Destructor
ListaEnlazadaSimple::~ListaEnlazadaSimple(){
    Nodo *aux1;//Nodo auxiliar
    Nodo *aux2;//Nodo auxliar

    //aux1 es igual a cabeza, esto es para poder recorrer la lista
    aux1 = cabeza;

    //Se recorre la lista y se eliminan los elementos(nodos) de la misma
    while(aux1 != nullptr)
    {
        aux2 = aux1;
        aux1 = aux1->getSig();
        delete aux2;
    }

    //Se decrementa el n�mero de elementos de la lista
    numElementos--;
}

//M�todo para agregar un nuevo elemento a la lista
void ListaEnlazadaSimple::insertarElemento(int numero)
{
    //Creaci�n de un objeto de tipo nodo
    Nodo *nodo = new Nodo(numero);

    if(cabeza == nullptr)
    {
        cabeza = nodo;
        cola = nodo;
        cabeza->setSig(nullptr);
        cola->setSig(nullptr);
    }
    else
    {
        cola->setSig(nodo);
        cola = nodo;
    }
    //Se aumenta en 1 el n�mero de elementos de la lista
    numElementos++;
}

//M�todo para imprimir los elementos de la lista
void ListaEnlazadaSimple::imprimirElementos()
{
    Nodo *aux;

    aux = cabeza;

    if(aux == nullptr)
        cout<<"\nLa lista esta vacia\n"<<endl;
    else
    {
        cout<<"\nLos elementos de la lista son los siguientes\n";

        //Imprime y recorre el valor de los nodos de la lista
        while(aux != nullptr)
        {
            cout<<aux->getElemento()<<endl;
            aux = aux->getSig();
        }

    }

    cout<<endl;
}


//M�todo para obtener el i�simo elemento de una lista
void ListaEnlazadaSimple::obtenerElemento()
{
    cout<<"Ejercicio 1: Valor de un nodo en la posicion n�sima de una lista"<<endl;

    bool encontrado = false;
    int n, p;
    Nodo *aux;

    aux = cabeza;
    p = 0;

    //Se pide la informaci�n
    cout<<"\nIngrese una posicion: ";
    cin>>n;

    while(aux != nullptr && p<=n)
    {
        if(p == n)
        {
            cout<<"\nEl elemento que se encuentra en la posicion "<<n<<" de la lista es "<<aux->getElemento()<<endl;
            encontrado = true;
            break;
        }

        p++;
        aux = aux->getSig();
    }

    if(encontrado == false)
        cout<<"\nLa lista no tiene posicion "<<n<<endl;

}


//M�todo que sirve para contar el n�mero de ocurrencias de un valor en la lista
void ListaEnlazadaSimple::contarOcurrencias()
{
    cout<<"Ejercicio 2: Contar el numero de ocurrencias de un valor en la lista"<<endl;

    int numOcurrencias = 0; //Contador del numero de ocurrencias de un n�mero en la lista
    int n;//Variable que es la que se tomara para contar el n�mero de ocurrencias
    Nodo *aux; //Auxiliar para recorrer la lista

    aux = cabeza;

    //Se pide que se ingrese un numero
    cout<<"\nIngrese un numero: ";
    cin>>n;

    while(aux != nullptr)
    {
        //Se verifica si se da la ocurrencia
        if(aux->getElemento() == n)
        {
            numOcurrencias++;
        }
        //Se pasa al siguiente nodo
        aux = aux->getSig();
    }

    //Se imprime el numero de ocurrencias
    cout<<"\nEl numero de veces que se repite el numero "<<n<<" en la lista es "<<numOcurrencias;

}


//M�todo para obtener el primer valor de la lista
int ListaEnlazadaSimple::obtenerPrimero()
{
    if(cabeza == nullptr)
    {
        cout<<"\nLa lista esta vacia, no se puede obtener el primer elemento"<<endl;
        return -1;
    }

    return cabeza->getElemento();
}


//Funci�n que retorna el n�mero de elementos que hay en la lista
int ListaEnlazadaSimple::getNumElementos()
{
    return numElementos;
}


//Funci�n que sirve para borrar el nodo cabeza de una lista
void ListaEnlazadaSimple::borrarCabeza()
{
    Nodo *aux;

    aux = cabeza;

    cabeza = cabeza->getSig();

    numElementos--;

    delete aux;
}

//M�todo que invierte los elementos de una lista a partir de un �ndice dado
void ListaEnlazadaSimple::invertirLista()
{
    bool encontrado = false;
    int n, i = 0;
    Nodo *aux = cabeza;

    Nodo *anterior = nullptr;
    Nodo *actual;
    Nodo *siguiente;

    //Se pide que se ingrese un numero (que ser� el �ndice de la lista)
    cout<<"\nIngrese un numero: ";
    cin>>n;


    while(aux != nullptr)
    {
        if(i == n)
        {
            //M�todo para invertir la lista
            actual = aux;
            while(actual != nullptr)
            {
                siguiente = actual->getSig();
                actual->setSig(anterior);
                anterior = actual;
                actual = siguiente;
            }

            Nodo *aux1 = cabeza;
            cabeza = cola;
            cola = aux1;

            encontrado = true;
            break;
        }
        else
        {
            i++;
            aux = aux->getSig();
        }
    }

    if(encontrado == false)
    {
        cout<<"\nLa lista no tiene un indice "<<n<<endl;
    }
    else
    {
        cout<<"\nLa lista fue invertida"<<endl;
    }

}
