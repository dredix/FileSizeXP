// FSizeColExt.h : Declaration of the CFSizeColExt

#ifndef __FSIZECOLEXT_H_
#define __FSIZECOLEXT_H_

/////////////////////////////////////////////////////////////////////////////
// CFSizeColExt

class ATL_NO_VTABLE CFSizeColExt :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFSizeColExt, &CLSID_FSizeColExt>,
	public IColumnProvider
{
public:
	CFSizeColExt() { }

	BEGIN_COM_MAP(CFSizeColExt)
		COM_INTERFACE_ENTRY_IID(IID_IColumnProvider, IColumnProvider)
	END_COM_MAP()

	DECLARE_REGISTRY_RESOURCEID(IDR_FSIZECOLEXT)

public:

	// IColumnProvider 
public:
	STDMETHODIMP Initialize(LPCSHCOLUMNINIT psci) { return S_OK; }
	STDMETHODIMP GetColumnInfo(DWORD dwIndex, SHCOLUMNINFO* psci);
	STDMETHODIMP GetItemData(LPCSHCOLUMNID pscid, LPCSHCOLUMNDATA pscd, VARIANT* pvarData);

};

#endif //__FSIZECOLEXT_H_
