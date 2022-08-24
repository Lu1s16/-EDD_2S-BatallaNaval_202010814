#include "Nodo_usuarios.h"
#include <string>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;


class Lista_doble_circular {

    public:
        nodo_usuario*primero;
        nodo_usuario*ultimo;
        int size;

        Lista_doble_circular(){
            primero = NULL;
            ultimo = NULL;
            size = 0;
        }

        int Graficar(){
            nodo_usuario*actual = primero;
            string contenido, nodos, conexiones;
            contenido = "digraph G { \n";
            

            int cont = 0;
            int no_nodo = 1;  
            
 
            //creo los nodos
            while(cont < size){
                nodos+=to_string(no_nodo) + "[shape=box, label=\"Nombre: " + actual->nick + "\nPassword: " + actual->password + "\nEdad: " + to_string(actual->edad) + "\nMonedas: " + to_string(actual->monedas) + "\", style=filled]\n";

                actual = actual->siguiente;
                ++no_nodo;
                ++cont;
                


            };

            //creo las conexiones

            //{rank=same
        
            //1->1[dir=both, arrowsize=0.5];

            //}
            conexiones = "{rank=same \n";

            no_nodo = 1;

            if(size == 1){
                conexiones+= to_string(no_nodo) + "->" + to_string(no_nodo) + "[dir=both, arrowsize=0.6]; \n";


            } else {

                while(no_nodo <= size){

                    if(no_nodo != size){
                        conexiones+= to_string(no_nodo) + "->" + to_string(no_nodo+1) + "[dir=both, arrowsize=0.6]; \n";

                    } else if (no_nodo == size){
                        conexiones+= to_string(no_nodo) + "->" + to_string(1) + "[dir=both, arrowsize=0.6]; \n";

                    };

                    ++no_nodo;
                };
            };
            conexiones+="\t}\n \n";

            contenido+= nodos + conexiones + "\n }";

            //creo el archivo .dot
            ofstream archivo;

            archivo.open("usuarios.dot", ios::out);

            if(archivo.fail()){
                cout << "Error";
                return 0;
            };

            //meto el contenido en el archivo
            archivo << contenido;

            archivo.close();

            system("dot -Tpng -O usuarios.dot");

            system("usuarios.dot.png");

            return 0;

 




            


        }

        void Imprimir_jugadas_por_usuario(){

            nodo_usuario*actual = primero;

            int cont = 0;

            while(cont < size){

                cout << "Jugador: " << actual->nick << endl;
                actual->Lista_jugadas->Imprimir_datos();

                ++cont;
                actual = actual->siguiente;
            }


            

        }

        //Funcion para insertar una nueva jugada.
        void Insertar_nueva_jugadas(string nick){


            nodo_usuario*actual = primero;
            
            
            int cont = 0;
            //Busco el usuario
            while(cont < size){
                

                if(actual->nick == nick){
                    
                    break;
                };


                actual = actual->siguiente;
                ++cont;
            };
            //al tener el usuario entro a la funcion de insertar jugadas

            actual->Lista_jugadas->Insertar_jugadas();

        }


        //funcion para editar informacion del usuario
        bool Reemplazar_datos(string nick_buscar, string pass_buscar, string new_nick, int new_edad, string new_password){
            //nick_buscar es el nick que se buscara
            //para encontrar el nodo donde se actualizara
            //los datos
            
            //primero verificamos que el nuevo nombre
            //que se quiera asignar no existe

            nodo_usuario*nodo_buscar = primero;
            int cont1 = 1;

            while(cont1 <= size){
                //empieza a recorrer todos los nodos

                if(new_nick == nodo_buscar->nick ){
                    //true significa que ya existe
                    //el nick que se quiere actualizar
                    return true;
                };

                nodo_buscar = nodo_buscar->siguiente;
                ++cont1;
            };


            
            //al ver que aun no existe ese nick
            //busco el nodo para actualizar los datos
            
            
            nodo_usuario*actual = primero;
            int cont = 0;

            while(cont < size){

                if(actual->nick == nick_buscar & actual->password == pass_buscar){
                    actual->nick = new_nick;
                    actual->edad = new_edad;
                    actual->password = new_password;
                    
                    
                };

                actual = actual->siguiente;
                ++cont;
            };
            return false;
        }

        //Funcion para eliminar la cuenta
        void Eliminar_por_nick(string nick){
            //algoritmo.
            //Buscar el nodo
            //cambiar las referencias del anteriro y siguiente nodo del actual
            //poner nulos las referencias del nodo actual
            //borrar los elementos.

            nodo_usuario*actual = primero;

            int cont = 0;
            while(cont < size){

                if(actual->nick == nick){

                    if(cont == 0){


                        nodo_usuario*nodo_anterior = actual->anterior;
                        nodo_usuario*nodo_siguiente = actual->siguiente;

                        primero = nodo_siguiente;

                        nodo_anterior->siguiente = nodo_siguiente;
                        nodo_siguiente->anterior = nodo_anterior;

                        actual->siguiente = NULL;
                        actual->anterior = NULL;

                        actual->nick = "";
                        actual->password = "";
                        actual->edad = 0;
                        actual->monedas = 0;
                    
                        --size;
                        break;

                    } else {

                        nodo_usuario*nodo_anterior = actual->anterior;
                        nodo_usuario*nodo_siguiente = actual->siguiente;

                        nodo_anterior->siguiente = nodo_siguiente;
                        nodo_siguiente->anterior = nodo_anterior;

                        actual->siguiente = NULL;
                        actual->anterior = NULL;

                        actual->nick = "";
                        actual->password = "";
                        actual->edad = 0;
                        actual->monedas = 0;
                    
                        --size;
                        break;

                    }


                    

                };


                actual = actual->siguiente;
                ++cont;

            };

        }

        


        void Ordenar_asc(){
            int i, k;
            nodo_usuario*actual;
            string aux_nick, aux_password;
            int aux_monedas, aux_edad;



            for(k = 1; k<size; ++k){
                actual = primero;
                for(i=0; i<size-k; ++i){

                    if(actual->edad > actual->siguiente->edad){
                        //cambio de posiciones
                        aux_nick = actual->nick;
                        actual->nick = actual->siguiente->nick;
                        actual->siguiente->nick = aux_nick;

                        aux_edad = actual->edad;
                        actual->edad = actual->siguiente->edad;
                        actual->siguiente->edad = aux_edad;

                        aux_monedas = actual->monedas;
                        actual->monedas = actual->siguiente->monedas;
                        actual->siguiente->monedas = aux_monedas;

                        aux_password = actual->password;
                        actual->password = actual->siguiente->password;
                        actual->siguiente->password = aux_password;

                    };
                    actual = actual->siguiente;

                };

            };


        }

         //descendente
        void Ordenar_des(){
            int i, k;
            nodo_usuario*actual;
            string aux_nick, aux_password;
            int aux_monedas, aux_edad;

            for(k = 1; k<size; ++k){
                actual = primero;
                for(i=0; i<size-k; ++i){


                    if(actual->edad < actual->siguiente->edad){

                        aux_nick = actual->nick;
                        actual->nick = actual->siguiente->nick;
                        actual->siguiente->nick = aux_nick;

                        aux_edad = actual->edad;
                        actual->edad = actual->siguiente->edad;
                        actual->siguiente->edad = aux_edad;

                        aux_monedas = actual->monedas;
                        actual->monedas = actual->siguiente->monedas;
                        actual->siguiente->monedas = aux_monedas;

                        aux_password = actual->password;
                        actual->password = actual->siguiente->password;
                        actual->siguiente->password = aux_password;


                    };

                    actual = actual->siguiente;

                };
            };
        }

        //Funcion para poder logearse el usuario
        nodo_usuario * Buscar_usuario(string nick, string password){
            nodo_usuario*actual = primero;
            int cont = 0;

            while(cont < size){

                if(actual->nick == nick & actual->password == password){
                    return actual;
                    break;
                };

                actual = actual->siguiente;
                ++cont;
            }

            return NULL;
        }

        //Funcion para insertar los usuarios al hacer la carga masiva
        //Tambien para crear nuevos usuarios
        //mando como parametro
        //el nick, password y edad del nuevo usuario
        //monedas sera 0 inicialmente
        bool insertar(string nick, string password, int monedas, int edad){


            //creamos variable para verificar si existe o no el usuario
            nodo_usuario*nodo_buscar = primero;
            int cont1 = 1;

            while(cont1 <= size){

                if(nick == nodo_buscar->nick){
                    //true significa que ya existe
                    //el nick que se quiere agregar
                    return true;
                };

                nodo_buscar = nodo_buscar->siguiente;
                ++cont1;

            };

            

            nodo_usuario*nuevo = new nodo_usuario();
            nuevo->nick = nick;
            nuevo->edad = edad;
            nuevo->password = password;
            nuevo->monedas = monedas;
            

            if(primero == NULL) {
                primero = nuevo;
                ultimo = nuevo;
                primero->siguiente = ultimo;
                nuevo->anterior = primero;
                
            } else {
                nodo_usuario*actual = primero;
                int cont = 1;

                while(cont < size) {
                    actual = actual->siguiente;

                    ++cont;
                };

                actual->siguiente = nuevo;
                nuevo->anterior = actual;
                ultimo = nuevo;
                ultimo->siguiente = primero;
                primero->anterior = ultimo;


            };

            ++size;

            //false significa que no existe el nick
            // y que se creo correctamente el nuevo
            //usuario
            return false;




        }
        void imprimir(){


            nodo_usuario*actual = primero;
            int cont = 0;

            while(cont < size){
            
                cout << "Nick: "<< actual->nick << endl;
                cout <<"Edad: "<< actual->edad << endl;
                cout <<"Monedas: "<< actual->monedas << endl;
                cout <<"Password: "<< actual->password << endl;
                cout << "" << endl;

                actual = actual->siguiente;
                ++cont;
                


            }


        }

    private:
};




