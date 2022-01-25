#include <iostream>
#include <clocale>

using namespace std;
int main(){
    setlocale(LC_ALL,"Russian");
    int n,i,j=1;
    cout<<"N= ";
    cin>>n;
    int *a=new int[n];
    for (i=0;i<=n;i++){
        *(a+i)=j;  
        j+=2;
    }
    cout<<"Массив:\n";
    for (i=0;i<=n;i++)
        cout<<*(a+i)<<'\n';
    system("pause");
    return 0;
}