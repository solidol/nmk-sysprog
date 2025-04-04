#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    HANDLE hFile;
    DWORD dwBytesWritten, dwBytesRead;
    char szBuffer[256] = "Hello World!";
    char szReadBuffer[256] = "";

    // Відкриття файлу
    hFile = CreateFile(L"c:\\test.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        cout << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    // Запис до файлу
    if (!WriteFile(hFile, szBuffer, strlen(szBuffer), &dwBytesWritten, NULL))
    {
        cout << "Помилка запису до файлу!" << endl;
        CloseHandle(hFile);
        return 1;
    }

    cout << "Записано в файл: " << dwBytesWritten << " байт" << endl;

    // Закриття файлу
    CloseHandle(hFile);

    // Відкриття файлу для читання
    hFile = CreateFile(L"c:\\test.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        cout << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    // Читання з файлу
    if (!ReadFile(hFile, szReadBuffer, sizeof(szReadBuffer), &dwBytesRead, NULL))
    {
        cout << "Помилка читання з файлу!" << endl;
        CloseHandle(hFile);
        return 1;
    }

    cout << "Прочитано з файлу: " << szReadBuffer << endl;

    // Закриття файлу
    CloseHandle(hFile);

    return 0;
}