#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

struct paises {
    int codigo_pais;
    string nome;

    void imprimir() const {
        cout << "\n" << codigo_pais << " - " << nome;
    }
};


int busca_pais(int codigo, struct paises lista_paises[], int contador_paises) {
    int i = 0;
    for(;lista_paises[i].codigo_pais != codigo && i < contador_paises;i++);
    if(i < contador_paises) {
        return i;
    }else {
        return -1;
    }
}

struct cidades {
    int codigo_cidade;
    string nome;
    string UF;
    int codigo_pais;

    void imprimir(struct paises lista_paises[], int contador_paises) const {
        cout << "\n" << codigo_cidade << " - " << nome << " - " << UF << " - " << lista_paises[busca_pais
        (codigo_pais, lista_paises, contador_paises)].nome;
    }
};
struct guias {
    int codigo_guia;
    string nome;
    string endereco;
    string telefone;
    int codigo_cidade;

    void imprimir() const {
        cout << "\n" << codigo_guia << " - " << nome << " - " << endereco << " - " << telefone << " - " << codigo_cidade;
    }
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

void erroCodigoJaExiste() {
    cout << "\nEste codigo ja existe tente outro :(\n";
}
void erroCodigoNaoExiste() {
    cout << "\nEste codigo nao existe tente outro :(\n";
}
void erroValorNegativo() {
    cout << "\nNao e possivel colocar valor negativo nessa entrada :(\n";
}

struct paises ler_pais(struct paises lista_paises[], int contador_paises) {
    struct paises pais;
    int buscacod;
    system("cls");
    cout << "\nLeitura do pais";
    cout << "\nCodigo pais: ";
    do {
        cin >> pais.codigo_pais;
        buscacod = busca_pais(pais.codigo_pais, lista_paises, contador_paises);
        if(buscacod != -1) {
            erroCodigoJaExiste();
        }else if(pais.codigo_pais < 0) {
            erroValorNegativo();
        }
    }while(pais.codigo_pais < 0 || buscacod != -1);
    cout << "\nNome: ";
    cin >> pais.nome;

    return pais;
}

int busca_cidade(int codigo, struct cidades lista_cidades[], int contador_cidades) {
    int i = 0;
    for(;lista_cidades[i].codigo_cidade != codigo && i < contador_cidades;i++);
    if(i < contador_cidades) {
        return i;
    }else {
        return -1;
    }
}

struct cidades ler_cidade(struct cidades lista_cidades[], int contador_cidades, struct paises lista_paises[], int
contador_paises) {
    struct cidades cidade;
    int buscacod;
    system("cls");
    cout << "\nLeitura de cidade";
    cout << "\nCodigo cidade: ";
    do {
        cin >> cidade.codigo_cidade;
        buscacod = busca_cidade(cidade.codigo_cidade, lista_cidades, contador_cidades);
        if(buscacod != -1) {
            erroCodigoJaExiste();
        }else if(cidade.codigo_cidade < 0) {
            erroValorNegativo();
        }
    }while(cidade.codigo_cidade < 0 || buscacod != -1);
    cout << "\nNome: ";
    cin >> cidade.nome;
    cout << "\nUF: ";
    cin >> cidade.UF;
    do {
        cout << "\nCodigo_pais: ";
        cin >> cidade.codigo_pais;
        buscacod = busca_pais(cidade.codigo_pais, lista_paises, contador_paises);
        if(buscacod == -1) {
            erroCodigoNaoExiste();
        }
    }while(buscacod == -1);

    return cidade;
}

int busca_guia(int codigo, struct guias lista_guias[], int contador_guias) {
    int i = 0;
    for(;lista_guias[i].codigo_guia != codigo && i < contador_guias;i++);
    if(i < contador_guias) {
        return i;
    }else {
        return -1;
    }
}

struct guias ler_guia(struct guias lista_guias[], int contador_guias, struct cidades lista_cidades[], int contador_cidades,
struct paises lista_pais[], int contador_pais) {
    struct guias guia;
    int buscacod;
    system("cls");
    cout << "\nLeitura de guia";
    cout << "\nCodigo guia: ";
    do {
        cin >> guia.codigo_guia;
        buscacod = busca_guia(guia.codigo_guia, lista_guias, contador_guias);
        if(buscacod != -1) {
            erroCodigoJaExiste();
        }else if(guia.codigo_guia < 0) {
            erroValorNegativo();
        }
    }while(guia.codigo_guia < 0 ||buscacod != -1);
    cout << "\nNome: ";
    fflush(stdin);
    getline(cin,guia.nome);
    cout << "\nEndereco: ";
    getline(cin,guia.endereco);
    cout << "\nTelefone: ";
    getline(cin,guia.telefone);
    fflush(stdin);
    do {
        cout << "\nCodigo_cidade: ";
        cin >> guia.codigo_cidade;
        buscacod = busca_cidade(guia.codigo_cidade, lista_cidades, contador_cidades);
        if(buscacod == -1) {
            erroCodigoNaoExiste();
        }else {
            lista_cidades[buscacod].imprimir(lista_pais, contador_pais);
        }
    }while(buscacod == -1);
    getch();
    return guia;
}

int busca_cliente(int codigo, struct clientes lista_clientes[], int contador_cliente) {
    int i;
    for(;i < contador_cliente)
        // esta parado aki tem que terminar //
}

struct clientes ler_cliente(struct clientes lista_clientes[], int contador_clientes, struct cidades lista_cidades[], int
contador_cidades, struct paises lista_pais[], int contador_pais) {
    struct clientes cliente;
    int buscacod;
    system("cls");
    cout << "\nLeitura de cliente";
    cout << "\nCodigo cliente: ";
    do {
        cin >> cliente.codigo_cliente;
        buscacod = busca_cliente(cliente.codigo_cliente, lista_clientes, contador_clientes);
        if(buscacod != -1) {
            erroCodigoJaExiste();
        }else if(cliente.codigo_cliente < 0) {
            erroValorNegativo();
        }
    }while(cliente.codigo_cliente < 0 ||buscacod != -1);
    cout << "\nNome: ";
    fflush(stdin);
    getline(cin,guia.nome);
    cout << "\nEndereco: ";
    getline(cin,guia.endereco);
    cout << "\nTelefone: ";
    getline(cin,guia.telefone);
    fflush(stdin);
    do {
        cout << "\nCodigo_cidade: ";
        cin >> guia.codigo_cidade;
        buscacod = busca_cidade(guia.codigo_cidade, lista_cidades, contador_cidades);
        if(buscacod == -1) {
            erroCodigoNaoExiste();
        }else {
            lista_cidades[buscacod].imprimir(lista_pais, contador_pais);
        }
    }while(buscacod == -1);
    getch();
    return guia;
}


int main() {

    int tamanho_paises = 10;
    int contador_paises = 3;
    paises lista_paises[tamanho_paises];

    lista_paises[0] = {1,"Brasil"};
    lista_paises[1] = {3,"Peru"};
    lista_paises[2] = {5,"Russia"};

    int tamanho_cidade = 10;
    int contador_cidades = 3;
    cidades lista_cidades[tamanho_cidade];

    lista_cidades[0] = {1,"São Paulo","SP", 1};
    lista_cidades[1] = {4,"Lima","LI", 3};
    lista_cidades[2] = {6,"Moscou","MC", 5};

    int tamanho_guias = 10;
    int contador_guias = 3;
    guias lista_guias[tamanho_guias];

    lista_guias[0] = {1,"Roberto Paulo Preto", "Rua K,513", "(18)99112-3344", 6};
    lista_guias[1] = {4,"Elma Maria Pinto", "Rua A,112", "(18)88212-3434", 1};
    lista_guias[2] = {8,"Tigrinho ta liberando", "Rua B,432", "(18)11875-3990", 4};

    int tamanho_clientes = 10;
    int contador_clientes = 3;
    clientes lista_clientes[tamanho_clientes];

    lista_clientes[0] = {1, "Elma Maria Pinto", "Rua J", 6};
    lista_clientes[1] = {2, "Dayde Costa", "Rua D", 1};
    lista_clientes[2] = {5, "Oscar Alho", "Rua W", 1};

    int op = 1;
    while(op != 0) {
        system("cls");
        cout << "\nOperacoes para se realizar:";
        cout << "\n0 - Sair";
        cout << "\n1 - Ler pais";
        cout << "\n2 - Ler cidade";
        cout << "\n3 - Ler Guia";
        cout << "\n4 - Ler Cliente";

        cout << "\n\nEntrada: ";
        cin >> op;

        if(op == 0) {
            system("cls");
            cout << "\n Tchau";
        }else if(op == 1) {
            if(contador_paises < tamanho_paises) {
                lista_paises[contador_paises] = ler_pais(lista_paises, contador_paises);
                contador_paises ++;
            }else {
                cout << "\nLista de paises cheia";
                _sleep(2000);
            }
        }else if(op == 2) {
            if(contador_cidades < tamanho_cidade) {
                lista_cidades[contador_cidades] = ler_cidade(lista_cidades, contador_cidades, lista_paises, contador_paises);
                contador_cidades ++;
            }else {
                cout << "\nLista de cidades cheia";
                _sleep(2000);
            }
        }else if(op == 3){
            if(contador_guias < tamanho_guias) {
                lista_guias[contador_guias] = ler_guia(lista_guias, contador_guias, lista_cidades, contador_cidades,lista_paises,
                contador_paises);
                contador_guias ++;
            }else {
                cout << "\nLista de guias cheia";
                _sleep(2000);
            }
        }else if(op == 4) {
            if(contador_clientes < tamanho_clientes) {
                lista_clientes[contador_clientes] = ler_cliente();
                contador_clientes ++;
            }else {
                cout << "\nLista de cliente cheia";
                _sleep(2000);
            }
        }else {
            cout << "Opcao invalida :C";
            _sleep(2000);
        }
    }
    return 0;
}

