#include "stdafx.h"
#include <iostream>
using namespace std;
struct Worker { // начало объявления структурного типа Worker
	char surname[30]; //объявление поля «фамилия работника»
	char position[15]; //объявление поля «название занимаемой должности»
	unsigned short int year; //объявление поля «год поступления на работу»
}; //конец объявление структуры Worker

int _tmain(int argc, _TCHAR* argv[]){
  int n = 10; // объявление константы n — числа элементов типа «Worker»
	bool people = false;
	unsigned short int now_year = 2015, seniority; // объявление переменных now_year — текущий год и seniority — стаж
	Worker* K = new Worker[n];
	Worker temp;
	for (int i = 0; i < n; i++){
		cout << "surname:";
		cin >> K[i].surname;
		cout << "\nposition: ";
		cin >> K[i].position;
		cout << "\nyear: ";
		cin >> K[i].year;
	}
	cout << "enter number: ";
	cin >> seniority;
	for (int i = 0; i < n; i++){
		if ((now_year - K[i].year) > seniority){
			cout << '\n' << K[i].surname;
			people = true;
		}
	}
	if (people = false)
		cout << "no one";
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n; j++)
			if (strcmp(K[i].surname, K[j].surname) > 0){
				temp = K[i];
				K[i] = K[j];
				K[j] = temp;
			}
	}
	for (int i = 0; i < n; i++)
		cout << '\n' << K[i].surname << endl;
	system("pause");
	return 0;
}