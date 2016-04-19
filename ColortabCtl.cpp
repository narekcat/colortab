// ColortabCtl.cpp : Implementation of the CColortabCtrl ActiveX Control class.

#include "stdafx.h"
#include "colortab.h"
#include "ColortabCtl.h"
#include "ColortabPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CColortabCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CColortabCtrl, COleControl)
	//{{AFX_MSG_MAP(CColortabCtrl)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CColortabCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CColortabCtrl)
	DISP_PROPERTY_EX(CColortabCtrl, "choocecolor", GetChoocecolor, SetChoocecolor, VT_I4)
	DISP_PROPERTY_EX(CColortabCtrl, "y", GetY, SetY, VT_I2)
	DISP_PROPERTY_EX(CColortabCtrl, "x", GetX, SetX, VT_I2)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CColortabCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CColortabCtrl, COleControl)
	//{{AFX_EVENT_MAP(CColortabCtrl)
	EVENT_STOCK_CLICK()
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CColortabCtrl, 1)
	PROPPAGEID(CColortabPropPage::guid)
END_PROPPAGEIDS(CColortabCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CColortabCtrl, "COLORTAB.ColortabCtrl.1",
	0xcb4a96a8, 0x611e, 0x45dc, 0xa5, 0x1b, 0xee, 0xa0, 0xa7, 0xfd, 0xee, 0x9e)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CColortabCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DColortab =
		{ 0x5d7f527b, 0xa1f1, 0x4c05, { 0x97, 0xa1, 0x8c, 0x39, 0xc, 0x44, 0x9b, 0xd8 } };
const IID BASED_CODE IID_DColortabEvents =
		{ 0xd2a15ebf, 0xd2bf, 0x45ba, { 0x80, 0xe1, 0xbf, 0x26, 0x6, 0x50, 0x7b, 0x1e } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwColortabOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CColortabCtrl, IDS_COLORTAB, _dwColortabOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CColortabCtrl::CColortabCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CColortabCtrl

BOOL CColortabCtrl::CColortabCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_COLORTAB,
			IDB_COLORTAB,
			afxRegApartmentThreading,
			_dwColortabOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CColortabCtrl::CColortabCtrl - Constructor

CColortabCtrl::CColortabCtrl()
{
	InitializeIIDs(&IID_DColortab, &IID_DColortabEvents);
	choocecolor=cl[0];
	for(int i=0;i<48;i++)
		br[i].CreateSolidBrush(cl[i]);
	y=1;
	x=1;
}


/////////////////////////////////////////////////////////////////////////////
// CColortabCtrl::~CColortabCtrl - Destructor

CColortabCtrl::~CColortabCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CColortabCtrl::OnDraw - Drawing function

void CColortabCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	long w=rcBounds.Width()/8,h=rcBounds.Height()/6;
	int i,j;
	for(i=0;i<6;i++)
		for(j=0;j<8;j++)
			rs[i*8+j]=CRect(j*w+2,i*h+2,(j+1)*w,(i+1)*h);
	for(i=0;i<48;i++)
		pdc->FillRect(rs[i],&br[i]);	
}


/////////////////////////////////////////////////////////////////////////////
// CColortabCtrl::DoPropExchange - Persistence support

void CColortabCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CColortabCtrl::OnResetState - Reset control to default state

void CColortabCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CColortabCtrl::AboutBox - Display an "About" box to the user

void CColortabCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_COLORTAB);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CColortabCtrl message handlers

long int CColortabCtrl::GetChoocecolor() 
{
	// TODO: Add your property handler here

	return choocecolor;
}

void CColortabCtrl::SetChoocecolor(long int nNewValue) 
{
	// TODO: Add your property handler here
	choocecolor=nNewValue;
	SetModifiedFlag();
}

void CColortabCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	FireClick();
	for(int i=0;i<48;i++)
		if(rs[i].PtInRect(point))
		{
			choocecolor=cl[i];
			break;
		}
	y=i/8+1;
	x=i%8+1;
	COleControl::OnLButtonDown(nFlags, point);
}

short CColortabCtrl::GetY() 
{
	// TODO: Add your property handler here

	return y;
}

void CColortabCtrl::SetY(short nNewValue) 
{
	// TODO: Add your property handler here
	y=nNewValue;
	SetModifiedFlag();
}

short CColortabCtrl::GetX() 
{
	// TODO: Add your property handler here
	
	return x;
}

void CColortabCtrl::SetX(short nNewValue) 
{
	// TODO: Add your property handler here
	x=nNewValue;
	SetModifiedFlag();
}
