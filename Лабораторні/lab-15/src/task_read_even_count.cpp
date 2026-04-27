#include <windows.h>
#include <iostream>
#include <sstream>

// Підрахунок парних чисел у файлі
int main() {
    HANDLE hFile = CreateFile(L"C:\\file.txt", GENERIC_READ, 0, NULL,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    char buffer[1024];
    DWORD bytesRead;

    ReadFile(hFile, buffer, sizeof(buffer), &bytesRead, NULL);

    std::stringstream ss(buffer);
    int num, count = 0;

    while (ss >> num) {
        if (num % 2 == 0) count++;
    }

    std::cout << "Парних чисел: " << count << std::endl;

    CloseHandle(hFile);
    return 0;
}
