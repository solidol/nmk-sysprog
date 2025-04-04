#include <windows.h>
#include <string>

int main() {
    HANDLE hFile = CreateFile(L"C:\\file.txt", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        DWORD dwBytesWritten;
        for (int i = 1; i <= 10; ++i) {
            std::wstring line = std::to_wstring(5) + L" x " + std::to_wstring(i) + L" = " + std::to_wstring(5 * i) + L"\n";
            WriteFile(hFile, line.c_str(), line.size() * sizeof(wchar_t), &dwBytesWritten, NULL);
        }
        CloseHandle(hFile);
    }
    return 0;
}
