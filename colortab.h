#if !defined(AFX_COLORTAB_H__C168046F_4E86_4E75_AB9A_F02262ABED8B__INCLUDED_)
#define AFX_COLORTAB_H__C168046F_4E86_4E75_AB9A_F02262ABED8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// colortab.h : main header file for COLORTAB.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CColortabApp : See colortab.cpp for implementation.

class CColortabApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORTAB_H__C168046F_4E86_4E75_AB9A_F02262ABED8B__INCLUDED)
