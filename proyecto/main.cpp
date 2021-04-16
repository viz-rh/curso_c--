#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>  
#include <iomanip>

using namespace std;
//base de datos principal
struct Product{
    int idGeneral;
    int id;
    string producto;
    float pc;
    float pv;
    int existencias;
    int nReorden;
    int st;
};
struct Usuario{
    int idGeneral;
    string usuario;
    string pass;
    int tipo;
    int st;
};

int ventas[50][4]; // 0=idCliente    1=idVendor  2=idProd    3=cant 
int venta[4];
//contadores de limite
int nDatos, idNuevo, userIdNuevo, sesion; 
int vActual=0;
//para intento de resolucion menus inestables
int option2, optionM1;
//proto menus
void menu1();
void menuAdmin();
void adminAltas();
void adminBajas();
void adminConsulta();
void adminInventario();
void adminModific();
void adminUsuarios();
void userAltas();
void userBajas();
void userConsultas();
void userModific();
void userinventario();
void menuVentas();
void adminCheckOut();
//proto function
int exist(string texto,int option);
void imprimir(int optiontype, int option);
int editProd(int optiontype, int option);
int autenticacion(int option);
void clearStruct();
int imprimirTicket(int option);
int agregar(int option);

//llenar datos
Product prodActual;
Product limpiarprod;
Product stock[50];
Usuario usuarios[10];
Usuario limpiarUser;
Usuario userActual;

void llenarDatos(){
        stock[0].idGeneral=0;
        stock[1].idGeneral=1;
        stock[2].idGeneral=2;
        stock[3].idGeneral=3;
        stock[4].idGeneral=4;

        stock[0].id=2;
        stock[1].id=4;
        stock[2].id=1;
        stock[3].id=3;
        stock[4].id=5;

        stock[0].producto="leche";
        stock[1].producto="pan";
        stock[2].producto="agua";
        stock[3].producto="huevos";
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

        //llenado de datos de usuario
        usuarios[0].idGeneral=0; usuarios[0].usuario="admin";    usuarios[0].pass="123"; usuarios[0].tipo=1;  usuarios[0].st=1;
        usuarios[1].idGeneral=1; usuarios[1].usuario="vend1";    usuarios[1].pass="123"; usuarios[1].tipo=2;  usuarios[1].st=1;
        usuarios[2].idGeneral=2; usuarios[2].usuario="vend2";    usuarios[2].pass="123"; usuarios[2].tipo=2;  usuarios[2].st=1;
        userIdNuevo=3;

    }

int main(){
    //llenamos los datos de la base
    llenarDatos();

    //iniciamos menu principal
    menu1();
}

void menu1(){
    while(true){
        optionM1=0;
        system("cls");
        cout<< "*************** MEMU PRINCIPAL ***************\n\n";
        cout<< "*escribe un numero para seleccionar una opcion\n";
        cout<< " 1   ADMINISTRADOR\n";
        cout<< " 2   VENTAS\n";
        cout<< " *   SALIR\n";
        cin>>optionM1;
        cin.clear();
        cin.sync();
        if(optionM1==0)break;
        //TODO******-------------------> conversor de string a int. <---------------------------*******
        //TODO******-------------------> seleccion de opciones con string. <---------------------------*******
        switch(optionM1){
            case 1:{
                if(autenticacion(1)==1){
                    system("cls");
                    menuAdmin();
                }
                break;
            }
            case 2:{
                if(autenticacion(2)==1){
                    system("cls");
                    menuVentas();
                }
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

void menuAdmin(){   
    while(true){
    option2=0;
    system("cls");
        cout<< "*************** MEMU ADMINISTRACION ***************\n\n";
        cout<< "*escribe un numero para seleccionar una opcion\n";
        cout<< " 1   Altas\n";
        cout<< " 2   Bajas\n";
        cout<< " 3   Consultas\n";
        cout<< " 4   Modificaciones\n";
        cout<< " 5   Mostrar inventario\n";
        cout<< " 6   Administracion de cuentas de usuario\n";
        cout<< " 7   Corte de caja general\n";
        cout<< " *   Regresar al menu principal\n";
        cout<< " opcion: ";
        cin>>option2;
        cin.clear();
        cin.sync();
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
                system("cls");
                adminBajas();
                break;
            }
            case 3:{
                //consultas
                system("cls");
                adminConsulta();
                break;
            }
            case 4:{
                //modificaciones
                adminModific();
                break;
            }
            case 5:{
                //inventario
                system("cls");
                adminInventario();
                break;
            }
            case 6:{
                 //usuarios
                system("cls");
                adminUsuarios();
                break;
            }
            case 7:{
                //corte de caja
                adminCheckOut();
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

void adminAltas(){
    int selecionar;
    int sel2;
    while(true){
        selecionar=0;
        sel2=0;
        clearStruct();
        system("cls");  
        cout<< "************AGREGAR NUEVO PRODUCTO************\n";
        cout<< "\n presione * para salir \n\n";

        cout<< "producto: ";cin>>prodActual.producto;
        if(prodActual.producto=="*") break;
        switch(exist(prodActual.producto,-1)){ // exist(nombre producto buscar, en: estructura productos)
            case -1:{ //no existe producto con mismo nombre
                do{
                    cout<< "Precio de Compra: \n";cin>>prodActual.pc;
                    cout<< "Precio de Venta: \n";cin>>prodActual.pv;
                    if(prodActual.pc>=prodActual.pv){
                        cout<<"ERROR: EL PRECIO DE COMPRA DEBE SER MENOR AL PRECIO DE VENTA\n";
                    }
                }while(prodActual.pc>=prodActual.pv);
                
                do{
                    cout<< "Cantidad en Existencia: \n";cin>>prodActual.existencias;
                    cout<< "Nivel de Reorden: \n";cin>>prodActual.nReorden;
                    if(prodActual.existencias<=prodActual.nReorden){
                        cout<<"ERROR: EL NUMERO DE EXISTENCIAS DEBE SER MAYOR AL NIVEL DE REORDEN\n";
                    }
                }while(prodActual.existencias<=prodActual.nReorden);
                prodActual.st=1;
                prodActual.id=idNuevo;
                agregar(-1); // (-1: agregar en estructura productos)
                break;
            }
            case -2:{ //ya existe un producto con mismo nombre
                cout<< "\n\n PRODUCTO YA EXISTENTE.";
                break;
            }
            case  0:{ //existe producto inactivo con mismo nombre
                system("cls");
                imprimir(-1,-2);// (-1: estructura productos, -2: imprimir titulos)
                imprimir(-1,-3);// (-1: estructura productos, -2: imprimir producto en uso)
                cout<< "\n\n PRODUCTO INACTIVO.\ndesea darlo de alta?\n1.- SI\n2.- NO"<<endl;cin>>sel2;
                if(sel2==1){
                    stock[prodActual.idGeneral].st=1;
                }
                break;
            }

        }
    }
}

void adminBajas(){
    while(true){
        clearStruct();
        imprimir(-1,-2);
        imprimir(-1,-1);
                    // PEDIR NOMBRE DEL PRODUCTO PARA ELIMINAR 
        cout<<"\nEscribe el nombre del producto para Bajar o escribe * para salr: ";cin>>prodActual.producto;
        if(prodActual.producto=="*")break;

        //buscamos info del producto
        switch (exist(prodActual.producto,-1)){ //buscar nombre de producto, en estructura productos
            case -1:{ //no existe producto
                system("cls");
                cout<<"Producto no existente. intente de nuevo\n";
                system("pause");
                break;
            }
            case  0:{ //el producto ya esta dado de baja
                system("cls");
                cout<<"el producto ya esta dado de baja\n";
                system("pause");
                break;
            }           
            case -2:{ //el producto es accesible para baja 
                //int opcion=0;
                imprimir(-1,-2); //imprimir titulos
                imprimir(-1,-3); //imprimir producto actual
                editProd(-1,-1);
                cout<<"\nlisto!\n";
                system("pause");
            }
        }
    }  
}

void adminConsulta(){
    int encontrado;
    string entrada;
    while(true){
        clearStruct();
        encontrado=0;
        //busqueda por nombre
        cout<<"escribe el nombre del producto buscado o * para salir: ";cin>>entrada;
        if(entrada=="*") break;
        encontrado = exist(entrada,-1);
        
        system("cls");
        if(encontrado==-2){
            imprimir(-1,-2);
            imprimir(-1,-3);
            cout<<endl;
        }else if(encontrado==-1){
            cout<<"el producto no existe\n";
        }else{
            cout<<"el producto esta dado de baja\n";
        }            
        
    }
}

void adminModific(){
    while(true){
        clearStruct();
        system("cls");
        cout<<"\nEscribe el nombre del producto a editar o escribe * para salir: ";cin>>prodActual.producto;
        if(prodActual.producto=="*")break;

        switch (exist(prodActual.producto,-1)){
        //no existe producto
            case -1:{
                system("cls");
                cout<<"Producto no existente. intente de nuevo\n";
                system("pause");
                break;
            }
        //el producto esta dado de baja
            case 0:{
                system("cls");
                cout<<"el producto no esta disponible\n";
                system("pause");
                break;
            }
        //el producto es accesible para editar  
            case -2:{
                int opcion=0;
                do{ 
                    system("cls");
                    imprimir(-1,-2);
                    imprimir(-1,-3);
                    cout<<"\nque valor desea modificar? \n1.-nombre \n2.-precio compra \n3.-precio venta \n4.-Existencia \n5.-N Reorden \n0.-TERMINAR Y ACTUALIZAR \n\nrespuesta: ";cin>>opcion;
                    switch(opcion){
                        //nombre
                        case 1:{
                            cout<<"NOMBRE: ";cin>>prodActual.producto;
                            break;
                        }
                        //pCompra
                        case 2:{
                            cout<<"PRECIO DE COMPRA: ";cin>>prodActual.pc;
                            break;
                        }
                        //pVenta
                        case 3:{
                            cout<<"PRECIO DE VENTA: ";cin>>prodActual.pv;
                            break;
                        }
                        //existencia
                        case 4:{
                            cout<<"EXISTENCIAS: ";cin>>prodActual.existencias;
                            break;
                        }
                        //nReorden
                        case 5:{
                            cout<<"NIVEL DE REORDEN: ";cin>>prodActual.nReorden;
                            break;
                        }    
                    }
                    if(opcion==0 && (prodActual.pc>=prodActual.pv || prodActual.existencias<=prodActual.nReorden)){
                        system("cls");
                        cout<<"el valor para precio de compra debe ser menor que el precio de venta\n";
                        cout<<"el valor para existencias debe ser mayor al nivel de reorden\n\n";
                        system("pause");
                        opcion=8;
                    } 
                }while(opcion!=0);
                
                system("cls");
                cout<<"********DATOS MODIFICADOS CORRECTAMENTE********";
                imprimir(-1,-2);
                imprimir(-1,-3);
                editProd(-1,-2);
                cout<<"listo!\n";
                system("pause");
            }
        }
    }
}

//cuentas de ususario
void adminUsuarios(){
    int option3;
    while(true){
        option3=0;
        system("cls");
        cout<< "*************** MEMU USUARIOS ***************\n\n";
        cout<< "*escribe un numero para seleccionar una opcion\n";
        cout<< " 1   Altas\n";
        cout<< " 2   Bajas\n";
        cout<< " 3   Consultas\n";
        cout<< " 4   Modificaciones\n";
        cout<< " 5   Mostrar cuentas de usuario\n";
        cout<< " *   regresar al menu anterior\n";
        cin>>option3;
        cin.clear();
        cin.sync();
        if(option3==0) break;
        switch(option3){
            case 1:{
                //alta usuarios
                system("cls");
                userAltas();
                break;
            }
            case 2:{
                //baja Usuarios
                system("cls");
                userBajas();
                break;
            }
            case 3:{
                //consultas
                system("cls");
                userConsultas();
                break;
            }
            case 4:{
                //modificaciones
                system("cls");
                userModific();
                break;
            }
            case 5:{
                //inventario
                system("cls");
                userinventario();
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
    void userAltas(){
        int sel2;
        while(true){
            clearStruct();
            system("cls");  
            cout<< "************AGREGAR NUEVO USUARIO************\n";
            cout<< "escribe el nombre del usuario o * para salir\n";cin>>userActual.usuario;
            if(userActual.usuario=="*") break;
            switch(exist(userActual.usuario,-2)){ //exist(nobre de usuario, estrucutura usuarios)
                case -1:{ //usuario disponible (no encontrado usuario con mismo nombre)
                    cout<< "escribe el pass\n";cin>>userActual.pass;
                    cout<< "escribe el tipo de usuario\n";cin>>userActual.tipo;
                    userActual.st=1;
                    userActual.idGeneral=userIdNuevo;
                    agregar(-2);
                    break;
                }
                case -2:{ //usuario ya existe
                    cout<< "\n\n el usuario que ha ingresado ya existe.";
                    system("pause");
                    break;
                }
                case  0:{ //usuario dado de baja
                    imprimir(-2,-2);
                    imprimir(-2,-3);
                    cout<< "\n\n el usuario que ha ingresado ya existe y esta dado de baja.\ndesea darlo de alta?\n1.- SI\n2.- NO"<<endl;cin>>sel2;
                    if(sel2==1)stock[userActual.idGeneral].st=1;
                }    
            }
        }
    }
    void userBajas(){
        while(true){
            clearStruct();
            imprimir(-2,-2);
            imprimir(-2,-1);

                        // PEDIR NOMBRE DEL USUARIO PARA ELIMINAR 
            cout<<"\nEscribe el nombre del ususario para Bajar o escribe * para salir: ";cin>>userActual.usuario;
            if(userActual.usuario=="*")break;
            //buscamos info del producto
            switch (exist(userActual.usuario,-2)){
                case -1:{//no existe usuario
                    system("cls");
                    cout<<"usuario no existente. intente de nuevo";
                    system("pause");
                    break;
                }           
                case  0:{//el ususario ya esta dado de baja
                    system("cls");
                    cout<<"el usuario ya esta dado de baja\n";
                    system("pause");
                    break;
                }               
                case -2:{//el usuario es accesible para baja 
                    int opcion=0;
                    imprimir(-2,-2);
                    imprimir(-2,-3);
                    editProd(-2,-1);
                    cout<<"listo!\n";
                    system("pause");
                }
            }
        }  
    }
    void userConsultas(){
        int encontrado;
        string entrada;
        while(true){
            clearStruct();
            encontrado=0;
            //busqueda por nombre 
            cout<<"escribe el nombre del usuario buscado o * para salir: ";cin>>entrada;
            if(entrada=="*") break;
            encontrado = exist(entrada,-2); //exist(nombre usuario a buscar,en estructura usuarios)

            system("cls");
            if(encontrado==-2){ //usuario encontrado
                imprimir(-2,-2);
                imprimir(-2,-3);
            }else if(encontrado==-1){
                cout<<"no se encontro el ususario\n";
            }else{
                cout<<"el usuario no esta activo\n";
            }
            system("pause");
            system("cls");
        }
    }
    void userModific(){
        while(true){
            clearStruct();
            system("cls");
            cout<<"\nEscribe el nombre del usuario a editar o escribe * para salir: ";cin>>userActual.usuario;
            if(userActual.usuario=="*")break;

            switch (exist(userActual.usuario,-2)){
                case -1:{//no existe el usuario
                    system("cls");
                    cout<<"usuario no existente. intente de nuevo\n";
                    system("pause");
                    break;
                }            
                case 0:{//el producto esta dado de baja
                    system("cls");
                    cout<<"el usuario no esta disponible\n";
                    system("pause");
                    break;
                }    
                case -2:{//el producto es accesible para editar  
                    system("cls");
                    int opcion=0;
                    imprimir(-2,-2);
                    imprimir(-2,-3);
                    do{
                        cout<<"\nque valor desea modificar? \n1.-nombre de ususario \n2.-pass \n3.-tipo \n\n0.-TERMINAR Y ACTUALIZAR \nrespuesta: ";cin>>opcion;
                        switch(opcion){
                            //usuario
                            case 1:{
                                cout<<"NOMBRE DEL USUARIO: ";cin>>userActual.usuario;
                                break;
                            }
                            //pass
                            case 2:{
                                cout<<"PASS: ";cin>>userActual.pass;
                                break;
                            }
                            //tipo
                            case 3:{
                                cout<<"TIPO: ";cin>>userActual.tipo;
                                break;
                            }
                        }    
                    }while(opcion!=0);
                    
                    system("cls");
                    cout<<"********DATOS MODIFICADOS********";
                    imprimir(-2,-2);
                    imprimir(-2,-3);
                    editProd(-2,-2);
                    cout<<"listo!\n";
                    system("pause");
                    
                }
            }
        }
    }
    void userinventario(){

        cout<< "\n\n ******USUARIOS ******"<<endl;
        imprimir(-2,-2);
        imprimir(-2,-1);
        system("pause");
    }

void adminInventario(){
    int opcion=0; //manejador de opcion para salida
    Product aux; //variable auxiliar para reorden
    Product a[50]=stock; //copia del orden original de stock

    while(true){
        cout<<"\n1.- ordenar por id\n2.-ordenar por nombre del producto\n*.- salir";cin>>opcion;
        cin.clear();
        cin.sync();
        if(opcion==0) break;

        //impresion de cabeceras
        cout<< "\n\n ******INVENTARIO******"<<endl;
        imprimir(-1,-2);
        cout<<"  resurtir";

        switch(opcion){    
            case 1:{ //reorden acendente por id
                for (int i = 0; i <  nDatos; i++) {
                    for (int j = 0; j < nDatos - 1; j++) {
                        if (stock[j].id > stock[j + 1].id){
                            aux = stock[j];
                            stock[j] = stock[j + 1];
                            stock[j + 1] = aux;
                        }
                    }
                }
                break;
            }
            case 2:{ //reorden acendente por nombre prod
                for (int i=1; i<nDatos; i++){
                    for (int j=0 ; j<nDatos - 1; j++){
                        auto arreglo1=stock[j].producto.c_str();
                        auto arreglo2=stock[j+1].producto.c_str();
                        if (strcmp(arreglo1,arreglo2)>0){
                            aux = stock[j];
                            stock[j] = stock[j+1];
                            stock[j+1] = aux;
                        }
                    }
                }
                break;
            }
                  
        }
        //impresion
        for(int i = 0; i <  nDatos; i++){
            exist(stock[i].producto,-1);
            if(prodActual.st==1){
                imprimir(-1,-3);
                if(prodActual.existencias<=prodActual.st){
                    cout<<setw(6)<<"*";
                }
            }
            
        }    
        cout<<endl;
        system("pause"); 
    }
    // restauracion orden original
        for(int i=1; i<=nDatos; i++){
            stock[i]=a[i];
        }
}

void adminCheckOut(){
    system("cls");
    float suma[]={0,0};
    for(int i=0; i<vActual;i++){
        suma[0]=suma[0]+(ventas[i][3]*stock[ventas[i][2]].pv); // 0=idCliente    1=idVendor  2=idProd    3=cant 
        suma[1]=suma[1]+(ventas[i][3]*stock[ventas[i][2]].pc); // 0=idCliente    1=idVendor  2=idProd    3=cant 
    }  
    cout<<"*******CORTE GENERAL********\n\n";
    cout<<"ingresos netos: "<<suma[0]<<endl;
    cout<<"egresos netos: "<<suma[1]<<endl;
    cout<<"ganancias totales: "<<suma[0]-suma[1]<<endl;
    system("pause");  
}

void menuVentas(){
    string option;
    
    cout<<"**EN VENTAS**\n";
    cout<<"*escribe * para imprimir ticket o ** para salir\n";
    cout<<"\ncliente "<<venta[0]+1<<"\n";
    venta[0]=0;
    while(true){
        //limpiar estructura
        clearStruct(); 
        //agregar dato idVendedor
        venta[1]=sesion;       
        // pedir nombre del producto
        cout<<"producto: ";cin>>prodActual.producto;

        if(prodActual.producto=="*"){
            //imprimrTicket(uno);
            system("cls");
            imprimirTicket(-1);
            
            cout<<"**EN VENTAS**\n";
            cout<<"*escribe * para imprimir ticket o ** para salir\n";
            cout<<"\ncliente "<<venta[0]++<<"\n";
        //verificar si quiere salir
        }else if(prodActual.producto=="**"){    
            //imprimirTicket(todos)
            system("cls");
            imprimirTicket(-2);
            venta[0]++;
            break;
        }else{

            //switch(verificar si existe el producto)
            switch(exist(prodActual.producto,-1)){                   
                //case(no existe)
                case -1:{
                    cout<<"\tverifique el nombre del producto\n";
                    break;
                }
                //case(no esta activo el producto)
                case 0:{
                    cout<<"\tel producto no esta disponible\n";
                    break;
                }
                //case(si existe)
                case -2:{
                    if(prodActual.existencias==0){
                        cout<<"\tel producto esta agotado\n\n";
                    }else{
                        //agregar dato idProducto a ventas[]
                        venta[2]=prodActual.idGeneral;
                        //pedir la cantidad a vender
                        cout<<"cantidad: ";cin>>venta[3];

                        //verificar si cumplimos con la cantidad
                        if(venta[3]<=prodActual.existencias){
                            //quitar el numero de articulos vendidos
                            stock[prodActual.idGeneral].existencias=prodActual.existencias-venta[3];
                            //llenamos registro de ventas
                            for(int i=0;i<4;i++){
                                ventas[vActual][i]=venta[i];
                            }
                            vActual++;
                        }else{
                            //pedir confirmacion para venta
                            cout<<"\tno hay "<<venta[3]<<", solo hay "<<prodActual.existencias<<". vender "<<prodActual.existencias<<"? s/n: ";cin>>option;
                            if(option=="s"){
                                //restar a producto actual la cantidad.
                                stock[prodActual.idGeneral].existencias=0;
                                venta[3]=prodActual.existencias;
                                for(int i=0;i<4;i++){
                                    ventas[vActual][i]=venta[i];
                                }
                                vActual++;
                            }else{
                                cout<<"\tcancelado!\n\n";
                            }
                        }
                    }
                
                }
            }
        }
    }       
}

//****************funciones*****************
agregar(int option){
    int selecionar=0;
    system("cls");
    cout<< "\n DATOS AGREGADOS"<<endl;
    
    imprimir(option,-2);
    imprimir(option,-3);    
    
    if(option==-1){
        stock[nDatos]=prodActual;
        stock[nDatos].id=idNuevo;
        stock[nDatos].idGeneral=nDatos;
        idNuevo++;
        nDatos++;
    }else{
        usuarios[userIdNuevo]=userActual;
        usuarios[userIdNuevo].idGeneral=userIdNuevo;
        userIdNuevo++;
    }                
}

imprimirTicket(int option){
    if(option==-1){//opcion imprimir por cliente
        system("cls");
        cout<<"\t\t\tticket de venta\n\n";
        cout<<"\tvendedor: "<<usuarios[sesion].usuario<<endl<<endl;
        cout<<setw(12)<<"producto"<<setw(12)<<"cantidad"<<setw(20)<<"precio unitario"<<setw(14)<<"subtotal\n";
        float total=0;
        float subtotal=0;
        for(int i=0;i<vActual;i++){
            if(venta[0]==ventas[i][0] &&ventas[i][1]==sesion){// 0=idCliente    1=idVendor  2=idProd    3=cant 
                subtotal=stock[ventas[i][2]].pv*ventas[i][3];
                total=subtotal+total;

                cout<<setw(12)
                <<stock[ventas[i][2]].producto<<setw(12)
                <<ventas[i][3]<<setw(20)
                <<stock[ventas[i][2]].pv<<setw(13)
                <<subtotal<<"\n";
            }         
        }

        cout<<setw(58)<<"Total: "<<total<<endl;
        system("pause");

    }else if(option==-2){//imprimir corte de caja vendedor
        
        int prod[nDatos][2];//array de productos vendidos
        int prodvendidos=0;//index de productos vendidos
        boolean success=false;//switch "producto ya registrado en array comprado"
        for(int i=0;i<vActual;i++){//llenado de array vendidos
            if(sesion==ventas[i][1]){
                //comparacion de producto con registro de vendidos
                for(int j=0; j<prodvendidos;j++){  
                    if(prod[j][0]==ventas[i][2]){
                        //suma cantidad de productos vendidos
                        prod[j][1]=prod[j][1]+ventas[i][3];
                        success=true;
                    }
                }
                //agregado nuevo registro de vendidos
                if(success==false){
                    prod[prodvendidos][0]=ventas[i][2];
                    prod[prodvendidos][1]=ventas[i][3];
                    prodvendidos++;
                }
            }
        }
        
        //impresion 1
        cout<<"\tCORTE DE CAJA VENDEDOR\n\nproductos vendidos\n";

        cout<<setw(12)<<"producto"<<setw(20)<<"cantidad original"<<setw(10)<<"vendidos"<<setw(14)<<"restantes"<<setw(14)<<"resurtir\n";
        for(int i=0;i<prodvendidos;i++){
            exist(stock[prod[i][0]].producto,-1);
            
            string resurtir=(prodActual.existencias<prodActual.nReorden)? "*" : "";
            cout<<setw(12)
                <<prodActual.producto<<setw(20)
                <<prodActual.existencias+prod[i][1]<<setw(10)
                <<prod[i][1]<<setw(14)
                <<prodActual.existencias<<setw(14)
                <<resurtir<<"\n";
        }

        int a=ventas[vActual-1][0]+1;  //auxiliar: ultimo cliente registrado    
        float client[a][2];//0= ventas totales 1=compras totales
        
        for(int i=0;i<a;i++){
            client[i][0]=0;
            client[i][1]=0;
        }

        float totales[]={0,0};  //total vendidos y comprados
        for(int i=0;i<vActual;i++){// 0=idCliente    1=idVendor  2=idProd    3=cant 
            if(ventas[i][1]==sesion){
                //llenamos datos de venta por cliente
                for(int j=0; j<a;j++){
                    if(j==ventas[i][0]){// 0=idCliente    1=idVendor  2=idProd    3=cant 
                        client[j][0]=client[j][0]+(stock[ventas[i][2]].pv*ventas[i][3]);
                        client[j][1]=client[j][1]+(stock[ventas[i][2]].pc*ventas[i][3]);
                        totales[0]=totales[0]+stock[ventas[i][2]].pv*ventas[i][3];
                        totales[1]=totales[1]+stock[ventas[i][2]].pc*ventas[i][3];
                    }
                }
            }
        }    
        
        //impresion 2
        cout<<"\nVentas por cliente\n";
        cout<<setw(10)<<"cliente"<<setw(10)<<"vendido\n";  
        for(int i=0; i<ventas[vActual-1][0]+1;i++){
            cout<<setw(10)
            <<"cliente "<<i+1<<setw(10)
            <<client[i][0]<<"\n"; 
        }

        //impresion 3 totales
        cout<<"\nganancias\n";
        cout<<"\n\tingresos netos: "<<totales[0]<<"\t\tegresos netos: "<<totales[1]<<"\n\tganancias: "<<totales[0]-totales[1]<<endl<<endl;
        system("pause");  
        system("cls");          
    }
}
//funcion de busqueda por id y producto 
exist(string texto,int option){

    if(option==-1){
        //data temporal 
        Product prodTemp;
        for(int i=0;i<nDatos;i++){
            prodTemp = stock[i];
            if(prodTemp.producto==texto){
                prodActual=prodTemp;
                if(prodTemp.st!=1) return 0;
                return -2;
            }
        } 
        return -1;  
    }else{
        //data temporal 
        Usuario userTemp;
        for(int i=0;i<userIdNuevo;i++){
            userTemp = usuarios[i];
            if(userTemp.usuario==texto){
                userActual=userTemp;
                if(userTemp.st!=1) return 0;
                return -2;
            }
        }
        return -1;      
    }
    
}
//funcion de impresion base de datos
void imprimir(int optiontype, int option){
    //menu impresiones
    switch(option){
    //imprimir todos los datos
        case -1:{
            if(optiontype==-1){
                //imprimir todos los datos
                for(int i=0;i<nDatos;i++){
                    if(stock[i].st==0);
                    else{
                        cout<<"\n"<<setw(4)<<
                        stock[i].id<<setw(12)<<
                        stock[i].producto<<setw(15)<<
                        stock[i].pc<<setw(15)<<
                        stock[i].pv<<setw(12)<<
                        stock[i].existencias<<setw(8)<<
                        stock[i].nReorden<<setw(4)<<
                        stock[i].st;
                    }
                }
            }else{
                ////imprimir todos los datos
                for(int i=0;i<userIdNuevo;i++){
                    if(usuarios[i].st==0);
                    else{
                        cout<<setw(4)<<
                        usuarios[i].idGeneral<<setw(12)<<
                        usuarios[i].usuario<<setw(15)<<
                        usuarios[i].pass<<setw(6)<<
                        usuarios[i].tipo<<setw(4)<<
                        usuarios[i].st<<"\n";
                    }
                }
            }
            break;
        }
    //imprimir titulos
        case -2:{
            //imprimir titulos
            if(optiontype==-1){
                cout<<"\n"<<setw(4)<<"id"<<setw(12)<<"nombre"<<setw(15)<<"precio compra"<<setw(15)<<"precio venta"<<setw(12)<<"Existencia"<<setw(8)<<"N Reorden"<<setw(4)<<"st";
            }else{
                cout<<"\n"<<setw(4)<<"id"<<setw(12)<<"usuario"<<setw(15)<<"pass"<<setw(6)<<"tipo"<<setw(4)<<"st\n";
            }
            break;
        }
    //imprimir prod Actual   
        case -3:{
            //imprimir resultado
            if(optiontype==-1){
                cout<<"\n"<<setw(4)<<
                prodActual.id<<setw(12)<<
                prodActual.producto<<setw(15)<<
                prodActual.pc<<setw(15)<<
                prodActual.pv<<setw(12)<<
                prodActual.existencias<<setw(8)<<
                prodActual.nReorden<<setw(4)<<
                prodActual.st;
            }else{
                cout<<setw(4)<<
                userActual.idGeneral<<setw(12)<<
                userActual.usuario<<setw(15)<<
                userActual.pass<<setw(6)<<
                userActual.tipo<<setw(4)<<
                userActual.st<<"\n";
            }
            break;
        }
    }
}

editProd(int optiontype, int option){
    switch (option){
        case -1:{
            //eliminar producto
            if(optiontype==-1) stock[prodActual.idGeneral].st=0;
            else usuarios[userActual.idGeneral].st=0;
            break;
        }
        case -2:{
            //editar producto
            if(optiontype==-1) stock[prodActual.idGeneral]=prodActual;
            else usuarios[userActual.idGeneral]=userActual;
            break;
        }
    }
}

autenticacion(int option){
    string user;
    string pass;
        clearStruct();
        system("cls");
        cout<<"***************login***************\npulsa * para salir\n\n";
        cout<<"usuario: ";cin>>user;
        if(user=="*") return 0;
        switch(exist(user,-2)){
            case -2:{
                cout<<"\npass: ";cin>>pass;
                if(pass != userActual.pass){
                    printf("la contrasena es erronea\n");
                    system("pause");
                    return 0;
                } 
                if(option == userActual.tipo){
                    sesion=userActual.idGeneral;
                    return 1;}
                else{
                    cout<<"el usuario no tiene permisos para ver este menu\n";
                    system("pause");
                    return 0;
                }
                break;
            }
            case 0:{
                system("cls");
                cout<<"el usuario que espesifico no esta activo.\n";
                system("pause");
                return 0;
                break;
            }
            case -1:{
                system("cls");
                cout<<"el usuario que espesifico no existe.\n";
                system("pause");
                return 0;
                break;
            }

        }

}
//vaciado del onjeto
void clearStruct(){
    prodActual=limpiarprod;
    userActual=limpiarUser;
}
