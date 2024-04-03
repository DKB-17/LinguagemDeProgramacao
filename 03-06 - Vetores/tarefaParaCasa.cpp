/*
Escreva um programa que cria umestrutura do tipo "produto",
que contem as seguintes informacoes: codigo, descricao, preco, quantidade_estoque.

Considere que a empresa possui 1000 produtos em estoque.
Leia as informacoes para cada produto.

Ao final da leitura, envie os dados dos produtos com estoque
inferior a 50 unidades para uma funcao que ira mostrar os
dados destes produtos.
*/

#include <iostream>

using namespace std;

struct produto{
    int codigo;
    string descricao;
    float preco;
    int quantidade_estoque;

};

void mostra_produto(produto pr){
        cout << "\n \nMostrando Produto" << endl;
        cout << "Codigo: " << pr.codigo << endl;
        cout << "Descricao: " << pr.descricao << endl;
        cout << "Preco: " << pr.preco << endl;
        cout << "Quantidade em Estoque: " << pr.quantidade_estoque << endl;

};

int main(){

    int tamanho = 5;
    produto produtos[tamanho];
    int i;

    for(i = 0; i< tamanho; i++){
        cout << "Lendo Produto" << endl;
        cout << "Codigo: ";
        cin >> produtos[i].codigo;
        cout << "Descricao: ";
        fflush(stdin);
        getline(cin,produtos[i].descricao);
        fflush(stdin);
        cout << "Preco: ";
        cin >> produtos[i].preco;
        cout << "Quantidade em Estoque: ";
        cin >> produtos[i].quantidade_estoque;
    }

    for(i = 0; i< tamanho; i++){
            mostra_produto(produtos[i]);
    }


    cout << "Produtos abaixo de 50 no estoque" << endl;

    for (i = 0; i < tamanho; i++){
        if (produtos[i].quantidade_estoque < 50){
                mostra_produto(produtos[i]);
        }
    }



    return 0;
}
