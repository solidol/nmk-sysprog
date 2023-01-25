#include <iostream>
using namespace std;
int main()
{
    //приклад 1 + 2 + 3+ ... + n
    int i = 1; 
    int sum = 0; 
    do{
        sum = sum + i;
        i++;
    } while(i<=10);
    cout << sum;
    system("PAUSE");
}