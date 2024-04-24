#include <iostream>

using namespace std;

struct cidade{
    int codigo;
    string nome;
    char UF[2];
};

struct especialidade{
    int codigo;
    string descricao;
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

struct consulta{
    int cpfPaciente;
    int codMedico;
    string data;
        int dia;
        int mes;
        int ano;
    string horario
        int hora;
        int minuto;
        int segundo;
    int codCID;
    int codMedicamento;
    int qtdeMedicamento;
};

int main(){

    return 0;
}
