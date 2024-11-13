#include <iostream>
#include <conio.h>

using namespace std;

typedef struct no arvoreBi;

struct no {
    int info;
    arvoreBi *direita;
    arvoreBi *esquerda;
    int altura;
};

int altura(no* raiz) {
    if(raiz == NULL) {
        return -1;
    }else {
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir) {
            return esq + 1;
        }else{
            return dir + 1;
        }
    }
}

int maior(int esq, int dir) {
    return (esq > dir)? esq:dir;
}

int alturaDoNo(no* no) {
    if(no == NULL) {
        return -1;
    }else {
        return no->altura;
    }
}

int fatorDeBalanceamento(no* no) {
    if(no) {
        return (alturaDoNo(no->esquerda) - alturaDoNo(no->direita));
    }else {
        return 0;
    }
}

no* rotacaoEsquerda(no* r) {
    no *y, *f;

    y = r->direita;
    f = y->esquerda;

    y->esquerda = r;
    r->direita = f;

    r->altura = maior(alturaDoNo(r->esquerda), alturaDoNo(r->direita)) + 1;
    y->altura = maior(alturaDoNo(y->esquerda), alturaDoNo(y->direita)) + 1;

    return y;
}

no* rotacaoDireita(no* r) {
    no *y, *f;

    y = r->esquerda;
    f = y->direita;

    y->direita = r;
    r->esquerda = f;

    r->altura = maior(alturaDoNo(r->esquerda), alturaDoNo(r->direita)) + 1;
    y->altura = maior(alturaDoNo(y->esquerda), alturaDoNo(y->direita)) + 1;

    return y;
}

no* rotacaDireitaEsquerda(no* r) {
    r->direita = rotacaoDireita(r->direita);
    return rotacaoEsquerda(r);
}
no* rotacaoEsquerdaDireita(no* r) {
    r->esquerda = rotacaoEsquerda(r->esquerda);
    return rotacaoDireita(r);
}

no* novoNo(int valor) {

    return new no{valor, nullptr, nullptr, 0};
}

arvoreBi* inserir_no(arvoreBi *raiz, int valor) {

    if(raiz == nullptr) {
        return novoNo(valor);
    }else {
        if(valor < raiz->info) {
            raiz->esquerda = inserir_no(raiz->esquerda, valor);
        }else if(valor > raiz->info) {
            raiz->direita = inserir_no(raiz->direita, valor);
        }else {
            cout << "O elemento " << valor << " ja exite";
        }
    }
    raiz->altura = maior(alturaDoNo(raiz->esquerda), alturaDoNo(raiz->direita)) + 1;
    return raiz;
}

void imprimir_no(no *raiz) {
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

no *remover_no(no *raiz, int valor) {
    if(raiz == NULL) {
        cout << "Valor nao encontrado\n";
        return NULL;
    }else {
        if(raiz->info == valor) {
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                return NULL;
            }else {
                if(raiz->esquerda != NULL && raiz->direita != NULL) {
                    no* aux = raiz->esquerda;
                    while(aux->direita != NULL) {
                        aux = aux->direita;
                    }
                    raiz->info = aux->info;
                    aux->info = valor;
                    raiz->esquerda = remover_no(raiz->esquerda, valor);
                    return raiz;
                }else {
                    no* aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    return aux;
                }
            }
        }else {
            if(valor < raiz->info) {
                raiz->esquerda = remover_no(raiz->esquerda, valor);
            }else {
                raiz->direita = remover_no(raiz->direita, valor);
            }

            raiz->altura = maior(alturaDoNo(raiz->esquerda), alturaDoNo(raiz->direita)) + 1;

            return raiz;
        }
    }

}

no* balancear_arvore(no* raiz) {
    int fb = fatorDeBalanceamento(raiz);

    if(fb < -1 && fatorDeBalanceamento(raiz->direita) <= 0)
        raiz = rotacaoEsquerda(raiz);
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerda) >= 0)
        raiz = rotacaoDireita(raiz);
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerda) < 0)
        raiz = rotacaoEsquerdaDireita(raiz);
    else if(fb < -1 && fatorDeBalanceamento(raiz->direita) > 0)
        raiz = rotacaDireitaEsquerda(raiz);

    return raiz;
}

void imprimir_arvore(no* raiz, int nivel) {
    int i;
    if(raiz) {
        imprimir_arvore(raiz->direita, nivel + 1);
        cout << "\n\n";
        for(i = 0; i<nivel; i++) {
            cout << "\t";
        }
        cout << raiz->info;
        imprimir_arvore(raiz->esquerda, nivel + 1);
    }
}

void menu() {
    system("cls");
    cout << "\nEstrutura de arvore";
    cout << "\n0 - Exit";
    cout << "\n1 - Inserir";
    cout << "\n2 - Buscar";
    cout << "\n3 - Imprimir crescente";
    cout << "\n4 - Remover";
    cout << "\n5 - Balancear";
    cout << "\n6 - Altura";
    cout << "\n7 - Imprimir arvore";
    cout << endl;
}

int main() {

    no *raiz = nullptr;
    int valor;

    int op = 1;
    while(op != 0) {

        menu();
        cout << "Op: ";
        cin >> op;
        if(op == 0) {
            cout << "Good Bye";
        }else
        if(op == 1) {
            cout << "Valor a inserir: ";
            cin >> valor;
            raiz = inserir_no(raiz, valor);
        }else
        if(op == 2) {
            cout << "Valor a ser buscado: ";
            cin >> valor;
            buscar_no(raiz, valor);
        }else
        if(op == 3) {
            imprimir_no(raiz);
            getch();
        }else
        if(op == 4) {
            cout << "Valor a ser removido: ";
            cin >> valor;
            raiz = remover_no(raiz, valor);
        }else
        if(op == 5) {
            raiz = balancear_arvore(raiz);
        }else
        if(op == 6) {
            cout << "Altura: " << altura(raiz) << endl;
            getch();
        }else
        if(op == 7) {
            imprimir_arvore(raiz, 1);
            getch();
        }
    }
}
