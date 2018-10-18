
// pnaaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "pnaa.h"
#include "pnaaDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CpnaaDlg dialog



CpnaaDlg::CpnaaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PNAA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CpnaaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_ANALYSISFILE, ListBox_AnalysisFiles);
	DDX_Control(pDX, IDC_LIST_DATAFILES, ListBox_DataFiles);
	DDX_Control(pDX, IDC_LIST_ELEMENTFILE, ListBox_ElementLibraries);
	DDX_Control(pDX, IDC_LIST_NUCLIDEFILE, ListBox_NulcideLibraries);
	DDX_Control(pDX, IDC_LIST_IRRADIATIONS, ListBox_Irradiations);
	DDX_Control(pDX, IDC_COMBO_COUNTTYPE, ComboBox_CountType);
	DDX_Control(pDX, IDC_COMBO_LONGDETECTOR, ComboBox_LongCountDetector);
	DDX_Control(pDX, IDC_COMBO_MASSUNIT, ComboBox_SampleMassUnit);
	DDX_Control(pDX, IDC_COMBO_REPORTUNITS, ComboBox_OutputReportUnit);
	DDX_Control(pDX, IDC_COMBO_SAMPLEFORM, ComboBox_SampleForm);
	DDX_Control(pDX, IDC_COMBO_SAMPLEMATERIAL, ComboBox_SampleMaterial);
	DDX_Control(pDX, IDC_COMBO_SAMPLETREATMENT, ComboBox_SampleTreatment);
	DDX_Control(pDX, IDC_COMBO_SHORTDETECTOR, ComboBox_ShortCountDetector);
	DDX_Control(pDX, IDC_DATETIMEPICKER_DURATION, DateTime_IrradiationDuration);
	DDX_Control(pDX, IDC_DATETIMEPICKER_STARTDATE, DateTime_IrradiationStartDate);
	DDX_Control(pDX, IDC_DATETIMEPICKER_STARTTIME, DateTime_IrradiationStartTime);
	DDX_Control(pDX, IDC_EDIT_ANALYST, EditBox_Analyst);
	DDX_Control(pDX, IDC_EDIT_CUSTOMER, EditBox_Customer);
	DDX_Control(pDX, IDC_EDIT_LONG_BACKGND, EdtiBox_LongCountBackground);
	DDX_Control(pDX, IDC_EDIT_NEUTRONFAST, EditBox_FastNeutronFlux);
	DDX_Control(pDX, IDC_EDIT_NEUTRONRATIO, EditBox_NeutronFluxRatio);
	DDX_Control(pDX, IDC_EDIT_NEUTRONTHERMAL, EditBox_ThermalNeutronFlux);
	DDX_Control(pDX, IDC_EDIT_SAMPLEMASS, EditBox_SampleMass);
	DDX_Control(pDX, IDC_EDIT_SHORT_BACKGND, EditBox_ShortCountBackground);
}

BEGIN_MESSAGE_MAP(CpnaaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_KILLFOCUS(IDC_EDIT_ANALYST, &CpnaaDlg::OnEnKillfocusEditAnalyst)
	ON_EN_KILLFOCUS(IDC_EDIT_CUSTOMER, &CpnaaDlg::OnEnKillfocusEditCustomer)
	ON_EN_KILLFOCUS(IDC_EDIT_SAMPLEMASS, &CpnaaDlg::OnEnKillfocusEditSamplemass)
	ON_EN_KILLFOCUS(IDC_EDIT_NEUTRONTHERMAL, &CpnaaDlg::OnEnKillfocusEditNeutronthermal)
	ON_EN_KILLFOCUS(IDC_EDIT_NEUTRONRATIO, &CpnaaDlg::OnEnKillfocusEditNeutronratio)
	ON_EN_KILLFOCUS(IDC_EDIT_NEUTRONFAST, &CpnaaDlg::OnEnKillfocusEditNeutronfast)
	ON_CBN_SELCHANGE(IDC_COMBO_MASSUNIT, &CpnaaDlg::OnCbnSelchangeComboMassunit)
	ON_CBN_EDITCHANGE(IDC_COMBO_MASSUNIT, &CpnaaDlg::OnCbnEditchangeComboMassunit)
	ON_CBN_SELCHANGE(IDC_COMBO_SAMPLEMATERIAL, &CpnaaDlg::OnCbnSelchangeComboSamplematerial)
	ON_CBN_EDITCHANGE(IDC_COMBO_SAMPLEMATERIAL, &CpnaaDlg::OnCbnEditchangeComboSamplematerial)
	ON_CBN_SELCHANGE(IDC_COMBO_SAMPLEFORM, &CpnaaDlg::OnCbnSelchangeComboSampleform)
	ON_CBN_EDITCHANGE(IDC_COMBO_SAMPLEFORM, &CpnaaDlg::OnCbnEditchangeComboSampleform)
	ON_CBN_SELCHANGE(IDC_COMBO_SAMPLETREATMENT, &CpnaaDlg::OnCbnSelchangeComboSampletreatment)
	ON_CBN_EDITCHANGE(IDC_COMBO_SAMPLETREATMENT, &CpnaaDlg::OnCbnEditchangeComboSampletreatment)
	ON_CBN_SELCHANGE(IDC_COMBO_COUNTTYPE, &CpnaaDlg::OnCbnSelchangeComboCounttype)
	ON_CBN_EDITCHANGE(IDC_COMBO_COUNTTYPE, &CpnaaDlg::OnCbnEditchangeComboCounttype)
	ON_CBN_SELCHANGE(IDC_COMBO_SHORTDETECTOR, &CpnaaDlg::OnCbnSelchangeComboShortdetector)
	ON_CBN_EDITCHANGE(IDC_COMBO_SHORTDETECTOR, &CpnaaDlg::OnCbnEditchangeComboShortdetector)
	ON_CBN_SELCHANGE(IDC_COMBO_LONGDETECTOR, &CpnaaDlg::OnCbnSelchangeComboLongdetector)
	ON_CBN_EDITCHANGE(IDC_COMBO_LONGDETECTOR, &CpnaaDlg::OnCbnEditchangeComboLongdetector)
	ON_CBN_SELCHANGE(IDC_COMBO_REPORTUNITS, &CpnaaDlg::OnCbnSelchangeComboReportunits)
	ON_CBN_EDITCHANGE(IDC_COMBO_REPORTUNITS, &CpnaaDlg::OnCbnEditchangeComboReportunits)
END_MESSAGE_MAP()


// CpnaaDlg message handlers

BOOL CpnaaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CpnaaDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CpnaaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CpnaaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CpnaaDlg::OnEnKillfocusEditAnalyst()
{
	// TODO: Add your control notification handler code here
}



void CpnaaDlg::OnEnKillfocusEditCustomer()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnEnKillfocusEditSamplemass()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnEnKillfocusEditNeutronthermal()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnEnKillfocusEditNeutronratio()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnEnKillfocusEditNeutronfast()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnSelchangeComboMassunit()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnEditchangeComboMassunit()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnSelchangeComboSamplematerial()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnEditchangeComboSamplematerial()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnSelchangeComboSampleform()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnEditchangeComboSampleform()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnSelchangeComboSampletreatment()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnEditchangeComboSampletreatment()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnSelchangeComboCounttype()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnEditchangeComboCounttype()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnSelchangeComboShortdetector()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnEditchangeComboShortdetector()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnSelchangeComboLongdetector()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnEditchangeComboLongdetector()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnSelchangeComboReportunits()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnCbnEditchangeComboReportunits()
{
	// TODO: Add your control notification handler code here
}
