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

void leitura_dados(struct cliente cliente[],int contador) {
    cout << "Leitura do cliente: ";
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

}
void leitura_indice(struct indice ind[], int contador) {
    cout << "Leitura ind:";
    cout << "Codigo: ";
    cin >> ind[contador].codigo;
    cout << "Endereco: ";
    cin >> ind[contador].ender;
}

void ordenar_lista(struct indice ind[], int tamanho) {
    indice aux;
    for(int i = 0; i < tamanho;i++) {
        for(int j = i + 1; j < tamanho; j++) {
            if(ind[i].codigo > ind[j].codigo) {
                aux = ind[i];
                ind[i] = ind[j];
                ind[j] = aux;
            }
        }
    }
}

void add_indice(struct indice ind[], int contador, struct cliente lsd[]){
    ind[contador].codigo = lsd[contador].codigo;
    ind[contador].ender = contador;
}

int main() {

    struct indice ind[20];
    struct cliente dados[20];
    int contador = 0;
    int sair = 1;

    while(sair != 0) {
        for(int i=0;i<ler;i++) {
            system("cls");
            leitura_dados(dados, contador);
            add_indice(ind,contador,dados);
            contador ++;
            ordenar_lista(ind, contador);
        }
    }
    for(int i=0; i < contador; i++) {
        cout << "\n";
        ind[i].imprimir();
        cout << "\t";
        dados[i].imprimir();
    }

    int codigobuscado;
    cout << "\nDigite o codigo buscado: ";
    cin >> codigobuscado;
    buscaSerial(ind,dados,contador, codigobuscado);


    cout << "\nDigite o codigo buscado: ";
    cin >> codigobuscado;
    buscaBinaria(ind,dados,contador, codigobuscado);

}

