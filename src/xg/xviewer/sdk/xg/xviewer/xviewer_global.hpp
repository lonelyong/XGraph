#pragma once

#ifdef XVIEWER_LIB
#    define XVIEWER_API __declspec(dllexport)
#else
#    define XVIEWER_API __declspec(dllimport)
#endif