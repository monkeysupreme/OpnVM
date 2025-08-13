#pragma once

#include <string>
#include "Machine.h"
#include "OpCode.h"

namespace Opn {

    VirtualMachine NewVM(const std::string& mode);

}