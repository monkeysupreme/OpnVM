#include "OpnVM/VM.h"

#include <iostream>

namespace Opn {

    VirtualMachine NewVM(const std::string& mode)
    {
        VirtualMachine vm = VirtualMachine(mode);
        return vm;
    }

}