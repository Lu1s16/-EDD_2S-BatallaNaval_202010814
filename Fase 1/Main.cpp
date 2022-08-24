#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>



#include "json/json.h"
#include "sha256.h"
#include "jsoncpp.cpp"
#include "Lista_categorias.cpp"
#include "Cola_tutorial.cpp"
#include "Lista_articulos_aux.cpp"



#include "Lista_doble_circular.cpp"

#include <fstream>



using namespace std;
using std::stoi;

Lista_doble_circular prueba; //la de usuarios
Lista_categorias categorias;
Cola_tutorial tutorial;
Lista_articulos_aux lista_aux;

//opciones del menu usuario



//opciones menu principal
void Carga_masiva(){

    // C:\\Users\\Julio Garcia\\Desktop\\prueba.json
    std::cout <<"Carga masiva" << std::endl;

    std:: string ruta;
    std:: cin >> ruta;
    
    // Using fstream to get the file pointer in file.
    ifstream file(ruta);
    Json::Value actualJson;
    Json::Reader reader;

    // Using reader we are parsing the Json
    reader.parse(file, actualJson);

    //en actualJson esta todo el contenido del archivo json

    //Read elements
    

    

    //lectura de usuarios:
    auto entriesArray = actualJson["usuarios"]; //entriesArray contiene la lista de usuarios
    for(int i = 0; i < actualJson["usuarios"].size(); ++i)
    {
        //elem contiene un usuario con sus datos(nick, password, monedas)
        auto elem = entriesArray[i];

        //luego accedo a cada valor de sus datos
        std::string nombre = elem["nick"].asString();
        std::string edad = elem["edad"].asString();
        std::string password = elem["password"].asString();
        std::string monedas = elem["monedas"].asString();

        int int_edad, int_monedas;
        //convertir un string a int
        int_edad = stoi(edad);
        int_monedas = stoi(monedas);

        string codigo_encriptado;

        codigo_encriptado = SHA256::cifrar(password);

        //se insertan los datos de los usuarios en la lista
        prueba.insertar(nombre, codigo_encriptado, int_monedas, int_edad);


        

    }

    //lectura de articulos:
    auto lista_arituclos = actualJson["articulos"];
    for(int i = 0; i < actualJson["articulos"].size(); ++i)
    {
        auto elem_articulo = lista_arituclos[i];

        std::string id = elem_articulo["id"].asString();
        std::string categoria = elem_articulo["categoria"].asString();
        std::string precio = elem_articulo["precio"].asString();
        std::string nombre_art = elem_articulo["nombre"].asString();
        std::string src = elem_articulo["src"].asString();

        int int_id, int_precio;

        int_id = stoi(id);
        int_precio = stoi(precio);

        //busco si ya existe la categoria en la lista
        //Si no existe, lo ingreso a la lista
        //luego ingreso el articulo con id, precio,nombre y src
        bool existe = categorias.Verificar(categoria);

        if(existe){
            categorias.insertar_solo_articulo(categoria, int_id, int_precio, nombre_art, src);
        } 
        else {
           
            categorias.Insertar_categoria(categoria, int_id, int_precio, nombre_art, src);
        };

        //Si ya existe, retorno su posicion.
        //luego meto ahi el articulo con id, precio, nombre y src

        //meto en la lista aux. para el ordenamiento

        lista_aux.Insertar(int_id, int_precio, nombre_art, src, categoria);

    }

    //lectura de tutorial:
    auto datos_tutorial = actualJson["tutorial"];
    
    auto elem_tuto = datos_tutorial["ancho"];


    std::string ancho = datos_tutorial["ancho"].asString();
    std::string alto = datos_tutorial["alto"].asString();
    
    int int_ancho, int_alto;
    int_ancho = stoi(ancho);
    int_alto = stoi(alto);
    //meto el ancho y alto en el primer nodo de la cola
    tutorial.Insertar(int_alto, int_ancho, 0, 0);

    auto movimientos = datos_tutorial["movimientos"];

    for(int j = 0; j < datos_tutorial["movimientos"].size(); ++j){
        auto elem_pos = movimientos[j];

        std::string pos_x = elem_pos["x"].asString();
        std::string pos_y = elem_pos["y"].asString();



        int int_pos_x, int_pos_y;
        int_pos_x = stoi(pos_x);
        int_pos_y = stoi(pos_y);

        //meto la pos_x y pos_y en los demas nodos de la cola
        tutorial.Insertar(0, 0, int_pos_x, int_pos_y);

    };


    cout << "Datos guardados correctamente" << endl;
    cout << "" << endl;

}

void Registrar_usuario(){
    std::cout <<"Registre su usuario" << std:: endl;
    string usuario;
    cout << "Ingrese un nombre de usuario: ";
    cin >> usuario;

    string pass;
    cout << "Ingrese un password: ";
    cin >> pass;

    int edad;
    cout << "Ingrese su edad: ";
    cin >> edad;

    string pass_codi = SHA256::cifrar(pass);

    int monedas = 0;

    bool ya_existe = prueba.insertar(usuario, pass_codi, monedas, edad);

    if(ya_existe){
        cout << "ERROR: El usuario ya existe, elija otro nombre por favor" << "\n\n";
        
    } else {
        cout << "\nSe registro correctamente el usuario\n" << "\n\n";
    };
    


}

int Login(nodo_usuario*usuario){

    bool seguir = true;

    while(seguir){
        //minetras seguir sea true
        //el usuario se mantendra en este usuario
        

        std:: cout << "******Bienvenido " << usuario->nick <<"******" << std:: endl;
        cout << "1. Editar informacion" << endl;
        cout << "2. Eliminar cuenta" << endl;
        cout << "3. Ver tutorial" << endl;
        cout << "4. Ver articulos" << endl;
        cout << "5. Realizar movimientos" << endl;
        cout << "6. Salir del menu" << endl;

        int opcion;
        cin >> opcion;

        //Editar informacion
        if(opcion == 1){

            cout << "---Editar informacion---" << endl;

            string new_nick;
            cout << "Ingrese su nuevo nick: ";
            cin >> new_nick;

            string new_password;
            cout << "Ingrese su nueva password: ";
            cin >> new_password;

            string new_pass_encriptado = SHA256::cifrar(new_password);

            int new_edad;
            cout << "Ingrese su nueva edad: ";
            cin >> new_edad;

            string pass_buscar_codi = SHA256::cifrar(usuario->password);

            bool existe = prueba.Reemplazar_datos(usuario->nick, pass_buscar_codi, new_nick, new_edad, new_pass_encriptado);

            if(existe){
                cout << "ERROR: El usuario que dese actualizar ya existe" << "\n\n";
                cout << "" << endl;

            } else {
                cout << "Actualizacion de datos correcto" << "\n\n";
                usuario->nick = new_nick;
                usuario->edad = new_edad;
                usuario->password = new_pass_encriptado;

            };   

            
        //Eliminar cuenta
        } else if(opcion == 2){

            string aceptar;
            cout << "Desea eliminar su cuenta[yes/no]" << endl;
            cin >> aceptar;
            if(aceptar == "yes"){
                cout << "Cuenta eliminada" << endl;
                prueba.Eliminar_por_nick(usuario->nick);
                seguir = false;


            } else if (aceptar == "no"){
                seguir = true;

            };

            
        //ver tutorial
        } else if(opcion == 3){
            tutorial.Imprimir_tutorial();
        

        //ver articulos
        } else if(opcion == 4){
            categorias.Imprimir();

        //realizar movimientos
        } else if(opcion == 5){
            int conta = 0;


            cout << "Ingrese sus jugadas" << endl;

            //entro a la funcion insertar_nueva_jugada
            //mando el nick ya que en esa funcion
            //se buscara el usuario donde se metera
            //la pila y el nombre de la jugada.
            prueba.Insertar_nueva_jugadas(usuario->nick);

            ++usuario->monedas;

        } else if(opcion == 6){
            seguir = false;
        };

        


    };
    

    return 0;
    
    

    

}

int Reportes(){

    bool seguir_reporte = true;

    while(seguir_reporte){
        int opcion;
        cout << "*********************Reportes**********************" << endl;
        cout << "* 1. Grafica usuariios                            *" << endl;
        cout << "* 2. Grafica articulos                            *" << endl;
        cout << "* 3. Grafica tutorial                             *" << endl;
        cout << "* 4. Grafica jugadas                              *" << endl;
        cout << "* 5. Usuarios ordenados por edad (ascendente)     *" << endl;
        cout << "* 6. usuarios ordenados por edad (descendente)    *" << endl;
        cout << "* 7. Articulos ordenados por precio (ascendente)  *" << endl;
        cout << "* 8. Articulos ordenados por precio (descendente) *" << endl;
        cout << "* 9. Salir de reportes                            *" << endl;
        cout << "***************************************************" << endl;
        cout << "Ingrese una opcion: ";
        
        cin >> opcion;

        if(opcion == 1){
            prueba.Graficar();

        } else if(opcion == 2){
            categorias.Graficar();

        } else if (opcion == 3){
            tutorial.Graficar();

        } else if (opcion == 4){

        } else if (opcion == 5){
            prueba.Ordenar_asc();
            prueba.imprimir();
            
        } else if (opcion == 6){
            prueba.Ordenar_des();
            prueba.imprimir();
            
        } else if (opcion == 7){
            lista_aux.Ordenar_asc();
            lista_aux.imprimir();

            
        } else if (opcion == 8){
            lista_aux.ordenar_desc();
            lista_aux.imprimir();
            
        } else if (opcion == 9){
            seguir_reporte = false;
            
        };


    };

    return 0;
   
            
}

void Ver_usuarios(){
    prueba.imprimir();
}



int Menu_princiapl(){
    std::cout <<"******Menu Principal******" << std::endl;
    std::cout <<"* 1. Carga masiva        *"<< std::endl;
    std::cout <<"* 2. Registrar Usuario   *"<< std::endl;
    std::cout <<"* 3. Login               *"<< std::endl;
    std::cout <<"* 4. Reportes            *"<< std::endl;
    std::cout <<"* 5. Ver usuarios        *" << std::endl;
    std::cout <<"* 6. Salir del juego     *"<< std::endl;
    std::cout <<"**************************" << std::endl;

    int valor;
    std::cin >> valor;

    if(valor == 1){
        Carga_masiva();
        Menu_princiapl();

    } else if(valor == 2){
        Registrar_usuario();
        Menu_princiapl();

        //login
    } else if(valor == 3){
        string usuario;
        string pass;
        cout << "Ingrese su usuario(nick): ";
        cin >> usuario;

        cout << "Ingrese su password: ";
        cin >> pass;

        cout << "\n";
        string encriptado = SHA256::cifrar(pass);
        
        nodo_usuario*nodo = prueba.Buscar_usuario(usuario, encriptado);
        
        if(nodo == NULL){
            cout << "password/usuario incorrecto" << endl;
            Menu_princiapl();
        } else {
            Login(nodo);
            cout << "Sesion cerrada" << endl;
            Menu_princiapl();

        };

        
        
        
        
        
        

    } else if(valor == 4){
        Reportes();
        Menu_princiapl();

    } else if(valor == 5){
        Ver_usuarios();
        Menu_princiapl();
    } else if(valor == 6){
        return 0;
    }
    return 0;
    

}



int main(int argc, char const *argv[]){

    Menu_princiapl();


    return 0;
}