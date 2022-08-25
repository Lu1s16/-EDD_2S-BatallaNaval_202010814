#include <string>
#include <iostream>

using namespace std;

class Nodo_articulos_aux{

    public:
        Nodo_articulos_aux*siguiente;
        string id;
        int precio;
        string nombre;
        string src;
        string categoria;

        Nodo_articulos_aux(){
            siguiente = NULL;
            id = "";
            precio = 0;
            nombre = "";
            src = "";
            categoria = "";
        }

    private:

};