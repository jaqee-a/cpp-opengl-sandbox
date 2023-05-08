#pragma once






#include "sandbox/decl.h"
#include <cstdlib>
#include <stdio.h>

namespace Sandbox {
    inline uuid_t GenUUID() {
        return rand() % RAND_MAX;
    }
}
