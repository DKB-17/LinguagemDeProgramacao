#include <iostream>

using namespace std;

int main(){

    cout << "funcionou";
    int *contador;
    *contador = 1;

    cout << &contador;
    cout << "\n" << contador;

    return 0;
}