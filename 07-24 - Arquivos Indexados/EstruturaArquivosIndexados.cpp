#include <iostream>
#include <conio.h>

using namespace std;

struct indice {
    int codigo;
    int ender;

    void imprimir() const {
        cout << codigo << "|" << ender;
    }
};
struct cliente {
    int codigo;
    string nome;
    string endereco;
    string cidade;
    char uf[2];

    void imprimir() const {
        cout << codigo << "|" << nome << "|" << endereco << "|" << cidade << "|" << uf;
    }
};

void buscaSerial(struct indice idx[], struct cliente cli[], int cont, int cod) {
    int i = 0;
    for(;i < cont && cod > idx[i].codigo; i++);
    if(cod == idx[i].codigo) {
        cout << "\n\nCliente Encontrado";
        i = idx[i].ender;
        cout << "\nCodigo do Cliente:" << cli[i].codigo;
        cout << "\nNome:" << cli[i].nome;
        cout << "\nEndereco:" << cli[i].endereco;
        cout << "\nCidade:" << cli[i].cidade;
        cout << "\nUf:" << cli[i].uf;
    }else {
            cout << "\n\n Cliente nao encontrado";
    }
    getch();
}
void buscaBinaria(struct indice idx[], struct cliente cli[], int contador, int cod) {

    int i = 0;
    int f = contador-1;
    int meio = (i+f)/2;
    for(; idx[meio].codigo != cod && i <= f; meio = (f+i)/2) {
        if(idx[meio].codigo > cod) {
            f = meio - 1;
        }else {
            i = meio + 1;
        }
    }
    if(idx[meio].codigo == cod) {
        cout << "\n\nCliente Encontrado";
        i = idx[meio].ender;
        cout << "\nCodigo do Cliente:" << cli[i].codigo;
        cout << "\nNome:" << cli[i].nome;
        cout << "\nEndereco:" << cli[i].endereco;
        cout << "\nCidade:" << cli[i].cidade;
        cout << "\nUf:" << cli[i].uf;
    }else {
        cout << "\n\n Cliente nao encontrado";
    }
    getch();
}


void add_indice(struct indice ind[], int contador, struct cliente lsd[]){
    if(contador != 0) {
        int i;
        for(i=contador; ind[i-1].codigo > lsd[contador].codigo && i>0 ;i--) {
                ind[i] = ind[i-1];
            }
        ind[i].codigo = lsd[contador].codigo;
        ind[i].ender = contador;
    }else {
        ind[contador].codigo = lsd[contador].codigo;
        ind[contador].ender = contador;
    }
}

void leitura_dados(struct cliente cliente[],int contador, struct indice ind[]) {
    cout << "\nCodigo:";
    cin >> cliente[contador].codigo;
    cout << "Nome:";
    fflush(stdin);
    getline(cin,cliente[contador].nome);
    cout << "Endereco:";
    getline(cin,cliente[contador].endereco);
    cout << "Cidade:";
    getline(cin,cliente[contador].cidade);
    fflush(stdin);
    cout << "Uf:";
    gets(cliente[contador].uf);
    add_indice(ind, contador,cliente);
}
void leitura_indice(struct indice ind[], int contador) {
    cout << "Leitura ind:";
    cout << "Codigo: ";
    cin >> ind[contador].codigo;
    cout << "Endereco: ";
    cin >> ind[contador].ender;
}

void imprimir_listas(struct cliente dados[], struct indice ind[], int contador) {

    for(int i=0; i < contador; i++) {
        cout << "\n";
        ind[i].imprimir();
        cout << "\t";
        dados[i].imprimir();
    }
}


int main() {
    int tamanho = 20;
    struct indice ind[tamanho];
    struct cliente dados[tamanho];
    int contador = 0;
    int op = 1;

    while(op != 0) {

        system("cls");
        cout << "\n Opcoes do sistema";
        cout << "\n 0 - Sair";
        cout << "\n 1 - Ler novo cliente";
        cout << "\n 2 - Exibir listas";
        cout << "\n 3 - Busca Serial";
        cout << "\n 4 - Busca Binaria";

        cout << "\n\nInsira um numero: ";
        cin >> op;

        int codigobuscado;
        if(op == 0) {
            system("cls");
            cout << "\n Tchau :)";
        }else if(op == 1) {
            if(contador < tamanho) {
                cout << "\nLeitura de cliente:";
                leitura_dados(dados, contador, ind);
                contador++;
            }else {
                cout << "\nLista cheia";
            }
            getch();
        }else if(op == 2) {
            imprimir_listas(dados, ind, contador);
            getch();
        }else if(op == 3) {
            cout << "\nDigite o codigo buscado: ";
            cin >> codigobuscado;
            buscaSerial(ind,dados,contador, codigobuscado);
            getch();
        }else if(op == 4) {
            cout << "\nDigite o codigo buscado: ";
            cin >> codigobuscado;
            buscaBinaria(ind,dados,contador, codigobuscado);
            getch();
        }else {
            cout << "\nEsta opcao nao existe, tente outra :(";
        }
    }
}

