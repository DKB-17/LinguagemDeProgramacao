#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace  std;

struct produto {
    string nome;
    int preco;
    int qtd_venda;
    string dia_venda;
};


void menu() {
    cout <<     "\nSISTEMA DE VENDAS\n"
            <<  "\n0 - sair"
            <<  "\n1 - carregar 1000 registros"
            <<  "\n2 - carregar 100.000 registros"
            <<  "\n3 - carregar 1.000.000 registros"
            <<  "\n4 - imprimir lista"
            <<  "\n5 - ordenacao Bolha"
            <<  "\n6 - ordenacao Insercao"
            <<  "\n7 - ordenacao Selecao"
            <<  "\n8 - ordenacao Contagem"
            <<  "\n9 - ordenacao Shell"
            <<  "\n10 - ordenacao Quicksort"
            <<  "\n11 - testar Todos"
            << endl;
}

string gerarNomeProduto() {
    vector<string> nomes = {"Camiseta", "Calca", "Tenis", "Bone", "Relogio", "Livro", "Celular", "Tablet", "Notebook", "Fone de Ouvido"};
    int indice = rand() % nomes.size();
    return nomes[indice];
}

string gerarDataVenda() {
    tm data = {0};
    data.tm_year = rand() % 5 + 120;
    data.tm_mon = rand() % 12;
    data.tm_mday = rand() % 28 + 1;
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y", &data);
    return string(buffer);
}

void lerElementos(vector<produto> &lst, int qtdElementos) {
    string line;
    ifstream result("listaDesorganizada.txt");
    if(result.is_open()){
        for(int i=0; i<qtdElementos;i++){
            getline(result, line);
            produto p;
            size_t pos = 0;
            string token;
            stringstream ss(line);

            getline(ss, token, ';');
            p.nome = token;

            getline(ss, token, ';');
            p.preco = stof(token);

            getline(ss, token, ';');
            p.qtd_venda = stoi(token);

            getline(ss, token, ';');
            p.dia_venda = token;

            lst.push_back(p);
        }
    }else{
        cout << "Arquivo nao abriu" << endl;
    }
}

void carregarRegistros(long nElementos, vector<produto> &lst) {
    
    lst.clear();
    ofstream arquivo("listaDesorganizada.txt");
    if(arquivo.is_open()){
        for(int i=0; i < nElementos; i++) {
                produto p;
                p.nome = gerarNomeProduto();
                p.preco = (rand() % 20 + 10);
                p.qtd_venda = rand() % 100 + 1;
                p.dia_venda = gerarDataVenda();
                arquivo << p.nome << ";" << p.preco << ";" << p.qtd_venda << ";" << p.dia_venda << "\n";
        }
        arquivo.close();
    }else{
        cout << "Arquivo nao abriu" << endl;
    }
    lerElementos(lst, nElementos);
}

void imprimirLista(const vector<produto> &lst) {
    system("cls");
    cout << "\n\tNome\t\tPreco\t\tQtd_venda\tDia_venda" << endl;
    for(const auto & i : lst) {
        cout << "\t" << i.nome << "\t\t" << i.preco << "\t\t" << i.qtd_venda << "\t\t" << i
        .dia_venda << endl;
    }
    getch();
}

void guardarDadosOrdenacao(double duracao, long qtdElementos, int tipoOrdenador){
    string line;
    fstream arquivo;
    arquivo.open("dadosTempoOrdenadores.txt", ios::out|ios::app);
    if(arquivo.is_open()) {
        arquivo << "Tempo: " << setprecision(4) << duracao << "seg" << "\tcom " << qtdElementos << " elementos";
        if(tipoOrdenador == 0){
            arquivo << " - Bubble";
        }else if(tipoOrdenador == 1){
            arquivo << " - Insercao";
        }else if(tipoOrdenador == 2){
            arquivo << " - Selecao";
        }else if(tipoOrdenador == 3){
            arquivo << " - Contagem";
        }else if(tipoOrdenador == 4){
            arquivo << " - Shell";
        }else if(tipoOrdenador == 5){
            arquivo << " - Quick";
        }
        arquivo << "\n";
        arquivo.close();
        }
}

bool testarOrdenacao(vector<produto> &lst){
    bool correto = true;
    for(int i= 0; i<lst.size(); i--){
        if(lst[i].preco < lst[i+1].preco){
            correto = false;
        }
    }
    return correto;
}

void bubbleSort(vector<produto> &lst) {

    clock_t start, end;
    start = clock();

    int i, tam = 1;
    bool troca = true;
    produto aux;
    while(troca) {
        troca = false;
        for(i = 0; i<lst.size() - tam; i++) {
            if(lst[i].preco < lst[i+1].preco) {
                troca = true;
                aux = lst[i];
                lst[i] = lst[i+1];
                lst[i+1] = aux;
            }
        }
        tam ++;
    }

    end = clock();
    double duracao = (double)(end-start) / CLOCKS_PER_SEC;

    if(testarOrdenacao(lst)){
        guardarDadosOrdenacao(duracao, lst.size(), 0);

        ofstream arquivo("listaOrgBubble.txt");
        if(arquivo.is_open()) {
            for(auto p : lst) {
                arquivo << p.nome << ";" << p.preco << ";" << p.qtd_venda << ";" << p.dia_venda << endl;
            }
            arquivo.close();
        }
    }else{
        cout << "Nao esta ordenado";
    }
}

void insertSort(vector<produto> &lst){

    clock_t start, end;
    start = clock();

    produto aux;
    int j;

    for(int i = 1; i<lst.size(); i++){
        j=0;
        while(lst[i-j].preco > lst[i-(j+1)].preco && j < i) {
            aux = lst[i-j];
            lst[i-j] = lst[i-(j+1)];
            lst[i-(j+1)] = aux;
            j++;
        }
    }

    end = clock();
    double duracao = (double)(end-start) / CLOCKS_PER_SEC;


    if(testarOrdenacao(lst)){
            guardarDadosOrdenacao(duracao, lst.size(), 1);

            ofstream arquivo("listaOrgInsert.txt");
            if(arquivo.is_open()) {
                for(auto p : lst) {
                    arquivo << p.nome << ";" << p.preco << ";" << p.qtd_venda << ";" << p.dia_venda << endl;
                }
                arquivo.close();
            }
        }else{
            cout << "Nao esta ordenado";
        }
}

void selectSort(vector<produto> &lst) {

    clock_t start, end;
    start = clock();

    produto aux;

    for(int i=0; i<lst.size()-1; i++) {
        int maxIndex = i;
        for(int j = i+1 ; j<lst.size(); j++) {
            if(lst[maxIndex].preco < lst[j].preco) {
                maxIndex = j;
            }
        }
        aux = lst[i];
        lst[i] = lst[maxIndex];
        lst[maxIndex] = aux;
    }

    end = clock();
    double duracao = (double)(end-start) / CLOCKS_PER_SEC;

    if(testarOrdenacao(lst)){
        guardarDadosOrdenacao(duracao, lst.size(), 2);
        ofstream arquivo("listaOrgSelect.txt");
        if(arquivo.is_open()) {
            for(auto p : lst) {
                arquivo << p.nome << ";" << p.preco << ";" << p.qtd_venda << ";" << p.dia_venda << endl;
            }
            arquivo.close();
        }
    }else{
        cout << "Nao esta ordenado";
    }
}

void countSort(vector<produto> &lst) {

    clock_t start, end;
    start = clock();

    map<int, vector<produto>> matriz;
    set<int> precos;

    for(int i=0; i < lst.size(); i++){
        matriz[-(lst[i].preco)].push_back(lst[i]);
    }
    lst.clear();
    for(auto &pair:matriz) {
        for(auto &produto : pair.second) {
            lst.push_back(produto);
        }
    }

    end = clock();
    double duracao = ((double)(end-start) / CLOCKS_PER_SEC);

    if(testarOrdenacao(lst)){
        guardarDadosOrdenacao(duracao, lst.size(), 3);
        ofstream arquivo("listaOrgCount.txt");
        if(arquivo.is_open()) {
            for(auto p : lst) {
                arquivo << p.nome << ";" << p.preco << ";" << p.qtd_venda << ";" << p.dia_venda << endl;
            }
            arquivo.close();
        }
    }else{
        cout << "Nao esta ordenado";
    }

}

void shellSort(vector<produto> &lst) {

    clock_t start, end;
    start = clock();

    produto aux;

    for(int i= lst.size()/2; i>0; i/=2) {
        for(int j = i; j < lst.size(); j+=1) {
            aux = lst[j];
            int k;
            for(k = j; k >= i && lst[k - i].preco < aux.preco; k -= i) {
                lst[k] = lst[k - i];
            }
            lst[k] = aux;
        }
    }

    end = clock();
    double duracao = ((double)(end-start) / CLOCKS_PER_SEC);

    if(testarOrdenacao(lst)){
        guardarDadosOrdenacao(duracao, lst.size(), 4);
        ofstream arquivo("listaOrgShell.txt");
        if(arquivo.is_open()) {
            for(auto p : lst) {
                arquivo << p.nome << ";" << p.preco << ";" << p.qtd_venda << ";" << p.dia_venda << endl;
            }
            arquivo.close();
        }
    }else{
        cout << "Nao esta ordenado";
    }
}
int partilar(vector<produto> &lst, int inicio, int fim) {
    int i = inicio-1;
    for(int n=inicio; n <= fim-1; n+=1) {
        if(lst[n].preco <= lst[fim].preco)
        {
            i+=1;
            produto temp = lst[i];
            lst[i] = lst[n];
            lst[n] = temp;
        }
    }
    produto temp = lst[i+1];
    lst[i+1] = lst[fim];
    lst[fim] = temp;

    return (i+1);
}


void quickSort(vector<produto> &lst, int inicio, int fim) {
    if(inicio < fim) {
        int i = partilar(lst, inicio, fim);
        quickSort(lst, inicio, i-1);
        quickSort(lst, i+1, fim);
    }
}

void chamarQuickSort(vector<produto> &lst) {

    clock_t start, end;
    start = clock();

    quickSort(lst, 0, lst.size());
    reverse(lst.begin(), lst.end());

    end = clock();
    double duracao = ((double)(end-start) / CLOCKS_PER_SEC);

    if(testarOrdenacao(lst)){
        guardarDadosOrdenacao(duracao, lst.size(), 5);
        ofstream arquivo("listaOrgQuick.txt");
        if(arquivo.is_open()) {
            for(auto p : lst) {
                arquivo << p.nome << ";" << p.preco << ";" << p.qtd_venda << ";" << p.dia_venda << endl;
            }
            arquivo.close();
        }
    }else{
        cout << "Nao esta ordenado";
    }
}

void testarTodos(vector<produto> &lst) {
    carregarRegistros(1000, lst);
    bubbleSort(lst);
    carregarRegistros(1000, lst);
    insertSort(lst);
    carregarRegistros(1000, lst);
    selectSort(lst);
    carregarRegistros(1000, lst);
    countSort(lst);
    carregarRegistros(1000, lst);
    shellSort(lst);
    carregarRegistros(1000, lst);
    chamarQuickSort(lst);
    carregarRegistros(100000, lst);
    bubbleSort(lst);
    carregarRegistros(100000, lst);
    insertSort(lst);
    carregarRegistros(100000, lst);
    selectSort(lst);
    carregarRegistros(100000, lst);
    countSort(lst);
    carregarRegistros(100000, lst);
    shellSort(lst);
    carregarRegistros(100000, lst);
    chamarQuickSort(lst);
    carregarRegistros(1000000, lst);
    bubbleSort(lst);
    carregarRegistros(1000000, lst);
    insertSort(lst);
    carregarRegistros(1000000, lst);
    selectSort(lst);
    carregarRegistros(1000000, lst);
    countSort(lst);
    carregarRegistros(1000000, lst);
    shellSort(lst);
    carregarRegistros(1000000, lst);
    chamarQuickSort(lst);
    cout << "fim";
}

int main()
{
    vector<produto> lstProduto;

    int op;
    do {
        menu();
        cout << "Opcao: ";
        cin >> op;
        if(op == 0) {
            cout << "Good Bye!";
        }else if(op == 1) {
                carregarRegistros(1000, lstProduto);
        }else if(op == 2) {
                carregarRegistros(100000, lstProduto);
        }else if(op == 3) {
                carregarRegistros(1000000, lstProduto);
        }else if(op == 4) {
                imprimirLista(lstProduto);
        }else if(op == 5) {
                bubbleSort(lstProduto);
        }else if(op == 6) {
                insertSort(lstProduto);
        }else if(op == 7) {
                selectSort(lstProduto);
        }else if(op == 8) {
                countSort(lstProduto);
        }else if(op == 9) {
                shellSort(lstProduto);
        }else if(op == 10) {
                chamarQuickSort(lstProduto);
        }else if(op == 11) {
                testarTodos(lstProduto);
        }else {
            cout << "Opcao invalida";
        }

    }while(op != 0);
}
