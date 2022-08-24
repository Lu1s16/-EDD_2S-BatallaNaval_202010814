#include "Nodo_articulo_aux.h"
#include <string>
#include <iostream>

using namespace std;

class Lista_articulos_aux {


    public:
        Nodo_articulos_aux*primero;
        int size;

        Lista_articulos_aux(){
            primero = NULL;
            size = 0;
        }

        void Insertar(int id, int precio, string nombre, string src, string categoria){

            Nodo_articulos_aux*nuevo_articulo = new Nodo_articulos_aux();
            nuevo_articulo->categoria = categoria;
            nuevo_articulo->id = id;
            nuevo_articulo->nombre = nombre;
            nuevo_articulo->precio = precio;
            nuevo_articulo->src = src;

            if(primero == NULL){
                primero = nuevo_articulo;
                ++size;
            } else {
                Nodo_articulos_aux*actual = primero;

                while(actual->siguiente != NULL){
                    actual = actual->siguiente;
                };

                actual->siguiente = nuevo_articulo;
                ++size;

            };


        }

        void imprimir(){
            Nodo_articulos_aux*actual = primero;

            while(actual != NULL){
                cout << "Nombre: " << actual->nombre << endl;
                cout << "Precio: " << actual->precio << endl;
                cout << "Id: " << actual->id << endl;
                cout << "Categoria: " << actual->categoria << endl;
                cout << "src: " << actual->src << endl;
                cout << ""  << endl;

                actual = actual->siguiente;

            }

        }

        void Ordenar_asc(){
            int i, k;
            Nodo_articulos_aux*actual;
            string aux_nombre, aux_categoria, aux_src;
            int aux_id, aux_precio;

            for(k = 1; k<size; ++k){
                actual = primero;
                for(i=0; i<size-k; ++i){

                    if(actual->precio > actual->siguiente->precio){
                        aux_nombre = actual->nombre;
                        actual->nombre = actual->siguiente->nombre;
                        actual->siguiente->nombre = aux_nombre;

                        aux_categoria = actual->categoria;
                        actual->categoria  = actual->siguiente->categoria;
                        actual->siguiente->categoria = aux_categoria;

                        aux_id = actual->id;
                        actual->id = actual->siguiente->id;
                        actual->siguiente->id = aux_id;

                        aux_precio = actual->precio;
                        actual->precio = actual->siguiente->precio;
                        actual->siguiente->precio = aux_precio;

                        aux_src = actual->src;
                        actual->src = actual->siguiente->src;
                        actual->siguiente->src = aux_src;

                    };
                    actual = actual->siguiente;

                };

            };

        }

        void ordenar_desc(){
            int i, k;
            Nodo_articulos_aux*actual;
            string aux_nombre, aux_categoria, aux_src;
            int aux_id, aux_precio;

            for(k = 1; k<size; ++k){
                actual = primero;
                for(i=0; i<size-k; ++i){

                    if(actual->precio < actual->siguiente->precio){
                        aux_nombre = actual->nombre;
                        actual->nombre = actual->siguiente->nombre;
                        actual->siguiente->nombre = aux_nombre;

                        aux_categoria = actual->categoria;
                        actual->categoria  = actual->siguiente->categoria;
                        actual->siguiente->categoria = aux_categoria;

                        aux_id = actual->id;
                        actual->id = actual->siguiente->id;
                        actual->siguiente->id = aux_id;

                        aux_precio = actual->precio;
                        actual->precio = actual->siguiente->precio;
                        actual->siguiente->precio = aux_precio;

                        aux_src = actual->src;
                        actual->src = actual->siguiente->src;
                        actual->siguiente->src = aux_src;

                    };
                    actual = actual->siguiente;

                };

            };

        }



    private:

};