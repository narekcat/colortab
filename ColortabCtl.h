#if !defined(AFX_COLORTABCTL_H__BC212311_3E8A_4CAE_A189_6E5B5BD23114__INCLUDED_)
#define AFX_COLORTABCTL_H__BC212311_3E8A_4CAE_A189_6E5B5BD23114__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// ColortabCtl.h : Declaration of the CColortabCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CColortabCtrl : See ColortabCtl.cpp for implementation.

const long int cl[48]={RGB(0,0,64),
RGB(0,0,128),
RGB(0,64,255),
RGB(0,128,0),
RGB(0,128,64),
RGB(0,128,128),
RGB(0,128,255),
RGB(0,255,0),
RGB(0,255,64),
RGB(0,255,128),
RGB(0,255,255),
RGB(64,0,0),
RGB(64,0,64),
RGB(64,0,128),
RGB(64,0,255),
RGB(255,64,255),
RGB(255,128,0),
RGB(255,128,64),
RGB(255,128,128),
RGB(255,128,255),
RGB(255,255,0),
RGB(255,255,64),
RGB(255,255,128),
RGB(0,64,64),
RGB(0,64,128),
RGB(128,0,64),
RGB(128,0,128),
RGB(128,0,255),
RGB(128,64,0),
RGB(128,64,64),
RGB(128,64,128),
RGB(128,64,255),
RGB(128,128,0),
RGB(128,128,64),
RGB(128,128,128),
RGB(128,128,255),
RGB(128,255,0),
RGB(128,255,64),
RGB(128,255,128),
RGB(128,255,255),
RGB(255,0,0),
RGB(255,0,64),
RGB(255,0,128),
RGB(255,0,255),
RGB(255,64,0),
RGB(255,64,64),
RGB(255,64,128),
RGB(255,64,255),};

class CColortabCtrl : public COleControl
{
	DECLARE_DYNCREATE(CColortabCtrl)

// Constructor
public:
	CColortabCtrl();
//	void Click(CPoint point);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColortabCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	CBrush br[48];
	long int choocecolor;
	short int y,x;
	CRect rs[48];
	~CColortabCtrl();

	DECLARE_OLECREATE_EX(CColortabCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CColortabCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CColortabCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CColortabCtrl)		// Type name and misc status
	// Message maps
	//{{AFX_MSG(CColortabCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
// Dispatch maps
public:
	//{{AFX_DISPATCH(CColortabCtrl)
	afx_msg long int GetChoocecolor();
	afx_msg void SetChoocecolor(long int nNewValue);
	afx_msg short GetY();
	afx_msg void SetY(short nNewValue);
	afx_msg short GetX();
	afx_msg void SetX(short nNewValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CColortabCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CColortabCtrl)
	dispidChoocecolor = 1L,
	dispidY = 2L,
	dispidX = 3L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORTABCTL_H__BC212311_3E8A_4CAE_A189_6E5B5BD23114__INCLUDED)
