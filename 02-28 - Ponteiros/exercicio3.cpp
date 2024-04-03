#include <iostream>
#include <conio.h>

using namespace std;

float func(int &x, int &y, int &z) {
    int aux;
    if(y < z){}else{
        aux = y;
        y = z;
        z = aux;
    }
    if(y < x){
        aux = x;
        x = y;
        y = aux;
    }
    if(z > x){
            aux = x;
            x = z;
            z = aux;
    }

    return ((x+y+z)/3);
}

int main(){

    int a,b,c;

    cout << "Digite os valores A, B, C :" ;
    cin >> a >> b >> c;


    cout << "menor valor: " << a << endl;
    cout << "Maior valor: " << c << endl;
    cout << "Media: " << func(a,b,c) << endl;
    
    getch();

}