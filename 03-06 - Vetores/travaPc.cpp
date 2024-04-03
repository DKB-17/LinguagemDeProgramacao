#include <iostream>
#include <math.h>

using namespace std;

int main(){

    int inicio[1];

    for(int i = 0;i < 10000000000000 ; i++){
        cout << inicio[i];
        inicio[i] = 0;
    }

    return 0;
}
