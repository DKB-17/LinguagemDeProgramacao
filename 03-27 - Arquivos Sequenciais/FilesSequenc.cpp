#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct registro{
    int codigo;
    string nome;
    string endereco;
    string cidade;
    char uf[2];

    void leitura(){
        cout << "\nLeitura do registro" << endl;
        cin >> codigo;
        cout << "Nome: ";
        fflush(stdin);
        getline(cin,nome);
        cout << "Endereço: ";
        getline(cin,endereco);
        cout << "Cidade: ";
        getline(cin,cidade);
        fflush(stdin);
        cout << "Estado(UF): ";
        gets(uf);

    }

    void imprimir(){
        cout << "\n" << codigo << "\t" << nome << "\t\t" << endereco << "\t\t" << cidade << "\t\t" << uf;
    }
};



int main(){

    int tamanho = 2;
    registro lista[tamanho];

    for(int i = 0;i< tamanho;i++){
        lista[i].leitura();
    }
    cout << "\nCodigo\tNome\t\tEndereco\t\tCidade\t\tUF";
    for(int i = 0;i< tamanho;i++){
        lista[i].imprimir();
    }

    return 0;
}
