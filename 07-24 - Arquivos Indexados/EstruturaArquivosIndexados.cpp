#include <iostream>
#include <conio.h>

using namespace std;

struct cliente {
    int codigo;
    string nome;
    string endereco;
    string cidade;
    string uf;
    int status;

    void imprimir() const {
        if(!status) {
            cout << codigo << "|" << nome << "|" << endereco << "|" << cidade << "|" << uf << "|" << status;
        }
    }
};

struct indice {
    int codigo;
    int ender;

    void imprimir(struct cliente& cli) const {
        if(!cli.status) {
            cout << codigo << "|" << ender;
        }
    }
};

void buscaSerial(struct indice idx[], struct cliente cli[], int cont, int cod) {
    int i = 0;
    for(;i < cont && cod > idx[i].codigo; i++);
    if(cod == idx[i].codigo && cli[i].status == false) {
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
int buscaBinaria(struct indice idx[], struct cliente cli[], int contador, int cod) {

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
    if(idx[meio].codigo == cod && cli[meio].status == false) {
        cout << "\n\nCliente Encontrado";
        i = idx[meio].ender;
        cout << "\nCodigo do Cliente:" << cli[i].codigo;
        cout << "\nNome:" << cli[i].nome;
        cout << "\nEndereco:" << cli[i].endereco;
        cout << "\nCidade:" << cli[i].cidade;
        cout << "\nUf:" << cli[i].uf;
        return i;
    }else {
        cout << "\n\n Cliente nao encontrado";
        getch();
    }
    return -1;
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
    do {
        cout << "Uf:";
        getline(cin,cliente[contador].uf);
    }while(cliente[contador].uf.length() > 2);
    fflush(stdin);
    cliente[contador].status = 0;
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
        ind[i].imprimir(dados[ind[i].ender]);
        cout << "\t";
        dados[i].imprimir();
    }
}

void exclusão_Registro(struct cliente dados[], struct indice ind[], int contador, int cod) {
    int pos = buscaBinaria(ind, dados, contador,cod);
    if(pos != -1) {
        dados[pos].status = true;
        getch();
    }
}

void leitura_Exaustiva(struct indice ind[], struct cliente dados[], int contador) {
    for(int k = 0;k<contador;k++) {
        int i = ind[k].ender;
        if(dados[i].status != 1) {
            dados[i].imprimir();
        }
    }
}

void reorganiza_lista(struct indice ind[], struct cliente dados[], int *contador, int tamanho) {
    int contadorExtInd = 0;
    int contadorExtDados = 0;
    struct cliente dados2[tamanho];
    struct indice ind2[tamanho];
    for(int i = 0; i < *contador; i++) {
        if(dados[ind[i].ender].status != 1) {
            ind2[contadorExtInd] = ind[i];
            contadorExtInd ++;
        }
        if(dados[i].status != 1) {
            dados2[contadorExtDados] = dados[i];
            contadorExtDados ++;
        }
    }
    for(int i=0;i<contadorExtInd;i++) {
        ind[i] = ind2[i];
        dados[i] = dados2[i];
    }
    *contador = contadorExtInd;

}

int main() {
    int tamanho = 20;
    struct indice ind[tamanho];
    struct cliente dados[tamanho];
    int contador = 9;
    int op = 1;

    ind[0] = {1,5};
    ind[1] = {2,2};
    ind[2] = {4,8};
    ind[3] = {6,4};
    ind[4] = {7,6};
    ind[5] = {8,0};
    ind[6] = {11,3};
    ind[7] = {12,7};
    ind[8] = {14,1};

    dados[0] = {8,"Jose","Rua F,90", "Candido Mota", "SP", 0};
    dados[1] = {14,"Carina","Rua F,25", "Assis", "SP", 0};
    dados[2] = {2,"Maria","Rua K,67", "Marilia", "SP", 1};
    dados[3] = {11,"Silvia","Rua B,203", "Assis", "SP", 0};
    dados[4] = {6,"Pedro","Rua J,38", "Assis", "SP", 0};
    dados[5] = {1,"Joao","Rua A,45", "Assis", "SP", 1};
    dados[6] = {7,"Cristina","Rua K,67", "Palmital", "SP", 0};
    dados[7] = {12,"Manoel","Rua K,45", "Londrina", "PR", 1};
    dados[8] = {4,"Antonio","Rua B,203", "Assis", "SP", 0};

    while(op != 0) {

        system("cls");
        cout << "\n Opcoes do sistema";
        cout << "\n 0 - Sair";
        cout << "\n 1 - Ler novo cliente";
        cout << "\n 2 - Exibir listas";
        cout << "\n 3 - Busca Serial";
        cout << "\n 4 - Busca Binaria";
        cout << "\n 5 - Exclusao de Registros";
        cout << "\n 6 - Reorganizacao do Arquivo";

        cout << "\n\nInsira um numero: ";
        cin >> op;

        int codigobuscado;
        int codigoexclusao;
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
        }else if(op == 5) {
            imprimir_listas(dados, ind, contador);
            cout << "\nDigite o cod que deseja excluir:";
            cin >> codigoexclusao;
            exclusão_Registro(dados, ind, contador, codigoexclusao);
        }else if(op == 6) {
            reorganiza_lista(ind, dados, &contador, tamanho);
            imprimir_listas(dados, ind, contador);
            getch();
        }else {
            cout << "\nEsta opcao nao existe, tente outra :(";
        }
    }
}

