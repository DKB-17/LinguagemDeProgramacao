#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

void imprime_string(const char*);

int main(){

    char vetString[] = "Isso refere-se a um conjunto de caracteres";
    cout << "A string = \n";
    imprime_string(vetString);
    cout << endl;

}

void imprime_string(const char *sptr){
    for(;*sptr!='\0'; sptr++){ // nao precisa de inicialização
        cout << *sptr;
    }
}
