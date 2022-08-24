#include <string>
#include <iostream>
#include "Pila_movimientos.cpp"

using namespace std;

class Nodo_lista_de_pilas{

    public:
        Nodo_lista_de_pilas*siguiente_jugada;
        string nombre_movimiento;
        Pila_movimientos*Pila_de_movimientos;

        Nodo_lista_de_pilas(){
            siguiente_jugada = NULL;
            nombre_movimiento = "";
            Pila_de_movimientos = new Pila_movimientos();

        }
    

    private:


};