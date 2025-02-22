#pragma once

#ifdef GLR_LIB
#    define GLR_API __declspec(dllexport)
#else
#    define GLR_API __declspec(dllimport)
#endif