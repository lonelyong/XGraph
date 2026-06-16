#pragma once

#ifdef GLV_LIB
#    define GLV_API __declspec(dllexport)
#else
#    define GLV_API __declspec(dllimport)
#endif