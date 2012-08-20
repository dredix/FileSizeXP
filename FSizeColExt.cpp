// FSizeColExt.cpp : Implementation of CFSizeColExt

#include "stdafx.h"
#include "resource.h"
#include "FileSizeXP.h"
#include "FSizeColExt.h"

/////////////////////////////////////////////////////////////////////////////
// CFSizeColExt

STDMETHODIMP CFSizeColExt::GetColumnInfo (
	DWORD dwIndex, SHCOLUMNINFO* psci )
{
	// We have 1 column, so return S_FALSE if dwIndex is not zero.
	if ( dwIndex != 0 )
	return S_FALSE;

	psci->scid.fmtid = CLSID_FSizeColExt;   // Use our CLSID as the format ID
	psci->scid.pid   = 0;                   // Use the column # as the ID
	psci->vt         = VT_LPSTR;				// We'll return the data as a string
	psci->fmt        = LVCFMT_RIGHT;        // Text will be right-aligned
	psci->csFlags    = SHCOLSTATE_TYPE_INT; // Data should be sorted as ints
	psci->cChars     = 10;                  // Default col width in chars
 
	wcsncpy ( psci->wszTitle, L"Size in Bytes", MAX_COLUMN_NAME_LEN );
	wcsncpy ( psci->wszDescription, L"Size in Bytes", MAX_COLUMN_DESC_LEN );
	psci->wszTitle[MAX_COLUMN_NAME_LEN-1] = 0;
	psci->wszDescription[MAX_COLUMN_DESC_LEN-1] = 0;

	return S_OK;
}

STDMETHODIMP CFSizeColExt::GetItemData (
	LPCSHCOLUMNID pscid, LPCSHCOLUMNDATA pscd, VARIANT* pvarData )
{
	USES_CONVERSION;
	LPCTSTR   szFilename = W2CT(pscd->wszFile);
	HANDLE    hfile;
	char      szField[31];
	LARGE_INTEGER liFileSize;


	// Verify that the format id and column numbers are what we expect.
	if ( pscid->fmtid == CLSID_FSizeColExt )
	{
		if ( pscid->pid != 0 )
			return S_FALSE;
	}
	else
		return S_FALSE;

	// If we're being called with a directory (instead of a file), we can
	// bail immediately.
	// Also bail if the file is offline (that is, backed up to tape or some
	// other storage).  
	if ( pscd->dwFileAttributes & (FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_OFFLINE) )
		return S_FALSE;

	// Open the file for read
	hfile = CreateFile ( szFilename, GENERIC_READ, FILE_SHARE_READ,
							NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );

	// Quit if file could not be open
	if ( hfile == INVALID_HANDLE_VALUE )
		return false;

	// Get the file size in bytes
	BOOL fileSizeOk = GetFileSizeEx( hfile, &liFileSize );

	// And close the file handle
	CloseHandle ( hfile );
	
	if ( !fileSizeOk )
		return false;
	
	// Convert the file size to char array with thousands separator
	sprintf_s( szField, 31, "%d\0", liFileSize );
	
	// Create a VARIANT with the details string, and return it back to the shell.
	CComVariant vData ( szField );

	vData.Detach ( pvarData );

	return S_OK;
}
