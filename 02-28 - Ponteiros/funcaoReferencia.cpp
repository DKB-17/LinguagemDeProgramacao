#include <iostream>

using namespace std;

int func(int &x, int y) {
    x = x + 1;
    y = y + 3;

    cout << "x : " << x << endl;
    cout << "y : " << y << endl;

    return (x+y);
}

int main(){

    int a,b;
    // cin >> a >> b;
    a = 10;
    b = 20;

    cout << "a : " << a << endl;
    cout << "b : " << b << endl;

    cout << "func(a,b) :" << func(a,b) << endl;

    
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;


}