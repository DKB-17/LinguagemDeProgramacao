#include <iostream>

using namespace std;

struct  no;

struct no {
    int info;
    no* direito = NULL;
    no* esquerda = NULL;
};

void inserir_no(no* raiz, int valor) {
    no* novo = new no;
    novo->info = valor;
    if(raiz == NULL) {
        raiz = novo;
    }else {
        no* aux = raiz;
        while(aux != NULL) {
            aux = raiz;
            if(novo->info < raiz->info) {
                if(aux->esquerda == NULL) {
                    aux->esquerda = novo;
                    break;
                }
                raiz = raiz->esquerda;
            }else {
                if(aux->direito == NULL) {
                    aux->direito = novo;
                    break;
                }
                raiz = raiz->direito;
            }
        }
    }
}

void imprimir_no(no* raiz) {
    if(raiz == NULL) {
        return;
    }
    imprimir_no(raiz->esquerda);
    cout << raiz->info << " ";
    imprimir_no(raiz->direito);
}

void menu() {
    system("cls");
    cout << "\nEstrutura de arvore";
    cout << "\n0 - Exit";
    cout << "\n1 - Inserir";
    cout << "\n2 - Buscar";
    cout << "\n3 - Imprimir";
    cout << endl;
}

int main() {

    no *raiz;

    int op = 1;
    while(op != 0) {
        menu();
        cout << "Op: ";
        cin >> op;
        if(op == 0) {
            cout << "Good Bye";
        }
        if(op == 1) {
            int valor;
            cout << "Valor a inserir: ";
            cin >> valor;
            inserir_no(raiz, valor);
        }
        if(op == 2) {
            //buscar_no(raiz);
        }
        if(op == 3) {
            imprimir_no(raiz);
        }
    }
}
