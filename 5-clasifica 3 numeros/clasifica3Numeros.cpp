#include <iostream>

using namespace std;

int main(){
    float a, b, c, d;
    cout<< "escribe el primer numero: ";
    cin>> a;
    cout<< "escribe el segundo numero: ";
    cin>> b;
    cout<< "escribe el terccer numero: ";
    cin>> c;

    a>=b? d=a : d=b;
    d>=c? d=d : d=c;
    cout<< "\n\n\nel numero mayor es: "<<d<<"\n\n";
}
