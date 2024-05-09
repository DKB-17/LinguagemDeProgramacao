#include <iostream>
#include <string.h>

using namespace std;


string lerTelefone(){
    string telefone;
    fflush(stdin);
    do{
        getline(cin, telefone);
    }while(strnlen(telefone) < 14)
    fflush(stdin);
    return telefone;
}
string lerEndereco(){
    string endereco;
    fflush(stdin);
    do{
        getline(cin, endereco);
    }while(strnlen(endereco) < 4)
    fflush(stdin);
    return endereco;
}
string lerNome{
    string nome;
    fflush(stdin);
    do{
        getline(cin, nome);
    }while(strnlen(nome) < 2)
    fflush(stdin);
    return nome;
}

struct cidade{
    int codigo;
    string nome;
    string UF;
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

     cout << "\nDigite a UF da cidade:";
     getline(cin, city.UF);
     fflush(stdin);
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

bool existeCidade(struct cidade city, struct cidade listaCity[], int tamanho){
    /*VERIFICAR SE A CIDADE CITY(ENTRADA) EXISTE NA listaCity[](ENTRADA), E RETORNA TRUE OU FALSE*/
    for(int i=0; i < tamanho; i++){
        if(city.codigo == listaCity[i].codigo){
            return true;
        }
    }
    return false;
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
        mostrarEspecialidade(listaEsp[i]);
    }
}

bool existeEspecialidade(int codigo, struct especialidade listaEsp[], int tamanho){
    /*VERIFICAR SE A ESPECIALIDADE ESP(ENTRADA) EXISTE NA listaEsp[](ENTRADA), E RETORNA TRUE OU FALSE*/
    if(tamanho != 0 && codigo != 0){
    for(int i=0; i < tamanho; i++){
        if(codigo == listaEsp[i].codigo){
            return true;
        }
    }
    return false;
    }else if(codigo == 0){
        return true;
    }
    cout << "/nLista de Especialidade Vazia";
    return false;
}
struct medicos{
    int codigo;
    string nome;
    int codigoEspecialidade;
    string endereco;
    string telefone;
    int codigoCidade;
};

void lerMedico(struct medicos med,struct especialidade listaEsp[], int tamanho){
    /*
    FUNCAO PARA LEITURA DE MEDICO;
    VERIFICACAO COM 0 PARA SAIDA;
    RETORNO DE DOS DADOS PARA O ATRIBUTO MEDICOS;
    */
    cout << "\nDigite o codigo do medico: (digite 0 para sair)";
    int i;
    cin >> i;
    // VERIFICA i != 0 (0 sendo a saida)
    if (i == 0){return;}else{
     med.codigo = i;
     cout << "\nDigite o nome do medico: ";
     med.nome = lerNome();
     do{
        cout << "\nDigite o codigo do especialista: ";
        cin >> i;
     }while(existeEspecialidade(i, listaEsp[],tamanho));
     cout << "\nDigite o endereco: ";
     med.endereco = lerEndereco();
     cout << "\nDigite o telefone: ";
     med.telefone = lerTelefone();
     do{
        cout << "\nDigite o codigo do especialista: ";
        cin >> i;
     }while(existeEspecialidade(i, listaEsp[],tamanho));
    }
}


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
