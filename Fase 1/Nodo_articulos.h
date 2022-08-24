#include <string>
#include <iostream>


using namespace std;

class nodo_articulos{

    public:
        nodo_articulos*next_articulo;
        int id;
        int precio;
        string nombre;
        string src;

        nodo_articulos(){
            next_articulo = NULL;
            id = 0;
            precio = 0;
            nombre = "";
            src = "";
        }

    private:
    
};