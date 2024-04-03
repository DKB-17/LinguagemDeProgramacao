#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

 struct produto{
        int codigo;
        string descricao;
        float preco;
        int quantidade_estoque;

    };

void mostra_estoque(produto);

int main(){

    int tamanho = 3;
    produto estoque[tamanho];

    cout << "Entrada dos produtos" << endl;
    for (int i = 0; i < tamanho; i++){
        cout << "Produto [" << (i+1) << "]" << endl;
        cout << "Codigo: ";
        cin >> estoque[i].codigo;
        cout << "Descricao: ";
        fflush(stdin);
        getline(cin,estoque[i].descricao);
        fflush(stdin);
        cout << "Preco: ";
        cin >> estoque[i].preco;
        cout << "Quantidade em estoque: ";
        cin >> estoque[i].quantidade_estoque;
    };

    for (int i = 0; i < tamanho; i++){
        if (estoque[i].quantidade_estoque < 50){
            mostra_estoque(estoque[i]);
        }
    }

    return 0;
}

void mostra_estoque(produto x){
    cout << "Produto com BAIXO ESTOQUE" << endl;
    cout << "Codigo: " << x.codigo << endl;
    cout << "Descricao: " << x.descricao << endl;
    cout << "Preco: " << x.preco << endl;
    cout << "Qtd em Estoque: " << x.quantidade_estoque << endl;
}
