#include <iostream>
#include <cstring>
#include <conio.h>
#include <iomanip>

using namespace std;

void limparTela();

/*Estrutura cidade*/
struct cidade {
    int codigo;
    string nome;
    string UF;
};

void imprimirCidade(const struct cidade &cidade);
cidade* buscarCidade(int codigo_buscado, struct cidade listaCidade[], int contador_cidade);
void imprimirListaCidade(struct cidade listaCidade[], int contador_cidade);
void lerCidade(struct cidade listaCidade[], int contador_cidade);

// Estrutura especialidade
struct especialidade {
    int codigo;
    string descricao;

};

void imprimirEspecialidade(struct especialidade &especialidade);
especialidade* buscarEspecialidade (int codigo_entrada, struct especialidade listaEspecialidade[], int
contador_especialidade);
void lerEspecialidade(struct especialidade listaEspecialidade[], int contador_especialidade);
void imprimirListaEspecialidade(struct especialidade listaEspecialidade[], int contador_especialidade);

struct CID {
    int codigo;
    string descricao;

};

void imprimirCID(const struct CID &cid);
void imprimirListaCID(struct CID listaCID[], int contador_cid);
CID* buscarCID(int codigo_entrada, struct CID listaCID[], int contador_cid);
void lerCID(struct CID listaCID[], int contador_cid);

struct medicamento {
    int codigo;
    string nome;
    int quantEstoque;
    int estoqueMinimo;
    int estoqueMaximo;
    float precoUnitario;

};
void imprimirMedicamento(const struct medicamento &medicamento);
void imprimirListaMedicamento(struct medicamento listaMedicamento[], int contador_medicamento);
medicamento* buscarMedicamento(int codigo_entrada, struct medicamento listaMedicamento[], int contador_medicamento);
void lerMedicamento(struct medicamento listaMedicamento[], int contador_medicamento);
void reduzirEstoque(struct medicamento* medicamento, int saida);

struct medico {
    int codigo;
    string nome;
    especialidade* codigoEspecialidade;
    string endereco;
    string telefone;
    cidade* codigoCidade;
};

void imprimirMedico(const struct medico& medico);
void imprimirListaMedico(struct medico listaMedico[], int contador_medico);
medico* buscarMedico(int codigo_entrada, struct medico listaMedico[], int contador_medico);
void lerMedico(struct medico listaMedico[], int contador_medico, struct especialidade listaEspecialidade[], int contador_especialidade, struct cidade listaCidade[], int contador_cidade);

struct paciente {
    string CPF;
    string nome;
    string endereco;
    cidade* codigoCidade;
};

void imprimirPaciente(const struct paciente &paciente);
void imprimirListaPaciente(paciente listaPacientes[], int contador_paciente);
paciente* buscarPaciente(string &codigo_entrada, struct paciente listaPaciente[], int contador_paciente);
void lerPaciente(struct paciente listaPaciente[], int contador_paciente, struct cidade listaCidade[], int contador_cidade);
void removerRegistroPaciente(struct paciente listaPaciente[], int *contador_paciente);

struct consulta {
    paciente cpfPaciente;
    medico codMedico;
    string dataHora;
    CID codCID;
    medicamento codMedicamento;
    int qtdeMedicamento;
};

void imprimirConsulta(const struct consulta &consulta);
void agendarConsulta(struct consulta *consulta, struct paciente listaPaciente[], int contador_paciente, struct medico listaMedico[],
    int contador_medico, struct CID listaCID[], int contador_cid, struct medicamento listaMedicamento[], int contador_medicamento);

int main() {
    setlocale(LC_ALL, "portuguese");

    int confirmacao;
    bool validacao;
    float valorBaseConsulta = 100.0;

    int tamanho_cidade = 10;
    int contador_cidade = 3;
    cidade listaCidade[tamanho_cidade];

    /*DADOS INJETADOS DE CIDADE*/

    listaCidade[0] = {1, "Assis", "SP"};
    listaCidade[1] = {2, "Candido Mota", "SP"};
    listaCidade[2] = {5, "Unai", "MG"};

    int tamanho_especialidade = 10;
    int contador_especialidade = 3;
    especialidade listaEspecialidade[tamanho_especialidade];

    /*DADOS INJETADOS DE ESPECIALIDADE*/

    listaEspecialidade[0] = {2, "Ortopedista"};
    listaEspecialidade[1] = {3, "Psiquiatra"};
    listaEspecialidade[2] = {5, "Neurologista"};

    int tamanho_cid = 10;
    int contador_cid = 3;
    CID listaCID[tamanho_cid];

    /*DADOS INJETADOS DE CID*/

    listaCID[0] = {1, "Infecção intestinal"};
    listaCID[1] = {3, "Virus mortal"};
    listaCID[2] = {4, "Bacteria nociva"};

    int tamanho_medicamento = 10;
    int contador_medicamento = 3;
    medicamento listaMedicamento[tamanho_medicamento];

    /*DADOS INJETADOS DE MEDICAMENTO*/

    listaMedicamento[0] = {2, "Tadalafila", 1, 4, 6, 2.5};
    listaMedicamento[1] = {3, "Paracetamol", 4, 5, 7, 5.9};
    listaMedicamento[2] = {4, "Neuzadina", 5, 3, 10, 10.2};

    int tamanho_medico = 10;
    int contador_medico = 3;
    medico listaMedico[tamanho_medico];

    /*DADOS INJETADOS DE MEDICO*/

    listaMedico[0] = {1, "Robeto", &listaEspecialidade[0], "Augusta Melo, 535", "(18)9912-2123", &listaCidade[0]};
    listaMedico[1] = {3, "Alex", &listaEspecialidade[1], "Daniel Cruz, 991", "(18)9933-3323", &listaCidade[2]};
    listaMedico[2] = {4, "Rodrigo", &listaEspecialidade[0], "Jose Nogueira, 123", "(18)9001-0013", &listaCidade[2]};

    int tamanho_paciente = 10;
    int contador_paciente = 3;
    paciente listaPaciente[tamanho_paciente];

    /*DADOS INJETADOS DE PACIENTE*/

    listaPaciente[0] = {"123.123.123-10", "Danilo", "Obama Clintom,566", &listaCidade[1]};
    listaPaciente[1] = {"145.645.623-04", "Rogerio", "Mello de Ferro", &listaCidade[2]};
    listaPaciente[2] = {"150.003.432-22", "Nicolas", "Lincom Presidente", &listaCidade[0]};

    int tamanho_consulta = 10;
    int contador_consulta = 3;
    consulta listaConsulta[tamanho_consulta];

    /*DADOS INJETOS DE CONSULTA*/

    listaConsulta[0] = {listaPaciente[0],listaMedico[2],"30/05/2024 14:01:31",listaCID[0],listaMedicamento[1],3};
    listaConsulta[1] = {listaPaciente[1],listaMedico[0],"30/05/2024 17:33:20",listaCID[2],listaMedicamento[2],4};
    listaConsulta[2] = {listaPaciente[1],listaMedico[1],"30/05/2024 18:53:10",listaCID[1],listaMedicamento[0],1};

    int op = 1;
    while (op != 0) {
        limparTela();
        cout << "\nMENU" << endl;
        cout << "\n0 - Sair";
        cout << "\n1 - Ler cidade";
        cout << "\n2 - Ler especialidade";
        cout << "\n3 - Ler CID";
        cout << "\n4 - Ler Medicamento";
        cout << "\n5 - Ler Medico";
        cout << "\n6 - Ler Paciente";
        cout << "\n7 - Excluir Registro de Paciente";
        cout << "\n8 - Agendar consulta";
        cout << "\n9 - Consultar medicamento";
        cout << "\n10 - Verificar minimos de estoque";
        cout << "\n11 - Arrecadacao de consulta";
        cout << "\n12 - Exibir total as listas";

        cout << "\n\nDigite qual acão deseja fazer: ";
        cin >> op;
        if (op == 0){
                cout << "\nByeee!!!";
        }else if(op == 1){
                if (contador_cidade < tamanho_cidade) {
                    do {
                        lerCidade(listaCidade,contador_cidade);
                        limparTela();
                        imprimirCidade(listaCidade[contador_cidade]);
                        cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                        cin >> confirmacao;
                    } while (confirmacao == 0);
                    if (confirmacao == 1) {
                        contador_cidade++;
                    }
                } else {
                    cout << "\nLista de cidade cheia :C";
                }
        }else if(op == 2){
                if (contador_especialidade < tamanho_especialidade) {
                    do {
                        lerEspecialidade(listaEspecialidade,contador_especialidade);
                        limparTela();
                        imprimirEspecialidade(listaEspecialidade[contador_especialidade]);
                        cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                        cin >> confirmacao;
                    } while (confirmacao == 0);
                    if (confirmacao == 1) {
                        contador_especialidade++;
                    }
                } else {
                    cout << "\nLista de especialidade cheia :C";
                }
        }else if(op == 3){
                if (contador_cid < tamanho_cid) {
                    do {
                        lerCID(listaCID,contador_cid);
                        limparTela();
                        imprimirCID(listaCID[contador_cid]);
                        cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                        cin >> confirmacao;
                    } while (confirmacao == 0);
                    if (confirmacao == 1) {
                        contador_cid++;
                    }
                } else {
                    cout << "\nLista de CID cheia :C";
                }
        }else if(op == 4){
                if (contador_medicamento < tamanho_medicamento) {
                    do {
                        lerMedicamento(listaMedicamento,contador_medicamento);
                        limparTela();
                        imprimirMedicamento(listaMedicamento[contador_medicamento]);
                        cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                        cin >> confirmacao;
                    } while (confirmacao == 0);
                    if (confirmacao == 1) {
                        contador_medicamento++;
                    }
                } else {
                    cout << "\nLista de Medicamento cheia :C";
                }
        }else if(op == 5){
                if (contador_medico < tamanho_medico) {
                    do {
                        lerMedico(listaMedico, contador_medico, listaEspecialidade, contador_especialidade, listaCidade,
                                  contador_cidade);
                        limparTela();
                        imprimirMedico(listaMedico[contador_medico]);
                        cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                        cin >> confirmacao;
                    } while (confirmacao == 0);
                    if (confirmacao == 1) {
                        contador_medico++;
                    }
                } else {
                    cout << "\nLista de Medico cheia :C";
                }
        }else if(op == 6){
                if (contador_paciente < tamanho_paciente) {
                    do {
                        lerPaciente(listaPaciente, contador_paciente, listaCidade, contador_cidade);
                        limparTela();
                        imprimirPaciente(listaPaciente[contador_paciente]);
                        cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                        cin >> confirmacao;
                    } while (confirmacao == 0);
                    if (confirmacao == 1) {
                        contador_paciente++;
                    }
                } else {
                    cout << "\nLista de Paciente cheia :C";
                }
        }else if(op == 7){
                removerRegistroPaciente(listaPaciente, &contador_paciente);
        }else if(op == 8){
                if (contador_consulta < tamanho_consulta) {
                    do {
                        agendarConsulta
                                (&listaConsulta[contador_consulta], listaPaciente, contador_paciente, listaMedico,
                                 contador_medico, listaCID, contador_cid, listaMedicamento, contador_medicamento);
                        limparTela();
                        imprimirConsulta(listaConsulta[contador_consulta]);
                        cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                        cin >> confirmacao;
                    } while (confirmacao == 0);
                    if (confirmacao == 1) {
                        reduzirEstoque(buscarMedicamento(listaConsulta[contador_consulta].codMedicamento.codigo,
                        listaMedicamento,
                        contador_medicamento),listaConsulta[contador_consulta].qtdeMedicamento);
                        contador_consulta++;
                    }
                } else {
                    cout << "\nLista de consulta cheia :C";
                }
        }else if(op == 9){
                if(contador_medicamento > 0) {
                    int i;
                    medicamento* encontrado;
                    do {
                        limparTela();
                        cout << "\nCodigos de medicamento"<<endl;
                        for(i=0;i<contador_medicamento;i++) {
                            cout << "\nMedicamento[" << i << "]: " << listaMedicamento[i].codigo;
                        }
                        cout << "\nDigite o codigo do medicament que deseja: ";
                        cin >> i;
                        encontrado = buscarMedicamento(i,listaMedicamento,contador_medicamento);
                        if(encontrado != NULL) {
                            imprimirMedicamento(*encontrado);
                            cout << "\nTotal em estoque: \t" << (encontrado->quantEstoque * encontrado
                                    ->precoUnitario);
                            validacao = true;
                        }else {
                            cout << "\nEste codigo nao existe na lista de medicamento :C";
                            validacao = false;
                        }
                    }while(!validacao);
                }else {
                    cout << "\nLista de medicamento vazia :C";
                }
        }else if(op == 10){
                if(contador_medicamento > 0) {
                    limparTela();
                    cout << "\nItems com baixo em estoque" << endl;
                    float soma = 0.0;
                    for(int i=0;i<contador_medicamento;i++) {
                        if(listaMedicamento[i].quantEstoque < listaMedicamento[i].estoqueMinimo) {
                            imprimirMedicamento(listaMedicamento[i]);
                            int quantidadeAComprar = listaMedicamento[i].estoqueMaximo -
                                                     listaMedicamento[i].quantEstoque;
                            cout << "\nQtd a comprar: \t\t" << quantidadeAComprar;
                            float valorComprar = (float)quantidadeAComprar * listaMedicamento[i].precoUnitario;
                            soma += valorComprar;
                            cout << "\nValor da comprada: \t" << valorComprar;
                            cout <<endl;
                        }
                    }
                    cout << "\nValor total: \t" << soma;

                }else {
                    cout << "\nLista de medicamento Vazia :C";
                }
        }else if(op == 11){
                if(contador_consulta > 0){
                    limparTela();
                    cout << "\nArrecadacao das consultas"<<endl;
                    float soma = 0.0;
                    cout << "\nPaciente\t|Medico\t\t|Data e Hora\t\t|CID\t|Medicamento\t|Qtd\t|Receita\t|Consulta\t|Total";
                    for(int i=0;i<contador_consulta;i++){
                        cout << "\n" << listaConsulta[i].cpfPaciente.nome << "\t\t" << listaConsulta[i].codMedico.nome << "\t\t" << listaConsulta[i].dataHora << "\t" << listaConsulta[i].codCID.codigo << "\t" << listaConsulta[i].codMedicamento.nome << "\t" << listaConsulta[i].qtdeMedicamento << "\t" << (listaConsulta[i].qtdeMedicamento * listaConsulta[i].codMedicamento.precoUnitario) << "\t\t" << valorBaseConsulta << "\t\t" << valorBaseConsulta + (listaConsulta[i].qtdeMedicamento * listaConsulta[i].codMedicamento.precoUnitario);
                        cout << "\n" << listaConsulta[i].cpfPaciente.CPF << "\t" << listaConsulta[i].codMedico.codigoEspecialidade->descricao << "\t" << "\t" << "\t" << "\t" << "\tPreco Uni:" << listaConsulta[i].codMedicamento.precoUnitario;
                        soma += (valorBaseConsulta + (listaConsulta[i].qtdeMedicamento * listaConsulta[i].codMedicamento.precoUnitario));
                    }
                    cout << endl;
                    cout << "\nSoma de Arrecadacao com as consulta: " << soma;
                }else{
                    cout << "\nLista de Consulta Vazia :C";
                }
        }else if(op == 12){
                if(contador_cidade > 0){
                    imprimirListaCidade(listaCidade,contador_cidade);
                    getch();
                }
                if(contador_especialidade > 0){
                    imprimirListaEspecialidade(listaEspecialidade,contador_especialidade);
                    getch();
                }
                if(contador_medico > 0){
                    imprimirListaMedico(listaMedico,contador_medico);
                    getch();
                }
                if(contador_paciente > 0){
                    imprimirListaPaciente(listaPaciente,contador_paciente);
                    getch();
                }
                if(contador_cid > 0){
                    imprimirListaCID(listaCID,contador_cid);
                    getch();
                }
                if(contador_medicamento > 0){
                    imprimirListaMedicamento(listaMedicamento,contador_medicamento);
                    getch();
                }
        }else{
                cout << "\nNao temos essa opcao:C ";
        }
        getch();
    }
    return 0;
}

/*Funcao para limpeza da tela do terminal*/
void limparTela(){
    system("cls");
}

/*Funcao ultilizada para imprimir as informacoes de uma estrutura cidade*/
void imprimirCidade(const struct cidade &cidade) {
        cout << "\nCidade: \t" << cidade.codigo;
        cout << "\nNome: \t\t" << cidade.nome;
        cout << "\nUF: \t\t" << cidade.UF;
}

/*Funcao utilizada para busca na lista de entrada(ListaCidade) interando pelo seu contador no processo de busca
binaria, onde na ocorrencia de uma registro com o mesmo valor atribuido(codigo_buscado) retorna o registro encontrado
com os dados e informacoes do registro em metodo de ponteiro para que todos dados seja conectados por blocos de
memoria apontados pelo sistema.*/
cidade* buscarCidade(int codigo_buscado, struct cidade listaCidade[], int contador_cidade) {
    int min = 0;
    int max = contador_cidade - 1;
    while(max >= min){

        int meio = (int)(min + max) / 2;
        if(listaCidade[meio].codigo == codigo_buscado){
            return &listaCidade[meio];
        } else if(listaCidade[meio].codigo > codigo_buscado){
            max = meio - 1;
        } else{
            min = meio + 1;
        }
    }
    return NULL;
}

/*Funcao para impressao de uma lista(listaCidade) - ultilizando impressao linear das informacoes na lista*/
void imprimirListaCidade(struct cidade listaCidade[], int contador_cidade) {
    limparTela();
    for (int i = 0; i < contador_cidade; i++) {
        imprimirCidade(listaCidade[i]);
        cout << endl;
    }
}

/*Funcao para leitura da informacoes de uma cidade(struct cidade), armazenadas dentro de uma lista de valores da
lista(listaCidade), no indice(contador)*/
void lerCidade(struct cidade listaCidade[], int contador_cidade) {
    limparTela();
    int codigo;
    cidade* encontrado;
    bool validacao;
    do {
        cout << "\nDigite o codigo da cidade: ";
        cin >> codigo;
        //reponsavel pela validacao da existencia de um codigo ja registrado dentro da lista, a funcao buscarCidade
        // retorna o endereco da memoria onde esta armazendo dentro da lista o registro com o codigo similar ao
        // codigo novo a ser inserido , caso encontre e apontado o endereco de memoria, senao retorna um ponteiro
        // para null.
        encontrado = buscarCidade(codigo,listaCidade,contador_cidade);
        if(encontrado == NULL){
            listaCidade[contador_cidade].codigo = codigo;
            validacao = true;
        }else{
            cout << "\nEste codigo ja esta registrado na lista de cidade";
            validacao = false;
        }
    }while(!validacao);
    cout << "\nDigite o nome da cidade: ";
    fflush(stdin);
    getline(cin, listaCidade[contador_cidade].nome);
    cout << "\nDigite a UF da cidade: ";
    getline(cin, listaCidade[contador_cidade].UF);
    fflush(stdin);

}
// ------------------------------------- ESPECIALIDADE -----------------------------------------------

void imprimirEspecialidade(struct especialidade &especialidade){
        cout << "\nEspecialidade: \t" << especialidade.codigo;
        cout << "\nDescricao: \t" << especialidade.descricao;
}

especialidade* buscarEspecialidade (int codigo_entrada, struct especialidade listaEspecialidade[], int contador_especialidade) {
    for (int i = contador_especialidade - 1; i > -1; i--) {
        if (codigo_entrada == listaEspecialidade[i].codigo) {
            return &listaEspecialidade[i];
        }
    }
    return NULL;
};

// Funcao para leitura de especialidade
void lerEspecialidade(struct especialidade listaEspecialidade[], int contador_especialidade) {
        limparTela();
        int codigo;
        bool validacao;
        especialidade* encontrado;
        do{
        cout << "\nDigite o codigo da especialidade: ";
        cin >> codigo;
        encontrado = buscarEspecialidade(codigo, listaEspecialidade, contador_especialidade);
        if (encontrado == NULL){
            listaEspecialidade[contador_especialidade].codigo = codigo;
            validacao = true;
        }else{
            cout << "\nEste codigo ja pretence a lista de Especialidade";
            validacao = false;
        }
        }while(!validacao);
        cout << "\nDigite a descricao: ";
        fflush(stdin);
        getline(cin, listaEspecialidade[contador_especialidade].descricao);
        fflush(stdin);
}

void imprimirListaEspecialidade(struct especialidade listaEspecialidade[], int contador_especialidade) {
    limparTela();
    for (int i = 0; i < contador_especialidade; i++) {
        imprimirEspecialidade(listaEspecialidade[i]);
        cout << endl;
    }
}
//-----------------------------------CID-----------------------------------------

void imprimirCID(const struct CID &cid) {
        cout << "\nCID: \t\t" << cid.codigo;
        cout << "\nDescricao: \t" << cid.descricao;
}

void imprimirListaCID(struct CID listaCID[], int contador_cid) {
    limparTela();
    for (int i = 0; i < contador_cid; i++) {
        imprimirCID(listaCID[i]);
        cout << endl;
    }
}

CID* buscarCID(int codigo_entrada, struct CID listaCID[], int contador_cid) {
    for (int i = 0; i < contador_cid; i++) {
        if (codigo_entrada == listaCID[i].codigo) {
            return &listaCID[i];
        }
    }
    return NULL;
}
void lerCID(struct CID listaCID[], int contador_cid) {
        limparTela();
        cout << "\nDigite o codigo da CID: ";
        cin >> listaCID[contador_cid].codigo;
        cout << "\nDigite a descricao: ";
        fflush(stdin);
        getline(cin, listaCID[contador_cid].descricao);
        fflush(stdin);
}

//---------------------------------MEDICAMENTO------------------------------------------

void imprimirMedicamento(const struct medicamento &medicamento) {
    cout << "\nMedicamento: \t\t" << medicamento.codigo;
    cout << "\nNome: \t\t\t" << medicamento.nome;
    cout << "\nQuantidade no Estoque: \t" << medicamento.quantEstoque;
    cout << "\nEstoque minimo: \t" << medicamento.estoqueMinimo;
    cout << "\nEstoque maximo: \t" << medicamento.estoqueMaximo;
    cout << "\nPreco Unitario: \t" << medicamento.precoUnitario;
}


void imprimirListaMedicamento(struct medicamento listaMedicamento[], int contador_medicamento) {
    limparTela();
    for(int i = 0; i < contador_medicamento; i++) {
        imprimirMedicamento(listaMedicamento[i]);
        cout << endl;
    }
}

medicamento* buscarMedicamento(int codigo_entrada, struct medicamento listaMedicamento[], int contador_medicamento) {
    for(int i=0; i<contador_medicamento; i++) {
        if(codigo_entrada == listaMedicamento[i].codigo) {
            return &listaMedicamento[i];
        }
    }
    return NULL;
}

void lerMedicamento(struct medicamento listaMedicamento[], int contador_medicamento) {
    limparTela();
    cout << "\nDigite o codigo do medicamento: ";
    cin >> listaMedicamento[contador_medicamento].codigo;
    cout << "\nDigite o nome do medicamento: ";
    fflush(stdin);
    getline(cin, listaMedicamento[contador_medicamento].nome);
    fflush(stdin);
    do {
        cout << "\nDigite a quantidade no Estoque: ";
        cin >> listaMedicamento[contador_medicamento].quantEstoque;
        if (listaMedicamento[contador_medicamento].quantEstoque < 0) {
            cout << "\nQuantidade negativo, Por favor digite outro valor";
        }
    } while (listaMedicamento[contador_medicamento].quantEstoque < 0);
    do {
        cout << "\nDigite a quantidade de estoque Minimo: ";
        cin >> listaMedicamento[contador_medicamento].estoqueMinimo;
        if (listaMedicamento[contador_medicamento].estoqueMinimo < 0) {
            cout << "\nQuantidade negativo, Por favor digite outro valor";
        }
    } while (listaMedicamento[contador_medicamento].estoqueMinimo < 0);
    do {
        cout << "\nDigite a quantidade de estoque Maximo: ";
        cin >> listaMedicamento[contador_medicamento].estoqueMaximo;
        if (listaMedicamento[contador_medicamento].estoqueMinimo > listaMedicamento[contador_medicamento].estoqueMaximo) {
            cout << "\nEstoque maximo esta menor que o minino :C, Por favor digite outro valor";
        }
    } while (listaMedicamento[contador_medicamento].estoqueMinimo > listaMedicamento[contador_medicamento].estoqueMaximo);
    do {
        cout << "\nDigite o valor unitario de cada medicamento: ";
        cin >> listaMedicamento[contador_medicamento].precoUnitario;
        if (listaMedicamento[contador_medicamento].precoUnitario < 0) {
            cout << "\nValor negativo, Por favor digite outro valor";
        }
    } while (listaMedicamento[contador_medicamento].precoUnitario < 0);
}


void reduzirEstoque(struct medicamento* medicamento, int saida) {
    medicamento->quantEstoque -= saida;
}

//-----------------------------------MEDICO-------------------------------------

void imprimirMedico(const struct medico& medico) {
    cout << "\nMedico: \t" << medico.codigo;
    cout << "\nNome: \t\t" << medico.nome;
    imprimirEspecialidade(*medico.codigoEspecialidade);
    cout << "\nEndereco: \t" << medico.endereco;
    cout << "\nTelefone: \t" << medico.telefone;
    imprimirCidade(*medico.codigoCidade);
}

void imprimirListaMedico(struct medico listaMedico[], int contador_medico) {
    limparTela();
    for (int i = 0; i < contador_medico; i++) {
        imprimirMedico(listaMedico[i]);
        cout << endl;
    }
}

medico* buscarMedico(int codigo_entrada, struct medico listaMedico[], int contador_medico) {
    for (int i = 0; i < contador_medico; i++) {
        if (codigo_entrada == listaMedico[i].codigo) {
            return &listaMedico[i];
        }
    }
    return NULL;
}

void lerMedico(struct medico listaMedico[], int contador_medico, struct especialidade listaEspecialidade[],
               int contador_especialidade, struct cidade listaCidade[], int contador_cidade) {
    if (contador_especialidade != 0 && contador_cidade != 0) {
        bool validacao;
        int codigo;
        limparTela();
        do {
            cout << "\nDigite o codigo do medico: ";
            cin >> codigo;
            if (buscarMedico(codigo, listaMedico, contador_medico) == NULL) {
                validacao = true;
                listaMedico[contador_medico].codigo = codigo;
            } else {
                cout << "\nCodigo de medico ja existe, Por favor digite outro codigo";
                validacao = false;
            }
        } while (!validacao);
        cout << "\nDigite o nome do medico: ";
        fflush(stdin);
        getline(cin, listaMedico[contador_medico].nome);
        fflush(stdin);
        do {
            imprimirListaEspecialidade(listaEspecialidade, contador_especialidade);
            cout << "\nDigite o codigo de Especialidade: ";
            cin >> codigo;
            listaMedico[contador_medico].codigoEspecialidade = buscarEspecialidade
                    (codigo, listaEspecialidade, contador_especialidade);
            if (listaMedico[contador_medico].codigoEspecialidade != NULL) {
                validacao = true;
            } else {
                cout << "\nCodigo de especialidade nao existe, Por favor digite outro valor";
                validacao = false;
            }
        } while (!validacao);
        cout << "\nDigite o endereco: ";
        fflush(stdin);
        getline(cin, listaMedico[contador_medico].endereco);
        fflush(stdin);
        do {
            cout << "\nDigite o telefone: ";
            fflush(stdin);
            getline(cin,listaMedico[contador_medico].telefone);
            fflush(stdin);
            if (listaMedico[contador_medico].telefone.size() != 14) {
                cout << "\nTelefone invalido, tente escriver ele nessa modelo (xx)xxxxx-xxxx";
            }
        } while (listaMedico[contador_medico].telefone.size() != 14);
        do {
            imprimirListaCidade(listaCidade, contador_cidade);
            cout << "\nDigite o codigo da Cidade: ";
            cin >> codigo;
            listaMedico[contador_medico].codigoCidade = buscarCidade(codigo, listaCidade, contador_cidade);
            if (listaMedico[contador_medico].codigoCidade != NULL) {
                validacao = true;
            } else {
                cout << "\nCodigo de cidade nao existe, Por favor digite outro valor";
                validacao = false;
                getch();
            }
        } while (!validacao);
    } else {
        if (contador_especialidade < 1) {
            cout << "\nLista de especialide Vazia, por fazer registre uma especialidade primeiro :C";
        }
        if (contador_cidade < 1) {
            cout << "\nLista de cidade Vazia, por fazer registre uma cidade primeiro :C";
        }
        getch();
    }
}

//-------------------------------PACIENTE-----------------------------------
void imprimirPaciente(const struct paciente &paciente) {
    cout << "\nPaciente: \t" << paciente.CPF;
    cout << "\nNome: \t\t" << paciente.nome;
    cout << "\nEndereco: \t" << paciente.endereco;
    imprimirCidade(*paciente.codigoCidade);
}

void imprimirListaPaciente(paciente listaPacientes[], int contador_paciente) {
    limparTela();
    for (int i = 0; i < contador_paciente; i++) {
        cout << "\nCodigo [" << i << "]:";
        imprimirPaciente(listaPacientes[i]);
    }
}

paciente* buscarPaciente(string &codigo_entrada, struct paciente listaPaciente[], int contador_paciente) {
    for (int i = contador_paciente - 1; i > -1; i--) {
        if (!(codigo_entrada.compare(listaPaciente[i].CPF))) {
            return &listaPaciente[i];
        }
    }
    return NULL;
}

void lerPaciente(struct paciente listaPaciente[], int contador_paciente, struct cidade listaCidade[], int contador_cidade) {
    if (contador_cidade > 0) {
        bool validacao;
        string CPF;
        int codigo;
        paciente *encontrado;
        limparTela();
        do {
            cout << "\nDigite o cpf do paciente: ";
            fflush(stdin);
            getline(cin, CPF);
            fflush(stdin);
            encontrado = buscarPaciente(CPF, listaPaciente, contador_paciente);
            if (encontrado == NULL) {
                if (CPF.size() > 13) {
                    validacao = true;
                    listaPaciente[contador_paciente].CPF = CPF;
                } else {
                    cout << "\nCPF invalido possui menos digitos que o necessario";
                    cout << "\nExemplo: 111.111.111-11";
                }
            } else {
                cout << "\nCPF do paciente ja existe, Por favor digite outro cpf";
                validacao = false;
            }
        } while (!validacao);
        do {
            cout << "\nDigite o nome do paciente: ";
            cin >> listaPaciente[contador_paciente].nome;
            validacao = (!listaPaciente[contador_paciente].nome.empty());
            if (!validacao) {
                cout << "\nO nome esta sem nada, por favor digite alguma coisa...";
            }
        } while (!validacao);
        do {
            cout << "\nDigite o endereco do paciente: ";
            fflush(stdin);
            getline(cin, listaPaciente[contador_paciente].endereco);
            fflush(stdin);
            validacao = (!listaPaciente[contador_paciente].endereco.empty());
            if (!validacao) {
                cout << "\nO endereco nao foi digitado, por favor digite algo...";
            }
        } while (!validacao);
        do {
            imprimirListaCidade(listaCidade, contador_cidade);
            cout << "\nDigite o codigo de uma cidade: ";
            cin >> codigo;
            listaPaciente[contador_paciente].codigoCidade = buscarCidade(codigo, listaCidade, contador_cidade);
            if (listaPaciente[contador_paciente].codigoCidade != NULL) {
                validacao = true;
            } else {
                cout << "\nCodigo de cidade nao existe, Por favor digite outro valor";
                validacao = false;
            }
        } while (!validacao);
    } else {
        cout << "\nLista de cidade Vazia, por favor registre uma cidade primeiro :C";
        getch();
    }
}

void removerRegistroPaciente(struct paciente listaPaciente[], int *contador_paciente) {
    if (*contador_paciente > 0) {
        int codigo_remocao;
        int confirmacao;
        do {
            do {
                limparTela();
                imprimirListaPaciente(listaPaciente, *contador_paciente);
                cout << "\n\nQual registro deseja remover: (-1 Cancelar remoção) ";
                cin >> codigo_remocao;
                if (codigo_remocao >= *contador_paciente || codigo_remocao < -1) {
                    cout << "Codigo de remocao nao pertece a lista, :C";
                    getch();
                } else if (codigo_remocao == -1) {
                    return;
                }
            } while (codigo_remocao >= *contador_paciente || codigo_remocao < -1);
            limparTela();
            imprimirPaciente(listaPaciente[codigo_remocao]);
            cout << "\n\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
            cin >> confirmacao;
        } while (confirmacao == 0);
        if (confirmacao == 1) {
            while (codigo_remocao < (*contador_paciente - 1)) {
                listaPaciente[codigo_remocao] = listaPaciente[codigo_remocao + 1];
                codigo_remocao++;
            }
            *contador_paciente = *contador_paciente - 1;
        }
    } else {
        cout << "\nLista de Paciente Vazia, nao tem oque remover";
        getch();
    }
}

//----------------------------------CONSULTA------------------------------------------
void imprimirConsulta(const struct consulta &consulta) {
    cout << "\n\tConsulta: ";
    imprimirPaciente(consulta.cpfPaciente);
    imprimirMedico(consulta.codMedico);

    cout << "\nData(dd/mm/yy hh:MM:ss): " << consulta.dataHora;

    imprimirCID(consulta.codCID);
    imprimirMedicamento(consulta.codMedicamento);
    cout << "\nQtd usado do Medicamento: \t" << consulta.qtdeMedicamento;
}

void
agendarConsulta(struct consulta *consulta, struct paciente listaPaciente[], int contador_paciente, struct medico listaMedico[],
                int contador_medico, struct CID listaCID[], int contador_cid, struct medicamento listaMedicamento[], int contador_medicamento) {
    if (contador_paciente > 0 && contador_medico > 0) {
        bool validacao;
        string CPF;
        int codigo;
        paciente* paciente;
        limparTela();
        do {
            imprimirListaPaciente(listaPaciente, contador_paciente);
            cout << "\nDigite o CPF do paciente: ";
            cin >> CPF;
            paciente = buscarPaciente(CPF, listaPaciente, contador_paciente);
            if (paciente == NULL) {
                cout << "\nEste CPF nao existe na lista de paciente :C";
                validacao = false;
                getch();
            } else {
                validacao = true;
                consulta->cpfPaciente = *paciente;
            }
        } while (!validacao);
        medico* medico;
        do {
            imprimirListaMedico(listaMedico, contador_medico);
            cout << "\nDigite o codigo do medico: ";
            cin >> codigo;
            medico = buscarMedico(codigo, listaMedico, contador_medico);
            if (medico == NULL) {
                cout << "\nEste codigo nao existe na lista de medico :C";
                validacao = false;
                getch();
            } else {
                consulta->codMedico = *medico;
                validacao = true;
            }
        } while (!validacao);

        do {
            cout << "Digite o data e hora: (dd/mm/yy hh:MM:ss) ";
            fflush(stdin);
            getline(cin, consulta->dataHora);
            fflush(stdin);
            if (consulta->dataHora.size() > 16 && consulta->dataHora.find('/') && consulta->dataHora.find(':')) {
                validacao = true;
            } else {
                validacao = false;
                cout << "\nData e hora incorretas :C";
                cout << "\nExemplo: 11/11/11 11:11:11";
            }
        } while (!validacao);
        CID* cid;
        do {
            imprimirListaCID(listaCID, contador_cid);
            cout << "\nDigite o codigo da CID: ";
            cin >> codigo;
            cid = buscarCID(codigo, listaCID, contador_cid);
            if (cid == NULL)  {
                validacao = false;
                cout << "\nEste codigo nao, pertence a lista de CID :C";
                getch();
            } else {
                consulta->codCID = *cid;
                validacao = true;
            }
        } while (!validacao);
        medicamento* medicamento;
        do {
            imprimirListaMedicamento(listaMedicamento, contador_medicamento);
            cout << "\nDigite o codigo do Medicamento: ";
            cin >> codigo;
            medicamento = buscarMedicamento(codigo, listaMedicamento, contador_medicamento);
            if (medicamento == NULL) {
                validacao = false;
                cout << "\nEste codigo nao, pertence a lista de Medicamento :C";
                getch();
            } else {
                consulta->codMedicamento = *medicamento;
                validacao = true;
            }
        } while (!validacao);

        do {
            imprimirMedicamento(consulta->codMedicamento);
            cout << "\nDigite a quantidade de medicamento que sera usado: ";
            cin >> consulta->qtdeMedicamento;
            if(consulta->qtdeMedicamento > consulta->codMedicamento.quantEstoque){
                cout << "\nA quantidade de medicamento nao pode ser maior que a quantidade do medicamento em estoque";
                validacao = false;
            }else if(consulta->qtdeMedicamento < 0){
                cout << "\nA quantidade de medicamento nao pode ser 0 nem negativo";
                validacao = false;
            }else {
                validacao = true;
            }
        }while(!validacao);

    } else {
        if (contador_paciente < 1) {
            cout << "\nLista de paciente Vazia, por favor registre um paciente primeiro :C";
        }
        if (contador_medico < 1) {
            cout << "\nLista de medico Vazia, por favor registre um medico primeiro :C";
        }
        if (contador_cid < 1) {
            cout << "\nLista de CID Vazia, por favor registre uma CID primeiro :C";
        }
        if (contador_medicamento < 1) {
            cout << "\nLista de medicamento Vazia, por favor registre um medicamento primeiro :C";
        }
        getch();
    }
}
