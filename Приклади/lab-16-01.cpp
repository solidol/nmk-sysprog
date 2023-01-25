#include <string.h>
#include <iostream>

class string{
	char *ch; // покажчик на текстовий рядок
	int len; // Довжина текстового рядка
	public:
	// Конструктори
	// створює об'єкт - порожній рядок
	string (int N = 80): len (0) {
		ch = new char [N + 1]; 
		ch[0] = '\0';
	}
	// створює об'єкт за заданим рядком
	string (const char * arch) {
		len = strlen (arch);
		ch = new char[len +1];
		strcpy(ch,arch);
	}

	// компоненти-функції
	// повертає посилання на довжину рядка
	int& len_str(void){
		return len;
	}
	// повертає покажчик на рядок
	char *str(void){
		return ch;
	}
};