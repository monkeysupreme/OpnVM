#pragma once

#include <Windows.h>

namespace Opn::Controls {

    void MoveCursor(int x, int y);

    void ClickLeftMouse();
    void ClickRightMouse();

    void OpenApp(const char* path);

}