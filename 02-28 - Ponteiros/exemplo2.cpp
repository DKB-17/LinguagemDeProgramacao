#include <iostream>

using namespace std;

void sqr(int x, int &result){
    result = x * x;
}

int main(){
    int w = 5, w2;

    sqr(w, w2);

    cout << w2;

}