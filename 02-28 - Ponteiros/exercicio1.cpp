#include <iostream>
#include <conio.h>

using namespace std;

void sumEsub(int x, int y, int z, int &soma, int &subtracao){

    soma = x + y + z;
    subtracao = x - y - z;
}

int main(){

    int a,b,c,soma,subtracao;

    cout << "Digite os valores de A,B,C respectivamento separados pelo espaco: ";
    cin >> a >> b >> c;

    sumEsub(a,b,c,soma,subtracao);

    cout << "Resultado" << endl;
    cout << "Soma = " << soma << endl;
    cout << "Subtracao = " << subtracao << endl;
    getch();

    return 0;
}