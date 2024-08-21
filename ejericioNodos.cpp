#include<iostream>
#include "Nodo.h"

using namespace std;

int main()
{
    //Creación de objetos de tipo Nodo
    Nodo *nodo1 = new Nodo(1);
    Nodo *nodo2 = new Nodo(2);
    Nodo *nodo3 = new Nodo(3);
    Nodo *nodo4 = new Nodo(4);
    Nodo *nodo5 = new Nodo(5);
    Nodo *nodo6 = new Nodo(6);
    Nodo *nodo7 = new Nodo(7);

    //Asignación de los nodos siguientes de los nodos
    nodo1->setSig(nodo2);
    nodo2->setSig(nodo3);
    nodo3->setSig(nodo4);
    nodo4->setSig(nodo1);
    nodo5->setSig(nodo2);
    nodo6->setSig(nodo3);
    nodo7->setSig(nodo2);

    //Mensaje de compilación exitosa
    cout<<"Todo bien"<<endl;

    system("pause");
    return 0;
}
