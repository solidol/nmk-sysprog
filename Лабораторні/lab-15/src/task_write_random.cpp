#include <windows.h>
#include <iostream>
#include <ctime>

// Запис 50 випадкових чисел у файл
int main() {
    srand(time(0));

    HANDLE hFile = CreateFile(L"C:\\file.txt", GENERIC_WRITE, 0, NULL,
        CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        std::cout << "Помилка\n";
        return 1;
    }

    char buffer[50];
    DWORD bytesWritten;

    for (int i = 0; i < 50; i++) {
        int num = rand() % 100;
        sprintf(buffer, "%d\r\n", num);
        WriteFile(hFile, buffer, strlen(buffer), &bytesWritten, NULL);
    }

    CloseHandle(hFile);
    return 0;
}
