#include <windows.h>
#include <iostream>
#include <cstring>

// Запис таблиці квадратів чисел у файл
int main() {
    HANDLE hFile = CreateFile(L"C:\\file.txt", GENERIC_WRITE, 0, NULL,
        CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        std::cout << "Помилка створення файлу\n";
        return 1;
    }

    char buffer[100];
    DWORD bytesWritten;

    for (int i = 1; i <= 20; i++) {
        sprintf(buffer, "%d^2 = %d\r\n", i, i * i);
        WriteFile(hFile, buffer, strlen(buffer), &bytesWritten, NULL);
    }

    CloseHandle(hFile);
    return 0;
}
