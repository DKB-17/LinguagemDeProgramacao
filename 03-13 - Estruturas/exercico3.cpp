// Escreva um programa que leias as seguintes informacoes dos clientes de uma empresa:
//CPF, nome, idade, salario.

//A leitura desses dados deve ser realizada em uma funcao especifica;


//Apos a leitura das informacoes, enviar os dados para outra funcao que vai calcular e retornar:
// - O nome e a idade do cliente mais velho
// -  nome e o salario do cliente com maior salario

//Considere que a empresa possui 1000 clientes.

#include <iostream>
#include <string.h>

using namespace std;

struct cliente{
    string CPF;
    string nome;
    int idade;
    float salario;

};

cliente leitura(){
    cliente c1;
    cout << "Lendo cliente" << endl;
    cout << "CPF: ";
    fflush(stdin);
    getline(cin, c1.CPF);
    cout << "Nome: ";
    getline(cin, c1.nome);
    fflush(stdin);
    cout << "Idade: ";
    cin >> c1.idade;
    cout << "Salario: ";
    cin >> c1.salario;

    return c1;
};

cliente maisVelho(cliente vet[], int tamanho){
    int i;
    cliente mV = vet[0];
    for (i = 1; i < tamanho; i++){
        if (mV.idade < vet[i].idade){
            mV = vet[i];
        }
    }
    return mV;
};

cliente maiorSalario(cliente vet[], int tamanho){
    int i;
    cliente mS = vet[0];
    for (i = 1; i < tamanho; i++){
        if (mS.salario < vet[i].salario){
            mS = vet[i];
        }
    }
    return mS;
};

void imprimir_cliente(cliente cli){
    cout << "Clinte" << endl;
    cout << "CFP: " << cli.CPF << endl;
    cout << "Nome: " << cli.nome << endl;
    cout << "Idade: " << cli.idade << endl;
    cout << "Salario: " << cli.salario << endl;
    cout << "\n\n";

};

int main(){

    int tamanho = 4;
    cliente vet[tamanho];
    int i;
    for (i = 0; i < tamanho; i ++){
        vet[i] = leitura();
    }

    cliente mV = maisVelho(vet, tamanho);
    cliente mS = maiorSalario(vet,tamanho);

    cout << "Imprimindo os clientes" << endl;
    for (i = 0; i < tamanho; i++){
        imprimir_cliente(vet[i]);
    }

    cout << "-----------------------------" << endl;

    cout << "Mais velho: " << mV.nome << "Idade: " << mV.idade << endl;
    cout << "Maior salario: " << mS.nome << "Salario: " << mS.salario << endl;


}
