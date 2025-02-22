#pragma once

#ifdef VKRENDERER_LIB
#    define VKR_API __declspec(dllexport)
#else
#    define VKR_API __declspec(dllimport)
#endif