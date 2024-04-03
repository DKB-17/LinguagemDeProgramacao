#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

int main(){

    char s1[20] = "Feliz ";
    char s2[] = "Ano Novo";
    char s3[40] = "";
    cout << "S1 = " << s1 << "\n S2 = " << s2;
    cout << "\n strcat(s1,s2) = " << strcat(s1,s2); // concatena s1 e s2
    cout << "\n strncat(s3,s1,5) = " << strncat(s3,s1,5); // concatena os N(5) primeiros caracteres da string S1 em S3
    cout << "\n strcat(s3,s1) = " << strcat(s3,s1);
    getch();

}
