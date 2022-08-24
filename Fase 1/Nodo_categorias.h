#include <string>
#include <iostream>
#include "Lista_articulos.cpp"

using namespace std;

class nodo_categorias{

    public:
        nodo_categorias*siguiente;
        string categoria;
        Lista_articulos*lista_de_articulos;
        
        
    

        nodo_categorias(){
            siguiente = NULL;
            categoria = "";
            //lista de articulos
            lista_de_articulos = new Lista_articulos();
            
            
        }

       
    private:

};