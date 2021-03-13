#include <iostream>

using namespace std;

int main(){
    float num;
    
    cout<< "escribe el numero a multiplicar: ";
    cin>> num;

    for ( int i = 1; i <11 ; i++){
        cout<<num<<" * "<< i <<" = "<< i*num <<endl;
    }
}
