# 09. Робота з рядками у програмі

[Перелік усіх робіт](README.md)

## Мета роботи 

Ознайомитись з IDE Visual Studio. Навчитися створювати проект. Здобути навички у роботі з рядками, як символьними масивами.

## Обладнання

Персональний комп'ютер, Visual Studio 2008 або інша середа розробки для мови C++

## Теоретичні відомості

### Загальні відомості

У мові С та в ранніх версіях мови С++ рядки розглядалися як символьні масиви. Рядок являє собою масив символів, який закінчується нуль-символом. Нагадаємо, що нуль-символ має код, що дорівнює 0, і запис у вигляді керуючої послідовності '\0'. За розташуванням нуль-символа визначається фактична довжина рядка. Кількість елементів символьного масиву складається з кількості символів у рядку плюс 1, тому що нуль-символ також є елементом масиву. Для опису рядка використовуються звичайні засоби опису масивів, наприклад: `char str[25];`. Індексування такого масиву, як і будь-якого іншого, починається з нуля. 

Адреса першого символу рядка може використовуватися по-різному:

* якщо рядок застосовується при ініціюванні масиву типу char, адреса його першого елемента стає синонімом імені масиву. Наприклад, ідентичними є такі описи масиву: 

```cpp
char st[] = "Слово"; 
char st[6] = "Слово"; 
char st[6] = {'С', 'л', 'о', 'в', 'о', '\0'};
char st[] = {'С', 'л', 'о', 'в', 'о', 0};
```

* якщо рядок використовується для ініціювання покажчика типу `char *`, адреса першого символу рядка буде початковим значенням покажчика, наприклад: 

```cpp
char *pst = "Слово";
```

Тут описується змінна-покажчик pst, яка одержує початкове значення, що дорівнює адресі першого елемента (символу 'С');

* якщо рядок використовується у виразі, що застосовує покажчик, то компілятор підставляє у вираз рядка адресу його першого символа, наприклад:

```cpp
char *pst; 
pst = "Перший символ";. 
```

Тут pst одержує адресу символа «П» (тобто першого символа рядка). Слід звернути увагу на те, що при описі символьного масиву його ім'я — не змінна, а покажчик-константа на початок рядка, тому її не можна використовувати в деяких операціях адресної арифметики. Зокрема, не можна здійснювати операцію присвоювання вигляду:

```cpp
char st[20]; 
st = "Петренко"; //— запис неправильний, тому що 
                 //не можна змінити значення st таким чином.
```

Виконання дій з елементами символьного масиву здійснюється через індекси або через покажчики. Для доступу до будь-якого символа рядка використовується індекс масиву char. Тобто, якщо описана змінна `char str [3];`, то третім елементом масиву можна скористатися, записавши: `str[2]` або `*(str+2)`. У процесі роботи з елементами двовимірного масиву застосовують або індекси масиву, або індекси покажчиків. Якщо описаний список прізвищ char `spis[5][15];`, то для використання символа масиву слід записати: `spis[і][j]` або `*(spis[і]+j)`. Аналогічно, якщо оголошений масив покажчиків `char *str[5]`, що містить 5 елементів, кожний з яких вказує на рядок, то доступ до символу рядка можна здійснити з використанням запису `*(str[і]+j)`. 

```cpp
#include <stdio.h>
void main() {
char alphabet [34]; // 33 букви плюс NULL
char letter;  int index=0;
for (letter = 'A'; letter <= 'Я'; letter++, index++) 
	alphabet[index] = letter;
alphabet[index] = 0;
printf("Букви  %s",alphabet);   
}
```

### Функції бібліотеки STRING (CSTRING)

| Ім'я                                                               | Примітки                                                                                                                                                       |
| ------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| void    \*memcpy(void \*dest, const void \*src, size_t n);         | копіює n байтів з області пам'яті src в dest, які не повинні перетинатися, у іншому випадку результат невизначений (можливо як правильне копіювання, так і ні) |
| void    \*memmove(void \*dest, const void \*src, size_t n);        | копіює n байтів з області пам'яті src в dest, які на відміну від memcpy можуть перекриватися                                                                   |
| void    \*memchr(const void \*s, int symbol, size_t n);            | Повертає вказівник на перше входження з в перших n байтах s, або NULL, якщо не знайдено                                                                        |
| int      memcmp(const void \*s1, const void \*s2, size_t n);       | порівнює перші n символів в областях пам'яті                                                                                                                   |
| void    \*memset(void \*, int z, size_t);                          | заповнює область пам'яті одним байтом z                                                                                                                        |
| char    \*strcat(char \*dest, const char \*src);                   | дописує рядок src в кінець dest                                                                                                                                |
| char    \*strncat(char \*dest, const char \*, size_t);             | дописує не більше n початкових символів рядка src (або всю src, якщо її довжина менше) у кінець dest                                                           |
| char    \*strchr(const char \*, int);                              | шукає символ у рядку, починаючи з голови і повертає його адресу, або NULL якщо не знайдений                                                                    |
| char    \*strrchr(const char \*, int);                             | шукає символ у рядку, починаючи з хвоста і повертає його адресу, або NULL якщо не знайдений                                                                    |
| int      strcmp(const char \*, const char \*);                     | лексикографічне порівняння рядків                                                                                                                              |
| int      strncmp(const char \*, const char \*, size_t);            | лексикографічне порівняння перших n байтів рядків                                                                                                              |
| int      strcoll(const char \*, const char \*);                    | лексикографічне порівняння рядків з урахуванням локалі  collating order                                                                                        |
| char    \*strcpy(char \*toHere, const char \*fromHere);            | копіює рядок з одного місця в інше                                                                                                                             |
| char    \*strncpy(char \*toHere, const char \*fromHere, size_t n); | копіює до n байт рядку з одного місця в інше                                                                                                                   |
| char    \*strerror(int);                                           | повертає рядкове подання повідомлення про помилку  errno (не потокобезпечна)                                                                                   |
| size_t   strlen(const char \*);                                    | повертає довжину рядка                                                                                                                                         |
| size_t   strspn(const char \*s, const char \*accept);              | визначає максимальну довжину початкового підрядка, що складається виключно з байтів, перерахованих в accept                                                    |
| size_t   strcspn(const char \*s, const char \*reject);             | визначає максимальну довжину початкового підрядка, що складається виключно з байтів, не перелічених у reject                                                   |
| char    \*strpbrk(const char \*s, const char \*accept);            | знаходить перше входження будь-якого символу, перерахованого в accept                                                                                          |
| char    \*strstr(const char \*haystack, const char \*needle);      | знаходить перше входження рядка needle в haystack                                                                                                              |
| char    \*strtok(char \*, const char \*);                          | перетворює рядок у послідовність токенів. Не потіко-безпечна, нереєнтрантна.                                                                                   |
| size_t   strxfrm(char \*dest, const char \*src, size_t n);         | створює відтрансльовану копію рядка, таку, що дослівне порівняння її (strcmp) буде еквівалентно порівнянню з коллатором.                                       |

### Функції бібліотеки CTYPE

| Ім'я                     | Примітки                                       |
| ------------------------ | ---------------------------------------------- |
| int isalnum(int symbol)  | чи символ є буквою або цифрою                  |
| int isalpha(int symbol)  | чи символ є буквою                             |
| int isblank(int symbol)  | чи є пропуском (доданий до C99)                |
| int iscntrl(int symbol)  | чи є керуючим символом                         |
| int isdigit(int symbol)  | чи є цифрою                                    |
| int isgraph(int symbol)  | чи є символом, який має графічне представлення |
| int islower(int symbol)  | чи є символом нижнього регістру                |
| int isprint(int symbol)  | чи є символом, який можна надрукувати          |
| int ispunct(int symbol)  | чи є символом пунктуації                       |
| int isspace(int symbol)  | чи є пропуском                                 |
| int isupper(int symbol)  | чи є буквою верхнього регістру                 |
| int isxdigit(int symbol) | чи є шістнадцятковим числом                    |
| int tolower(int symbol)  | приводить символ до нижнього регістру          |
| int toupper(int symbol)  | приводить символ до верхнього регістру         |
| int isascii(int symbol)  | повертає числове значення символу від 0 до 127 |
| int toascii(int symbol)  | конвертує символ у ASCII                       |

## Хід роботи

1. Завантажити Visual Studio 2008. Знайдіть на робочому столі ярлик з Visual Studio 2008 або Пуск → Всі програми→ Microsoft → Microsoft Visual Studio 2008.

2. Створити новий проект «Visual C++ (консольное приложение Win32)». Файл → Cтворити → Проект, тип проекту «Консольное приложение Win32».

3. Перевірити роботу програми та намалювати блок-схему алгоритму

```cpp
#include <сstring> 
#include <iostream>
using namespace std;
void main (void) {
	char *tk, *spt=", .!";  
	char st[ ] = "Перевірити роботу програми та намалювати блок-схему алгоритму.";
	cout << st<< endl;
	int і = 1;
	tk = strtok (st, spt);
	while (tk != NULL){
		cout << і << " слово — " << tk << " — містить " << strlen(tk) << " символів" << endl;
		tk = strtok(NULL, spt); і++;
	}   
}
```

4. Написати дві програми для розв'язку задачі відповідно до вашого варіанту та наступного.
	
    Варіант 1. Скласти програму, яка у рядку, що вводиться з клавіатури, видаляє n елементів, починаючи з k-го елемента. Де n і k — цифри цілого типу, що вводяться з клавіатури. Перетворений рядок вивести на екран.
    
    Варіант 2. Ввести рядок з клавіатури. Після кожного символу вставити пробіл. Перетворений рядок вивести на екран.
    
    Варіант 3. Дано два рядки. Перевірити, чи вони збігаються, і вивести відповідне повідомлення.
    
    Варіант 4. Видалити з рядка всі символи +. Перетворений рядок вивести на екран.
    
    Варіант 5. Введіть з клавіатури. Підрахувати скільки разів серед символів даного рядка зустрічається символ '+' і скільки разів символ '—'.
    
    Варіант 6. Скласти програму, яка у рядку, що вводиться з клавіатури, замінює в ній всі знаки оклику крапками.
    
    Варіант 7. З'ясувати, чи вірно, що серед символів рядка є всі літери, що входять у слово father.
    
    Варіант 8. Дано рядок s. Видалити з цього рядка послідовність символів букв 'no'.
    
    Варіант 9. Дано рядок s, серед символів якого є знак оклику. Сформувати новий рядок, що містить усі символи до першої появи знака оклику у вихідному рядку.
    
    Варіант 10. Дано рядок s. Перетворити рядок, видаливши з нього всі коми.
    

5. Намалювати блок-схеми для програм, виконаних у попередньому завданні.
6. Скласти звіт про роботу та відповісти на контрольні питання

## Контрольні запитання

1. Перелічте які ви знаєте конструкції для масиву символів String?
2. Через що здійснюється виконання дій з елементами символьного масиву?
3. Чи можна об'єднувати рядки за допомогою стандартних операцій додавання?
4. За допомогою якого метода можна дізнатися зі скільков символів складається рядок?

## Довідники та додаткові матеріали

Англійські посібники:

1. [C++ Strings](https://www.geeksforgeeks.org/c-string-class-and-its-applications/) by GeeksforGeeks
2. [C++ String Functions with Examples](https://www.guru99.com/cpp-string.html) by Guru99
3. [C++ String](http://www.cplusplus.com/reference/string/) by cplusplus.com
4. [String (C++)](https://en.cppreference.com/w/cpp/string/basic_string) by cppreference.com
5. [C++ Program to Count Number of Words in a String](https://www.programiz.com/cpp-programming/examples/word-count-string) by Programiz
6. [Строки в С++. Рядки (strings)](https://prog-cpp.ru/cpp-string/) by prog-cpp.ru
7. [Стрічки в C++](https://www.ukrprog.com.ua/posts/programmirovanie-na-c-c/52-strichki-v-c.html) by Ukrprog
8. [Строки в С++. Огляд і основні операції](https://studopedia.com.ua/1_22304_stroki-v-c-oglyad-i-osnovni-operatsiyi.html) by Studopedia
9. [Строки в С++. Операції зі стрічками](https://pidpryemstvo.in.ua/cpp/strings.html) by Pidpryemstvo.in.ua
