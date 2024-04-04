#include <iostream>


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


void busca_serial(registro reg[], int tamanho){

    int codigo;

    cout << "Digite o codigo buscado: ";
    cin >> codigo;

    int i = 0;
    for (; i < tamanho && codigo > reg[i].codigo; i++);
    if (reg[i].codigo == codigo){
        cout << "Cliente encontrado" << endl << endl;
        reg[i].imprimir();
    }else{
        cout << "Cliente nao encontrado" << endl;
    }

}

void menu(){
    cout << "Menu" << endl;

    cout << "/n 1 - Adicional na lista";
    cout << "/n 1 - Buscar";

}

int main(){

    int tamanho = 5;
    registro lista[tamanho];

    int i;
    for (i = 0; i<tamanho;i++){
        lista[i].leitura();
    }
    busca_serial(lista, tamanho);


    return 0;
}

