#include <iostream>
#include <conio.h>

using namespace std;

struct registro{
    int cod;
    string name;

    void read(){
        cout << "\nReading register";
        cout << "\nCod: ";
        cin >> cod;
        cout << "\nName: ";
        fflush(stdin);
        getline(cin, name);
        /*cout << "\nAddress: ";
        getline(cin, address);
        */fflush(stdin);
    }
    void show(){
        cout << "\n-----------Show register-------------";
        cout << "\nCod: " << cod << "\nName: " << name << endl; //<< "\nAddress: " << address;
    }
};

void read_line(registro line[], int tamanho, int &contador){
    char sair = 'n';
    for (int i; i<tamanho && sair != 'y';i++){
        line[i].read();
        contador += 1;
        cout << "\nWant to leave:";
        cin >> sair;
    }
};

void show_line(registro line[], int tamanho){
    for(int i=0; i<tamanho;i++){
        line[i].show();
    }
}

void line_delete(int line[], int tamanho, int &contador){
    char sair = 'n';
    for (int i=0;i<tamanho && sair != 'y';i++){
        cout << "\nWrite the cod then want to delete: ";
        cin >> line[i];
        contador += 1;

        cout << "\nWant to leave: ";
        cin >> sair;
    }
}

void update_line(registro lineS[], int &contadorS, int lineT[], int &contadorT, registro lineA[], int tamanho, int &contadorA){
    int i = 0; //lineA[]
    int j = 0; //lineT[]
    int k = 0; //lineS[]
    for(;i<tamanho && k < contadorS;i++,k++){
        while(lineS[k].cod == lineT[j]){
            k++;
            j++;
        }
        lineA[i] = lineS[k];
        contadorA += 1;
        if(lineT[j] < lineS[k].cod){
            j++;
        }
    }
}

int main(){

    int tamanho = 10;

    registro arqS[tamanho/2];
    int arqT[tamanho/2];
    registro arqA[tamanho];

    int contS = 0;
    int contT = 0;
    int contA = 0;

    read_line(arqS,(tamanho/2), contS);
    system("cls");
    show_line(arqS, contS);
    getch();
    line_delete(arqT, (tamanho/2), contT);
    update_line(arqS,contS,arqT,contT,arqA,tamanho,contA);
    show_line(arqA, contA);

    return 0;
};
