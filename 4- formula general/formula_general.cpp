
#include <iostream>
#include <cmath>

using namespace std;

int main(){

    //declaraciones
        int a;
        int b;
        int c;
 

    //input
        cout<< "escribe el coeficinete del termino cuadratico: \n";
        cin>>a;

        cout<< "escribe el coeficiente del termino lineal: \n";
        cin>>b;

        cout<< "escribe el coeficiente del termino independiente: \n";
        cin>>c;

    //logica
        int b1 = 0-b;
        int b2 = b*b;
        c =4 * a * c;
        int d = b2-c;

    //----------pruebas
        // cout<<b1<<" = b1\n"<<b2<<" = b2\n"<<c<<" = c"<<d<<" = d";

        if(d<=0)
            {
    //----------error
                cout<<"la ecuacion no tiene solucion";
                return 0;
            }else
            {
                double raiz= sqrt(d);
       
                float x1= (b1+raiz)/(a*2);
                float x2= (b1-raiz)/(a*2);

    //----------output
                    cout<< "\nel valor de x1 es igual a: "<<x1;
                    cout<< "\nel valor de x2 es igual a: "<<x2;
                    return 0;

            }
        
}