#include <string>
#include <iostream>

using namespace std;

class Nodo_size{
    public:
        Nodo_size*siguiente_nodo;
        int ancho;
        int alto;
        int pos_x;
        int pos_y;

        Nodo_size(){
            siguiente_nodo = NULL;
            ancho = 0;
            alto = 0;
            pos_x = 0;
            pos_y = 0;
        }



    private:

};

