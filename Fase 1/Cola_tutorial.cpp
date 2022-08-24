#include "Nodo_tutorial.h"
#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class Cola_tutorial {

    public:
        Nodo_size*primero;
        Nodo_size*ultimo;
        int size;

        Cola_tutorial(){
            primero = NULL;
            ultimo = NULL;
            size = 0;
        }

        //Funcion para insertar los datos del tutorial de la carga masiva
        void Insertar(int alto, int ancho, int pos_x, int pos_y){
            
            Nodo_size*nuevo_nodo = new Nodo_size();
            nuevo_nodo->alto = alto;
            nuevo_nodo->ancho = ancho;
            nuevo_nodo->pos_x = pos_x;
            nuevo_nodo->pos_y = pos_y;

            if(primero == NULL){
                primero = nuevo_nodo;
                ultimo = nuevo_nodo;


            } else {
                nuevo_nodo->siguiente_nodo = ultimo;
                ultimo = nuevo_nodo;

            };

            ++size;

        }

        int Graficar(){
            Nodo_size*actual = ultimo;
            string contenido, nodos, conexiones;
            contenido = "digraph G { \n";

            int no_nodo = 1;

            //creo nodos
            while(actual != NULL){

                //nodos posiciones
                if(actual->siguiente_nodo != NULL){
                    nodos+=to_string(no_nodo) + "[shape=box, label=\"Posicion x: " + to_string(actual->pos_x) + "\nPosicion y: " + to_string(actual->pos_y) + "\", style=filled]\n";


                } else {
                    //nodo tamaño
                    nodos+=to_string(no_nodo) + "[shape=box, label=\"Alto: " + to_string(actual->alto) + "\nAncho: " + to_string(actual->ancho) + "\", style=filled]\n";
                };

                ++no_nodo;
                actual = actual->siguiente_nodo;


            };

            conexiones = "{rank=same \n";
            no_nodo = 1;

            while(no_nodo <= size){

                if(no_nodo != size){
                    conexiones+= to_string(no_nodo) + "->" + to_string(no_nodo+1) + "[arrowsize=0.5]; \n";

                    
                };
                ++no_nodo;


            };

            conexiones+="} \n \n";

            contenido+= nodos + conexiones + "\n }";

            ofstream archivo;

            archivo.open("tutorial.dot", ios::out);

            if(archivo.fail()){
                cout << "Error";
                return 0;
            };

            archivo << contenido;

            archivo.close();

            system("dot -Tpng -O tutorial.dot");

            system("tutorial.dot.png");

            return 0;






            





        }

        //Funcion para imprimir los datos del tutorial
        void Imprimir_tutorial(){
            cout << "\n";
            cout << "Tutorial" << endl;

            Nodo_size*otro = primero;

            cout << "Size: " << endl;
            cout << "\tAncho: " << otro->ancho << endl;
            cout << "\tAlto: " << otro->alto << endl;

            
            Nodo_size*actual = ultimo;
            cout << "Movimientos:" << endl;

            while(actual != NULL){
                if(actual->siguiente_nodo != NULL){
                    //IMPRIMO POSICIONES
                    cout << "\tpos_x: " << actual->pos_x << endl;
                    cout << "\tpos_y: " << actual->pos_y << endl;
                    cout << "" << endl;

                };



                actual = actual->siguiente_nodo;

            };

                

            
            cout << "\n";

        }



    private:    

};