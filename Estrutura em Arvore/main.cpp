#include <iostream>
#include <conio.h>

using namespace std;

typedef struct no arvoreBi;

struct no {
    int info;
    arvoreBi *direita;
    arvoreBi *esquerda;
};

arvoreBi* inserir_no(arvoreBi *raiz, int valor) {
    arvoreBi* novo = (arvoreBi*) malloc(sizeof(arvoreBi));


    novo->info = valor;
    novo->direita = nullptr;
    novo->esquerda = nullptr;

    if(raiz == nullptr) {
        return novo;
    }else {
        arvoreBi *pai = nullptr;
        arvoreBi *atual = raiz;
        while (atual != nullptr) {
            pai = atual;

            if(valor < atual->info) {
                atual = atual->esquerda;
            } else {
                atual = atual->direita;
            }
        }
        if(valor <  pai->info) {
            pai->esquerda = novo;
        } else {
            pai->direita = novo;
        }
    }
}

void imprimir_no(no *&raiz) {
    if(raiz == nullptr) {
        return;
    }
    imprimir_no(raiz->esquerda);
    cout << raiz->info << " - ";
    imprimir_no(raiz->direita);
}

no  *buscar_no(no *raiz, int valor) {
    if(raiz == NULL) {
        return NULL;
    }
    no *atual = raiz;
    while(atual->info != valor) {
        if(valor < atual->info) atual=atual->esquerda;
        else atual=atual->direita;
        if(atual == NULL) return NULL;
    }
    return atual;
}

void menu() {
    system("cls");
    cout << "\nEstrutura de arvore";
    cout << "\n0 - Exit";
    cout << "\n1 - Inserir";
    cout << "\n2 - Buscar";
    cout << "\n3 - Imprimir";
    cout << "\n4 - Remover";
    cout << "\n5 - Balancear";
    cout << endl;
}

int main() {

    no *raiz = nullptr;

    int op = 1;
    while(op != 0) {
        menu();
        cout << "Op: ";
        cin >> op;
        if(op == 0) {
            cout << "Good Bye";
        }else
        if(op == 1) {
            int valor;
            cout << "Valor a inserir: ";
            cin >> valor;
            raiz = inserir_no(raiz, valor);
        }else
        if(op == 2) {
            int valor;
            cout << "Valor a ser buscado: ";
            cin >> valor;
            buscar_no(raiz, valor);
        }else
        if(op == 3) {
            imprimir_no(raiz);
            getch();
        }else
        if(op == 4) {
            //remover_no(raiz);
        }else
        if(op == 5) {
            //balancear_arvore(raiz);
        }
    }
}
