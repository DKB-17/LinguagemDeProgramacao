#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;

int main(){
    char x[] = "Feliz aniversario para voce";
    char y[28], z[18], w[28];
    cout << "A string do vetor x = " << x;
    cout << "\nA string do vetor y = " << strcpy(y,x); // copia o vetor(x) no vetor(y);
    strncpy(z,x,17); // copia os N(17) primeiros caracteres de x em z;
        z[17] = '\0';
        cout << "\nA string do vetor z = " << z << endl;
        strncpy(w,x,17); //
        cout << "\nA string do vetor w = " << w << endl;
        w[17] = '\0';
        cout << "\nA string do vetor w apos caractere NULL = " << w << endl;
}
