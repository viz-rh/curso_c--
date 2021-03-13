// estructura basica en c++

#include <iostream> 
#include <conio.h>

using namespace std;

struct Persona{
 char nombre[20], apellido[20];
 int edad;
};

int main(){
 Persona cliente[3];
 
 for(int i = 0; i < 1; i++){
  cout << "Nombre cliente " << i+1 <<  endl;
  cin.getline(cliente[i].nombre,20);
  cout << "Apellido cliente " << i+1 << endl;
  cin.getline(cliente[i].apellido,20);
  cout << "Edad cliente " << i+1 << endl;
  cin >> cliente[i].edad;
  cin.ignore();
 }

 cout<<cliente[0].nombre;
 return 0;
}