#include <iostream>
#include <cstring>

using namespace std;

struct cidade {
    int codigo;
    string nome;
    char UF[3];

    void lerCidade() {
        system("cls");
        cout << "\nDigite o codigo da cidade: ";
        cin >> codigo;
        cout << "\nDigite o nome da cidade: ";
        fflush(stdin);
        getline(cin, nome);
        fflush(stdin);
        cout << "\nDigite a UF da cidade: ";
        gets(UF);

    }

    void imprimirCidade() const {
        cout << "\nCidade: " << codigo;
        cout << "\nNome: " << nome;
        cout << "\nUF: " << UF;
    }
};

struct especialidade {
    int codigo;
    string descricao;

    void lerEspecialidade() {
        system("cls");
        cout << "\nDigite o codigo da especialidade: ";
        cin >> codigo;
        cout << "\nDigite a descricao: ";
        fflush(stdin);
        getline(cin, descricao);
        fflush(stdin);
    }

    void imprimirEspecialidade() const {
        cout << "\nEspecialidade: " << codigo;
        cout << "\nDescricao: " << descricao;
    }

};

struct CID {
    int codigo;
    string descricao;

    void lerCID() {
        system("cls");
        cout << "\nDigite o codigo da CID: ";
        cin >> codigo;
        cout << "\nDigite a descricao: ";
        fflush(stdin);
        getline(cin, descricao);
        fflush(stdin);
    }

    void imprimirCID() const {
        cout << "\nCID: " << codigo;
        cout << "\nDescricao: " << descricao;
    }
};

struct medicamento {
    int codigo;
    string nome;
    int quantEstoque;
    int estoqueMinimo;
    int estoqueMaximo;
    float precoUnitario;

    void lerMedicamento() {
        system("cls");
        cout << "\nDigite o codigo do medicamento: ";
        cin >> codigo;
        cout << "\nDigite o nome do medicamento: ";
        fflush(stdin);
        getline(cin, nome);
        fflush(stdin);
        do {
            cout << "\nDigite a quantidade no Estoque: ";
            cin >> quantEstoque;
            if (quantEstoque < 0) {
                cout << "\nQuantidade negativo, Por favor digite outro valor";
            }
        } while (quantEstoque < 0);
        do {
            cout << "\nDigite a quantidade de estoque Minimo: ";
            cin >> estoqueMinimo;
            if (estoqueMinimo < 0) {
                cout << "\nQuantidade negativo, Por favor digite outro valor";
            }
        } while (estoqueMinimo < 0);
        do {
            cout << "\nDigite a quantidade de estoque Maximo: ";
            cin >> estoqueMaximo;
            if (estoqueMinimo > estoqueMaximo) {
                cout << "\nEstoque maximo esta menor que o minino :C, Por favor digite outro valor";
            }
        } while (estoqueMinimo > estoqueMaximo);
        do {
            cout << "\nDigite o valor unitario de cada medicamento: ";
            cin >> precoUnitario;
            if (precoUnitario < 0) {
                cout << "\nValor negativo, Por favor digite outro valor";
            }
        } while (precoUnitario < 0);
    }

    void imprimirMedicamento() const {
        cout << "\nMedicamento: " << codigo;
        cout << "\nNome: \t" << nome;
        cout << "\nQuantidade no Estoque: \t" << quantEstoque;
        cout << "\nEstoque minimo: \t" << estoqueMinimo;
        cout << "\nEstoque maximo: \t" << estoqueMaximo;
        cout << "\nPreco Unitario: \t" << precoUnitario;
    }
};

bool existeEspecialidade(int codigo_entrada, struct especialidade listaEspecialidade[], int contador_especialidade){
    for(int i = contador_especialidade-1; i > -1;i--){
        if(codigo_entrada == listaEspecialidade[i].codigo){
            return true;
        }
    }
    return false;
};

void imprimirListaEspecialidade(struct especialidade listaEspecialidade[], int contador_especialidade){
    for(int i=0; i<contador_especialidade;i++){
        listaEspecialidade[i].imprimirEspecialidade();
        cout << endl;
    }
}

bool existeCidade(int codigo_entrada, struct cidade listaCidade[], int contador_cidade){
    for(int i = contador_cidade-1; i > -1;i--){
        if(codigo_entrada == listaCidade[i].codigo){
            return true;
        }
    }
    return false;
}

void imprimirListaCidade(struct cidade listaCidade[], int contador_cidade){
    for(int i=0; i<contador_cidade;i++){
        listaCidade[i].imprimirCidade();
        cout << endl;
    }
}



struct medico {
    int codigo;
    string nome;
    int codigoEspecialidade;
    string endereco;
    char telefone[14];
    int codigoCidade;

};

void imprimirMedico(struct medico listaMedico[],int contador_medico) const {
    cout << "\nMedico: " << listaMedico[contador_medico].codigo;
    cout << "\nNome: \t" << listaMedico[contador_medico].nome;
    cout << "\nCodigo Especialidade: \t" << listaMedico[contador_medico].codigoEspecialidade;
    cout << "\nEndereco: \t" << listaMedico[contador_medico].endereco;
    cout << "\nTelefone: \t" << listaMedico[contador_medico].telefone;
    cout << "\nCodigo Cidade: \t" << listaMedico[contador_medico].codigoCidade;
}

bool existeMedico(int codigo, struct medico listaMedico[], int contador_medico) {
    for(int i= contador_medico - 1; i > -1; i--){
        if (codigo == listaMedico[i].codigo){
            return true;
        }
    }
    return false;
}


void lerMedico(struct medico listaMedico[], int contador_medico, struct especialidade listaEspecialidade[], int contador_especialidade, struct cidade listaCidade[], int contador_cidade){
    if(contador_especialidade != 0 && contador_cidade != 0) {
        bool validacao;
        int codigo;
        system("cls");
        do {
            cout << "\nDigite o codigo do medico: ";
            cin >> codigo;
            validacao = existeMedico(codigo,listaMedico,contador_medico);
            if(validacao){
                cout << "\nCodigo de medico ja existe, Por favor digite outro codigo";
            }
        }while(validacao);
        cout << "\nDigite o nome do medico: ";
        fflush(stdin);
        getline(cin, listaMedico[contador_medico].nome);
        fflush(stdin);
        do {
            imprimirListaEspecialidade(listaEspecialidade, contador_especialidade);
            cout << "\nDigite o codigo de Especialidade: ";
            cin >> listaMedico[contador_medico].codigoEspecialidade;
            validacao = existeEspecialidade(listaMedico[contador_medico].codigoEspecialidade, listaEspecialidade, contador_especialidade);
            if (!validacao) {
                cout << "\nCodigo de especialidade nao existe, Por favor digite outro valor";
            }
        } while (!validacao);
        cout << "\nDigite o endereco: ";
        fflush(stdin);
        getline(cin, listaMedico[contador_medico].endereco);
        fflush(stdin);
        do {
            cout << "\nDigite o telefone: ";
            gets(listaMedico[contador_medico].telefone);
            if(strlen(listaMedico[contador_medico].telefone) != 14){
                cout << "\nTelefone invalido, tente escriver ele nessa modelo (xx)xxxxx-xxxx";
            }
        }while(strlen(listaMedico[contador_medico].telefone) != 14);
        do {
            imprimirListaCidade(listaCidade,contador_cidade);
            cout << "\nDigite o codigo da Cidade: ";
            cin >> listaMedico[contador_medico].codigoCidade;
            validacao = existeCidade(listaMedico[contador_medico].codigoCidade, listaCidade, contador_cidade);
            if (!validacao) {
                cout << "\nCodigo de cidade nao existe, Por favor digite outro valor";
            }
        } while (!validacao);
    }else{
        if(contador_especialidade == 0){
            cout << "\nLista de especialide Vazia, por fazer registre uma especialidade primeiro :C";
        }else{
            cout << "\nLista de cidade Vazia, por fazer registre uma cidade primeiro :C";
        }
    }
}

struct paciente {
    int CPF;
    string nome;
    string endereco;
    int codigoCidade;
};

struct datetime {
    int ano;
    int mes;
    int dia;
};

struct timestamp {
    int hora;
    int minuto;
    int segundo;
};

struct consulta {
    int cpfPaciente;
    int codMedico;
    datetime data;
    timestamp horario;
    int codCID;
    int codMedicamento;
    int qtdeMedicamento;
};

int main() {

    setlocale(LC_ALL, "portuguese");

    int confirmacao;

    int tamanho_cidade = 10;
    int contador_cidade = 3;
    cidade listaCidade[tamanho_cidade];

    /*DADOS INJETADOS DE CIDADE*/

    listaCidade[0] = {1, "Assis", "SP"};
    listaCidade[1] = {3, "Candido Mota", "SP"};
    listaCidade[2] = {4, "Unai", "MG"};

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

    listaMedicamento[0] = {2, "Tadala", 3, 1, 6, 2.5};
    listaMedicamento[1] = {3, "Paracetamol", 4, 2, 7, 5.9};
    listaMedicamento[2] = {4, "Neuzadina", 5, 3, 10, 10.2};

    int tamanho_medico = 10;
    int contador_medico = 3;
    medico listaMedico[tamanho_medico];

    /*DADOS INJETADOS DE MEDICO*/

    listaMedico[0] = {1,"Robeto",2,"Augusta Melo, 535","(18)9912-2123",1};
    listaMedico[1] = {3,"Alex",3,"Daniel Cruz, 991","(18)9933-3323",4};
    listaMedico[2] = {4,"Rodrigo",2,"Jose Nogueira, 123","(18)9001-0013",4};

    int op = 1;
    while (op != 0) {
        system("cls");
        cout << "\nMENU" << endl;
        cout << "\n0 - Sair";
        cout << "\n1 - Ler cidade";
        cout << "\n2 - Ler especialidade";
        cout << "\n3 - Ler CID";
        cout << "\n4 - Ler Medicamento";
        cout << "\n5 - Ler Medico";

        cout << "\n\nDigite qual acão deseja fazer: ";
        cin >> op;
        switch (op) {
            case 1:
                if (contador_cidade < tamanho_cidade) {
                    do {
                        listaCidade[contador_cidade].lerCidade();
                        system("cls");
                        listaCidade[contador_cidade].imprimirCidade();
                        cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                        cin >> confirmacao;
                    } while (confirmacao == 0);
                    if (confirmacao == 1) {
                        contador_cidade++;
                    }
                } else {
                    cout << "\nLista de cidade cheia :C";
                }
                break;
            case 2:
                if (contador_especialidade < tamanho_especialidade) {
                    do {
                        listaEspecialidade[contador_especialidade].lerEspecialidade();
                        system("cls");
                        listaEspecialidade[contador_especialidade].imprimirEspecialidade();
                        cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                        cin >> confirmacao;
                    } while (confirmacao == 0);
                    if (confirmacao == 1) {
                        contador_especialidade++;
                    }
                } else {
                    cout << "\nLista de especialidade cheia :C";
                }
                break;
            case 3:
                if (contador_cid < tamanho_cid) {
                    do {
                        listaCID[contador_cid].lerCID();
                        system("cls");
                        listaCID[contador_cid].imprimirCID();
                        cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                        cin >> confirmacao;
                    } while (confirmacao == 0);
                    if (confirmacao == 1) {
                        contador_cid++;
                    }
                } else {
                    cout << "\nLista de CID cheia :C";
                }
                break;
            case 4:
                if (contador_medicamento < tamanho_medicamento) {
                    do {
                        listaMedicamento[contador_medicamento].lerMedicamento();
                        system("cls");
                        listaMedicamento[contador_medicamento].imprimirMedicamento();
                        cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                        cin >> confirmacao;
                    } while (confirmacao == 0);
                    if (confirmacao == 1) {
                        contador_medicamento++;
                    }
                } else {
                    cout << "\nLista de Medicamento cheia :C";
                }
                break;
            case 5:
                if (contador_medico < tamanho_medico) {
                    do {
                        lerMedico(listaMedico,contador_medico,listaEspecialidade,contador_especialidade,listaCidade,contador_cidade);
                        system("cls");
                        listaMedico[contador_medico].imprimirMedico();
                        cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                        cin >> confirmacao;
                    } while (confirmacao == 0);
                    if (confirmacao == 1) {
                        contador_medico++;
                    }
                } else {
                    cout << "\nLista de Medico cheia :C";
                }
                break;
            default:
                break;
        }

    }
    return 0;
}
