#include <string>
#include <iostream>


using namespace std;

class nodo_articulos{

    public:
        nodo_articulos*next_articulo;
        string id;
        int precio;
        string nombre;
        string src;

        nodo_articulos(){
            next_articulo = NULL;
            id = "";
            precio = 0;
            nombre = "";
            src = "";
        }

    private:
    
};