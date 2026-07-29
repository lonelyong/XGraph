#pragma once

#ifdef GLR_LIB
#    ifdef _WIN32
#        define IGL_CORE_API __declspec(dllexport)
#    else
#        define IGL_CORE_API
#    endif
#else
#    ifdef _WIN32
#        define IGL_CORE_API __declspec(dllimport)
#    else
#        define IGL_CORE_API
#    endif
#endif