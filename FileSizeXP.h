

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Aug 20 16:21:38 2012
 */
/* Compiler settings for FileSizeXP.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __FileSizeXP_h__
#define __FileSizeXP_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFSizeColExt_FWD_DEFINED__
#define __IFSizeColExt_FWD_DEFINED__
typedef interface IFSizeColExt IFSizeColExt;
#endif 	/* __IFSizeColExt_FWD_DEFINED__ */


#ifndef __FSizeColExt_FWD_DEFINED__
#define __FSizeColExt_FWD_DEFINED__

#ifdef __cplusplus
typedef class FSizeColExt FSizeColExt;
#else
typedef struct FSizeColExt FSizeColExt;
#endif /* __cplusplus */

#endif 	/* __FSizeColExt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IFSizeColExt_INTERFACE_DEFINED__
#define __IFSizeColExt_INTERFACE_DEFINED__

/* interface IFSizeColExt */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFSizeColExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("27C64FD2-8F75-48CF-BFF9-59A981E7A339")
    IFSizeColExt : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IFSizeColExtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFSizeColExt * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFSizeColExt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFSizeColExt * This);
        
        END_INTERFACE
    } IFSizeColExtVtbl;

    interface IFSizeColExt
    {
        CONST_VTBL struct IFSizeColExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFSizeColExt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFSizeColExt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFSizeColExt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFSizeColExt_INTERFACE_DEFINED__ */



#ifndef __FILESIZEXPLib_LIBRARY_DEFINED__
#define __FILESIZEXPLib_LIBRARY_DEFINED__

/* library FILESIZEXPLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_FILESIZEXPLib;

EXTERN_C const CLSID CLSID_FSizeColExt;

#ifdef __cplusplus

class DECLSPEC_UUID("C27E7751-4561-462A-AB14-6835ECF16A28")
FSizeColExt;
#endif
#endif /* __FILESIZEXPLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


