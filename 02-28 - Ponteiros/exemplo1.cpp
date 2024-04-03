#include <iostream>

using namespace std;

int main(){

    int a = 10;
    int *ptrA = &a;
    int **ptrB = &ptrA;

    cout << *ptrB << endl;

    return 0;
}