#include <iostream>
#include <cstring>
#include <conio.h>

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
        cout << "\nCidade: \t" << codigo;
        cout << "\nNome: \t\t" << nome;
        cout << "\nUF: \t\t" << UF;
    }
};

cidade buscarCidade(int codigo_entrada, struct cidade listaCidade[], int contador_cidade) {
    for (int i = contador_cidade - 1; i > -1; i--) {
        if (codigo_entrada == listaCidade[i].codigo) {
            return listaCidade[i];
        }
    }
    return cidade{-1, ""};
}

void imprimirListaCidade(struct cidade listaCidade[], int contador_cidade) {
    system("cls");
    for (int i = 0; i < contador_cidade; i++) {
        listaCidade[i].imprimirCidade();
        cout << endl;
    }
}

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
        cout << "\nEspecialidade: \t" << codigo;
        cout << "\nDescricao: \t" << descricao;
    }
};

especialidade buscarEspecialidade
(int codigo_entrada, struct especialidade listaEspecialidade[], int contador_especialidade) {
    for (int i = contador_especialidade - 1; i > -1; i--) {
        if (codigo_entrada == listaEspecialidade[i].codigo) {
            return listaEspecialidade[i];
        }
    }
    return especialidade{-1};
};

void imprimirListaEspecialidade(struct especialidade listaEspecialidade[], int contador_especialidade) {
    system("cls");
    for (int i = 0; i < contador_especialidade; i++) {
        listaEspecialidade[i].imprimirEspecialidade();
        cout << endl;
    }
}

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
        cout << "\nCID: \t\t\t" << codigo;
        cout << "\nDescricao: \t" << descricao;
    }
};

void imprimirListaCID(struct CID listaCID[], int contador_cid) {
    system("cls");
    for (int i = 0; i < contador_cid; i++) {
        listaCID[i].imprimirCID();
        cout << endl;
    }
}

CID* buscarCID(int codigo_entrada, struct CID listaCID[], int contador_cid) {
    for (int i = 0; i < contador_cid; i++) {
        if (codigo_entrada == listaCID[i].codigo) {
            return &listaCID[i];
        }
    }
    CID cid_nao_encontrada = {-1};
    return &cid_nao_encontrada;
}

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
        cout << "\nMedicamento: \t\t" << codigo;
        cout << "\nNome: \t\t\t" << nome;
        cout << "\nQuantidade no Estoque: \t" << quantEstoque;
        cout << "\nEstoque minimo: \t" << estoqueMinimo;
        cout << "\nEstoque maximo: \t" << estoqueMaximo;
        cout << "\nPreco Unitario: \t" << precoUnitario;
    }

    void reduzirEstoque(int saida) {
        quantEstoque -= saida;
    }
};

void imprimirListaMedicamento(struct medicamento listaMedicamento[], int contador_medicamento) {
    system("cls");
    for(int i = 0; i < contador_medicamento; i++) {
        listaMedicamento[i].imprimirMedicamento();
        cout << endl;
    }
}

medicamento* buscarMedicamento(int codigo_entrada, struct medicamento listaMedicamento[], int contador_medicamento) {
    for(int i=0; i<contador_medicamento; i++) {
        if(codigo_entrada == listaMedicamento[i].codigo) {
            return &listaMedicamento[i];
        }
    }
    medicamento medicamento_nao_encontrado = {-1};
    return &medicamento_nao_encontrado;
}

struct medico {
    int codigo;
    string nome;
    especialidade codigoEspecialidade;
    string endereco;
    char telefone[14];
    cidade codigoCidade;
};

void imprimirMedico(struct medico medico) {
    cout << "\nMedico: \t" << medico.codigo;
    cout << "\nNome: \t\t" << medico.nome;
    medico.codigoEspecialidade.imprimirEspecialidade();
    cout << "\nEndereco: \t" << medico.endereco;
    cout << "\nTelefone: \t" << medico.telefone;
    medico.codigoCidade.imprimirCidade();
}

void imprimirListaMedico(struct medico listaMedico[], int contador_medico) {
    system("cls");
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
    medico medico_nao_encontrado = {-1};
    return &medico_nao_encontrado;
}

void lerMedico
(
    struct medico listaMedico[], int contador_medico, struct especialidade listaEspecialidade[],
    int contador_especialidade, struct cidade listaCidade[], int contador_cidade) {
    if (contador_especialidade != 0 && contador_cidade != 0) {
        bool validacao;
        int codigo;
        system("cls");
        do {
            cout << "\nDigite o codigo do medico: ";
            cin >> codigo;
            listaMedico[contador_medico] = *buscarMedico(codigo, listaMedico, contador_medico);
            if (listaMedico[contador_medico].codigo != -1) {
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
            if (listaMedico[contador_medico].codigoEspecialidade.codigo != -1) {
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
            gets(listaMedico[contador_medico].telefone);
            if (strlen(listaMedico[contador_medico].telefone) != 14) {
                cout << "\nTelefone invalido, tente escriver ele nessa modelo (xx)xxxxx-xxxx";
            }
        } while (strlen(listaMedico[contador_medico].telefone) != 14);
        do {
            imprimirListaCidade(listaCidade, contador_cidade);
            cout << "\nDigite o codigo da Cidade: ";
            cin >> codigo;
            listaMedico[contador_medico].codigoCidade = buscarCidade(codigo, listaCidade, contador_cidade);
            if (listaMedico[contador_medico].codigoCidade.codigo != -1) {
                validacao = true;
            } else {
                cout << "\nCodigo de cidade nao existe, Por favor digite outro valor";
                validacao = false;
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

struct paciente {
    string CPF;
    string nome;
    string endereco;
    cidade codigoCidade;
};

void imprimirPaciente(const struct paciente &paciente) {
    cout << "\nPaciente: \t" << paciente.CPF;
    cout << "\nNome: \t\t" << paciente.nome;
    cout << "\nEndereco: \t" << paciente.endereco;
    paciente.codigoCidade.imprimirCidade();
}

void imprimirListaPaciente(paciente listaPacientes[], int contador_paciente) {
    system("cls");
    for (int i = 0; i < contador_paciente; i++) {
        cout << "\nCodigo [" << i << "]:";
        imprimirPaciente(listaPacientes[i]);
    }
}

paciente* buscarPaciente(const string &codigo_entrada, struct paciente listaPaciente[], int contador_paciente) {
    for (int i = contador_paciente - 1; i > -1; i--) {
        if (!(codigo_entrada.compare(listaPaciente[i].CPF))) {
            return &listaPaciente[i];
        }
    }
    paciente paciente_nao_encontrado = {""};
    return &paciente_nao_encontrado;
}

void lerPaciente
(struct paciente listaPaciente[], int contador_paciente, struct cidade listaCidade[], int contador_cidade) {
    if (contador_cidade > 0) {
        bool validacao;
        string CPF;
        int codigo;
        do {
            cout << "\nDigite o cpf do paciente: ";
            fflush(stdin);
            getline(cin, CPF);
            fflush(stdin);
            listaPaciente[contador_paciente] = *buscarPaciente(CPF, listaPaciente, contador_paciente);
            if (listaPaciente[contador_paciente].CPF.empty()) {
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
            if (listaPaciente[contador_paciente].codigoCidade.codigo != -1) {
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
                system("cls");
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
            system("cls");
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
    paciente* cpfPaciente;
    medico* codMedico;
    //datetime data;
    //timestamp horario;
    string dataHora;
    CID* codCID;
    medicamento* codMedicamento;
    int qtdeMedicamento;
};

void imprimirConsulta(const struct consulta &consulta) {
    cout << "\n\tConsulta: ";
    imprimirPaciente(*consulta.cpfPaciente);
    imprimirMedico(*consulta.codMedico);

    cout << "\nData(dd/mm/yy hh:MM:ss): " << consulta.dataHora;

    consulta.codCID->imprimirCID();
    consulta.codMedicamento->imprimirMedicamento();
    cout << "\nQtd usado do Medicamento: \t" << consulta.qtdeMedicamento;
}

void
agendarConsulta(struct consulta *consulta, struct paciente listaPaciente[], int contador_paciente, struct medico listaMedico[],
    int contador_medico, struct CID listaCID[], int contador_cid, struct medicamento listaMedicamento[], int contador_medicamento) {
    if (contador_paciente > 0 && contador_medico > 0) {
        bool validacao;
        string CPF;
        int codigo;
        do {
            imprimirListaPaciente(listaPaciente, contador_paciente);
            cout << "\nDigite o CPF do paciente: ";
            cin >> CPF;
            consulta->cpfPaciente = buscarPaciente(CPF, listaPaciente, contador_paciente);
            if (consulta->cpfPaciente->CPF.empty()) {
                cout << "\nEste CPF nao existe na lista de paciente :C";
                validacao = false;
                getch();
            } else {
                validacao = true;
            }
        } while (!validacao);
        do {
            imprimirListaMedico(listaMedico, contador_medico);
            cout << "\nDigite o codigo do medico: ";
            cin >> codigo;
            consulta->codMedico = buscarMedico(codigo, listaMedico, contador_medico);
            if (consulta->codMedico->codigo == -1) {
                cout << "\nEste codigo nao existe na lista de medico :C";
                validacao = false;
                getch();
            } else {
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

        do {
            imprimirListaCID(listaCID, contador_cid);
            cout << "\nDigite o codigo da CID: ";
            cin >> codigo;
            consulta->codCID = buscarCID(codigo, listaCID, contador_cid);
            if (consulta->codCID->codigo == -1) {
                validacao = false;
                cout << "\nEste codigo nao, pertence a lista de CID :C";
                getch();
            } else {
                validacao = true;
            }
        } while (!validacao);

        do {
            imprimirListaMedicamento(listaMedicamento, contador_medicamento);
            cout << "\nDigite o codigo do Medicamento: ";
            cin >> codigo;
            consulta->codMedicamento = buscarMedicamento(codigo, listaMedicamento, contador_medicamento);
            if (consulta->codMedicamento->codigo == -1) {
                validacao = false;
                cout << "\nEste codigo nao, pertence a lista de Medicamento :C";
                getch();
            } else {
                validacao = true;
            }
        } while (!validacao);

        do {
            consulta->codMedicamento->imprimirMedicamento();
            cout << "\nDigite a quantidade de medicamento que sera usado: ";
            cin >> consulta->qtdeMedicamento;
            if(consulta->qtdeMedicamento > consulta->codMedicamento->quantEstoque){
                cout << "\nA quantidade de medicamento nao pode ser maior que a quantidade do medicamento em estoque";
                validacao = false;
            }else if(consulta->qtdeMedicamento < 0){
                cout << "\nA quantidade de medicamento nao pode ser negativo nem 0";
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

    listaMedico[0] = {1, "Robeto", listaEspecialidade[0], "Augusta Melo, 535", "(18)9912-2123", listaCidade[0]};
    listaMedico[1] = {3, "Alex", listaEspecialidade[1], "Daniel Cruz, 991", "(18)9933-3323", listaCidade[2]};
    listaMedico[2] = {4, "Rodrigo", listaEspecialidade[0], "Jose Nogueira, 123", "(18)9001-0013", listaCidade[2]};

    int tamanho_paciente = 10;
    int contador_paciente = 3;
    paciente listaPaciente[tamanho_paciente];

    /*DADOS INJETADOS DE PACIENTE*/

    listaPaciente[0] = {"123.123.123-10", "Danilo", "Obama Clintom,566", listaCidade[1]};
    listaPaciente[1] = {"145.645.623-04", "Rogerio", "Mello de Ferro", listaCidade[2]};
    listaPaciente[2] = {"150.003.432-22", "Nicolas", "Lincom Presidente", listaCidade[0]};

    int tamanho_consulta = 10;
    int contador_consulta = 3;
    consulta listaConsulta[tamanho_consulta];

    /*DADOS INJETOS DE CONSULTA*/

    listaConsulta[0] = {};
    listaConsulta[1] = {};
    listaConsulta[2] = {};

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
        cout << "\n6 - Ler Paciente";
        cout << "\n7 - Excluir Registro de Paciente";
        cout << "\n8 - Agendar consulta";
        cout << "\n9 - Consultar medicamento";

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
                        lerMedico(listaMedico, contador_medico, listaEspecialidade, contador_especialidade, listaCidade,
                         contador_cidade);
                        system("cls");
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
                break;
            case 6:
                if (contador_paciente < tamanho_paciente) {
                    do {
                        lerPaciente(listaPaciente, contador_paciente, listaCidade, contador_cidade);
                        system("cls");
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
                break;
            case 7:
                removerRegistroPaciente(listaPaciente, &contador_paciente);
                break;
            case 8:
                if (contador_consulta < tamanho_consulta) {
                    do {
                        agendarConsulta
                        (&listaConsulta[contador_consulta], listaPaciente, contador_paciente, listaMedico,
                         contador_medico, listaCID, contador_cid, listaMedicamento, contador_medicamento);
                        system("cls");
                        imprimirConsulta(listaConsulta[contador_consulta]);
                        cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                        cin >> confirmacao;
                    } while (confirmacao == 0);
                    if (confirmacao == 1) {
                        listaConsulta[contador_consulta].codMedicamento->reduzirEstoque(listaConsulta[contador_consulta].qtdeMedicamento);
                        contador_consulta++;
                    }
                } else {
                    cout << "\nLista de consulta cheia :C";
                }
                break;
            case 9:
                // anda nao foi finalizado;
                if(contador_medicamento > 0) {
                    int i;
                    medicamento encontrado;
                    do {
                        system("cls");
                        cout << "\nCodigos de medicamento"<<endl;
                        for(i=0;i<contador_medicamento;i++) {
                            cout << "\nMedicamento[" << i << "]: " << listaMedicamento[i].codigo;
                        }
                        cout << "\nDigite o codigo do medicament que deseja: ";
                        cin >> i;
                        encontrado = *buscarMedicamento(i,listaMedicamento,contador_medicamento);
                        encontrado.imprimirMedicamento();
                        cout << "\nTotal em estoque: " << encontrado.quantEstoque * encontrado.precoUnitario;
                    }while(!validacao);
                }else {
                    cout << "\nLista de medicamento vazia :C";
                }
                getch();
                break;
            default:
                break;
        }
    }
    return 0;
}
