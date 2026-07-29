#pragma once

#ifndef XG_RES_ROOT
#    define XG_RES_ROOT res /
#endif

#ifndef XG_MODULE_NAME
#    define XG_MODULE_NAME ""
#endif

#define XG_MOD_RES(m, n) XG_RES_ROOT #m "/" n
#define XG_RES(n) XG_RES_ROOT XG_MODULE_NAME "/" n