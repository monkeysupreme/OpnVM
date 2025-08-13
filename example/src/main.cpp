#include <iostream>
#include "OpnVM/VM.h"

int main(int argc, char** argv) 
{
    auto vm = Opn::NewVM("debug");

    std::vector<uint8_t> code;
    
    vm.PushOpenApp(code, 
        "C:\\Users\\caleb\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Visual Studio Code\\Visual Studio Code.lnk"
    );
    Opn::VirtualMachine::PushEndProgram(code);

    vm.Run(code);
}