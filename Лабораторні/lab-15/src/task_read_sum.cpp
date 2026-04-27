#include <windows.h>
#include <iostream>
#include <sstream>

// Обчислення суми чисел з файлу
int main() {
    HANDLE hFile = CreateFile(L"C:\\file.txt", GENERIC_READ, 0, NULL,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        std::cout << "Помилка відкриття\n";
        return 1;
    }

    char buffer[1024];
    DWORD bytesRead;

    ReadFile(hFile, buffer, sizeof(buffer), &bytesRead, NULL);

    std::stringstream ss(buffer);
    int num, sum = 0;

    while (ss >> num) {
        sum += num;
    }

    std::cout << "Сума: " << sum << std::endl;

    CloseHandle(hFile);
    return 0;
}
