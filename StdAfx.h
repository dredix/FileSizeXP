// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__2E855542_6BBC_4291_8DC2_9B9B2D1C2A7B__INCLUDED_)
#define AFX_STDAFX_H__2E855542_6BBC_4291_8DC2_9B9B2D1C2A7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WINVER       0x0500     // W2K/98
#define _WIN32_WINNT 0x0500     // W2K
#define _WIN32_IE    0x0500     // IE 5+
#define _ATL_APARTMENT_THREADED

// ATL
#include <atlbase.h>
extern CComModule _Module;
#include <atlcom.h>
#include <atlconv.h>

// STL
#include <string>
#include <list>
typedef std::basic_string<TCHAR> tstring;   // a TCHAR string

// Win32
#include <shlwapi.h>
#include <comdef.h>
#include <shlobj.h>
#include <shlguid.h>

// IO manipulation
#include <iostream>
#include <locale>
#include <sstream>

#define countof(x) (sizeof(x)/sizeof((x)[0]))

#ifdef DEFAULT_UNREACHABLE
#undef DEFAULT_UNREACHABLE  // nuke the lame MS version
#endif
#ifndef _DEBUG
    #if _MSC_VER > 1100
        #define DEFAULT_UNREACHABLE default: __assume(0); break
    #else
        #define DEFAULT_UNREACHABLE default: break
    #endif
#elif defined(ASSERT)
#define DEFAULT_UNREACHABLE default: ASSERT(0); break   // use MFC assert
#else
#define DEFAULT_UNREACHABLE default: _ASSERTE(0); break // use CRT assert
#endif

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__2E855542_6BBC_4291_8DC2_9B9B2D1C2A7B__INCLUDED)
