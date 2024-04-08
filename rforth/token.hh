// This header ensures C linkage is enforced when running C++ unit tests on C code.

#ifdef __cplusplus

extern "C" {

#include "token.h"

}

#else

#include "token.h"

#endif
