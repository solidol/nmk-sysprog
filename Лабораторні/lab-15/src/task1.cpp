#include <windows.h>
#include <iostream>

int main() {
    HANDLE hFile = CreateFile(L"C:\\file.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Не вдалося відкрити файл!" << std::endl;
        return 1;
    }

    char buffer[256];
    DWORD bytesRead;
    int sum = 0;

    while (ReadFile(hFile, buffer, sizeof(buffer) - 1, &bytesRead, NULL) && bytesRead > 0) {
        buffer[bytesRead] = '\0';
        char* token = strtok(buffer, " \n");
        while (token) {
            int number = atoi(token);
            if (number % 2 != 0) {
                sum += number;
            }
            token = strtok(NULL, " \n");
        }
    }

    CloseHandle(hFile);
    std::cout << "Сума непарних чисел: " << sum << std::endl;
    return 0;
}
