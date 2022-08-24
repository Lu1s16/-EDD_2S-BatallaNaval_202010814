#include <string>
#include <iostream>


using namespace std;

class Nodo_movimiento{

    public:
        Nodo_movimiento*siguiente_move;
        int mov_x;
        int mov_y;

        Nodo_movimiento(){
            siguiente_move = NULL;
            mov_x = 0;
            mov_y = 0; 
        }


    private:
    
};