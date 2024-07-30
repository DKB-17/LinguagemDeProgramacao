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
    char nome[30];
    char endereco[35];
    char cidade[30];
    char uf[2];

    void imprimir() const {
        cout << codigo << "|" << nome << "|" << endereco << "|" << cidade << "|" << uf;
    }
};

void buscaSerial(struct indice idx[], struct cliente cli[], int cont, int cod) {
    int i = 0;
    for(;i < cont && cod > idx[i].codigo; i++)
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

void leitura_dados(struct cliente cliente[],int contador) {
    cout << "Leitura do cliente:";
    cout << "Codigo:";
    cin >> cliente[contador].codigo;
    cout << "Nome:";
    gets(cliente[contador].nome);
    cout << "Endereco:";
    gets(cliente[contador].endereco);
    cout << "Cidade:";
    gets(cliente[contador].cidade);
    cout << "Codigo:";
    gets(cliente[contador].uf);
}
void leitura_indice(struct indice ind[], int contador) {
    cout << "Leitura ind:";
    cout << "Codigo: ";
    cin >> ind[contador].codigo;
    cout << "Endereco: ";
    cin >> ind[contador].ender;
}

void add_indice(struct indice ind[], int contador, struct cliente lsd[]){
    int aux = 0;
    for(;ind[contador-aux].codigo > lsd[contador].codigo && aux < contador ;aux++) {
        ind[contador - (aux-1)] = ind[contador-aux];
    }
    ind[contador-aux].codigo = lsd[contador].codigo;
    ind[contador-aux].ender = contador;
}

int main() {

    struct indice ind[20];
    struct cliente dados[20];
    int contador;
    int ler;

    cout << "Quantas leituras seram realizadas: ";
    cin >> ler;

    for(int i=0;i<ler;i++) {
        system("cls");
        cout << "\n\nLeitura da Area de dados";
        leitura_dados(dados, contador);
        add_indice(ind,contador,dados);
        contador ++;
    }
    for(int i=0; i < contador; i++) {
        cout << "\n";
        ind[i].imprimir();
        cout << "\t";
        dados[i].imprimir();
    }

}

