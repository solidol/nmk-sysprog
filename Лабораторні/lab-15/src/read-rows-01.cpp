#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    HANDLE hFile = CreateFile(L"C:\\numbers.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        cout << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    int sum = 0;

    const int bufferSize = 1024;
    char buffer[bufferSize];

    DWORD bytesRead;
    while (ReadFile(hFile, buffer, bufferSize, &bytesRead, NULL) && bytesRead > 0) {
        string numbers(buffer, bytesRead);
        size_t pos = 0;
        while ((pos = numbers.find("\n")) != string::npos) {
            string subs = numbers.substr(0, pos);
            cout <<"number:" <<stoi(subs)<<endl;
            numbers.erase(0, pos + 1);
        }
       // cout << "number:" << stoi(numbers); 
    }

    CloseHandle(hFile);

    return 0;
}
