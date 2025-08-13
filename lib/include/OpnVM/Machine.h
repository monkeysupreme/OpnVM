#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory>
#include "Controls.h"
#include "OpCode.h"

namespace Opn {

    class VirtualMachine
    {
    public:
        std::vector<std::pair<int64_t, int64_t>> Stack;

        explicit VirtualMachine(const std::string& mode);

        void Run(const std::vector<uint8_t>& code);

        static void AppendInt64(std::vector<uint8_t>& code, int64_t value);
        static void AppendString(std::vector<uint8_t>& code, const std::string& value);

        static void PushCursorPos(std::vector<uint8_t>& code, int64_t x, int64_t y);
        static void PushMoveCursor(std::vector<uint8_t>& code);
        static void PushClickLeftMouse(std::vector<uint8_t>& code);
        static void PushClickRightMouse(std::vector<uint8_t>& code);
        
        void PushOpenApp(std::vector<uint8_t>& code, const std::string& path);
        
        static void PushEndProgram(std::vector<uint8_t>& code);

    private:
        std::string m_Mode;

        size_t m_ProgramCounter;
        std::vector<uint8_t> m_Code;
    };

}