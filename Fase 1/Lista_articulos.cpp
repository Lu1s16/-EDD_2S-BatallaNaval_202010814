#include "Nodo_articulos.h"
#include <string>
#include <iostream>

using namespace std;


class Lista_articulos {

    public:
        nodo_articulos*primero;
        int size_articulos;

        Lista_articulos(){
            primero = NULL;
            size_articulos = 0;
        }

        //metodo para imprimir los articulos
        void Recorrer_elementos(){
            nodo_articulos*actual = primero;
            cout << "\t" << "ID" << "\tNombre" << "\tPrecio" << "\tSrc" << endl;
            while(actual != NULL){

  
                cout << "\t" << actual->id;
                cout << "\t" << actual->nombre;
                cout << "\t" << actual->precio;
                cout << "\t" << actual->src;
                cout << "" << endl;

                actual = actual->next_articulo;

            };
            cout << "" << endl;

        }

        //Funcion para crear los nodos
        string Crear_nodos(int no_estructura, int no_dato, string categoria){
            string estructura;
            estructura = to_string(no_estructura) + "[shape=record, label=\"<f" + to_string(no_dato) + "> " + categoria + "| ";
            ++no_dato; 
            nodo_articulos*actual = primero;
            while(actual != NULL){

                if(size_articulos != no_dato) {
                    //creo los label
                    estructura+="<f"+ to_string(no_dato) + "> " + "Nombre: " +actual->nombre + "\n ID: " + actual->id + "\n Precio: " + to_string(actual->precio) + "\n Src: " + actual->src + "| ";

                } else {
                    estructura+="<f"+ to_string(no_dato) + "> " + "Nombre: " +actual->nombre + "\n ID: " + actual->id + "\n Precio: " + to_string(actual->precio) + "\n Src: " + actual->src + "\"]\n ";
                }

                

                ++no_dato;
                actual = actual->next_articulo;
            };

            return estructura;



        }

        //funcion para insertar los articulos de la carga masiva
        void Insertar_articulo(string id, int precio, string nombre, string src){

            nodo_articulos*nuevo_articulo = new nodo_articulos();
            nuevo_articulo->id = id;
            nuevo_articulo->nombre = nombre;
            nuevo_articulo->precio = precio;
            nuevo_articulo->src = src;  

            if(primero == NULL){
                primero = nuevo_articulo;
                ++size_articulos;
            } else {
                nodo_articulos*actual = primero;

                while(actual->next_articulo != NULL){
                    actual = actual->next_articulo;
                };

                actual->next_articulo = nuevo_articulo;
                ++size_articulos;

            };         
        


        }

        void Ordenar_precio_asc();

        void Ordenar_precio_desc();



    private:

};