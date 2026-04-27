#include <windows.h>
#include <iostream>

// Створення папки та переміщення файлу
int main() {
    // Створення каталогу
    if (CreateDirectory(L"C:\\MyFolder", NULL)) {
        std::cout << "Папку створено\n";
    } else {
        std::cout << "Папка вже існує або помилка\n";
    }

    // Переміщення файлу
    if (MoveFile(L"C:\\file.txt", L"C:\\MyFolder\\file.txt")) {
        std::cout << "Файл переміщено\n";
    } else {
        std::cout << "Помилка переміщення\n";
    }

    return 0;
}
