#include <iostream>
#include <windows.h>
#include <string.h>



using namespace std;

  //declaraciones
    int option1;

    int id[20];
    string producto[20];
    float pc[20];
    float pv[20];
    int existencias[20];
    int nReorden[20];
    int st[20];

//llenar datos
    void llenarDatos(){
        id[0]=2;
        id[1]=4;
        id[2]=1;
        id[3]=3;
        id[4]=5;

        producto[0]="leche";
        producto[1]="pan";
        producto[2]="agua";
        producto[3]="huevo";
        producto[4]="refresco";

        pc[0]=12.35;
        pc[1]=5.5;
        pc[2]=13.39;
        pc[3]=22.4;
        pc[4]=10.99;

        pv[0]=15.5;
        pv[1]=7.95;
        pv[2]=18.55;
        pv[3]=30.39;
        pv[4]=14.75;

        existencias[0]=16;
        existencias[1]=18;
        existencias[2]=12;
        existencias[3]=20;
        existencias[4]=30;

        nReorden[0]=5;
        nReorden[1]=6;
        nReorden[2]=4;
        nReorden[3]=7;
        nReorden[4]=8;

        st[0]=1;
        st[1]=1;
        st[2]=1;
        st[3]=1;
        st[4]=1;

    }

int menuAdmin(){


        cout<< "*************** MEMU PRINCIPAL ***************\n\n";
        cout<< "*escribe un numero para seleccionar una opcion\n";
        cout<< " 1   Altas\n";
        cout<< " 2   Bajas\n";
        cout<< " 3   Consultas\n";
        cout<< " 4   Modificaciones\n";
        cout<< " 5   Administracion de cuentas de usuario\n";
        cout<< " 6   Mostrar inventario\n";
        cout<< " 7   Corte de caja general\n";
        cout<< " 8   Regresar al menu principal\n";
        cout<< " *   SALIR\n";
        cout<< " opcion: ";
        cin>>option1;
        
        switch(option1){
            case 1:{
               //altas

                break;
            }
            case 2:{
                //bajas
                break;
            }
            case 3:{
                //consultas
                break;
            }
            case 4:{
                //modificaciones
                break;
            }
            case 5:{
                //usuarios
                break;
            }
            case 6:{
                //inventario
                break;
            }
            case 7:{
                //corte de caja
                break;
            }
            case 8:{
                //menu anterior
                break;
            }
            case 0:{
                return 0;
                break;
            }
            default:{
                system("cls");
                cout<<"SELECCONA UNA OPCIN VALIDA\n";
                system("pause");
                system("cls");
                
            }
           
        }
         
}

int menuVentas(){
}

int menu1(){
        cout<< "*************** MEMU PRINCIPAL ***************\n\n";
        cout<<id[1]<<endl;
        cout<< "*escribe un numero para seleccionar una opcion\n";
        cout<< " 1   ADMINISTRADOR\n";
        cout<< " 2   VENTAS\n";
        cout<< " *   SALIR\n";
        cin>>option1;
        
        switch(option1){
            case 1:{
                 system("cls");
                menuAdmin();
                break;
            }
            case 2:{
                 system("cls");
                menuVentas();
                break;
            }
            case 0:{
                return 0;
                break;
            }
            default:{
                system("cls");
                cout<<"SELECCONA UNA OPCIN VALIDA\n";
                system("pause");
                system("cls");
                menu1(); 
            }
           
        }
         
    }

int main(){

    llenarDatos();
    menu1();

}