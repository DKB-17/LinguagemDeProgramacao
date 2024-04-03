#include <iostream>

using namespace std;

void imprimeVetor(char[]);

int main(){

    char vetString[] = "Hello World!";

    cout << "String: " ;
    imprimeVetor(vetString);


}

void imprimeVetor(char vetor[]){
    for(int i = 0; vetor[i] != '\0';i++){
        cout << vetor[i];
    }
}
