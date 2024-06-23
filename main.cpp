
#include <chrono>
#include <thread>

#include <windows.h>


void numLock_event()
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.wVk = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.dwFlags = KEYEVENTF_SCANCODE;
    ip.ki.wScan = 0x45;  // NumLock 0x45

    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

int main(int argc, char *argv[])
{
    int64_t interval = 60000;

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        numLock_event();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        numLock_event();
    }
}
