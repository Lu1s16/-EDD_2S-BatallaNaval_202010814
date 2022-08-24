#include <string>
#include <iostream>
#include "Nodo_lista_de_pilas.h"

using namespace std;

class Lista_pilas{

    public:
        Nodo_lista_de_pilas*primero;
        int size_jugadas;

        Lista_pilas(){
            primero = NULL;
            size_jugadas = 0;
        }

        //Funcion donde se meteran los movimientos
        //y el nombre de la jugada
        void Insertar_jugadas(){
            Nodo_lista_de_pilas*nueva_jugada = new Nodo_lista_de_pilas();

            bool terminado = false;
            //false significa que aun se sigen ingresando movimientos
            while(terminado == false){

                int mov_x, mov_y;

                cout << "Ingrese movimiento en x: ";
                cin >> mov_x;

                cout << "Ingrese movimiento en y: ";
                cin >> mov_y;
                


                //terminado = false
                //significa que el usuario sigue ingresando jugadas
                if(terminado == false){

                    nueva_jugada->Pila_de_movimientos->Insertar_movimiento(mov_x, mov_y);
                    string option;

                    cout << "Desea ingresar otro movimiento?(yes/no)";
                    cin >> option;

                    if(option == "no"){
                        terminado = true;

                    } else if(option == "yes"){
                        terminado = false;
                    };
                    

                };




            };

            string nombre_jugada;

            cout << "Ingrese el nombre de su jugada: ";
            cin >> nombre_jugada;

            nueva_jugada->nombre_movimiento = nombre_jugada;

            if(primero == NULL){
                primero = nueva_jugada;

            } else {
                Nodo_lista_de_pilas*actual = primero;
                    
                while(actual->siguiente_jugada != NULL){
                    actual = actual->siguiente_jugada;
                        
                };

                actual->siguiente_jugada = nueva_jugada;

            };

            ++size_jugadas;





                

            


            

            

        }


        //imprimir nombre y pila de movimientos:
        //es una lista que contiene como atributos
        //nombre y una pila
        void Imprimir_datos(){
            Nodo_lista_de_pilas*actual = primero;

            cout << "Jugadas: "<< endl;

            while(actual != NULL){
                cout <<"Nombre jugada: "<< actual->nombre_movimiento << endl;
                actual->Pila_de_movimientos->Imprimir_movimientos();

                actual = actual->siguiente_jugada;
            };

        }


    private:

};