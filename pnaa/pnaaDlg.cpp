
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

