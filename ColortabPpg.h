#if !defined(AFX_COLORTABPPG_H__35736CB1_9FF3_4F5B_B541_D968EF999995__INCLUDED_)
#define AFX_COLORTABPPG_H__35736CB1_9FF3_4F5B_B541_D968EF999995__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// ColortabPpg.h : Declaration of the CColortabPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CColortabPropPage : See ColortabPpg.cpp.cpp for implementation.

class CColortabPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CColortabPropPage)
	DECLARE_OLECREATE_EX(CColortabPropPage)

// Constructor
public:
	CColortabPropPage();

// Dialog Data
	//{{AFX_DATA(CColortabPropPage)
	enum { IDD = IDD_PROPPAGE_COLORTAB };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CColortabPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORTABPPG_H__35736CB1_9FF3_4F5B_B541_D968EF999995__INCLUDED)
