
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
	ON_BN_CLICKED(IDC_BUTTON_SHORTBACKGND, &CpnaaDlg::OnBnClickedButtonShortbackgnd)
	ON_BN_CLICKED(IDC_BUTTON_LONGBACKGND, &CpnaaDlg::OnBnClickedButtonLongbackgnd)
	ON_BN_CLICKED(IDC_BUTTON_APPENDIRRAD, &CpnaaDlg::OnBnClickedButtonAppendirrad)
	ON_BN_CLICKED(IDC_BUTTON_INSERTIRRAD, &CpnaaDlg::OnBnClickedButtonInsertirrad)
	ON_BN_CLICKED(IDC_BUTTON_REMOVEIRRAD, &CpnaaDlg::OnBnClickedButtonRemoveirrad)
	ON_BN_CLICKED(IDC_BUTTON_REMOVEALLIRRAD, &CpnaaDlg::OnBnClickedButtonRemoveallirrad)
	ON_BN_CLICKED(IDC_BUTTON_ADDDATA, &CpnaaDlg::OnBnClickedButtonAdddata)
	ON_BN_CLICKED(IDC_BUTTON_REMOVEDATA, &CpnaaDlg::OnBnClickedButtonRemovedata)
	ON_BN_CLICKED(IDC_BUTTON_REMOVEALLDATA, &CpnaaDlg::OnBnClickedButtonRemovealldata)
	ON_BN_CLICKED(IDC_BUTTON_ANALYZE, &CpnaaDlg::OnBnClickedButtonAnalyze)
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
	InitializeDirectoryLists();
	InitializeComboBoxValues();

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


void CpnaaDlg::OnBnClickedButtonShortbackgnd()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnBnClickedButtonLongbackgnd()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnBnClickedButtonAppendirrad()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnBnClickedButtonInsertirrad()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnBnClickedButtonRemoveirrad()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnBnClickedButtonRemoveallirrad()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnBnClickedButtonAdddata()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnBnClickedButtonRemovedata()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnBnClickedButtonRemovealldata()
{
	// TODO: Add your control notification handler code here
}


void CpnaaDlg::OnBnClickedButtonAnalyze()
{
	// TODO: Add your control notification handler code here
}


// Generic handling function to load default extension and file filter info. Calls
// a separate function to return a vector of CStrings containing all of the file
// names selected.
std::vector<CString> CpnaaDlg::ReturnFilteredFilename(const camType::FileType file_type)
{
	camType::FileSearchParams params = ReturnFilenameFilteringParams(file_type);
	std::vector<CString> results;

	if (params.directory == genie_defaults::empty_tchar_string)
	{
		// bad file_type supplied to the open-file routine
		// log error to error file
	}
	else
	{
		results = ReturnVectorDirectoryFileListing(params);
	}

	return results;
}


std::vector<CString> CpnaaDlg::ReturnVectorDirectoryFileListing(const camType::FileSearchParams params)
{
	WIN32_FIND_DATA Find_Data;
	HANDLE fdHandle{ INVALID_HANDLE_VALUE };
	std::vector<CString> result;

	CString path = ReturnFilterSearchPathname(params);
	fdHandle = FindFirstFile(path, &Find_Data);
	if (fdHandle == INVALID_HANDLE_VALUE)
	{
		// Log error
	}
	else
	{
		do
		{
			if (Find_Data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				// found a directory; do nothing
			}

			else
			{
				result.push_back(Find_Data.cFileName);
			}

		} while (FindNextFile(fdHandle, &Find_Data) != 0);
	}

	return result;
}


camType::FileSearchParams CpnaaDlg::ReturnFilenameFilteringParams(const camType::FileType file_type)
{
	camType::FileSearchParams filename_defaults;

	switch (file_type)
	{
	case camType::FileType::analysis_sequence:
		filename_defaults.directory = genie_defaults::directory_control;
		filename_defaults.extension = genie_defaults::extension_analysisseq;
		filename_defaults.filter = genie_defaults::filter_analysisseq;
		break;

	case camType::FileType::background:
		filename_defaults.directory = genie_defaults::directory_data;
		filename_defaults.extension = genie_defaults::extension_data;
		filename_defaults.filter = genie_defaults::filter_data;
		break;

	case camType::FileType::data:
		filename_defaults.directory = genie_defaults::directory_data;
		filename_defaults.extension = genie_defaults::extension_data;
		filename_defaults.filter = genie_defaults::filter_data;
		break;

	case camType::FileType::library_element:
		filename_defaults.directory = genie_defaults::directory_library;
		filename_defaults.extension = genie_defaults::extension_elementlib;
		filename_defaults.filter = genie_defaults::filter_elementlib;
		break;

	case camType::FileType::library_element2:
		filename_defaults.directory = genie_defaults::directory_library;
		filename_defaults.extension = genie_defaults::extension_nuclidelib;
		filename_defaults.filter = genie_defaults::filter_elementlib;
		break;

	case camType::FileType::library_nuclide:
		filename_defaults.directory = genie_defaults::directory_library;
		filename_defaults.extension = genie_defaults::extension_nuclidelib;
		filename_defaults.filter = genie_defaults::filter_nuclidelib;
		break;

	case camType::FileType::report:
		filename_defaults.directory = genie_defaults::directory_report;
		filename_defaults.extension = genie_defaults::extension_report;
		filename_defaults.filter = genie_defaults::filter_report;
		break;

	case camType::FileType::report_template:
		filename_defaults.directory = genie_defaults::directory_control;
		filename_defaults.extension = genie_defaults::extension_reporttemplt;
		filename_defaults.filter = genie_defaults::filter_reporttemplt;
		break;

	case camType::FileType::other:
	default:
		filename_defaults.directory = genie_defaults::empty_tchar_string;
		filename_defaults.extension = genie_defaults::empty_tchar_string;
		filename_defaults.filter = genie_defaults::empty_tchar_string;
	}

	return filename_defaults;
}


CString CpnaaDlg::ReturnFilterSearchPathname(const camType::FileSearchParams search_param)
{
	CString return_value;
	if (search_param.directory != genie_defaults::empty_tchar_string)
	{
		CString directory{ search_param.directory };
		CString extension{ search_param.extension };
		return_value = directory + extension;
	}
	return return_value;
}


std::vector<CString> CpnaaDlg::PopulateListboxDirectoryListing(CListBox& list_box, const camType::FileType param)
{
	// Receive the vector list of filenames
	std::vector<CString> dir_listing{ ReturnFilteredFilename(param) };
	
	// Update the UI
	UpdateCListBoxContents(dir_listing, list_box);
	return dir_listing;
}


void CpnaaDlg::InitializeDirectoryLists()
{
	AnalysisListboxDirectoryList = PopulateListboxDirectoryListing(ListBox_AnalysisFiles, camType::FileType::analysis_sequence);
	NuclideLibListboxDirectoryList = PopulateListboxDirectoryListing(ListBox_NulcideLibraries, camType::FileType::library_nuclide);
	ElementLibListboxDirectoryList = PopulateListboxDirectoryListing(ListBox_ElementLibraries, camType::FileType::library_element2);
	DatafileListboxDirectoryList = PopulateListboxDirectoryListing(ListBox_DataFiles, camType::FileType::data);
}


void CpnaaDlg::InitializeComboBoxValues()
{
	CreateComboBoxValues(ComboBox_SampleMassUnit, camType::ComboType::mass_unit);
	CreateComboBoxValues(ComboBox_SampleMaterial, camType::ComboType::sample_material);
	CreateComboBoxValues(ComboBox_SampleForm, camType::ComboType::sample_form);
	CreateComboBoxValues(ComboBox_SampleTreatment, camType::ComboType::measurement_treatment_type);
	CreateComboBoxValues(ComboBox_CountType, camType::ComboType::measurement_count_type);
	CreateComboBoxValues(ComboBox_ShortCountDetector, camType::ComboType::measurement_detector);
	CreateComboBoxValues(ComboBox_LongCountDetector, camType::ComboType::measurement_detector);
	CreateComboBoxValues(ComboBox_OutputReportUnit, camType::ComboType::output_report_units);
}


void CpnaaDlg::CreateComboBoxValues(CComboBox& combo_box, const camType::ComboType combo_type)
{
	switch (combo_type)
	{
	case camType::ComboType::mass_unit:
		combo_box.AddString(_T("g"));
		combo_box.AddString(_T("mg"));
		combo_box.AddString(_T("ug"));
		combo_box.AddString(_T("ng"));
		combo_box.SetCurSel(1);
		break;

	case camType::ComboType::sample_material:
		combo_box.AddString(_T("silicon"));
		combo_box.AddString(_T("boron"));
		combo_box.AddString(_T("quartz"));
		combo_box.AddString(_T("graphite"));
		combo_box.AddString(_T("other"));
		combo_box.SetCurSel(0);
		break;

	case camType::ComboType::sample_form:
		combo_box.AddString(_T("unspecified"));
		combo_box.AddString(_T("rod"));
		combo_box.AddString(_T("sheet"));
		combo_box.AddString(_T("plate"));
		combo_box.AddString(_T("cylinder"));
		combo_box.AddString(_T("chunk"));
		combo_box.AddString(_T("other"));
		combo_box.SetCurSel(0);
		break;

	case camType::ComboType::measurement_treatment_type:
		combo_box.AddString(_T("unspecified"));
		combo_box.AddString(_T("unetched"));
		combo_box.AddString(_T("etched"));
		combo_box.SetCurSel(0);
		break;

	case camType::ComboType::measurement_count_type:
		combo_box.AddString(_T("unspecified")); 
		combo_box.AddString(_T("short count"));
		combo_box.AddString(_T("long count"));
		combo_box.AddString(_T("short and long counts"));
		combo_box.SetCurSel(0);
		break;

	case camType::ComboType::measurement_detector:
		combo_box.AddString(_T("unspecified"));
		combo_box.AddString(_T("rear 1"));
		combo_box.AddString(_T("rear 2"));
		combo_box.AddString(_T("rear 3"));
		combo_box.AddString(_T("rear 4"));
		combo_box.SetCurSel(0);
		break;

	case camType::ComboType::output_report_units:
		combo_box.AddString(_T("pph"));
		combo_box.AddString(_T("ppt"));
		combo_box.AddString(_T("ppm"));
		combo_box.AddString(_T("ppb"));
		combo_box.AddString(_T("ppmb"));
		combo_box.SetCurSel(2);
		break;
	}
}


void CpnaaDlg::RemoveVectorItem(std::vector<CString>& directory_listing, const int selected_item)
{
	int vector_size{ directory_listing.size() };
	if ((selected_item >= 0) && (selected_item <= vector_size))
		directory_listing.erase(directory_listing.begin() + selected_item);
}


void CpnaaDlg::RemoveAllVectorItems(std::vector<CString>& vector_data)
{
	std::vector<CString>().swap(vector_data);
}


void CpnaaDlg::UpdateCListBoxContents(const std::vector<CString>& vector_data, CListBox& list_box)
{
	list_box.ResetContent();
	for (size_t i{ 0 }; i < vector_data.size(); i++)
		list_box.AddString(vector_data.at(i));
}


void CpnaaDlg::AppendVectorItem(std::vector<CString>& vector_data, const CString& item)
{
	if (item.IsEmpty)
	{
		// problem here; should not allow empty CStrings!
	}
	else
	{
		vector_data.push_back(item);
	}
}


void CpnaaDlg::InsertVectorItem(std::vector<CString>& vector_data, const CString& item, const int position)
{
	bool position_exceeds_vector_dimension{ (position > (vector_data.size() + 1)) ? true : false };
	if (position_exceeds_vector_dimension)
	{
		// problem here; should not "insert" data in positions larger than the vector size
	}
	else if(item.IsEmpty)
	{
		// problem here; should not allow empty CString
	}
	else
	{
		// std::vector::insert put the inserted object before the selected position,
		// so add one to put it after
		vector_data.insert(vector_data.begin() + position + 1, item);
	}
}
