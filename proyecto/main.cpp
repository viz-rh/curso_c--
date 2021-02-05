#include <iostream>

using namespace std;

  //declaraciones
    int option1;


int menu1(){
        cout<< "*************** MEMU PRINCIPAL ***************\n\n";
        cout<< "*escribe un numero para seleccionar una opcion\n";
        cout<< " 1   ADMINISTRADOR\n";
        cout<< " 2   VENTAS\n";
        cout<< " 3   SALIR\n";
        cin>>option1;

        switch(option1){
            case 1:{
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                break;
            }
            default:{
                cout<<"SELECCONA UNA OPCIN VALIDA";
                getchar();
                menu1();
                break;
            }
        }
    }

int main(){
     //input
    menu1();

 
    
}