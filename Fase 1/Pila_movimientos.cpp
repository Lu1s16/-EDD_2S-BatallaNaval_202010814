#include "Nodo_movimientos.h"
#include <string>
#include <iostream>

using namespace std;


class Pila_movimientos {

    public:
        Nodo_movimiento*primero;
        
        
        Pila_movimientos(){
            primero = NULL;
            

        }

        void Insertar_movimiento(int mov_x, int mov_y){
            Nodo_movimiento*nuevo_movimiento = new Nodo_movimiento();

            nuevo_movimiento->mov_x = mov_x;
            nuevo_movimiento->mov_y = mov_y;

            if(primero == NULL){
                cout << "meto un dato" << endl;
                primero = nuevo_movimiento;
                

            } else {
                Nodo_movimiento*actual = primero;
                
                while(actual->siguiente_move != NULL){
                    actual = actual->siguiente_move;
                };

                actual->siguiente_move = nuevo_movimiento;
                

            };



        }

        void Imprimir_movimientos(){

            //recorro del ultimo al primero
            Nodo_movimiento*actual2 = primero;
            cout << "Movimientos: " << endl;
            

            while(actual2 != NULL){
                cout << "movimiento en x: "<< actual2->mov_x << endl;
                cout << "movimiento en y: "<< actual2->mov_y << endl;
                cout << "" << endl;
                
                actual2 = actual2->siguiente_move;
            };

        }

    private:

};