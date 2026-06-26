#pragma once

#include <vine/vi_global.hpp>

#ifdef XVIEWER_LIB
#    define XVIEWER_API V_EXPORT
#else
#    define XVIEWER_API V_IMPORT
#endif