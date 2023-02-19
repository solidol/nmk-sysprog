[Перелік усіх робіт](README.md)

---

# 18. Використання механізму успадкування в класах

## Мета роботи 

Ознайомитись з теорією та на практиці з механізмом успадкування класів 

## Обладнання

Персональний комп’ютер, Visual Studio 2008 або інша середа розробки для мови C++

## Теоретичні відомості

### Успадкування

Успадкування у програмуванні - це принцип створення класу на базі вже існуючого, при цьому ми маємо можливість користуватися функціоналом (властивостями та методами) базового. Класи створені в такий спосіб називаються похідними чи дочірніми, але в основі якого створюються — батьком чи базовим.

Похідний клас ми можемо вдосконалити, додаючи:

* Нові змінні.
* Опції.
* Конструктори.

І все це не змінюючи базовий клас. 

### Модифікатор доступу `protected`

Для початку потрібно знати про доступ protected, який є невід'ємною частиною успадкування. **protected** – це модифікатор доступу, який працює як private, але поширюється **також** на властивості предка.

```cpp
class Animals {
  protected:
    int zebras;
};
 
class Dog : public Animals {
  int counter_zebras () {
    return zebras;
  }
};
```

Якби змінна `zebras` перебувала у доступі private, то використання їх у функції `counter_zebras` призвело до помилки. 

### Створення дочірнього класу

Щоб успадкувати клас, потрібно використовувати конструкцію нижче:

`class <ім'я нащадка> : <модифікатор успадкування> <ім'я батьківського класу>{};`

Перше на що треба звернути увагу на двокрапку `(:)` вона одинарна, а не подвійна як у області видимості.

Друге це `<модифікатор успадкування>`. При його оперуванні можна задати, якими модифікаторами доступу батьківського класу можна буде користуватися в дочірньому. Давайте докладніше це розберемо.

Взагалі можна вказувати: public, private, protected. З цих трьох майже завжди використовується public, але не погано знати, як працюють інші. 

**public** - можна використовувати `public` і `protected` батьківського класу.

```cpp
class Animals {
  public:
    int counter;  // загальна кількість тварин
  protected:
    int zebras;
    int bears;
    int dogs;
 
    // функція обчислення загальної кількості тварин
    count_animals() {
      counter = dogs + bears + zebras;
    }
    set_dogs(int count_of_dogs) {
      dogs = count_of_dogs;
    }
};
 
class Dog : public Animals {
  public:
    int count_dogs() {
      return dogs;  // використали змінну dog
    }
};
```



**private** – користуватися можна лише властивостями (не функціями) батька. Щоб використовувати функції, потрібно дозволити це безпосередньо (і без круглих дужок, тільки ім'я), а також дозволяти потрібно в публічному доступі (public). Робиться це так `<батьківський клас> :: <властивості>;`.

```cpp
class Dog : private Animals {
  public:
    int count_dogs() {
      return dogs;  // використали змінну dog
    }
    Animals :: set_dogs; 
 
};
 
int main() {
    Dog jack;
    int k;
    cout << "Введите количество собак: "; cin >> k;
 
    jack.set_dogs(k);
    cout << "Количество собак равняется: "<< jack.count_dogs();
    return 0;
}
```

**protected** — ідентичний private, але властивості public перетворюється на доступ protected. 

## Хід роботи

1. Завантажити Visual Studio 2008. Знайдіть на робочому столі ярлик з Visual Studio 2008 або Пуск → Всі програми→ Microsoft → Microsoft Visual Studio 2008.

2. Створити новий проект «Visual C++ (консольное приложение Win32)». Файл → Cтворити → Проект, тип проекту «Консольное приложение Win32».

3. Перевірити роботу програми та намалювати блок-схему алгоритму

```cpp
#include <iostream>
using namespace std;

// батьківський клас
class Shape {
   public:
      void setWidth(int w) {
         width = w;
      }
      void setHeight(int h) {
         height = h;
      }
      
   protected:
      int width;
      int height;
};

// дочірній клас
class Rectangle: public Shape {
   public:
      int getArea() { 
         return (width * height); 
      }
};

int main(void) {
   Rectangle Rect;
 
   Rect.setWidth(5);
   Rect.setHeight(7);

   // друкуємо плющу об'єкту
   cout << "Total area: " << Rect.getArea() << endl;

   return 0;
}
```

4. Розв'язати задачу згідно з варіантом. Намалювати блок-схему.

    Варіант I

      Описати батьківський клас з ім'ям Animals та дочірній клас Mammals.

      Написати програму, яка буде виводити загальну кількість ссавців та кількість особин кожної статті.

    Варіант II

      Описати батьківський клас з ім'ям Buildings та дочірній клас Skyscrapers.
	
      Написати програму, яка буде друкувати загальну кількість будівель, кількість хмарочосів та висоту найвищого з них.

    Варіант III 

      Описати батьківський клас з ім'ям Devices та дочірній клас Smartphones.
    
      Написати програму, яка буде друкувати загальну кількість приладів, кількість смартфонів з них та кількість смартфонів різних брендів
   
    Варіант IV
   
      Описати батьківський клас з ім'ям Cars та дочірній клас Pickups.
    
      Написати програму, яка буде диводити кількість та марку пікапів, а також виводити середню кількість кінських сил різних марок пікапів.
   
    
## Контрольні запитання

1. Опишіть метод успадкування в ООП.

2. Які існують модифікатори доступу при успадкування?

3. Чим відрізняється `protected` від `private`?

4. Як використовувати функції з модфікатором `private`?

## Довідники та додаткові матеріали

1.  [GeeksforGeeks - Object Oriented Programming(OOPs) Concept in C++](https://www.geeksforgeeks.org/object-oriented-programming-oops-concept-in-c/)
2.  [W3Schools - C++ OOP](https://www.w3schools.com/cpp/cpp_oop.asp)
3.  [TutorialsPoint - C++ Object Oriented](https://www.tutorialspoint.com/cplusplus/cpp_object_oriented.htm)
4.  [Programiz - C++ Object-oriented Programming](https://www.programiz.com/cpp-programming/object-oriented-programming)
5.  [Learn-C - Object Oriented Programming](https://www.learn-c.org/en/Object_Oriented_Programming)
6.  [cplusplus.com - Classes (I)](https://www.cplusplus.com/doc/tutorial/classes/)
7.  [Udemy - Object-Oriented Programming in C++](https://www.udemy.com/topic/object-oriented-programming-in-c-plus-plus/)
8.  [ООП в С++. Поліморфізм і наслідування](https://www.viva64.com/en/t/0079/)
9.  [Основы ООП в С++. Классы и объекты](https://metanit.com/cpp/tutorial/4.1.php)
10. [LearnCpp: Introduction to Object Oriented Programming (OOP) in C++](https://www.learncpp.com/cpp-tutorial/object-oriented-programming/)
11. [Cplusplus.com: Polymorphism](https://www.cplusplus.com/doc/tutorial/polymorphism/)
12. [GeeksforGeeks: Object Oriented Programming (OOPs) Concept in C++](https://www.geeksforgeeks.org/object-oriented-programming-oops-concept-in-c/)
13. [JavaTpoint: C++ OOPs Concepts](https://www.javatpoint.com/cpp-oops-concepts)
14. [OOP in C++ - YouTube Playlist by Neso Academy](https://www.youtube.com/watch?v=_bYFu9mBnr4&list=PLBlnK6fEyqRgp46KUv4ZY69yXmpwKOIev)