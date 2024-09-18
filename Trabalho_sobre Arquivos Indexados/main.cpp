#include <iostream>
#include <conio.h>
#include <clocale>
#include <iomanip>

using namespace std;


void erroCodigoJaExiste() {
    cout << "\nEste codigo ja existe tente outro :(\n";
}

void erroCodigoNaoExiste() {
    cout << "\nEste codigo nao existe tente outro :(\n";
}

void erroValorNegativo() {
    cout << "\nNao e possivel colocar valor negativo nessa entrada :(\n";
}

struct paises {
    int codigo;
    string nome;
};

void imprimirPais(const struct paises &pais) {
    cout << pais.codigo << " - " << pais.nome;
}

paises* busca_pais(int codigo_entrada, struct paises lista_paises[], int contador_paises) {
    if (contador_paises != 0) {
        int i = 0;
        for (; lista_paises[i].codigo != codigo_entrada && i < contador_paises; i++);
        if (i < contador_paises) {
            return &lista_paises[i];
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

void imprimirListaPais(struct paises listaPaises[], int contador_paises) {
    cout << "\nLista de Paises: " << endl;
    for (int i = 0; i < contador_paises; i++) {
        imprimirPais(listaPaises[i]);
        cout << endl;
    }
}

void ler_pais(struct paises lista_paises[], int &contador_paises) {
    struct paises pais;
    paises buscacod*;
    system("cls");
    cout << "\nLeitura do pais";
    cout << "\nCodigo pais: ";
    do {
        cin >> pais.codigo;
        buscacod = busca_pais(pais.codigo, lista_paises, contador_paises);
        if (buscacod != NULL) {
            erroCodigoJaExiste();
        } else if (pais.codigo < 0) {
            erroValorNegativo();
        }
    } while (pais.codigo < 0 || buscacod != NULL);
    cout << "\nNome: ";
    cin >> pais.nome;

    lista_paises[contador_paises] = pais;
    contador_paises += 1;
}


struct cidades {
    int codigo;
    string nome;
    string UF;
    paises *codigo_pais;
};

void imprimirCidade(const struct cidades &cidade) {
    cout << cidade.codigo << " - " << cidade.nome << " - " << cidade.UF << " - ";
    imprimirPais(*cidade.codigo_pais);
}

cidades *busca_cidade(int codigo_entrada, struct cidades lista_cidades[], int contador_cidades) {
    if (contador_cidades != 0) {
        int i = 0;
        for (; lista_cidades[i].codigo != codigo_entrada && i < contador_cidades; i++);
        if (i < contador_cidades) {
            return &lista_cidades[i];
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

void imprimirListaCidades(struct cidades listaCidades[], int contador_cidades) {
    cout << "\nLista de Cidades: " << endl;
    for (int i = 0; i < contador_cidades; i++) {
        imprimirCidade(listaCidades[i]);
        cout << endl;
    }
}

void ler_cidade(struct cidades lista_cidades[], int &contador_cidades, struct paises lista_paises[],
    int contador_paises) {
    struct cidades cidade;
    cidades *buscaCidade;
    int codpais;
    paises *buscaPais;
    system("cls");
    cout << "\nLeitura de cidade";
    cout << "\nCodigo cidade: ";
    do {
        cin >> cidade.codigo;
        buscaCidade = busca_cidade(cidade.codigo, lista_cidades, contador_cidades);
        if (buscaCidade != NULL) {
            erroCodigoJaExiste();
        } else if (cidade.codigo < 0) {
            erroValorNegativo();
        }
    } while (cidade.codigo < 0 || buscaCidade != NULL);
    cout << "\nNome: ";
    cin >> cidade.nome;
    cout << "\nUF: ";
    cin >> cidade.UF;
    do {
        imprimirListaPais(lista_paises, contador_paises);
        cout << "\nCodigo_pais: ";
        cin >> codpais;
        buscaPais = busca_pais(codpais, lista_paises, contador_paises);
        if (buscaPais == NULL) {
            erroCodigoNaoExiste();
        }
    } while (buscaPais == NULL);
    cidade.codigo_pais = buscaPais;
    contador_cidades += 1;
}

struct guias {
    int codigo_guia;
    string nome;
    string endereco;
    string telefone;
    int codigo_cidade;

    void imprimir() const {
        cout << "\n" << codigo_guia << " - " << nome << " - " << endereco << " - " << telefone << " - " <<
                codigo_cidade;
    }
};


struct clientes {
    int codigo_cliente;
    string nome;
    string endereco;
    int codigo_cidade;

    void imprimir
    (
        struct cidades lista_cidades[], int contador_cidades, struct paises lista_paises[], int contador_paises)
    const {
        cout << "\n" << codigo_cliente << " - " << nome << " - " << endereco << " - ";
        lista_cidades[busca_cidade(codigo_cidade, lista_cidades, contador_cidades)].imprimir
                (lista_paises, contador_paises);
    }
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

int busca_guia(int codigo, struct guias lista_guias[], int contador_guias) {
    int i = 0;
    for (; lista_guias[i].codigo_guia != codigo && i < contador_guias; i++);
    if (i < contador_guias) {
        return i;
    } else {
        return -1;
    }
}

struct guias ler_guia
(
    struct guias lista_guias[], int contador_guias, struct cidades lista_cidades[], int contador_cidades,
    struct paises lista_pais[], int contador_pais) {
    struct guias guia;
    int buscacod;
    system("cls");
    cout << "\nLeitura de guia";
    cout << "\nCodigo guia: ";
    do {
        cin >> guia.codigo_guia;
        buscacod = busca_guia(guia.codigo_guia, lista_guias, contador_guias);
        if (buscacod != -1) {
            erroCodigoJaExiste();
        } else if (guia.codigo_guia < 0) {
            erroValorNegativo();
        }
    } while (guia.codigo_guia < 0 || buscacod != -1);
    cout << "\nNome: ";
    fflush(stdin);
    getline(cin, guia.nome);
    cout << "\nEndereco: ";
    getline(cin, guia.endereco);
    cout << "\nTelefone: ";
    getline(cin, guia.telefone);
    fflush(stdin);
    do {
        cout << "\nCodigo_cidade: ";
        cin >> guia.codigo_cidade;
        buscacod = busca_cidade(guia.codigo_cidade, lista_cidades, contador_cidades);
        if (buscacod == -1) {
            erroCodigoNaoExiste();
        } else {
            lista_cidades[buscacod].imprimir(lista_pais, contador_pais);
        }
    } while (buscacod == -1);
    getch();
    return guia;
}

int busca_cliente(int codigo, struct clientes lista_clientes[], int contador_cliente) {
    int i;
    for (; i < contador_cliente && codigo != lista_clientes[i].codigo_cliente; i++) {
    }
    if (i < contador_cliente) {
        return i;
    } else {
        return -1;
    }
}

struct clientes ler_cliente
(
    struct clientes lista_clientes[], int contador_clientes, struct cidades lista_cidades[], int
    contador_cidades, struct paises lista_pais[], int contador_pais) {
    struct clientes cliente;
    int buscacod;
    system("cls");
    cout << "\nLeitura de cliente";
    cout << "\nCodigo cliente: ";
    do {
        cin >> cliente.codigo_cliente;
        buscacod = busca_cliente(cliente.codigo_cliente, lista_clientes, contador_clientes);
        if (buscacod != -1) {
            erroCodigoJaExiste();
        } else if (cliente.codigo_cliente < 0) {
            erroValorNegativo();
        }
    } while (cliente.codigo_cliente < 0 || buscacod != -1);
    cout << "\nNome: ";
    fflush(stdin);
    getline(cin, cliente.nome);
    cout << "\nEndereco: ";
    getline(cin, cliente.endereco);
    fflush(stdin);
    do {
        cout << "\nCodigo_cidade: ";
        cin >> cliente.codigo_cidade;
        buscacod = busca_cidade(cliente.codigo_cidade, lista_cidades, contador_cidades);
        if (buscacod == -1) {
            erroCodigoNaoExiste();
        } else {
            lista_cidades[buscacod].imprimir(lista_pais, contador_pais);
        }
    } while (buscacod == -1);
    getch();
    return cliente;
}

void imprimir_lista_cliente
(
    struct clientes lista_cliente[], int contador_cliente, struct cidades lista_cidades[],
    int contador_cidades, struct paises lista_paises[], int contador_paises) {
    cout << "\nLista Clientes\n";
    for (int i = 0; i < contador_cliente; i++) {
        lista_cliente[i].imprimir(lista_cidades, contador_cidades, lista_paises, contador_paises);
    }
}

void remover_cliente
(
    struct clientes lista_clientes[], int &contador_cliente, struct cidades lista_cidades[],
    int contador_cidades, struct paises lista_paises[], int contador_paises) {
    imprimir_lista_cliente
            (lista_clientes, contador_cliente, lista_cidades, contador_cidades, lista_paises, contador_paises);

    contador_cliente -= 1;
}

int main() {
    int tamanho_paises = 10;
    int contador_paises = 3;
    paises lista_paises[tamanho_paises];

    lista_paises[0] = {1, "Brasil"};
    lista_paises[1] = {3, "Peru"};
    lista_paises[2] = {5, "Russia"};

    int tamanho_cidade = 10;
    int contador_cidades = 3;
    cidades lista_cidades[tamanho_cidade];

    lista_cidades[0] = {1, "Sao Paulo", "SP", 1};
    lista_cidades[1] = {4, "Lima", "LI", 3};
    lista_cidades[2] = {6, "Moscou", "MC", 5};

    int tamanho_guias = 10;
    int contador_guias = 3;
    guias lista_guias[tamanho_guias];

    lista_guias[0] = {1, "Roberto Paulo Preto", "Rua K,513", "(18)99112-3344", 6};
    lista_guias[1] = {4, "Elma Maria Pinto", "Rua A,112", "(18)88212-3434", 1};
    lista_guias[2] = {8, "Tigrinho ta liberando", "Rua B,432", "(18)11875-3990", 4};

    int tamanho_clientes = 10;
    int contador_clientes = 3;
    clientes lista_clientes[tamanho_clientes];

    lista_clientes[0] = {1, "Elma Maria Pinto", "Rua J", 6};
    lista_clientes[1] = {2, "Dayde Costa", "Rua D", 1};
    lista_clientes[2] = {5, "Oscar Alho", "Rua W", 1};

    int op = 1;
    while (op != 0) {
        system("cls");
        cout << "\nOperacoes para se realizar:";
        cout << "\n0 - Sair";
        cout << "\n1 - Ler pais";
        cout << "\n2 - Ler cidade";
        cout << "\n3 - Ler Guia";
        cout << "\n4 - Ler Cliente";
        cout << "\n5 - Remover Registro";

        cout << "\n\nEntrada: ";
        cin >> op;

        if (op == 0) {
            system("cls");
            cout << "\n Tchau";
        } else if (op == 1) {
            if (contador_paises < tamanho_paises) {
                lista_paises[contador_paises] = ler_pais(lista_paises, contador_paises);
                contador_paises++;
            } else {
                cout << "\nLista de paises cheia";
            }
        } else if (op == 2) {
            if (contador_cidades < tamanho_cidade) {
                lista_cidades[contador_cidades] = ler_cidade
                        (lista_cidades, contador_cidades, lista_paises, contador_paises);
                contador_cidades++;
            } else {
                cout << "\nLista de cidades cheia";
            }
        } else if (op == 3) {
            if (contador_guias < tamanho_guias) {
                lista_guias[contador_guias] = ler_guia
                (lista_guias, contador_guias, lista_cidades, contador_cidades, lista_paises,
                 contador_paises);
                contador_guias++;
            } else {
                cout << "\nLista de guias cheia";
            }
        } else if (op == 4) {
            if (contador_clientes < tamanho_clientes) {
                lista_clientes[contador_clientes] = ler_cliente
                (lista_clientes, contador_clientes, lista_cidades,
                 contador_cidades, lista_paises, contador_paises);
                contador_clientes++;
            } else {
                cout << "\nLista de cliente cheia";
            }
        } else if (op == 5) {
            if (contador_clientes > 0) {
                remover_cliente
                (lista_clientes, contador_clientes, lista_cidades, contador_cidades, lista_paises,
                 contador_paises);
            } else {
                cout << "\nLista Vazia :(";
            }
        } else {
            cout << "Opcao invalida :C";
        }
        _sleep(2000);
    }
    return 0;
}
