#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>  
#include <iomanip>

using namespace std;
//base de datos principal
struct Product{
    int id;
    string producto;
    float pc;
    float pv;
    int existencias;
    int nReorden;
    int st;
};
//contadore de limite
int nDatos, idNuevo;

//proto menus
int menuAdmin();
int adminAltas();
int adminBajas();
int menu1();
int adminInventario();
int menuVentas();

//proto function
int exist(string texto,int option);
void imprimir(int option);
void clearStruct();

//llenar datos
Product prodActual;
Product stock[50];
void llenarDatos(){
        stock[0].id=2;
        stock[1].id=4;
        stock[2].id=1;
        stock[3].id=3;
        stock[4].id=5;

        stock[0].producto="leche";
        stock[1].producto="pan";
        stock[2].producto="agua";
        stock[3].producto="huevo";
        stock[4].producto="refresco";

        stock[0].pc=12.35;
        stock[1].pc=5.5;
        stock[2].pc=13.39;
        stock[3].pc=22.4;
        stock[4].pc=10.99;

        stock[0].pv=15.5;
        stock[1].pv=7.95;
        stock[2].pv=18.55;
        stock[3].pv=30.39;
        stock[4].pv=14.75;

        stock[0].existencias=16;
        stock[1].existencias=18;
        stock[2].existencias=12;
        stock[3].existencias=20;
        stock[4].existencias=30;

        stock[0].nReorden=5;
        stock[1].nReorden=6;
        stock[2].nReorden=4;
        stock[3].nReorden=7;
        stock[4].nReorden=8;

        stock[0].st=1;
        stock[1].st=1;
        stock[2].st=1;
        stock[3].st=1;
        stock[4].st=1;

        //revision de mayor id (codigo extra)
        idNuevo = (stock[0].id>=stock[1].id)? stock[0].id : stock[1].id;
        idNuevo = (idNuevo>=stock[2].id)? idNuevo : stock[2].id;
        idNuevo = (idNuevo>=stock[3].id)? idNuevo : stock[3].id;
        idNuevo = (idNuevo>=stock[4].id)? idNuevo : stock[4].id;
        idNuevo++;

        //establecimiento de numero de datos iniciales
        nDatos = 5;

    }

int main(){
    //llenamos los datos de la base
    llenarDatos();

    //iniciamos menu principal
    menu1();
}

menu1(){
    
    while(true){
        
        int option1=0;
        system("cls");
        cout<< "*************** MEMU PRINCIPAL ***************\n\n";
        cout<< "*escribe un numero para seleccionar una opcion\n";
        cout<< " 1   ADMINISTRADOR\n";
        cout<< " 2   VENTAS\n";
        cout<< " *   SALIR\n";
        cin>>option1;
        //******-------------------> conversor de string a int. <---------------------------*******
        //******-------------------> seleccion de opciones con string. <---------------------------*******
        if(option1==0) break;
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
            default:{
                system("cls");
                cout<<"SELECCONA UNA OPCIN VALIDA\n";
                system("pause");
                system("cls");
            }
           
        }
    }    
    }

menuAdmin(){
    while(true){
    int option2=0;
    system("cls");
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
        cin>>option2;
        if(option2==0)break;
        switch(option2){
            case 1:{
               //altas
                system("cls");
                adminAltas();
                break;
            }
            case 2:{
                //bajas
                adminBajas();
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
                system("cls");
                adminInventario();
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
            default:{
                system("cls");
                cout<<"SELECCONA UNA OPCIN VALIDA\n";
                system("pause");
                system("cls");
                
            } 
        }
    }         
}

adminAltas(){
    int selecionar;
    int sel2;
    while(true){
        selecionar=0;
        sel2=0;
        clearStruct();
        system("cls");  
        cout<< "************AGREGAR NUEVO PRODUCTO************\n";
        cout<< "\n presione * para salir \n\n";

        cout<< "*escribe el nombre del producto\n";cin>>prodActual.producto;
        if(prodActual.producto=="*") break;
        if(exist(prodActual.producto,-1)==0){
           
            cout<< "*escribe el Precio de Compra del producto \n";cin>>prodActual.pc;
            cout<< "*escribe el Precio de Venta del producto \n";cin>>prodActual.pv;
            cout<< "*escribe la Cantidad en Existencia del producto \n";cin>>prodActual.existencias;
            cout<< "*escribe el Nivel de Reorden del producto \n";cin>>prodActual.nReorden;
            cout<< "*escribe el ST \n";cin>>prodActual.st;

                    //script llenar datos:
            system("cls");
            cout<< "\n DATOS PARA AGREGAR"<<endl;
            imprimir(2);
            imprimir(3);    
            cout<< "\n\n desea insertar los datos? \n1.-agregar \n 2.-cancelar"<<endl;cin>>selecionar;   
            if (selecionar==1){
                // stock[nDatos].id=prodActual.id;
                // stock[nDatos].producto=prodActual.producto;
                // stock[nDatos].pc=prodActual.pc;
                // stock[nDatos].pv=prodActual.pv;
                // stock[nDatos].existencias=prodActual.existencias;
                // stock[nDatos].nReorden=prodActual.nReorden;
                // stock[nDatos].st=prodActual.st;
                stock[nDatos]=prodActual;
                idNuevo++;
                nDatos++;
            }else{break;
            }
        }else{
            cout<< "\n\n el producto que ha ingresado ya existe. desea ingresar otro?\n1.- SI\n2.- NO"<<endl;cin>>sel2;
            if(sel2==2)break;
        }              
    }
    }

adminBajas(){
    int idErase;
    cout<< "|\tid\t|  nombre\t| precio compra\t| precio venta\t| Existencia\t| N Reorden\t|\tst\t|\n";
    cout<< ".--------------------------------------------------------------------------------------------------------.\n";
        for(int i=0;i<nDatos;i++){
            cout<<"|\t"<<
                stock[i].id<<"\t|\t"<<
                stock[i].producto<<"\t|\t"<<
                stock[i].pc<<"\t|\t"<<
                stock[i].pv<<"\t|\t"<<
                stock[i].existencias<<"\t|\t"<<
                stock[i].nReorden<<"\t|\t"<<
                stock[i].st<<"\t|\n";
                
        }
    cout<<"\nId de producto a eliminar: ";cin>>idErase;
    
}

adminInventario(){
    char salir[1];
    cout<< "\n\n ******INVENTARIO******"<<endl;
    imprimir(2);
    imprimir(1);
    system("pause");
    //menuAdmin();
}

menuVentas(){
}
//funcion de busqueda por id y producto 
exist(string texto,int option){

    //data temporal 
    Product prodTemp;

    for(int i=0;i<nDatos;i++){

        prodTemp = stock[i];
        if(option==-1){
            if(prodTemp.producto==texto){
                prodActual=prodTemp;
                return 1;
            }
        }else{
            if(prodTemp.id==option){
                prodActual=prodTemp;
                return 1;
            }
        }
    }
    return 0;  
}
//funcion de impresion base de datos
void imprimir(int option){

    //menu impresiones
    switch(option){
        case 1:{
            //imprimir todos los datos
            for(int i=0;i<nDatos;i++){
                cout<<setw(4)<<
                stock[i].id<<setw(12)<<
                stock[i].producto<<setw(15)<<
                stock[i].pc<<setw(15)<<
                stock[i].pv<<setw(12)<<
                stock[i].existencias<<setw(8)<<
                stock[i].nReorden<<setw(4)<<
                stock[i].st<<"\n";
            }
            break;
        }
        case 2:{
            //imprimir titulos
            cout<<"\n"<<setw(4)<<"id"<<setw(12)<<"nombre"<<setw(15)<<"precio compra"<<setw(15)<<"precio venta"<<setw(12)<<"Existencia"<<setw(8)<<"N Reorden"<<setw(4)<<"st\n";
            break;
        }
        case 3:{
            //imprimir resultado
            cout<<setw(4)<<
                prodActual.id<<setw(12)<<
                prodActual.producto<<setw(15)<<
                prodActual.pc<<setw(15)<<
                prodActual.pv<<setw(12)<<
                prodActual.existencias<<setw(8)<<
                prodActual.nReorden<<setw(4)<<
                prodActual.st<<"\n";
        }
    }
}
//vaciado del puntero
void clearStruct(){
    prodActual.id=0;
    prodActual.producto="";
    prodActual.existencias=0;
    prodActual.pc=0;
    prodActual.pv=0;
    prodActual.nReorden=0;
    prodActual.st=0;
}