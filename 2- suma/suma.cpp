#include <iostream>

using namespace std;

int main(){
  //declaraciones
    int num1;
    int num2;
    int resultado;
  //input
    cout<< "escribe el primer sumando: ";
    cin>>num1;

    cout<< "escribe el segundo sumando: ";
    cin>>num2;
  //logica
    resultado=num1+num2;
  //ouput
    cout<< "el resultado de "<<num1<<" mas "<<num2<<" es igual a: "<<resultado;
    return 0;
}
