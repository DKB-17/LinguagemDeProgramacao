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

int busca_serial(registro reg[], int tamanho){

    int codigo;

    cout << "Digite o codigo buscado: ";
    cin >> codigo;

    int i;
    for (i = 0; i < tamanho; i++){
        if (reg[i].codigo == codigo){
            return i;
        }
        if (reg[i].codigo > codigo){
            i = tamanho;
        }
    }
    return -1;
}


int main(){

    int tamanho = 5;
    registro lista[tamanho];

    int i;
    for (i = 0; i<tamanho;i++){
        lista[i].leitura();
    }

    int busca = busca_serial(lista, tamanho);
    if (busca || busca == 0 ){
        lista[busca].imprimir();
    }else {
        cout << "Registro nao encontrado";
    };

    return 0;
}

