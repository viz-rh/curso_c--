
#include <iostream>

using namespace std;

int main(){

    // declaraciones
    float base;
    float altura;
    float area;

    //input
    cout<< "escribe la medida de la base del triangulo: ";
    cin>>base;

    cout<< "escribe la medida de la altura del triangulo: ";
    cin>>altura;
    
    //logica
    area=(base*altura)/2;

    //output
    cout<< "el area del triangulo es igual a: "<<area;
    return 0;
}
