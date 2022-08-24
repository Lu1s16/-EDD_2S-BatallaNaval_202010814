#include <string>
#include <iostream>

using namespace std;

class Nodo_articulos_aux{

    public:
        Nodo_articulos_aux*siguiente;
        int id;
        int precio;
        string nombre;
        string src;
        string categoria;

        Nodo_articulos_aux(){
            siguiente = NULL;
            id = 0;
            precio = 0;
            nombre = "";
            src = "";
            categoria = "";
        }

    private:

};