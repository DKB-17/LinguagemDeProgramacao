#include <iostream>

using namespace std;

struct cidade{
    int codigo;
    string nome;
    char UF[2];
};

void lerCidade(struct cidade city){
    /*
    FUNCAO PARA LEITURA DE CIDADE;
    VERIFICACAO COM 0 PARA SAIDA;
    RETORNO DE DOS DADOS PARA O ATRIBUTO CIDADE;
    */
    cout << "\nDigite o codigo da cidade: (digite 0 para sair)";
    int i;
    cin >> i;
    // VERIFICA i != 0 (0 sendo a saida)
    if (i == 0){return;}else{
     city.codigo = i;
     cout << "\nDigite o nome da cidade: ";
     fflush(stdin);
     getline(cin, city.nome);
     fflush(stdin);
     cout << "\nDigite a UF da cidade:";
     gets(2,city.UF);
    }
}

void mostrarCidade(struct cidade city){
    /*FUNCAO PARA EXIBIR OS DADOS DE CIDADE*/
    cout << "\n" <<city.codigo << "\t|\t" << city.nome << "\t|\t" << city.UF;
}

void mostrarListaCidade(struct cidade listaCity[], int tamanho){
    /*FUNCAO PARA PESCORER EXIBINDO A LISTA DE CIDADE*/
    cout << "\nCODIGO\t|\tNOME\t|\tUF";
    for(int i = 0;i<tamanho;i++){
        mostrarCidade(listaCity[i]);
    }
}

struct especialidade{
    int codigo;
    string descricao;
};

void lerEspecialidade(struct especialidade esp){
    /*
    FUNCAO PARA LEITURA DE ESPECIALIDADE;
    VERIFICACAO COM 0 PARA SAIDA;
    RETORNO DE DOS DADOS PARA O ATRIBUTO ESPECIALIDADE;
    */
    cout << "\nDigite o codigo da especialidade: (digite 0 para sair)";
    int i;
    cin >> i;
    // VERIFICA i != 0 (0 sendo a saida)
    if (i == 0){return;}else{
     esp.codigo = i;
     cout << "\nDigite a descricao da especialidade: ";
     fflush(stdin);
     getline(cin, esp.descricao);
     fflush(stdin);
    }
}

void mostrarEspecialidade(struct especialidade esp){
    /*FUNCAO PARA EXIBIR OS DADOS DE ESPECIALIDADE*/
    cout << "\n" <<esp.codigo << "\t|\t" << esp.descricao;
}

void mostrarListaEspecialidade(struct especialidade listaEsp[], int tamanho){
    /*FUNCAO PARA PESCORER EXIBINDO A LISTA DE ESPECIALIDADE*/
    cout << "\nCODIGO\t|\tDESCRICAO";
    for (int i = 0; i < tamanho; i++){
        mostrarEspecialidade(listaEso[i]);
    }
}
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

struct CID{
    int codigo;
    string descricao;
};

struct medicamentos{
    int codigo;
    string descricao;
    int quantEstoque;
    int estoqueMinimo;
    int estoqueMaximo;
    float precoUnitario;
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
    timestamp horario
    int codCID;
    int codMedicamento;
    int qtdeMedicamento;
};

int main(){



    return 0;
}
