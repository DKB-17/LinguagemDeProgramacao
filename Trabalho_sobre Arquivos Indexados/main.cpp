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

void erroOpcaoInvalida() {
    cout << "\nOpcao invalida :(";
}

void erroQuantidadeMaxima() {
    cout << "\nQuantidade maxima ja alcancada :(";
}

void mensagemAcaoRealizada() {
    cout << "\nAcao realizada com sucesso :)";
}

struct paises {
    int codigo;
    string nome;
    int status = 1;
};

void imprimirPais(const struct paises &pais) {
    if(pais.status == 1) {
        cout << pais.codigo << " -\t" << pais.nome;
    }
}

paises* buscarPais(int codigo_entrada, struct paises lista_paises[], int contador_paises) {
    if (contador_paises != 0) {
        int i = 0;
        for (; lista_paises[i].codigo != codigo_entrada && i < contador_paises; i++);
        if (i < contador_paises && lista_paises[i].status == 1) {
            return &lista_paises[i];
        }
    }
    return NULL;
}

void imprimirListaPais(struct paises listaPaises[], int contador_paises) {
    cout << "\nLista de Paises: " << endl;
    for (int i = 0; i < contador_paises; i++) {
        imprimirPais(listaPaises[i]);
        cout << endl;
    }
}

void lerPais(struct paises lista_paises[], int &contador_paises) {
    struct paises pais;
    paises *buscaPais;
    system("cls");
    cout << "\nLeitura do pais";
    cout << "\nCodigo pais: ";
    do {
        cin >> pais.codigo;
        buscaPais = buscarPais(pais.codigo, lista_paises, contador_paises);
        if (buscaPais != NULL) {
            erroCodigoJaExiste();
        } else if (pais.codigo < 0) {
            erroValorNegativo();
        }
    } while (pais.codigo < 0 || buscaPais != NULL);
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
    cout << cidade.codigo << " -\t" << cidade.nome << " -\t" << cidade.UF << " -\t";
    imprimirPais(*cidade.codigo_pais);
}

cidades *buscarCidade(int codigo_entrada, struct cidades lista_cidades[], int contador_cidades) {
    if (contador_cidades != 0) {
        int i = 0;
        for (; lista_cidades[i].codigo != codigo_entrada && i < contador_cidades; i++);
        if (i < contador_cidades) {
            return &lista_cidades[i];
        }
    }
    return NULL;
}

void imprimirListaCidades(struct cidades listaCidades[], int contador_cidades) {
    cout << "\nLista de Cidades: " << endl;
    for (int i = 0; i < contador_cidades; i++) {
        imprimirCidade(listaCidades[i]);
        cout << endl;
    }
}

void lerCidade(struct cidades lista_cidades[], int &contador_cidades, struct paises lista_paises[],
    int contador_paises) {
    struct cidades cidade;
    cidades *buscaCidade;
    int codpais;
    system("cls");
    cout << "\nLeitura de cidade";
    cout << "\nCodigo cidade: ";
    do {
        cin >> cidade.codigo;
        buscaCidade = buscarCidade(cidade.codigo, lista_cidades, contador_cidades);
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
        cidade.codigo_pais = buscarPais(codpais, lista_paises, contador_paises);
        if (cidade.codigo_pais == NULL) {
            erroCodigoNaoExiste();
        }else if(codpais < 0) {
            erroValorNegativo();
        }
    } while (cidade.codigo_pais == NULL || codpais < 0);
    lista_cidades[contador_cidades] = cidade;
    contador_cidades += 1;
}

struct guias {
    int codigo;
    string nome;
    string endereco;
    string telefone;
    cidades *codigo_cidade;
    int status = 1;
};

void imprimirGuia(const struct guias &guia)  {
    if(guia.status != 0) {
        cout << guia.codigo << " -\t" << guia.nome << " -\t" << guia.endereco << " -\t" << guia.telefone << " -\t";
        imprimirCidade(*guia.codigo_cidade);
    }
}

void imprimirListaGuia(const struct guias listaGuias[], int contador_guias) {
    cout << "\nLista de Guias: " << endl;
    for (int i = 0; i < contador_guias; i++) {
        if(listaGuias[i].status != 0) {
            imprimirGuia(listaGuias[i]);
            cout << endl;
        }
    }
}

guias* buscarGuia (int codigo_entrada, struct guias lista_guais[], int contador_guias) {
    if(contador_guias != 0) {
        int i;
        for(;lista_guais[i].codigo != codigo_entrada && i < contador_guias; i++);
        if(i < contador_guias && lista_guais[i].status != 0) {
            return &lista_guais[i];
        }
    }
    return NULL;

}

void lerGuia(struct guias lista_guias[], int &contador_guias, struct cidades lista_cidades[], int contador_cidades) {
    struct guias guia;
    guias *buscaGuia;
    int codigo_cidade;
    int confirmacao;
    system("cls");
    cout << "\nLeitura de guia:";
    cout << "\nCodigo guia: ";
    do {
        cin >> guia.codigo;
        buscaGuia = buscarGuia(guia.codigo, lista_guias, contador_guias);
        if (buscaGuia != NULL) {
            erroCodigoJaExiste();
        } else if (guia.codigo < 0) {
            erroValorNegativo();
        }
    } while (guia.codigo < 0 || buscaGuia != NULL);
    cout << "\nNome: ";
    fflush(stdin);
    getline(cin, guia.nome);
    cout << "\nEndereco: ";
    getline(cin, guia.endereco);
    cout << "\nTelefone: ";
    getline(cin, guia.telefone);
    fflush(stdin);
    do {
        imprimirListaCidades(lista_cidades, contador_cidades);
        cout << "\nCodigo_cidade: ";
        cin >> codigo_cidade;
        guia.codigo_cidade = buscarCidade(codigo_cidade, lista_cidades, contador_cidades);
        if (guia.codigo_cidade == NULL) {
            erroCodigoNaoExiste();
        } else {
            imprimirCidade(*guia.codigo_cidade);
            cout << "\n1)Confimar\t2)Cancelar";
            cin >> confirmacao;
        }
    } while (guia.codigo_cidade == NULL || confirmacao != 1);
    lista_guias[contador_guias] = guia;
    contador_guias += 1;
}

struct clientes{
    int codigo;
    string nome;
    string endereco;
    cidades* codigo_cidade;
    int status = 1;
};

struct indice_clientes {
    int codigo;
    clientes *cliente;
};

void imprimirCliente(const struct clientes &cliente){
    if(cliente.status == 1) {
        cout << cliente.codigo << " -\t" << cliente.nome << " -\t" << cliente.endereco << " -\t";
        imprimirCidade(*cliente.codigo_cidade);
    }
}

void imprimirListaCliente(const struct clientes listaClientes[], int contador_clientes) {
    cout << "\nLista de Clientes: " << endl;
    for (int i = 0; i < contador_clientes; i++) {
            imprimirCliente(listaClientes[i]);
            cout << endl;
    }
}

clientes* buscarCliente(int codigo_entrada, struct clientes lista_clientes[], int contador_clientes) {
    if(contador_clientes != 0) {
        int i;
        for(;lista_clientes[i].codigo != codigo_entrada && i < contador_clientes;i++){};
        if(i < contador_clientes && lista_clientes[i].status == 1) {
            return &lista_clientes[i];
        }
    }
    return NULL;
}

void adicionarIndiceCliente(struct indice_clientes listaIndiceCliente[], int contador, struct clientes cliente) {
    if(contador != 0) {
        int i;
        for(i = contador; listaIndiceCliente[i-1].codigo > cliente.codigo && i>0; i--) {
            listaIndiceCliente[i] = listaIndiceCliente[i-1];
        }
        listaIndiceCliente[i].codigo = cliente.codigo;
        listaIndiceCliente[i].cliente = &cliente;
    }else {
        listaIndiceCliente[contador].codigo = cliente.codigo;
        listaIndiceCliente[contador].cliente = &cliente;
    }
}

void lerCliente(struct clientes lista_clientes[], int &contador_clientes, struct cidades lista_cidades[], int
contador_cidades, struct indice_clientes lista_indice_clientes[]) {
    struct clientes cliente;
    clientes *buscaCliente;
    int codigo_cidade;
    int confirmacao;
    system("cls");
    cout << "\nLeitura de cliente: ";
    cout << "\nCodigo cliente: ";
    do {
        cin >> cliente.codigo;
        buscaCliente = buscarCliente(cliente.codigo, lista_clientes, contador_clientes);
        if (buscaCliente != NULL) {
            erroCodigoJaExiste();
        } else if (cliente.codigo < 0) {
            erroValorNegativo();
        }
    } while (cliente.codigo < 0 || buscaCliente != NULL);
    cout << "\nNome: ";
    fflush(stdin);
    getline(cin, cliente.nome);
    cout << "\nEndereco: ";
    getline(cin, cliente.endereco);
    fflush(stdin);
    do {
        imprimirListaCidades(lista_cidades, contador_cidades);
        cout << "\nCodigo_cidade: ";
        cin >> codigo_cidade;
        cliente.codigo_cidade = buscarCidade(codigo_cidade, lista_cidades, contador_cidades);
        if (cliente.codigo_cidade == NULL) {
            erroCodigoNaoExiste();
        } else {
            imprimirCidade(*cliente.codigo_cidade);
            cout << "\n1)Confimar\t2)Cancelar";
            cin >> confirmacao;
        }
    } while (cliente.codigo_cidade == NULL || confirmacao != 1);
    lista_clientes[contador_clientes] = cliente;
    adicionarIndiceCliente(lista_indice_clientes, contador_clientes, cliente);
    contador_clientes += 1;
}

void reorganizarListaCliente(struct clientes listaClientes[], int
&contador_clientes) {
    struct clientes novaLista[contador_clientes];
    int j= -1;
    for(int k= 0; k<contador_clientes; k++) {
        struct clientes *i = &listaClientes[k];
        if(i->status == 1) {
            j++;
            novaLista[j] = *i;
        }
    }
    contador_clientes = j+1;
    for(int k=0;k<contador_clientes;k++) {;
        listaClientes[k] = novaLista[k];
    }
}

struct pacotes {
    int codigo;
    string descricao;
    guias *codigo_guia;
    float valor_por_pessoa;
    int total_participantes;
    int quant_max_participantes;
};

struct indice_pacotes {
    int codigo;
    pacotes *end_pacote;
};

struct indice_pacote_guia {
    guias *end_guia;
    pacotes *end_pacote;
};

void imprimirPacote(const struct pacotes &pacote){
    cout << pacote.codigo << " - " << pacote.descricao << " - ";
    imprimirGuia(*pacote.codigo_guia);
    cout << " - " << fixed << setprecision(2) << pacote.total_participantes * pacote.valor_por_pessoa;
}

void imprimirListaPacotes(const struct pacotes listaPacotes[], int contador_pacotes, bool listacheia=false) {
    cout << "\nLista de Pacotes: " << endl;
    for (int i = 0; i < contador_pacotes; i++) {
        if(listacheia) {
            if(listaPacotes[i].total_participantes == listaPacotes[i].quant_max_participantes) {
                imprimirPacote(listaPacotes[i]);
                cout << endl;
            }
        }else {
            imprimirPacote(listaPacotes[i]);
            cout << endl;
        }
    }
}

pacotes* buscarPacote(int codigo_entrada, struct pacotes listaPacotes[], int contador_pacotes) {
    if(contador_pacotes != 0) {
        int i = 0;
        for(;listaPacotes[i].codigo != codigo_entrada && i < contador_pacotes;i++);
        if(i < contador_pacotes) {
            return &listaPacotes[i];
        }
    }
    return NULL;
}

indice_pacote_guia* buscarGuiaPacote(int codigo_entrada, struct indice_pacote_guia listaGuiaPacotes[], int contador) {
    if(contador != 0) {
        int i = 0;
        for(;listaGuiaPacotes[i].end_guia->codigo != codigo_entrada && i < contador;i++);
        if(i < contador && listaGuiaPacotes[i].end_guia->status != 0) {
            return &listaGuiaPacotes[i];
        }
    }
    return NULL;
}

void adicionarIndicePacote(struct indice_pacotes listaIndicePacote[], int contador, struct pacotes pacote) {
    if(contador != 0) {
        int i;
        for(i = contador; listaIndicePacote[i-1].codigo > pacote.codigo && i>0; i--) {
            listaIndicePacote[i] = listaIndicePacote[i-1];
        }
        listaIndicePacote[i].codigo = pacote.codigo;
        listaIndicePacote[i].end_pacote = &pacote;
    }else {
        listaIndicePacote[contador].codigo = pacote.codigo;
        listaIndicePacote[contador].end_pacote = &pacote;
    }
}

void adicionaPacoteGuia(struct indice_pacote_guia listaGuiasPacotes[], int contador, struct pacotes pacote) {
    if(contador != 0) {
        int i;
        for(i = contador; listaGuiasPacotes[i-1].end_guia->codigo > pacote.codigo_guia->codigo && i>0; i--) {
            listaGuiasPacotes[i] = listaGuiasPacotes[i-1];
        }
        listaGuiasPacotes[i].end_guia = pacote.codigo_guia;
        listaGuiasPacotes[i].end_pacote = &pacote;
    }else {
        listaGuiasPacotes[contador].end_guia = pacote.codigo_guia;
        listaGuiasPacotes[contador].end_pacote = &pacote;
    }
}

void lerPacotes(struct pacotes listaPacotes[], int &contador_pacotes, struct guias listaGuias[], int contador_guias,
struct indice_pacotes lista_indice_pacotes[], struct indice_pacote_guia lista_guia_pacotes[]) {
    struct pacotes pacote;
    struct pacotes *buscaPacote;
    int codigo_guia;
    int confirmacao;
    system("cls");
    cout << "\nLeitura de pacote: ";
    cout << "\nCodigo pacote: ";
    do {
        cin >> pacote.codigo;
        buscaPacote = buscarPacote(pacote.codigo, listaPacotes, contador_pacotes);
        if (buscaPacote != NULL) {
            erroCodigoJaExiste();
        } else if (pacote.codigo < 0) {
            erroValorNegativo();
        }
    } while (pacote.codigo < 0 || buscaPacote != NULL);
    cout << "\nDescricao: ";
    fflush(stdin);
    getline(cin, pacote.descricao);
    fflush(stdin);
    do {
        imprimirListaGuia(listaGuias, contador_guias);
        cout << "\nCodigo_guia: ";
        cin >> codigo_guia;
        pacote.codigo_guia = buscarGuia(codigo_guia, listaGuias, contador_guias);
        if (pacote.codigo_guia == NULL) {
            erroCodigoNaoExiste();
        } else {
            imprimirGuia(*pacote.codigo_guia);
            cout << "\n1)Confimar\t2)Cancelar";
            cin >> confirmacao;
        }
    } while (pacote.codigo_guia == NULL || confirmacao != 1);
    listaPacotes[contador_pacotes] = pacote;
    adicionarIndicePacote(lista_indice_pacotes, contador_pacotes, pacote);
    adicionaPacoteGuia(lista_guia_pacotes, contador_pacotes, pacote);
    contador_pacotes += 1;
}

void reorganizarListaGuias(struct guias listaGuias[], int
&contador) {
    struct guias novaLista[contador];
    int j= -1;
    for(int k= 0; k<contador; k++) {
        struct guias *i = &listaGuias[k];
        if(i->status == 1) {
            j++;
            novaLista[j] = *i;
        }
    }
    contador = j+1;
    for(int k=0;k<contador;k++) {;
        listaGuias[k] = novaLista[k];
    }
}

struct vendas {
    int codigo;
    clientes* codigo_cliente;
    pacotes *codigo_pacote;
    int quantidade_pessoas;
    float valor_total;
};

void imprimirVenda(const struct vendas venda) {
    cout << venda.codigo << " - " << venda.codigo_pacote->descricao << " - " << venda.quantidade_pessoas << " - "
    << fixed << setprecision(2) << venda.valor_total;
}

void imprimirListaVenda(struct vendas listaVenda[], int contador_vendas) {
    float soma = 0;
    cout << "\nLista de Vendas: " << endl;
    for (int i = 0; i < contador_vendas; i++) {
        soma += listaVenda[i].valor_total;
        imprimirVenda(listaVenda[i]);
        cout << endl;
    }
    cout << "Valor total vendido: " << soma;
}

vendas* buscarVenda(int codigo_entrada, struct vendas listaVenda[], int contador_vendas) {
    if(contador_vendas != 0) {
        int i = 0;
        for(;listaVenda[i].codigo != codigo_entrada && i< contador_vendas;i++);
        if(i < contador_vendas) {
            return &listaVenda[i];
        }
    }
    return NULL;
}

struct indice_vendas_cliente {
    clientes *end_cliente;
    vendas *end_venda;
};

indice_vendas_cliente* buscarVendaCliente(int codigo_cliente, struct indice_vendas_cliente listaVendasCliente[], int
contador) {
    int inicio = 0;
    int fim = contador;
    int meio = (inicio + fim) / 2;
    while(listaVendasCliente[meio].end_cliente->codigo != codigo_cliente && inicio < fim) {
        if(listaVendasCliente[meio].end_cliente->codigo < codigo_cliente) {
            inicio = meio + 1;
        }else {
            fim = meio - 1;
        }
        meio = (inicio + fim) / 2;
    }
    if(listaVendasCliente[meio].end_cliente->codigo == codigo_cliente) {
        return &listaVendasCliente[meio];
    }else {
        return NULL;
    }
}


void adicionarVendasCliente(struct indice_vendas_cliente listaVendasClientes[], struct vendas listaVendas[], int contador) {
    listaVendasClientes[contador].end_cliente = listaVendas[contador].codigo_cliente;
    listaVendasClientes[contador].end_venda = &listaVendas[contador];
}

void lerVenda(struct vendas listaVendas[], int &contador_vendas, struct clientes listaClientes[], int
contador_clientes, struct pacotes listaPacotes[], int contador_pacotes, struct indice_vendas_cliente listaVendasClientes[]) {
    struct vendas venda;
    struct vendas *buscaVenda;
    int cod_cliente;
    int cod_pacote;
    int confirmacao;
    do {
        system("cls");
        cout << "\nLeitura de Venda: ";
        cout << "\nCodigo: ";
        do {
            cin >> venda.codigo;
            buscaVenda = buscarVenda(venda.codigo, listaVendas, contador_vendas);
            if(buscaVenda != NULL) {
                erroCodigoJaExiste();
            }else if(venda.codigo < 0) {
                erroValorNegativo();
            }
        }while(venda.codigo < 0 || buscaVenda != NULL);
        do {
            system("cls");
            imprimirListaCliente(listaClientes, contador_clientes);
            cout << "\nCodigo cliente: ";
            cin >> cod_cliente;
            venda.codigo_cliente = buscarCliente(cod_cliente, listaClientes, contador_clientes);
            if(venda.codigo_cliente == NULL) {
                erroCodigoNaoExiste();
            }else {
                imprimirCliente(*venda.codigo_cliente);
                cout << "\n1)Confimar\t2)Cancelar";
                cin >> confirmacao;
            }
        }while(venda.codigo_cliente == NULL || confirmacao != 1);
        do {
            system("cls");
            imprimirListaPacotes(listaPacotes, contador_pacotes);
            cout << "\nCodigo pacote: ";
            cin >> cod_pacote;
            venda.codigo_pacote = buscarPacote(cod_pacote, listaPacotes, contador_pacotes);
            if(venda.codigo_pacote == NULL) {
                erroCodigoNaoExiste();
            }else {
                imprimirPacote(*venda.codigo_pacote);
                cout << "\n1)Confimar\t2)Cancelar";
                cin >> confirmacao;
            }
        }while(venda.codigo_pacote == NULL || confirmacao != 1);
        system("cls");
        do {
            if(confirmacao == 0) {
                system("cls");
                cout << "\nVagas disponiveis: " << venda.codigo_pacote->quant_max_participantes - venda.codigo_pacote->total_participantes;
            }
            cout << "\nQuantidade de pessoas: ";
            cin >> venda.quantidade_pessoas;
            if(venda.quantidade_pessoas + venda.codigo_pacote->total_participantes > venda.codigo_pacote->quant_max_participantes) {
                confirmacao = 0;
                erroQuantidadeMaxima();
            }else {
                confirmacao = 1;
            }
        }while(confirmacao != 1);
        venda.valor_total = venda.quantidade_pessoas * venda.codigo_pacote->valor_por_pessoa;
        cout << "\n Valor total: " << venda.valor_total;
        cout << "\n1)Confimar\t2)Cancelar\t3)Recomecar";
        cin >> confirmacao;
    }while(confirmacao != 1 && confirmacao != 2);
    if(confirmacao == 1) {
        venda.codigo_pacote->total_participantes += venda.quantidade_pessoas;
        listaVendas[contador_vendas] = venda;
        adicionarVendasCliente(listaVendasClientes, listaVendas, contador_vendas);
        contador_vendas += 1;
    }
}

void removerCliente(struct clientes lista_clientes[], int &contador_cliente, struct
indice_vendas_cliente listaVendasCliente[], int contador_vendas_clientes) {
    system("cls");
    imprimirListaCliente(lista_clientes, contador_cliente);
    int codigo_entrada;
    cout << "\nDigite o codigo de cliente que deseja remover: ";
    cin >> codigo_entrada;
    struct clientes *cliente = buscarCliente(codigo_entrada, lista_clientes, contador_cliente);
    if(cliente != NULL) {
        struct indice_vendas_cliente *venda_cliente = buscarVendaCliente(cliente->codigo,listaVendasCliente, contador_vendas_clientes);
        if(venda_cliente == NULL) {
            int confirmacao;
            imprimirCliente(*cliente);
            cout << "\n1)Confirmar\t2)Cancelar: ";
            cin >> confirmacao;
            if(confirmacao == 1) {
                cliente->status = 0;
            }
        }else {
            cout << "\nEste cliente possui venda registrada, nao sera possivel remove-lo :(";
        }
    }else {
        erroCodigoNaoExiste();
    }
}

void removerGuia(struct guias lista_guias[], int &contador_guias, struct
indice_pacote_guia listaGuiasPacotes[]) {
    system("cls");
    imprimirListaGuia(lista_guias, contador_guias);
    int codigo_entrada;
    cout << "\nDigite o codigo do guia que deseja remover: ";
    cin >> codigo_entrada;
    struct guias *guia = buscarGuia(codigo_entrada, lista_guias, contador_guias);
    if(guia != NULL) {
        struct indice_pacote_guia *pacote_guia = buscarGuiaPacote(guia->codigo, listaGuiasPacotes, contador_guias);
        if(pacote_guia == NULL) {
            int confirmacao;
            imprimirGuia(*guia);
            cout << "\n1)Confirmar\t2)Cancelar: ";
            cin >> confirmacao;
            if(confirmacao == 1) {
                guia->status = 0;
            }
        }else {
            cout << "\nEste guia possui pacote registrado, nao sera possivel remove-lo :(";
        }
    }else {
        erroCodigoNaoExiste();
    }
}

int main() {

    setlocale(LC_ALL, "portuguese");

    int tamanho_paises = 10;
    int contador_paises = 3;
    paises lista_paises[tamanho_paises];

    lista_paises[0] = {1, "Brasil"};
    lista_paises[1] = {3, "Peru"};
    lista_paises[2] = {5, "Russia"};

    int tamanho_cidade = 10;
    int contador_cidades = 3;
    cidades lista_cidades[tamanho_cidade];

    lista_cidades[0] = {1, "Sao Paulo", "SP", &lista_paises[1]};
    lista_cidades[1] = {4, "Lima", "LI", &lista_paises[1]};
    lista_cidades[2] = {6, "Moscou", "MC", &lista_paises[2]};

    int tamanho_guias = 10;
    int contador_guias = 3;
    guias lista_guias[tamanho_guias];

    lista_guias[0] = {1, "Roberto Paulo Preto", "Rua K,513", "(18)99112-3344", &lista_cidades[0]};
    lista_guias[1] = {4, "Elma Maria Pinto", "Rua A,112", "(18)88212-3434", &lista_cidades[1]};
    lista_guias[2] = {8, "Tigrinho ta liberando", "Rua B,432", "(18)11875-3990", &lista_cidades[2]};

    int tamanho_clientes = 10;
    int contador_clientes = 3;
    int contador_indice_cliente = 3;
    clientes lista_clientes[tamanho_clientes];
    indice_clientes lista_indice_clientes[tamanho_cidade];

    lista_clientes[0] = {1, "Elma Maria Pinto", "Rua J", &lista_cidades[0]};
    lista_clientes[1] = {2, "Dayde Costa", "Rua D", &lista_cidades[1]};
    lista_clientes[2] = {5, "Oscar Alho", "Rua W", &lista_cidades[1]};

    lista_indice_clientes[0] = {lista_clientes[0].codigo, &lista_clientes[0]};
    lista_indice_clientes[1] = {lista_clientes[1].codigo, &lista_clientes[1]};
    lista_indice_clientes[2] = {lista_clientes[2].codigo, &lista_clientes[2]};

    int tamanho_pacotes = 10;
    int contador_pacotes = 3;
    struct pacotes lista_pacotes[tamanho_pacotes];
    struct indice_pacotes lista_indice_pacotes[tamanho_pacotes];
    struct indice_pacote_guia lista_guias_pacotes[tamanho_pacotes];

    lista_pacotes[0] = {3, "Viagem Roma", &lista_guias[0], 150.00 , 12, 50 };
    lista_pacotes[1] = {5, "Passeio em Candido Mota", &lista_guias[2], 10.00, 60, 60};
    lista_pacotes[2] = {6, "Viagem Marte", &lista_guias[1], 2000.00, 2, 10};

    lista_indice_pacotes [0] = {lista_pacotes[0].codigo,&lista_pacotes[0]};
    lista_indice_pacotes [1] = {lista_pacotes[1].codigo,&lista_pacotes[1]};
    lista_indice_pacotes [2] = {lista_pacotes[2].codigo,&lista_pacotes[2]};

    lista_guias_pacotes[0] = {lista_pacotes[0].codigo_guia, &lista_pacotes[0]};
    lista_guias_pacotes[1] = {lista_pacotes[2].codigo_guia, &lista_pacotes[2]};
    lista_guias_pacotes[2] = {lista_pacotes[1].codigo_guia, &lista_pacotes[1]};

    int tamanho_vendas = 10;
    int contador_vendas = 3;
    struct vendas lista_vendas[tamanho_vendas];
    struct indice_vendas_cliente lista_vendas_clientes[tamanho_vendas];

    lista_vendas[0] = {1, &lista_clientes[1], &lista_pacotes[0], 4, 600.00};
    lista_vendas_clientes[0] = {lista_vendas[0].codigo_cliente, &lista_vendas[0]};
    lista_vendas[1] = {2, &lista_clientes[2], &lista_pacotes[1], 6, 60.00};
    lista_vendas_clientes[1] = {lista_vendas[1].codigo_cliente, &lista_vendas[1]};
    lista_vendas[2] = {3, &lista_clientes[1], &lista_pacotes[2], 2, 4000.00};
    lista_vendas_clientes[0] = {lista_vendas[2].codigo_cliente, &lista_vendas[2]};


    int op = 1;
    while (op != 0) {
        cout << "\nOque deseja fazer: ";
        cout << "\n1)Ler dado\t2)Excluir dado\t3)Mostrar dado\t4)Reorganizar dados" << endl;
        try {
            cin >> op;
            if(op > 3) {
                erroOpcaoInvalida();
            }else {
                if(op == 1) {
                    system("cls");
                    cout << "\nOque deseja fazer: ";
                    cout << "\n1)Ler pais\t2)Ler Cidade\t3)Ler Guia\t4)Ler Cliente\t5)Ler Pacote\t6)Ler Verda" << endl;
                    cin >> op;
                    if(op == 1) {
                        lerPais(lista_paises, contador_paises);
                    }else if(op == 2) {
                        lerCidade(lista_cidades, contador_cidades, lista_paises, contador_paises);
                    }else if(op == 3) {
                        lerGuia(lista_guias, contador_guias, lista_cidades, contador_cidades);
                    }else if(op == 4) {
                        lerCliente(lista_clientes, contador_clientes, lista_cidades, contador_cidades, lista_indice_clientes);
                    }else if(op == 5) {
                        lerPacotes(lista_pacotes, contador_pacotes,lista_guias, contador_guias, lista_indice_pacotes,
                         lista_guias_pacotes);
                    }else if(op == 6) {
                        lerVenda(lista_vendas, contador_vendas, lista_clientes, contador_clientes, lista_pacotes,
                        contador_pacotes, lista_vendas_clientes);
                    }else {
                        erroOpcaoInvalida();
                    }
                }else if(op == 2) {
                    system("cls");
                    cout << "\nOque deseja fazer: ";
                    cout << "\n1)Excluir pais\t2)Excluir Cidade\t3)Excluir Guia\t4)Excluir Cliente\t5)Excluir Pacote\t6)Excluir Verda" << endl;
                    cin >> op;
                    if(op == 1) {

                    }else if(op == 2) {

                    }else if(op == 3) {
                        removerGuia(lista_guias,contador_guias,lista_guias_pacotes);
                        reorganizarListaGuias(lista_guias,contador_guias);
                    }else if(op == 4) {
                        removerCliente(lista_clientes,contador_clientes,lista_vendas_clientes,contador_vendas);
                        reorganizarListaCliente(lista_clientes, contador_guias);
                    }else if(op == 5) {

                    }else if(op == 6) {

                    }

                }else if(op == 3) {
                    system("cls");
                    cout << "\nOque deseja fazer: ";
                    cout << "\n1)Mostrar pais\t2)Mostrar Cidade\t3)Mostrar Guia\t4)Mostrar Cliente\t5)Mostrar";
                    cout << " Pacote\t6)Mostrar Verda\t7)Mostrar Pacotes cheios" << endl;
                    cin >> op;
                    if(op == 1) {
                        imprimirListaPais(lista_paises, contador_paises);
                    }else if(op == 2) {
                        imprimirListaCidades(lista_cidades, contador_cidades);
                    }else if(op == 3) {
                        imprimirListaGuia(lista_guias, contador_guias);
                    }else if(op == 4) {
                        imprimirListaCliente(lista_clientes, contador_clientes);
                    }else if(op == 5) {
                        imprimirListaPacotes(lista_pacotes, contador_pacotes);
                    }else if(op == 6) {
                        imprimirListaVenda(lista_vendas, contador_vendas);
                    }else if(op == 7) {
                        imprimirListaPacotes(lista_pacotes,contador_pacotes,true);
                    }else {
                        erroOpcaoInvalida();
                    }
                }
            }
            getch();
        }catch(...){
            erroOpcaoInvalida();
        }
    }
    return 0;
}
