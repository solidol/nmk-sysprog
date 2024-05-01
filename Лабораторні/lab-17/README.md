# 18. Використання механізму успадкування в класах

[Перелік усіх робіт](../README.md)

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

Розв'яжи задачу про наслідування згідно з варіантом. Створіть батьківський клас Vehicle з властивостями make, model та методом drive(), який буде виводити повідомлення про те, що транспорт знаходиться в русі.
    
    Варіант 1. Створіть клас Car, який наслідується від класу Vehicle та має додаткову властивість numOfDoors та метод honk(), який буде виводити повідомлення про те, що машина сигналить.
    
    Варіант 2. Створіть клас Bicycle, який наслідується від класу Vehicle та має додаткову властивість numOfGears та метод ringBell(), який буде виводити повідомлення про те, що велосипед дзвонить.
    
    Варіант 3. Створіть клас Truck, який наслідується від класу Vehicle та має додаткову властивість cargoCapacity та метод unloadCargo(), який буде виводити повідомлення про те, що вантаж вивантажується.
    
    Варіант 4. Створіть клас Motorcycle, який наслідується від класу Vehicle та має додаткову властивість topSpeed та метод wheelie(), який буде виводити повідомлення про те, що мотоцикл виконує віллі.
    
    Варіант 5. Створіть клас Boat, який наслідується від класу Vehicle та має додаткову властивість length та метод anchor(), який буде виводити повідомлення про те, що човен закидає якір.
    
    Варіант 6. Створіть клас Airplane, який наслідується від класу Vehicle та має додаткову властивість wingspan та метод takeoff(), який буде виводити повідомлення про те, що літак злітає зі злітної смуги.
    
    Варіант 7. Створіть клас Train, який наслідується від класу Vehicle та має додаткову властивість power, що містить потужність локомотива, locType, що містить тип локомотива та метод unloadCargo(), який буде виводити повідомлення про те, що вантаж вивантажується.

    Варіант 8. Створіть клас Bus, який наслідується від класу Vehicle та має додаткову властивість capacity та метод honk(), який буде виводити повідомлення про те, що автобус сигналить.

    Варіант 9. Створіть клас Tram, який наслідується від класу Vehicle та має додаткову властивість capacity та метод ringBell(), який буде виводити повідомлення про те, що трамвай сигналить.

    Варіант 10. Створіть клас CargoAirplane, який наслідується від класу Vehicle та має додаткову властивість cargoCapacity та метод unload(), який буде виводити повідомлення про те, що літак переходить у стан вивантаження.
   
    
5. Скласти звіт про роботу та відповісти на контрольні питання. Додати у звіт код програм, намалювати блоксхеми

6. Зберегти звіт у форматі PDF та надати викладачеві на перевірку.


## Контрольні запитання

1. Що таке успадкування?
2. Які переваги успадкування можна отримати в програмуванні?
3. Як створити клас-потомок, успадкований від батьківського класу?
4. Як визначити доступ до класів-потомків та батьківських класів?
5. Що таке різнорідне успадкування та як його використовувати в програмуванні?
6. Як забезпечити захист від доступу до деяких методів чи властивостей батьківського класу в класі-потомку?
7. Як використовувати успадкування для створення складних структур даних, наприклад списків чи дерев?
8. Як можна використовувати віртуальні методи в успадкованих класах?
9. Чи можна успадкувати від більше ніж одного класу в C++?
10. Як вирішити проблему конфліктів імен під час успадкування в C++?

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