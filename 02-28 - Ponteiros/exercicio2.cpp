#include <iostream>
#include <conio.h>

using namespace std;

void somEave(int &x, int &y){
    float sum = x + y;
    float med = (x+y)/2;

    x = sum;
    y = med;

};


int main(){

    int a,b;

    cout << "Digite o valor de A e B:";
    cin >> a >> b;

    somEave(a,b);

    cout << "Soma: " << a << endl;
    cout << "Media: " << b << endl; 
    getch();
}
