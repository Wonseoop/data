#include <windows.h>
#include <string>
#include <iostream>

// 클립보드에 텍스트 복사 함수
void copyToClipboard(const std::string& text) {
    if (OpenClipboard(nullptr)) {
        EmptyClipboard();
        HGLOBAL hClipboardData = GlobalAlloc(GMEM_MOVEABLE, text.size() + 1);
        if (hClipboardData) {
            char* pchData = static_cast<char*>(GlobalLock(hClipboardData));
            memcpy(pchData, text.c_str(), text.size() + 1);
            GlobalUnlock(hClipboardData);
            SetClipboardData(CF_TEXT, hClipboardData);
        }
        CloseClipboard();
    }
}

int main() {
    std::string input;
    std::cout << "클립보드에 복사할 문자열을 입력하세요: ";
    std::getline(std::cin, input);

    // 입력값을 클립보드에 복사
    copyToClipboard(input);

    std::cout << "문자열이 클립보드에 복사되었습니다." << std::endl;

    return 0;
}
