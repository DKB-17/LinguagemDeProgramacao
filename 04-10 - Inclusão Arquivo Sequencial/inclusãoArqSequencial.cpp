#include <iostream>

using namespace std;

struct registro{
    int cod;

    void ler(){
        cout << "\nLeitura";
        cout << "\nCod: ";
        cin >> cod;
    }
    void mostrar(){
        cout << "\nCod: " << cod;
    }
};


int main(){

    int tamanho = 10

    registro arqS[tamanho];
    registro arqT[tamanho/2];
    registro arqA[tamanho/2];

    int contS, contT, contA;
    contS = 0;
    contT = 0;
    contA = 0;
    char sair;


    for(int i=0; i<(tamanho/2) && sair != 's' ;i++){
        arqS.ler();
        contS += 1;
        cout << "Deseja sair: ";
        cin >> sair;
    }
    for(int i=0; i<(tamanho/2) && sair != 's' ;i++){
        arqT.ler();
        contT += 1;
        cout << "Deseja sair: ";
        cin >> sair;
    }

    int i,j,k;
    i = 0; //arqA
    j = 0; //arqS
    k = 0; // arqT
    for(;i<contA;i++){
        if (j < contS && k < contT){
            if(arqS[j].cod < arqT[k].cod){
                arqA[i] = arqS[j];
                j++;
            }else{
                arqA[i] = arqT[k];
                k++;
            }
        }else if(j < contS)){
            arqA[i] = arqS[j];
            j++;
        }else {
            arqA[i] = arqT[k];
            k++;
        }
    }

    return 1;

}

