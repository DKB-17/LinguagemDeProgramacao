#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <string>
#include <sstream>
#include <map>

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

void carregarRegistros(int nElementos, vector<produto> &lst) {
    
    lst.clear();
    ifstream arquivo("listaDesorganizada.txt");
    if(!arquivo.is_open()){
        ofstream arquivo("listaDesorganizada.txt");
        if (arquivo.is_open()) {
            for(int i=lst.size(); i<nElementos; i++) {
                produto p;
                p.nome = gerarNomeProduto();
                p.preco = (rand() % 20 + 10);
                p.qtd_venda = rand() % 100 + 1;
                p.dia_venda = gerarDataVenda();
                arquivo << p.nome << ";" << p.preco << ";" << p.qtd_venda << ";" << p.dia_venda << "\n";
            }
        }else{
            cout << "Arquivo nao abriu" << endl;
        }
    }
    arquivo.close();

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
    ofstream arquivo("dadosTempoOrdenadores.txt");
    ifstream arquivo2("dadosTempoOrdenadores.txt");
    if(!arquivo2.is_open()){
        ofstream arquivo("dadosTempoOrdenadores.txt");
        if(arquivo.is_open()) {
            arquivo << "Tempo: " << duracao << "seg" << "\tcom " << qtdElementos << " elementos";
            if(tipoOrdenador == 0){
                arquivo << " - Bubble";
            }
            if(tipoOrdenador == 1){
                arquivo << " - Insercao";
            }
            if(tipoOrdenador == 0){
                arquivo << " - Selecao";
            }
            if(tipoOrdenador == 0){
                arquivo << " - Contagem";
            }
            if(tipoOrdenador == 0){
                arquivo << " - Shell";
            }
            if(tipoOrdenador == 0){
                arquivo << " - Quick";
            }
            arquivo << "\n";
            
        }else{
            cout << "Arquivo nao abriu";
        }
    }else{
        while(getline(arquivo2, line)) {
            arquivo << line;
        };
        arquivo << "Tempo: " << duracao << "seg" << "\tcom " << qtdElementos << " elementos";
            if(tipoOrdenador == 0){
                arquivo << " - Bubble";
            }
            if(tipoOrdenador == 1){
                arquivo << " - Insercao";
            }
            if(tipoOrdenador == 0){
                arquivo << " - Selecao";
            }
            if(tipoOrdenador == 0){
                arquivo << " - Contagem";
            }
            if(tipoOrdenador == 0){
                arquivo << " - Shell";
            }
            if(tipoOrdenador == 0){
                arquivo << " - Quick";
            }
            arquivo << "\n";
            
    }
    arquivo.close();
    arquivo2.close();
}

bool testarOrdenação(vector<produto> lst){
    for(int i=1;i<lst.size();i++){
        if(lst[i-1].preco > lst[i].preco){
            return false;
        }
    }
    return true;
}

void bubbleSort(vector<produto> &lst) {

    clock_t start, end;
    start = clock();

    int i, tam = 1, troca = 1;
    while(troca) {
        troca = 0;
        for(i = 0; i<lst.size() - tam; i++) {
            if(lst[i].preco < lst[i+1].preco) {
                troca = 1;
                produto aux = lst[i];
                lst[i] = lst[i+1];
                lst[i+1] = aux;
            }
        }
        tam ++;
    }

    end = clock();
    double duracao = (double)(end-start) / CLOCKS_PER_SEC;

    if(testarOrdenação(lst)){
        guardarDadosOrdenacao(duracao, lst.size(), 0);

        ofstream arquivo("listaOrgBubble.txt");
        if(arquivo.is_open()) {
            for(auto p : lst) {
                arquivo << p.nome << ";" << p.preco << ";" << p.qtd_venda << ";" << p.dia_venda << endl;
            }
            arquivo.close();
        }
    }else{
        cout << "Não esta ordenado";
    }
}

void insertSort(vector<produto> &lst){

    clock_t start, end;
    start = clock();

    for(int i = 1; i<lst.size(); i++){
        produto aux = lst[i];
        int j = (i-1);
        for(; j>=0 && lst[j].preco > lst[i].preco; j--){
            lst[j+1] = lst[j];
        }
        lst[j+1] = aux;
    }

    end = clock();
    double duracao = (double)(end-start) / CLOCKS_PER_SEC;


    if(testarOrdenação(lst)){
            guardarDadosOrdenacao(duracao, lst.size(), 1);

            ofstream arquivo("listaOrgInsert.txt");
            if(arquivo.is_open()) {
                for(auto p : lst) {
                    arquivo << p.nome << ";" << p.preco << ";" << p.qtd_venda << ";" << p.dia_venda << endl;
                }
                arquivo.close();
            }
        }else{
            cout << "Não esta ordenado";
        }
}

void selectSort(vector<produto> lst) {

    clock_t start, end;
    start = clock();

    for(int i=0; i<lst.size()-1; i++) {
        int minIndex = i;
        for(int j =i+1;j<lst.size(); j++) {
            if(lst[minIndex].preco > lst[j].preco) {
                minIndex = j;
            }
        }
        produto aux = lst[i];
        lst[i] = lst[minIndex];
        lst[minIndex] = aux;
    }

    end = clock();
    double duracao = (double)(end-start) / CLOCKS_PER_SEC;

    if(testarOrdenação(lst)){
        guardarDadosOrdenacao(duracao, lst.size(), 3);
        ofstream arquivo("listaOrgSelect.txt");
        if(arquivo.is_open()) {
            for(auto p : lst) {
                arquivo << p.nome << ";" << p.preco << ";" << p.qtd_venda << ";" << p.dia_venda << endl;
            }
            arquivo.close();
        }
    }else{
        cout << "Não esta ordenado";
    }
}

void countSort(vector<produto> &lst) {

    clock_t start, end;
    start = clock();

    map<int ,vector<produto>> matriz;
    for(int i=0; i< lst.size(); i++){
        matriz[lst[i].preco].push_back(lst[i]);
    }
    for(int i=0;i<matriz.size();i++) {
        for(int j=0;j<matriz[i].size();j++) {
            lst.push_back(matriz[i][j]);
        }
    }

    end = clock();
    double duracao = ((double)(end-start) / CLOCKS_PER_SEC);

    if(testarOrdenação(lst)){
        guardarDadosOrdenacao(duracao, lst.size(), 4);
        ofstream arquivo("listaOrgCount.txt");
        if(arquivo.is_open()) {
            for(auto p : lst) {
                arquivo << p.nome << ";" << p.preco << ";" << p.qtd_venda << ";" << p.dia_venda << endl;
            }
            arquivo.close();
        }
    }else{
        cout << "Não esta ordenado";
    }

}

void shellSort(vector<produto> &lst) {

    clock_t start, end;
    start = clock();

    produto aux;
    int troca = 0;
    for(int i=lst.size(); i>0;i=i/2) {
        troca = 0;
        for(int j = 0; j+i < lst.size();j++) {
            if(lst[j].preco > lst[j+i].preco) {
                aux = lst[j];
                lst[j] = lst[j+i];
                lst[j+i] = aux;
                troca = 1;
            }
        }
        if(!troca) {
            i=0;
        }
    }

    end = clock();
    double duracao = ((double)(end-start) / CLOCKS_PER_SEC);

    if(testarOrdenação(lst)){
        guardarDadosOrdenacao(duracao, lst.size(), 5);
        ofstream arquivo("listaOrgShell.txt");
        if(arquivo.is_open()) {
            for(auto p : lst) {
                arquivo << p.nome << ";" << p.preco << ";" << p.qtd_venda << ";" << p.dia_venda << endl;
            }
            arquivo.close();
        }
    }else{
        cout << "Não esta ordenado";
    }
}

void quickSort(vector<produto> &lst, int inicio, int fim) {
    if(inicio < fim) {
        produto aux;
        int i = inicio;
        for(int n=inicio; n < fim; n++) {
            if(lst[n].preco <= lst[fim].preco) {
                aux = lst[n];
                lst[n] = lst[i];
                lst[i] = aux;
                i++;
            }
        }
        aux = lst[fim];
        lst[fim] = lst[i];
        lst[i] = aux;
        quickSort(lst, inicio, i-1);
        quickSort(lst, i+1, fim);
    }
}

void chamarQuickSort(vector<produto> &lst, int inicio, int fim) {

    clock_t start, end;
    start = clock();

    quickSort(lst, inicio, fim);

    end = clock();
    double duracao = ((double)(end-start) / CLOCKS_PER_SEC);

    if(testarOrdenação(lst)){
        guardarDadosOrdenacao(duracao, lst.size(), 6);
        ofstream arquivo("listaOrgQuick.txt");
        if(arquivo.is_open()) {
            for(auto p : lst) {
                arquivo << p.nome << ";" << p.preco << ";" << p.qtd_venda << ";" << p.dia_venda << endl;
            }
            arquivo.close();
        }
    }else{
        cout << "Não esta ordenado";
    }
}

void testarTodos(vector<produto> &lst) {

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
                chamarQuickSort(lstProduto, 0, (int)lstProduto.size());
        }else if(op == 11) {
                testarTodos(lstProduto);
        }else {
            cout << "Opcao invalida";
        }

    }while(op != 0);
}
