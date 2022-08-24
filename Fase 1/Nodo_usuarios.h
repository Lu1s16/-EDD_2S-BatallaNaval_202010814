#include <string>
#include <iostream>
#include "Lista_pilas.cpp"


using namespace std;



class nodo_usuario{
    public:
        nodo_usuario*siguiente;
        nodo_usuario*anterior;
        string nick;
        string password;
        int monedas;
        int edad;
        //arbol avl con las compras

        //pila de jugadas con nombre
        Lista_pilas*Lista_jugadas;


        nodo_usuario(){
            siguiente = NULL;
            anterior = NULL;
            nick = "";
            password = "";
            monedas = 0;
            edad = 0;
            Lista_jugadas = new Lista_pilas();
        }

    private:

};