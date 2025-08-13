#include "OpnVM/Controls.h"

#include <thread>
#include <chrono>

namespace Opn::Controls {

    void MoveCursor(int x, int y) 
    {
        int steps = 50;
        int delay = 5;

        POINT current;
        GetCursorPos(&current);

        double startX = current.x;
        double startY = current.y;

        double dx = static_cast<double>(x) - startX;
        double dy = static_cast<double>(y) - startY;

        for (int i = 0; i <= steps; ++i) 
        {
            double t = static_cast<double>(i) / steps;

            int x = static_cast<int>(startX + dx * t);
            int y = static_cast<int>(startY + dy * t);
            SetCursorPos(x, y);
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
    }

    void ClickLeftMouse() 
    {
        INPUT inputs[2] = {};

        inputs[0].type = INPUT_MOUSE;
        inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

        inputs[1].type = INPUT_MOUSE;
        inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

        SendInput(2, inputs, sizeof(INPUT));
    }

    void ClickRightMouse() 
    {
        INPUT inputs[2] = {};

        inputs[0].type = INPUT_MOUSE;
        inputs[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;

        inputs[1].type = INPUT_MOUSE;
        inputs[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;

        SendInput(2, inputs, sizeof(INPUT));
    }

    void OpenApp(const char* path)
    {
        ShellExecuteA(
            nullptr,
            "open",
            path,
            nullptr,
            nullptr,
            SW_SHOWNORMAL
        );
    }

}