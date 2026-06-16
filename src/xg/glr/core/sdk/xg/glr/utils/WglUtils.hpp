#pragma once
#ifdef _WIN32

#    include <glr/glr_global.h>

#    include <Windows.h>

namespace xg {
namespace glutils
{
class GLR_API WglContextManager {
  public:
    static HGLRC CreateByHwnd(HWND hWnd, int major, int minor, int core);

    static HGLRC CreateByBitmap(void** color_buffer, int width, int height, int major, int minor, int core);
};

} // namespace glutils
} // namespace xg

#endif // _WIN32
