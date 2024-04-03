#include <iostream>
#include <math.h>

using namespace std;

void somavetor(int*, int);

int main(){

    int tamanho = 10;
    int vetor[tamanho]; // todo arranjo(vetor) é um ponteiro
    int *ptr;
    ptr = vetor; // ou ptr = &vetor[0];


    for (int i = 0; i < tamanho; i++){
        vetor[i] = rand()%10;
    }

    for (int i= 0; i < tamanho; i++){
        cout << "Elemento " << i << " = " << *ptr++; // o comando *ptr++ usado dentro de um cout faz a execução imprimindo primeiro o valor apontado pelo ponteiro e depois soma +1 no ponteiro deslocando ele de posicao
        cout << endl;
    }

    somavetor(vetor, tamanho); // a entrada na funcao deveria ser um ponteiro, entretando todo vetor e arranjo travalho com vetor e funciona entrada como ponteiro

    for (int i= 0; i < tamanho; i++){
        cout << "Elemento " << i << " = " << *ptr++; // o comando *ptr++ usado dentro de um cout faz a execução imprimindo primeiro o valor apontado pelo ponteiro e depois soma +1 no ponteiro deslocando ele de posicao
        cout << endl;
    }


    return 0;
}

void somavetor(int *ptrvetor, int MAX){
    int soma = 10;
    for (int i = 0; i < MAX;i++){
        *ptrvetor = *ptrvetor + soma;
        ptrvetor++;
    }

}
