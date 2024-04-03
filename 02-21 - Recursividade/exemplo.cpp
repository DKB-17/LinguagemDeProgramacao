#include <iostream>

using namespace std;

int fatorial(int num){
    if (num == 0) {
        return 1;
    }
    else {
        return num * fatorial(num-1);
    }
}

int main(){

    int num;

    cout << "--Descubra seu fatorial--" << endl;
    cout << "Digite o numero:";
    cin >> num;
    fatorial(num);

    return 0;

}