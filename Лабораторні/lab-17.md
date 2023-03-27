# 17. Перевантаження операторів

[Перелік усіх робіт](README.md)

## Мета роботи 

Ознайомитися з можливостями перевантаження операторів та ситуаціями де це необхадно.

## Обладнання

Персональний комп’ютер, Visual Studio 2008 або інша середа розробки для мови C++

## Теоретичні відомості

Перевантаження операторів у С++ дозволяє використовувати оператори для роботи з об'єктами класів, які ми самі створюємо. Це дозволяє зробити код більш зрозумілим та приємнішим для розробників.

При перевантаженні оператора ми можемо задати нову функціональність для цього оператора, коли він використовується з нашим класом. Наприклад, ми можемо перевизначити операції додавання (+), віднімання (-), множення (*) та ділення (/) для об'єктів нашого класу, якщо вважаємо, що це має сенс для нашого класу.

Перевантаження операторів дозволяє зробити код більш зрозумілим та коротким, наприклад, замість виклику методів можна використовувати оператори, що є більш зрозумілим для багатьох програмістів.

Для перевантаження операторів ми можемо використовувати функції-члени та звичайні функції. Функції-члени перевантажують оператори для конкретного класу, в той час як звичайні функції перевантажують оператори для двох об'єктів різних класів або для одного об'єкта та додаткових параметрів.

Наприклад, для перевантаження операції додавання (+) ми можемо використовувати функцію-член у класі:

```cpp
class Vector {
public:
    Vector operator+(const Vector& vec) {
        Vector result;
        result.x = this->x + vec.x;
        result.y = this->y + vec.y;
        result.z = this->z + vec.z;
        return result;
    }
private:
    double x, y, z;
};
```

Або звичайну функцію поза класом:

```cpp
class Vector {
public:
    double x, y, z;
};

Vector operator+(const Vector& vec1, const Vector& vec2) {
    Vector result;
    result.x = vec1.x + vec2.x;
    result.y = vec1.y + vec2.y;
    result.z = vec1.z + vec2.z;
    return result;
}
```

## Хід роботи

## Контрольні запитання

1. Що таке перевантаження операторів у C++?
2. Які оператори можуть бути перевантажені в C++?
3. Як використовувати перевантаження операторів для користувацьких типів даних?
4. Як можна використовувати перевантаження операторів для стандартних типів даних?
5. Як використовувати перевантаження операторів для створення векторів, матриць та інших складних структур даних?
6. Як використовувати перевантаження операторів для роботи зі строками?
7. Як можна використовувати перевантаження операторів для здійснення операцій введення та виведення даних?
8. Які є обмеження та побічні ефекти при використанні перевантаження операторів?

## Довідники та додаткові матеріали

1.  [C++ Operators - cppreference.com](https://en.cppreference.com/w/cpp/language/operators)
2.  [Operator Overloading in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/operator-overloading-c/)
3.  [C++ Overloading (Operator and Function) - tutorialspoint](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm)
4.  [Overloading the arithmetic operators using friend functions - learncpp.com](https://www.learncpp.com/cpp-tutorial/93-overloading-the-arithmetic-operators-using-friend-functions/)
5.  [C++ Operator Overloading - programiz.com](https://www.programiz.com/cpp-programming/operator-overloading)
6.  [Перегрузка операторов в C++ - codelessons.ru](https://codelessons.ru/cplusplus/peregruzka-operatorov-v-c.html)
7.  [Перегрузка операторов в C++ - metanit.com](https://metanit.com/cpp/tutorial/6.10.php)
8.  [Перегрузка операторов C++ - cpp.com.ru](https://cpp.com.ru/operators.html)
9.  [Перегрузка операторов в C++ - eax.me](https://eax.me/cpp-overload/)
10. [Перегрузка операторов в C++ - cyberforum.ru](https://www.cyberforum.ru/cpp-beginners/thread1689464.html)