#include <iostream>
#include <conio.h>

using namespace std;

int fibonnati(int num) {
    if (num < 2){
        return num;
    }else{
        return  fibonnati(num-2) + fibonnati(num-1);
    }
}

int main(){

    int num;
    cout << "Fibonnati" << endl;

    cout << "Digite a quantidade de numeros da sequencia quer descobrir:" ;
    cin >> num;
    int i;
    for(i = num;i > 0; i--)
        cout << fibonnati(num) << " - " ;

}
