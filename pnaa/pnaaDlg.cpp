
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
	DDX_Control(pDX, IDC_DATETIMEPICKER_STARTDATE, DateTime_IrradiationStartDate);
	DDX_Control(pDX, IDC_DATETIMEPICKER_STARTTIME, DateTime_IrradiationStartTime);
	DDX_Control(pDX, IDC_EDIT_ANALYST, EditBox_Analyst);
	DDX_Control(pDX, IDC_EDIT_CUSTOMER, EditBox_Customer);
	DDX_Control(pDX, IDC_EDIT_LONG_BACKGND, EditBox_LongCountBackground);
	DDX_Control(pDX, IDC_EDIT_NEUTRONFAST, EditBox_FastNeutronFlux);
	DDX_Control(pDX, IDC_EDIT_NEUTRONRATIO, EditBox_NeutronFluxRatio);
	DDX_Control(pDX, IDC_EDIT_NEUTRONTHERMAL, EditBox_ThermalNeutronFlux);
	DDX_Control(pDX, IDC_EDIT_SAMPLEMASS, EditBox_SampleMass);
	DDX_Control(pDX, IDC_EDIT_SHORT_BACKGND, EditBox_ShortCountBackground);
	DDX_Control(pDX, IDC_DATETIMEPICKER_STOPDATE, DateTime_IrradiationStopDate);
	DDX_Control(pDX, IDC_DATETIMEPICKER_STOPTIME, DateTime_IrradiationStopTime);
	DDX_Control(pDX, IDC_BUTTON_SHORTBACKGND, Button_ShortBackgroundSelect);
	DDX_Control(pDX, IDC_BUTTON_LONGBACKGND, Button_LongBackgroundSelect);
}

BEGIN_MESSAGE_MAP(CpnaaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_KILLFOCUS(IDC_COMBO_SAMPLEMATERIAL, &CpnaaDlg::OnCbnKillfocusComboSamplematerial)
	ON_CBN_SELCHANGE(IDC_COMBO_COUNTTYPE, &CpnaaDlg::OnCbnSelchangeComboCounttype)
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
	ON_CBN_KILLFOCUS(IDC_COMBO_SAMPLEFORM, &CpnaaDlg::OnCbnKillfocusComboSampleform)
	ON_CBN_KILLFOCUS(IDC_COMBO_SAMPLETREATMENT, &CpnaaDlg::OnCbnKillfocusComboSampletreatment)
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
	InitializeDateTimePickers();
	InitializeCountProperties();
	InitializeWorkingDirectory();

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


void CpnaaDlg::OnCbnSelchangeComboCounttype()
{
	// TODO: Add your control notification handler code here
	int selection{ ComboBox_CountType.GetCurSel() };
	switch (selection)
	{
	case 0:
		// no selection, do nothing
		break;

	case 1:
		// Short count
		EnableCount(camType::DetectorMode::short_cnt);
		DisableCount(camType::DetectorMode::long_cnt);
		break;

	case 2:
		// Long count
		EnableCount(camType::DetectorMode::long_cnt);
		DisableCount(camType::DetectorMode::short_cnt);
		break;

	case 3:
		// Do both
		EnableCount(camType::DetectorMode::short_cnt);
		EnableCount(camType::DetectorMode::long_cnt);
		break;
	}
}


void CpnaaDlg::OnCbnKillfocusComboSamplematerial()
{
	AddToCComboBox(ComboBox_SampleMaterial);
}


void CpnaaDlg::OnCbnKillfocusComboSampleform()
{
	AddToCComboBox(ComboBox_SampleForm);
}


void CpnaaDlg::OnCbnKillfocusComboSampletreatment()
{
	AddToCComboBox(ComboBox_SampleTreatment);
}


void CpnaaDlg::OnBnClickedButtonShortbackgnd()
{
	std::vector<CString> list = ReturnSelectedFiles(camType::FileType::background, camType::FileSelectMode::single);
	if(list.size()!= 0)
		EditBox_ShortCountBackground.SetWindowTextW(list.at(0));
}


void CpnaaDlg::OnBnClickedButtonLongbackgnd()
{
	std::vector<CString> list = ReturnSelectedFiles(camType::FileType::background, camType::FileSelectMode::single);
	if (list.size() != 0)
		EditBox_LongCountBackground.SetWindowTextW(list.at(0));	
}


void CpnaaDlg::OnBnClickedButtonAppendirrad()
{
	camType::Irradiation irrad = CreateIrradiation();
	CString irrad_string = ReturnIrradiationVectorString(irrad);
	AppendVectorItem(IrradiationList, irrad_string);
	UpdateCListBoxContents(IrradiationList, ListBox_Irradiations);
}


void CpnaaDlg::OnBnClickedButtonInsertirrad()
{
	int selected{ ListBox_Irradiations.GetCurSel() };
	if (selected != LB_ERR)
	{
		camType::Irradiation irrad = CreateIrradiation();
		CString irrad_string = ReturnIrradiationVectorString(irrad);
		InsertVectorItem(IrradiationList, irrad_string, selected);
		UpdateCListBoxContents(IrradiationList, ListBox_Irradiations);
	}
}


void CpnaaDlg::OnBnClickedButtonRemoveirrad()
{
	int selected{ ListBox_Irradiations.GetCurSel() };
	if (selected != LB_ERR)
	{
		RemoveVectorItem(IrradiationList, selected);
		UpdateCListBoxContents(IrradiationList, ListBox_Irradiations);
	}
}


void CpnaaDlg::OnBnClickedButtonRemoveallirrad()
{
	RemoveAllVectorItems(IrradiationList);
	UpdateCListBoxContents(IrradiationList, ListBox_Irradiations);
}


void CpnaaDlg::OnBnClickedButtonAdddata()
{
	std::vector<CString> list = ReturnSelectedFiles(camType::FileType::data, camType::FileSelectMode::multiple);
	if (CurrentDataDirectory != PreviousDataDirectory)
	{
		RemoveAllVectorItems(DatafileListboxDirectoryList);
		PreviousDataDirectory = CurrentDataDirectory;
	}
	list = RejectDuplicateVectorItems(DatafileListboxDirectoryList, list);
	DatafileListboxDirectoryList.insert(std::end(DatafileListboxDirectoryList), std::begin(list), std::end(list));
	UpdateCListBoxContents(DatafileListboxDirectoryList, ListBox_DataFiles);
}


void CpnaaDlg::OnBnClickedButtonRemovedata()
{
	int selected{ ListBox_DataFiles.GetCurSel() };
	if (selected != LB_ERR)
	{
		RemoveVectorItem(DatafileListboxDirectoryList, selected);
		UpdateCListBoxContents(DatafileListboxDirectoryList, ListBox_DataFiles);
	}
}


void CpnaaDlg::OnBnClickedButtonRemovealldata()
{
	RemoveAllVectorItems(DatafileListboxDirectoryList);
	UpdateCListBoxContents(DatafileListboxDirectoryList, ListBox_DataFiles);
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


void CpnaaDlg::RemoveVectorItem(std::vector<CString>& vector_data, const size_t selected_item)
{
	size_t vector_size{ vector_data.size() };
	if ((selected_item >= 0) && (selected_item <= vector_size))
		vector_data.erase(vector_data.begin() + selected_item);
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
	if (item.IsEmpty())
	{
		// problem here; should not allow empty CStrings!
	}
	else
	{
		vector_data.push_back(item);
	}
}


void CpnaaDlg::AppendVectorItem(std::vector<CString>& vector_data, const std::vector<CString>& item)
{
	int size_to_add = item.size();
	int size_of_orig = vector_data.size();
	vector_data.reserve(size_of_orig + size_to_add);
	vector_data.insert(std::end(vector_data), std::begin(item), std::end(item));
}


void CpnaaDlg::InsertVectorItem(std::vector<CString>& vector_data, const CString& item, const size_t position)
{
	bool position_exceeds_vector_dimension{ (position > (vector_data.size() + 1)) ? true : false };
	if (position_exceeds_vector_dimension)
	{
		// problem here; should not "insert" data in positions larger than the vector size
	}
	else if(item.IsEmpty())
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


void CpnaaDlg::InitializeDateTimePickers()
{
	CTime default_time(1972, 1, 1, 0, 0, 0);
	DateTime_IrradiationStartTime.SetFormat(genie_defaults::dtp_time_format);
	DateTime_IrradiationStartTime.SetTime(&default_time);
	DateTime_IrradiationStopTime.SetFormat(genie_defaults::dtp_time_format);
	DateTime_IrradiationStopTime.SetTime(&default_time);
}


CTime CpnaaDlg::ReturnCTimeObject(const CDateTimeCtrl& picker_control)
{
	CTime picker_value;
	DWORD dwvalue = picker_control.GetTime(picker_value);
	return (dwvalue != GDT_VALID) ? CTime() : picker_value;
}


CTime CpnaaDlg::ReturnCombinedCTimeObjects(const CTime& date, const CTime& time)
{
	SYSTEMTIME st;
	st.wYear = date.GetYear();
	st.wMonth = date.GetMonth();
	st.wDay = date.GetDay();
	st.wHour = time.GetHour();
	st.wMinute = time.GetHour();
	st.wSecond = time.GetSecond();
	return CTime(st);
}


camType::Irradiation CpnaaDlg::CreateIrradiation()
{
	CTime date, time, start, stop;
	camType::Irradiation irr;

	// Get irradiation start
	date = ReturnCTimeObject(DateTime_IrradiationStartDate);
	time = ReturnCTimeObject(DateTime_IrradiationStartTime);
	start = ReturnCombinedCTimeObjects(date, time);

	// Get irradiation stop
	date = ReturnCTimeObject(DateTime_IrradiationStopDate);
	time = ReturnCTimeObject(DateTime_IrradiationStopTime);
	stop = ReturnCombinedCTimeObjects(date, time);

	// Generate the irradiation
	irr = ReturnIrradiationInstance(start, stop);
	Irradiations.push_back(irr);
	return irr;
}


camType::Irradiation CpnaaDlg::ReturnIrradiationInstance(const CTime& start, const CTime& stop)
{
	camType::Irradiation irr;
	irr.irradiation_start = start;
	irr.irradiation_end = stop;
	CTimeSpan ts = stop - start;
	irr.irradiation_duration = ts.GetTotalSeconds();
	return irr;
}


CString CpnaaDlg::ReturnIrradiationVectorString(const camType::Irradiation vector_item)
{
	CString out_string;
	if (vector_item.irradiation_duration <= 0)
	{
		// error condition: start time happens after stop time
		// generate an error
		out_string.Append(genie_defaults::empty_time_string);
	}
	else
	{
		out_string.Append(vector_item.irradiation_start.Format(genie_defaults::combined_time_format));
		out_string.Append(genie_defaults::empty_time_spacer);
		out_string.Append(vector_item.irradiation_end.Format(genie_defaults::combined_time_format));
	}
	return out_string;
}


void CpnaaDlg::InitializeCountProperties()
{
	EditBox_ShortCountBackground.EnableWindow(FALSE);
	EditBox_ShortCountBackground.SetCueBanner(genie_defaults::empty_background_string);
	ComboBox_ShortCountDetector.EnableWindow(FALSE);
	Button_ShortBackgroundSelect.EnableWindow(FALSE);

	EditBox_LongCountBackground.EnableWindow(FALSE);
	EditBox_LongCountBackground.SetCueBanner(genie_defaults::empty_background_string);
	ComboBox_LongCountDetector.EnableWindow(FALSE);
	Button_LongBackgroundSelect.EnableWindow(FALSE);
}


void CpnaaDlg::EnableCount(const camType::DetectorMode detector)
{
	switch (detector)
	{
	case camType::DetectorMode::short_cnt:
		ComboBox_ShortCountDetector.EnableWindow(TRUE);
		Button_ShortBackgroundSelect.EnableWindow(TRUE);
		EditBox_ShortCountBackground.EnableWindow(TRUE);
		break;

	case camType::DetectorMode::long_cnt:
		ComboBox_LongCountDetector.EnableWindow(TRUE);
		Button_LongBackgroundSelect.EnableWindow(TRUE);
		EditBox_LongCountBackground.EnableWindow(TRUE);
		break;
	}
}


void CpnaaDlg::DisableCount(const camType::DetectorMode detector)
{
	switch (detector)
	{
	case camType::DetectorMode::short_cnt:
		ComboBox_ShortCountDetector.EnableWindow(FALSE);
		Button_ShortBackgroundSelect.EnableWindow(FALSE);
		EditBox_ShortCountBackground.EnableWindow(FALSE);
		break;

	case camType::DetectorMode::long_cnt:
		ComboBox_LongCountDetector.EnableWindow(FALSE);
		Button_LongBackgroundSelect.EnableWindow(FALSE);
		EditBox_LongCountBackground.EnableWindow(FALSE);
		break;
	}
}


CString CpnaaDlg::ReturnCurrentPathname()
{
	TCHAR pathname[MAX_PATH];
	::GetCurrentDirectory(MAX_PATH, pathname);
	return CString(pathname);
}


std::vector<CString> CpnaaDlg::RejectDuplicateVectorItems(const std::vector<CString>& data_vector, const std::vector<CString>& test_vector)
{
	std::vector<CString> loc_data = data_vector;
	std::vector<CString> loc_test = test_vector;
	for (size_t i{ 0 }; i < loc_data.size(); i++)
	{
		for (size_t j{ 0 }; j < loc_test.size(); j++)
		{
			if (loc_data.at(i) == loc_test.at(j))
			{
				loc_test.erase(std::begin(loc_test) + j);
				j--;
			}
		}
	}
	return loc_test;
}


std::vector<CString> CpnaaDlg::ReturnSelectedFiles(const camType::FileType file_type, const camType::FileSelectMode mode)
{
	DWORD mode_flag = SetFileOpenDlgModeFlag(mode);
	camType::FileSearchParams filter_params = ReturnFilenameFilteringParams(file_type);

	CFileDialog dlg(TRUE, filter_params.extension, NULL,
		mode_flag, filter_params.filter, NULL, 0, TRUE);
	std::vector<CString> file_vector;
	if (dlg.DoModal() == IDOK)
	{
		file_vector = VectorizeFileSelections(dlg);
		CurrentDataDirectory = ReturnFilePathName(dlg);
	}
	return file_vector;
}


DWORD CpnaaDlg::SetFileOpenDlgModeFlag(const camType::FileSelectMode custom_mode)
{
	DWORD mode = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
	if (custom_mode == camType::FileSelectMode::multiple)
		mode |= OFN_ALLOWMULTISELECT;
	return mode;
}


std::vector<CString> CpnaaDlg::VectorizeFileSelections(const CFileDialog& file_dialog)
{
	POSITION pos(file_dialog.GetStartPosition());
	CString path;
	std::vector<CString> return_vector;

	while (pos)
	{
		path = file_dialog.GetNextPathName(pos);
		path = ::PathFindFileNameW(path);
		if (IsUniqueVectorEntry(return_vector, path))
		{
			return_vector.push_back(path);
		}
	}
	return return_vector;
}


bool CpnaaDlg::IsUniqueVectorEntry(const std::vector<CString> string_vector, const CString test_string)
{
	bool flag{ true };
	for (size_t i{ 0 }; i < string_vector.size(); i++)
	{
		if (string_vector.at(i) == test_string)
			false;
	}
	return flag;
}


CString CpnaaDlg::ReturnFilePathName(const CFileDialog& file_dialog)
{
	POSITION pos(file_dialog.GetStartPosition());
	CString file_path, folder_path;
	file_path = file_dialog.GetPathName();
	folder_path = file_path.Left(file_path.GetLength() - file_dialog.GetFileName().GetLength());
	return folder_path;
}


void CpnaaDlg::InitializeWorkingDirectory()
{
	::SetCurrentDirectory(genie_defaults::directory_data);
	CurrentDataDirectory = ReturnCurrentPathname();
	PreviousDataDirectory = CurrentDataDirectory;
}


void CpnaaDlg::AddToCComboBox(CComboBox& combo_box)
{
	CString window_text;
	combo_box.GetWindowTextW(window_text);
	int res = combo_box.FindStringExact(-1, window_text);
	if (res == CB_ERR)
	{
		combo_box.AddString(window_text);
	}
}


bool CpnaaDlg::GetCurrentDialogState()
{
	std::vector<bool> result;
	result.push_back(ReadDialog_Edit(EditBox_Analyst));
	result.push_back(ReadDialog_Edit(EditBox_Customer));
	result.push_back(ReadDialog_Edit(EditBox_SampleMass));
	 // STOPPED HERE: 5 Nov 2018
	//  Need to come up with a way to determine which type of count is selected
	return false;
}


bool CpnaaDlg::ReadDialog_Edit(const CEdit& edit_box)
{
	CString item;
	edit_box.GetWindowTextW(item);
	return (item.IsEmpty()) ? false : true;
}


bool CpnaaDlg::ReadDialog_ComboBox(const CComboBox& combo_item)
{
	CString item;
	combo_item.GetWindowTextW(item);
	return (item == _T("unspecified")) ? false : true;
}


bool CpnaaDlg::ReadDialog_ListBox(const CListBox& list_item)
{
	int count = list_item.GetCount();
	return (count == 0 || count == LB_ERR) ? false : true;
}
