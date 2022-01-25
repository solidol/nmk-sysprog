#include <iostream.h>
#include <conio.h>
int main ( )
{ int x = 10;
  int *px (&x);   // int *px = &x;
cout << "x =" << x << endl; 
  cout << "*px =" << *px << endl;
  x *= 2;          //x=x*2;
  cout << "Новое значение *px = " << *px << endl;*
  px += 2;       // *px=*px + 2;
  cout << "Результат *px, т. e. x = " << x << endl;
  getch();     //задержка экрана
}