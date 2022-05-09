#include <iostream>
#define WINVER 0x0500
#include <windows.h>

void spam() {
    INPUT ip;
    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    ip.ki.wVk = 0x4E; // virtual-key code for the "m" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(rand() % 50);
    ip.ki.wVk = 0x4F; // virtual-key code for the "down" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(rand() % 50);
    ip.ki.wVk = 0x4F; // virtual-key code for the "down" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(rand() % 50);
    ip.ki.wVk = 0x42; // virtual-key code for the "down" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    Sleep(rand() % 50);
    ip.ki.wVk = 0x0D; // virtual-key code for the "enter" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
}

int main()
{
    float delay = 0.5;
    std::cout << "Enter delay time(in seconds): ";
    std::cin >> delay;
    std::cout << "There may be lag when trying to stop the spammer, to reduce this effect, please put a longer delay \n";
    std::cout << "F4 to toggle spam" << "\n";
    while (true) {
        if (GetAsyncKeyState(VK_F4)) { //F4 key
            while (true) {
                spam();
                Sleep(rand() % static_cast<int>(delay * 1000));
                if (GetAsyncKeyState(VK_F4)) {
                    break;
                }
            }
        }
    }
    Sleep(0.5);

}
