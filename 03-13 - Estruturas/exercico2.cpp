#include <iostream>
#include <conio.h>

using namespace std;

struct pessoa{
    string nome;
    int idade;
    string endereco;
};

void imprimir_pessoa(pessoa x){
        cout << "\t Nome:" << x.nome << endl;
        cout << "\t Idade:" << x.idade << endl;
        cout << "\t Endereco:" << x.endereco << endl;
        cout << endl;
};

pessoa ler_pessoa(){
    pessoa x;
    cout << "Lendo Pessoa" << endl;
    cout << "Nome: ";
    fflush(stdin);
    getline(cin, x.nome);
    fflush(stdin);
    cout << "Idade: ";
    cin >> x.idade;
    cout << "Endereco: ";
    fflush(stdin);
    getline(cin, x.endereco);
    fflush(stdin);

    cout << "Leitura completa";
    getch();
    return x;
};

void imprimir_menu(){
    system("cls");
    cout << "Menu de Opcoes" << endl;
    cout << "0 - Sair" << endl;
    cout << "1 - Adicionar a lista" << endl;
    cout << "2 - Imprimir lista" << endl;
    cout << "3 - Atualizar informacoes da pessoa" << endl;
};

void modifica_info(pessoa x[], string nomeBusca, int tamanho){
    for(int i = 0; i <= tamanho; i++){
        if(nomeBusca == x[i].nome){
            cout << "Pessoa encontrada" << endl;
            cout << "Digite a nova idade: ";
            cin >> x[i].idade;
            cout << "Digite o novo endereco: ";
            fflush(stdin);
            getline(cin, x[i].endereco);
            fflush(stdin);

        }
    }
};

int main(){
    int i;
    int contador = 0;
    pessoa pessoas[10];
    string nomeModificacao;
    int op;
    bool sair = false;
    while(!sair){
        imprimir_menu();
        cin >> op;
        switch(op){
    case 0:
            sair = true;
            break;
    case 1:
            if (contador < 10){
            pessoas[contador] = ler_pessoa();
            contador ++;
            }else{
                cout << "Limite de pessoas lidas alcançado :c" << endl;
            }
            break;
    case 2:
            for (int i = 0; i < contador; i++){
                imprimir_pessoa(pessoas[i]);
            }
            getch();
            break;
    case 3:
            cout << "Digite o nome da Pessoa que seja mudar as informacoes: ";
            fflush(stdin);
            getline(cin, nomeModificacao);
            fflush(stdin);
            modifica_info(pessoas, nomeModificacao, contador);
            break;
    default:
            cout << "Opção invalida :c" << endl;
            break;
        }
        system("cls");
    }

    return 0;
}
