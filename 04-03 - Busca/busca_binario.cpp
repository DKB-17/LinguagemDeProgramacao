#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

struct registro{
    int cod;
    string nome;
    string endereco;
    string cidade;
    char uf[2];

    void leitura(){
        cout << "\nLeitura do registro" << endl;
        cin >> cod;
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
        cout << "\n" << cod << "\t" << nome << "\t\t" << endereco << "\t\t" << cidade << "\t\t" << uf << endl;
    }
};

void busca_binaria(registro li[], int tamanho){

    int codigo;

    cout << "Digite o codigo buscado: ";
    cin >> codigo;

    int i, f, m;
    i = 0;
    f = tamanho - 1;
    m = (i+f)/2;
    while (i < f && codigo != li[m].cod){
    if(li[m].cod < codigo){
        i = m + 1;
    }else {
        f = m - 1;
    }
    m = (i+f)/2;
}
    if (codigo == li[m].cod){
        li[m].imprimir();
    }else {
        cout << "Codigo nao encontrado" << endl;
    }
}

int main(){

    int tamanho = 2;
    registro lista[tamanho];

    int i;
    for (i = 0; i<tamanho;i++){
        lista[i].leitura();
    }

    busca_binaria(lista, tamanho);
    busca_binaria(lista, tamanho);
    busca_binaria(lista, tamanho);
    busca_binaria(lista, tamanho);
    busca_binaria(lista, tamanho);


    return 0;

}


