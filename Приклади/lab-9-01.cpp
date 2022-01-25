#include <cstring> 
#include <iostream>

using namespace std;
int main (void) {
    char *tk, *spt=", .!-";  
    char st[ ] = "This header file defines several functions to manipulate C strings and arrays.";
    cout << st<< endl;
    int i = 1;
    tk = strtok (st, spt);
    while (tk != NULL){
        cout << i << " слово — " << tk << " — містить " << strlen(tk) << " символів" << endl;
        tk = strtok(NULL, spt); i++;
    }
    system("pause");      
}