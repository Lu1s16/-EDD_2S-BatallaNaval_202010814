#include "Nodo_categorias.h"
#include <string>
#include <iostream>

using namespace std;

class Lista_categorias {
    
    public:
        nodo_categorias*primero;
        int size_categorias;

        Lista_categorias(){
            primero = NULL;
            size_categorias = 0;
        }

        //Esta funcion insertara una categoria
        //y el articulo si aun no existe la categoria
        //en la lista
        void Insertar_categoria(string categoria, string id, int precio, string nombre, string src){
            nodo_categorias*nueva_categoria = new nodo_categorias();
            nueva_categoria->categoria = categoria;
            nueva_categoria->lista_de_articulos->Insertar_articulo(id, precio, nombre, src);
            

            if(primero == NULL){
                primero = nueva_categoria;
                ++size_categorias;
            } else {
                nodo_categorias*actual = primero;
                
                while(actual->siguiente != NULL){
                    actual = actual->siguiente;
                };

                actual->siguiente = nueva_categoria;
                ++size_categorias;

            };


        }

        //Esta funcion insertara el articulo
        //en una categoria ya existente
        void insertar_solo_articulo(string categoria, string id, int precio, string nombre, string src){
            //actual nos servira para encontrar la categoria ya existente
            nodo_categorias*actual = primero;
            while(actual != NULL){

                if(actual->categoria == categoria){
                    actual->lista_de_articulos->Insertar_articulo(id, precio, nombre, src);
                    break;

                };

                actual = actual->siguiente;
                    
            };

        }

        //esta funcion servira para verificar si ya existe
        //la categoria o si no existe.
        //true = si existe
        //false = no existe
        bool Verificar(string categoria){
            //actual nos servira para recorrer la lista y buscar la categoria
            nodo_categorias*actual = primero;

            while(actual != NULL){

                if(actual->categoria == categoria){
                    return true;
                };
                actual = actual->siguiente;

            };

            return false;


        }

        //imprime todas las cateogrias y articulos
        void Imprimir(){
            nodo_categorias*actual = primero;
            cout << "*******Articulos*******"<<endl;

            while(actual != NULL){

                
                cout << "Categoria: "<<actual->categoria << "\n";

                actual->lista_de_articulos->Recorrer_elementos();
                
                actual = actual->siguiente;
            };
            cout << "" << endl;

        }

        int Graficar(){
            nodo_categorias*actual = primero;
            string contenido, nodos, conexiones;
            contenido = "digraph estructuras { \n";

            int no_estructura = 1; //estructura
            int no_dato = 0; //para lo que va dentro f0...
            //1 [shape=record,label="<f0> cat1|<f1> art1|<f2> art2"];
            
            while(actual != NULL){

                nodos+=actual->lista_de_articulos->Crear_nodos(no_estructura, no_dato, actual->categoria);

                actual = actual->siguiente;
                ++no_estructura;



            };
            //hacer conexiones
            //struct1:f0 -> struct2:f0;

            no_estructura = 1;
            while(no_estructura <= size_categorias){

                if(no_estructura!=size_categorias){
                    conexiones+= to_string(no_estructura) + ":f0 ->" + to_string(no_estructura+1) + ":f0;\n";

                };

                

                ++no_estructura;
            };

            contenido+=nodos + conexiones + "}";

            ofstream archivo;

            archivo.open("articulos.dot", ios::out);

            if(archivo.fail()){
                cout << "Error";
                return 0;

            };

            archivo << contenido;

            archivo.close();

            system("dot -Tpng -O articulos.dot");

            system("articulos.dot.png");

            



            return 0;

            
        }


    private:
};
