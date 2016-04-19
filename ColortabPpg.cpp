// ColortabPpg.cpp : Implementation of the CColortabPropPage property page class.

#include "stdafx.h"
#include "colortab.h"
#include "ColortabPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CColortabPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CColortabPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CColortabPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CColortabPropPage, "COLORTAB.ColortabPropPage.1",
	0x11a4494b, 0x8e9a, 0x4052, 0xaa, 0x4d, 0x49, 0xbc, 0x4e, 0xf3, 0x5c, 0x62)


/////////////////////////////////////////////////////////////////////////////
// CColortabPropPage::CColortabPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CColortabPropPage

BOOL CColortabPropPage::CColortabPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_COLORTAB_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CColortabPropPage::CColortabPropPage - Constructor

CColortabPropPage::CColortabPropPage() :
	COlePropertyPage(IDD, IDS_COLORTAB_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CColortabPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CColortabPropPage::DoDataExchange - Moves data between page and properties

void CColortabPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CColortabPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CColortabPropPage message handlers
