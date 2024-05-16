#include <iostream>
#include <string.h>

using namespace std;

struct cidade{
    int codigo;
    string nome;
    string UF;

    void lerCidade(){
        system("cls");
        cout << "\nDigite o codigo da cidade: ";
        cin >> codigo;
        cout << "\nDigite o nome da cidade: ";
        fflush(stdin);
        getline(cin, nome);
        cout << "\nDigite a UF da cidade: ";
        getline(cin,UF);
        fflush(stdin);
    }

    void imprimirCidade(){
        cout << "\nCidade: " << codigo;
        cout << "\nNome: " << nome;
        cout << "\nUF: " << UF;
    }
};

struct especialidade{
    int codigo;
    string descricao;

    void lerEspecialidade(){
        system("cls");
        cout << "\nDigite o codigo da especialidade: ";
        cin >> codigo;
        cout << "\nDigite a descricao: ";
        fflush(stdin);
        getline(cin, descricao);
        fflush(stdin);
    }

    void imprimirEspecialidade(){
        cout << "\nEspecialidade: " << codigo;
        cout << "\nDescricao: " << descricao;
    }

};

struct CID{
    int codigo;
    string descricao;

    void lerCID(){
        system("cls");
        cout << "\nDigite o codigo da CID: ";
        cin >> codigo;
        cout << "\nDigite a descricao: ";
        fflush(stdin);
        getline(cin, descricao);
        fflush(stdin);
    }

    void imprimirCID(){
        cout << "\nCID: " << codigo;
        cout << "\nDescricao: " << descricao;
    }
};

struct medicamentos{
    int codigo;
    string nome;
    int quantEstoque;
    int estoqueMinimo;
    int estoqueMaximo;
    float precoUnitario;

    void lerMedicamento(){
        system("cls");
        cout << "\nDigite o codigo do medicamento: ";
        cin >> codigo;
        cout << "\nDigite o nome do medicamento: ";
        fflush(stdin);
        getline(cin, nome);
        fflush(stdin);
        do{
            cout << "\nDigite a quantidade no Estoque: ";
            cin >> quantEstoque;
            if (quantEstoque < 0){
                cout << "\nQuantidade negativo, Por favor digite outro valor";
            }
        }while(quantEstoque < 0);
        do {
            cout << "\nDigite a quantidade de estoque Minimo: ";
            cin >> estoqueMinimo;
            if (estoqueMinimo < 0){
                cout << "\nQuantidade negativo, Por favor digite outro valor";
            }
        }while(estoqueMinimo < 0);
        do{
            cout << "\nDigite a quantidade de estoque Maximo: ";
            cin >> estoqueMaximo;
            if (estoqueMinimo > estoqueMaximo){
                cout << "\nEstoque maximo esta menor que o minino :C, Por favor digite outro valor";
            }
        }while(estoqueMinimo > estoqueMaximo);
        do{
            cout << "\nDigite o valor unitario de cada medicamento: ";
            cin >> precoUnitario;
            if (precoUnitario < 0){
                cout << "\nValor negativo, Por favor digite outro valor";
            }
        }while(precoUnitario < 0);
    }

    void imprimirMedicamento(){
        cout << "\nMedicamento: " << codigo;
        cout << "\nNome: \t" << nome;
        cout << "\nQuantidade no Estoque: \t" << quantEstoque;
        cout << "\nEstoque minimo: \t" << estoqueMinimo;
        cout << "\nEstoque maximo: \t" << estoqueMaximo;
        cout << "\nPreco Unitario: \t" << precoUnitario;
    }
};


struct medicos{
    int codigo;
    string nome;
    int codigoEspecialidade;
    string endereco;
    string telefone;
    int codigoCidade;
};

struct pacientes{
    int CPF;
    string nome;
    string endereco;
    int codigoCidade;
};

struct datetime{
    int ano;
    int mes;
    int dia;
};

struct timestamp{
    int hora;
    int minuto;
    int segundo;
};

struct consulta{
    int cpfPaciente;
    int codMedico;
    datetime data;
    timestamp horario;
    int codCID;
    int codMedicamento;
    int qtdeMedicamento;
};

int main(){

    setlocale(LC_ALL,"portuguese");

    int confirmacao;

    int tamanho_cidade = 10;
    int contador_cidade = 3;
    cidade listaCidade[tamanho_cidade];

    /*DADOS INJETADOS DE CIDADE*/

    listaCidade[0] = {1,"Assis","SP"};
    listaCidade[1] = {3,"Candido Mota","SP"};
    listaCidade[2] = {4,"Unai","MG"};

    int tamanho_especialidade = 10;
    int contador_especialidade = 3;
    especialidade listaEspecialidade[tamanho_especialidade];

    /*DADOS INJETADOS DE ESPECIALIDADE*/

    listaEspecialidade[0] = {2,"Ortopedista"};
    listaEspecialidade[1] = {3,"Psiquiatra"};
    listaEspecialidade[2] = {5,"Neurologista"};

    int tamanho_cid = 10;
    int contador_cid = 3;
    CID listaCID[tamanho_cid];

    /*DADOS INJETADOS DE CID*/

    listaCID[0] = {1,"Infecção intestinal"};
    listaCID[1] = {3,"Virus mortal"};
    listaCID[2] = {4,"Bacteria nociva"};

    int tamanho_medicamento = 10;
    int contador_medicamento = 3;
    medicamentos listaMedicamento[tamanho_medicamento];

    /*DADOS INJETADOS DE MEDICAMENTO*/

    listaMedicamento[0]={2,"Tadala",3,1,6,2.5};
    listaMedicamento[1]={3,"Paracetamol",4,2,7,5.9};
    listaMedicamento[2]={4,"Neuzadina",5,3,10,10.2};


    int op = 1;
    while(op != 0){
        system("cls");
        cout << "\nMENU"<<endl;
        cout << "\n0 - Sair";
        cout << "\n1 - Ler cidade";
        cout << "\n2 - Ler especialidade";
        cout << "\n3 - Ler CID";
        cout << "\n4 - Ler Medicamento";

        cout << "\n\nDigite qual acão deseja fazer: ";
        cin >> op;
        switch (op){
            case 1:
                if(contador_cidade < tamanho_cidade){
                    do{
                    listaCidade[contador_cidade].lerCidade();
                    system("cls");
                    listaCidade[contador_cidade].imprimirCidade();
                    cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                    cin >> confirmacao;
                    }while(confirmacao == 0 && confirmacao != 3);
                    if(confirmacao = 1){
                        contador_cidade ++;
                    }
                }else{
                    cout << "\nLista de cidade cheia :C";
                }
            break;
            case 2:
                if(contador_especialidade < tamanho_especialidade){
                    do{
                    listaEspecialidade[contador_especialidade].lerEspecialidade();
                    system("cls");
                    listaEspecialidade[contador_especialidade].imprimirEspecialidade();
                    cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                    cin >> confirmacao;
                    }while(confirmacao == 0 && confirmacao != 3);
                    if(confirmacao = 1){
                        contador_especialidade ++;
                    }
                }else{
                    cout << "\nLista de especialidade cheia :C";
                }
            break;
            case 3:
                if(contador_cid < tamanho_cid){
                    do{
                    listaCID[contador_cid].lerCID();
                    system("cls");
                    listaCID[contador_cid].imprimirCID();
                    cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                    cin >> confirmacao;
                    }while(confirmacao == 0 && confirmacao != 3);
                    if(confirmacao = 1){
                        contador_cid ++;
                    }
                }else{
                    cout << "\nLista de CID cheia :C";
                }
            break;
            case 4:
                if(contador_medicamento < tamanho_medicamento){
                    do{
                    listaMedicamento[contador_medicamento].lerMedicamento();
                    system("cls");
                    listaMedicamento[contador_medicamento].imprimirMedicamento();
                    cout << "\nConfirmar (1-SIM) (0-NAO) (3-CANCELAR): ";
                    cin >> confirmacao;
                    }while(confirmacao == 0 && confirmacao != 3);
                    if(confirmacao = 1){
                        contador_medicamento ++;
                    }
                }else{
                    cout << "\nLista de Medicamento cheia :C";
                }
            break;
            default:
            break;
        }

    }
    return 0;
}
