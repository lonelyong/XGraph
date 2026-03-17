#pragma once

#ifdef GLR_LIB
#    ifdef _WIN32
#        define GLR_API __declspec(dllexport)
#    else
#        define GLR_API
#    endif
#else
#    ifdef _WIN32
#        define GLR_API __declspec(dllimport)
#    else
#        define GLR_API
#    endif
#endif