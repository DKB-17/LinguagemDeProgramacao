#include <iostream>
#include <conio.h>
using namespace std;

int main(){

    int num, fatorial=1;
    cout << "Descobra o fatorial" << endl;
    cout << "Digite um numero: ";
    cin >> num;
    for(int x = num; x > 0; x--){
        fatorial = fatorial * x;
    }
    cout << fatorial << endl;
    getch();

}
