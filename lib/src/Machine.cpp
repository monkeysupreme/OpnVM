#include "OpnVM/Machine.h"

namespace Opn {

    VirtualMachine::VirtualMachine(const std::string& mode) 
    {
        m_Mode = mode;
        m_ProgramCounter = 0;
    }

    
    void VirtualMachine::Run(const std::vector<uint8_t>& code) 
    {
        m_Code = code;
        Stack.clear();

        while (m_ProgramCounter < m_Code.size())
        {
            uint8_t op = m_Code[m_ProgramCounter++];

            switch (op)
            {
            case OPCODE_PUSH_POS: {
                if (m_ProgramCounter + 2 * sizeof(int64_t) > m_Code.size()) 
                {
                    throw std::runtime_error("Unexpected end of bytecode reached");
                }

                int64_t first;
                int64_t second;

                std::memcpy(&first, &m_Code[m_ProgramCounter], sizeof(int64_t));
                m_ProgramCounter += sizeof(int64_t);

                std::memcpy(&second, &m_Code[m_ProgramCounter], sizeof(int64_t));
                m_ProgramCounter += sizeof(int64_t);

                Stack.emplace_back(first, second);

                if (m_Mode == "debug") 
                {
                    std::cout << "OPCODE_PUSH_POS (" << first << ", " << second << ")\n";
                }

                break;
            }
            case OPCODE_MOVE_CURSOR_TO_POS: {
                if (Stack.empty())
                {
                    throw std::runtime_error("Stack underflow");
                }

                auto pos = Stack.back();
                Stack.pop_back();

                Controls::MoveCursor(pos.first, pos.second);

                if (m_Mode == "debug")
                {
                    std::cout << "OPCODE_MOVE_CURSOR_TO_POS\n";
                }

                break;
            }
            case OPCODE_CLICK_LEFT_MOUSE: {
                Controls::ClickLeftMouse();

                if (m_Mode == "debug")
                {
                    std::cout << "OPCODE_CLICK_LEFT_MOUSE\n";
                }

                break;
            }
            case OPCODE_CLICK_RIGHT_MOUSE: {
                Controls::ClickRightMouse();

                if (m_Mode == "debug") 
                {
                    std::cout << "OPCODE_CLICK_RIGHT_MOUSE\n";
                }

                break;
            }
            case OPCODE_OPEN_APPLICATION: {
                int64_t length = 0;
                std::memcpy(&length, &m_Code[m_ProgramCounter], sizeof(int64_t));
                m_ProgramCounter += sizeof(int64_t);

                if (m_ProgramCounter + length > m_Code.size())
                {
                    throw std::runtime_error("Unexpected end of bytecode reached");
                }

                std::string path(reinterpret_cast<const char*>(&m_Code[m_ProgramCounter]), length);
                m_ProgramCounter += length;

                Controls::OpenApp(path.c_str());
                break;
            }
            case OPCODE_END: {
                if (m_Mode == "debug") 
                {
                    std::cout << "OPCODE_END: Shutting down VM...\n";
                }
                return;
            }
            default: {
                throw std::runtime_error("Unknown OpCode " + std::to_string(op));
            }
            }
        }
    }

    void VirtualMachine::AppendInt64(std::vector<uint8_t>& code, int64_t value) 
    {
        uint8_t bytes[sizeof(int64_t)];
        std::memcpy(bytes, &value, sizeof(int64_t));
        code.insert(code.end(), bytes, bytes + sizeof(int64_t));
    }

    void VirtualMachine::AppendString(std::vector<uint8_t>& code, const std::string& value)
    {
        AppendInt64(code, static_cast<int64_t>(value.size()));
        code.insert(code.end(), value.begin(), value.end());
    }

    void VirtualMachine::PushCursorPos(std::vector<uint8_t>& code, int64_t x, int64_t y) 
    {
        code.push_back(OPCODE_PUSH_POS);
        AppendInt64(code, x);
        AppendInt64(code, y);
    }

    void VirtualMachine::PushMoveCursor(std::vector<uint8_t>& code)
    {
        code.push_back(OPCODE_MOVE_CURSOR_TO_POS);
    }

    void VirtualMachine::PushClickLeftMouse(std::vector<uint8_t>& code)
    {
        code.push_back(OPCODE_CLICK_LEFT_MOUSE);
    }

    void VirtualMachine::PushClickRightMouse(std::vector<uint8_t>& code)
    {
        code.push_back(OPCODE_CLICK_RIGHT_MOUSE);
    }

    void VirtualMachine::PushOpenApp(std::vector<uint8_t>& code, const std::string& path)
    {
        code.push_back(OPCODE_OPEN_APPLICATION);
        AppendString(code, path);
    }

    void VirtualMachine::PushEndProgram(std::vector<uint8_t>& code) 
    {
        code.push_back(OPCODE_END);
    }

}