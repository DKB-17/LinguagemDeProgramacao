#include <iostream>
#include <conio.h>

using namespace std;

struct paises {
    int codigo_pais;
    string nome;
};
struct cidades {
    int codigo_cidade;
    string nome;
    string UF;
    int codigo_pais;
};
struct guais {
    int codigo_guia;
    string nome;
    string endereco;
    string telefone;
    int codigo_cidade;
};
struct clientes {
    int codigo_cliente;
    string nome;
    string endereco;
    int codigo_cidade;
};
struct pacotes {
    int codigo_pacote;
    string descricao;
    int codigo_guia;
    int valor_por_pessoa;
    int total_participantes;
    int quant_max_participantes;
};
struct indice_pacote {
    int codigo_pacote;
    int end_pacote;
};
struct indice_pacote_guia {
    int codigo_guia;
    int end_pacote;
};

struct vendas {
    int codigo_venda;
    int codigo_cliente;
    int codigo_pacote;
    int quantidade_pessoas;
    int valor_total;
};

struct indice_vendas {
    int codigo_venda;
    int end_venda;
};

struct indice_vendas_cliente {
    int codigo_cliente;
    int end_venda;
};

struct paises ler_pais() {
    struct paises pais;
    system("cls");
    cout << "\nLeitura do pais";
    cout << "\nCodigo pais: ";
    cin >> pais.codigo_pais;
    cout << "\nNome: ";
    cin >> pais.nome;

    return pais;
}

int busca_pais(int codigo, struct paises lista_paises[], int contador_paises) {
    int i = 0;
    for(;lista_paises[i].codigo_pais != codigo && i < contador_paises;i++);
    if(i < contador_paises) {
        return i;
    }else {
        return -1;
    }
}

struct cidades ler_cidade(struct paises lista_paises[], int contador_paises) {
    struct cidades cidade;
    system("cls");
    cout << "\nLeitura de cidade";
    cout << "\nCodigo cidade: ";
    cin >> cidade.codigo_cidade;
    cout << "\nNome: ";
    cin >> cidade.nome;
    cout << "\nUF: ";
    cin >> cidade.UF;
    do {
        cout << "\nCodigo_pais: ";
        cin >> cidade.codigo_pais;
    }while(busca_pais(cidade.codigo_pais, lista_paises, contador_paises) == -1);

    return cidade;
}

int main() {

    int tamanho_paises = 10;
    int contador_paises = 3;
    paises lista_paises[tamanho_paises];

    lista_paises[0] = {1,"Brasil"};
    lista_paises[1] = {3,"Peru"};
    lista_paises[2] = {5,"Russia"};

    int tamanho_cidade = 10;
    int contador_cidade = 3;
    cidades lista_cidades[tamanho_cidade];

    lista_cidades[0] = {1,"São Paulo","SP", 1};
    lista_cidades[1] = {4,"Lima","Região de Lima", 3};
    lista_cidades[2] = {6,"Moscou","Cidade federal de moscou", 5};

    int tamanho_guias = 10;
    int contador_guias = 3;
    guais lista_guias[tamanho_guias];

    lista_guias[0] = {1,"Roberto Paulo Preto", "Rua K,513", "(18)99112-3344", 6};
    lista_guias[1] = {4,"Elma Maria Pinto", "Rua A,112", "(18)88212-3434", 1};
    lista_guias[2] = {8,"Tigrinho ta liberando", "Rua B,432", "(18)11875-3990", 4};

    int op = 1;
    while(op != 0) {
        system("cls");
        cout << "\nOperacoes para se realizar:";
        cout << "\n0 - Sair";
        cout << "\n1 - Ler pais";
        cout << "\n2 - Ler cidade";

        cout << "\n\nEntrada: ";
        cin >> op;

        if(op == 0) {
            system("cls");
            cout << "\n Tchau";
        }else if(op == 1) {
            if(contador_paises < tamanho_paises) {
                lista_paises[contador_paises] = ler_pais();
                contador_paises ++;
            }else {
                cout << "\nLista de paises cheia";
                getch();
            }
        }else if(op == 2) {
            if(contador_cidade < tamanho_cidade) {
                lista_cidades[contador_cidade] = ler_cidade(lista_paises, contador_paises);
                contador_cidade ++;
            }else {
                cout << "\nLista de cidades cheia";
                getch();
            }
        }else {
            cout << "Opção invalida :C";
            getch();
        }
    }



    return 0;
}

