class Nodo{
    private:
        int elemento;
        Nodo *sig;
    public:
        Nodo(int x); //Constructor que inicializa el elemnto
        ~Nodo(); //Destructor
        int getElemento();
        void setElemento(int x);
        Nodo *getSig();
        void setSig(Nodo *siguiente);

};

//Constructor que inicializa el elemento
Nodo::Nodo(int x)
{
 elemento=x;
 sig=nullptr;
}

//Destructor
Nodo::~Nodo(){
}

//Método que retorna el valor del elemento
int Nodo:: getElemento()
{
    return elemento;
}

//Método que establece el valor del elemento
void Nodo:: setElemento(int valor)
{
    elemento=valor;
}

//Método que retorna un apuntador de tipo Nodo
Nodo* Nodo::getSig()
{
    return sig;
}

//Método que establece un apuntador de tipo Nodo
void Nodo::setSig(Nodo *siguiente)
{
    sig=siguiente;
}
