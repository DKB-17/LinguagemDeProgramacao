#include <iostream>
#include <conio.h>

using namespace std;

struct carro {
    char marca[15];
    char modelo[15];
    char chassi[15];
    int ano;
    float preco;
    int quilom;

};

void funcao(struct carro carro_param){
    cout << carro_param.marca << endl;
    cout << carro_param.quilom <<endl;
}

int main(){
    struct carro meucarro, carro_dele, carro_da_empresa;
    cin >> meucarro.marca;
    cin >> carro_da_empresa.marca;
    cout << meucarro.marca << endl;
    cout << carro_dele.marca << endl;
    cout << carro_da_empresa.marca << endl;

    meucarro.quilom = 0;
    cout << meucarro.quilom << endl;
    cout << meucarro.preco;
    getch();
    funcao(carro_da_empresa);


}
