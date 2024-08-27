#include <iostream>

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



int main() {

    return 0;
}

