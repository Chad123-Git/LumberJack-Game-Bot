#include <iostream>
#include <vector>
#include <windows.h>

bool isWhite(COLORREF pixel) {
    COLORREF whiteColor = RGB(255, 255, 255);
    return (pixel == whiteColor);
}

bool isBrown(COLORREF pixel) {
    COLORREF brownColor = RGB(161, 116, 56);
    return (pixel == brownColor);
}

bool isBlue(COLORREF pixel) {
    COLORREF blueColor = RGB(211, 247, 255);
    return (pixel == blueColor);
}

void pressKey(WORD keyCode) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = keyCode;
    input.ki.dwFlags = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    INPUT releaseInput = input;
    releaseInput.ki.dwFlags = KEYEVENTF_KEYUP;

    INPUT inputs[] = { input, releaseInput };
    SendInput(2, inputs, sizeof(INPUT));
}

int main() {
    std::vector<POINT> coordinates = { {888, 512}, {884, 586}, {1024, 512}, {1035, 586} };
    int delayDuration = 70;  

    while (true) {
        std::vector<COLORREF> pixelColors(coordinates.size());

        for (size_t i = 0; i < coordinates.size(); ++i) {
            HDC hdc = GetDC(NULL);
            pixelColors[i] = GetPixel(hdc, coordinates[i].x, coordinates[i].y);
            ReleaseDC(NULL, hdc);
        }

        bool brownPixel = isBrown(pixelColors[0]);
        bool bluePixel = isBlue(pixelColors[0]);
        bool whitePixel = isWhite(pixelColors[1]);

        if (brownPixel && whitePixel) {
            pressKey(VK_RIGHT);
        }
        else if (bluePixel && whitePixel) {
            pressKey(VK_LEFT);
        }
        else if (isBrown(pixelColors[2]) && isWhite(pixelColors[3])) {
            pressKey(VK_LEFT);
        }
        else if (isBlue(pixelColors[2]) && isWhite(pixelColors[3])) {
            pressKey(VK_RIGHT);
        }

        Sleep(delayDuration);  
    }

    return 0;
}
