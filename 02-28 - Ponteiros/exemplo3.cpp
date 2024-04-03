#include <iostream>
#include <conio.h>

using namespace std;

void funcaltera(int *pontk){

    *pontk = *pontk + *pontk + 3;
}

int main(){

    int n = 5;
    cout << "O valor original do numero: " << n;
    funcaltera(&n);
    cout << "\n\nO novo valor do numero = " << n;
    getch();
    return 0;
}