#include <iostream>
#include <string.h>

using namespace std;

int main(){

    char nome1[] = "Giovanna";
    char nome2[10];
    char nome3[] = "Carol";
    char nome4[10];
    char nome5[] = "Vinicius";
    char nome6[10];
    char nome7[] = "Manuela";
    char nome8[10];

    strcpy(nome2,nome1);

    cout << strcmp(nome1, nome3) << endl;
    cout << "Nome1 = " << nome1 << endl;
    cout << "Nome2 = " << nome2 << endl;



}
