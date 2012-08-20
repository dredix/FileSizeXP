// FileSizeXP.cpp : Implementation of DLL Exports.


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f FileSizeXPps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "FileSizeXP.h"

#include "FileSizeXP_i.c"
#include "FSizeColExt.h"

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_FSizeColExt, CFSizeColExt)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, hInstance, &LIBID_FILESIZEXPLib);
        DisableThreadLibraryCalls(hInstance);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
        _Module.Term();
    return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow()
{
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer()
{
    // On NT, add our extension to the list of approved extensions.
    if ( 0 == (GetVersion() & 0x80000000) )
        {
        CRegKey reg;
        LONG    lRet;

        lRet = reg.Open ( HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved"),
                          KEY_SET_VALUE );

        if ( ERROR_SUCCESS != lRet )
            return E_ACCESSDENIED;

        lRet = reg.SetValue ( _T("File size column ext"), 
                              _T("{C27E7751-4561-462A-AB14-6835ECF16A28}") );

        reg.Close();

        if ( ERROR_SUCCESS != lRet )
            return E_ACCESSDENIED;
        }

    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer(false);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer()
{
    // On NT, remove our extension from the list of approved extensions.

    if ( 0 == (GetVersion() & 0x80000000) )
        {
        CRegKey reg;
        LONG    lRet;

        lRet = reg.Open ( HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved"),
                          KEY_SET_VALUE );

        if ( ERROR_SUCCESS == lRet )
            {
            reg.DeleteValue ( _T("{C27E7751-4561-462A-AB14-6835ECF16A28}") );
            reg.Close();
            }
        }

    return _Module.UnregisterServer(false);
}
