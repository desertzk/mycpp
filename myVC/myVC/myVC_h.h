

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sat Oct 25 23:07:55 2014
 */
/* Compiler settings for myVC.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
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


#ifndef __myVC_h_h__
#define __myVC_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ImyVC_FWD_DEFINED__
#define __ImyVC_FWD_DEFINED__
typedef interface ImyVC ImyVC;

#endif 	/* __ImyVC_FWD_DEFINED__ */


#ifndef __CmyVCDoc_FWD_DEFINED__
#define __CmyVCDoc_FWD_DEFINED__

#ifdef __cplusplus
typedef class CmyVCDoc CmyVCDoc;
#else
typedef struct CmyVCDoc CmyVCDoc;
#endif /* __cplusplus */

#endif 	/* __CmyVCDoc_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __myVC_LIBRARY_DEFINED__
#define __myVC_LIBRARY_DEFINED__

/* library myVC */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_myVC;

#ifndef __ImyVC_DISPINTERFACE_DEFINED__
#define __ImyVC_DISPINTERFACE_DEFINED__

/* dispinterface ImyVC */
/* [uuid] */ 


EXTERN_C const IID DIID_ImyVC;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("DE938E8F-BDAF-464B-92B4-963184508CA3")
    ImyVC : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ImyVCVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ImyVC * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ImyVC * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ImyVC * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ImyVC * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ImyVC * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ImyVC * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ImyVC * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ImyVCVtbl;

    interface ImyVC
    {
        CONST_VTBL struct ImyVCVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ImyVC_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ImyVC_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ImyVC_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ImyVC_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ImyVC_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ImyVC_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ImyVC_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ImyVC_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CmyVCDoc;

#ifdef __cplusplus

class DECLSPEC_UUID("03FDC533-DE40-4EDE-8E51-688D03DFB74F")
CmyVCDoc;
#endif
#endif /* __myVC_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


