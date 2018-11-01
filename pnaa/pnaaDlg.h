
// pnaaDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxdtctl.h"

// Standard libaries
#include <vector>

// Local includes
#include "ProgramDefaults.h"
#include "camTypes.h"

// CpnaaDlg dialog
class CpnaaDlg : public CDialogEx
{
	// Construction
public:
	CpnaaDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PNAA_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEnKillfocusEditAnalyst();
	afx_msg void OnEnKillfocusEditCustomer();
	afx_msg void OnEnKillfocusEditSamplemass();
	afx_msg void OnEnKillfocusEditNeutronthermal();
	afx_msg void OnEnKillfocusEditNeutronratio();
	afx_msg void OnEnKillfocusEditNeutronfast();
	afx_msg void OnCbnSelchangeComboMassunit();
	afx_msg void OnCbnEditchangeComboMassunit();
	afx_msg void OnCbnSelchangeComboSamplematerial();
	afx_msg void OnCbnEditchangeComboSamplematerial();
	afx_msg void OnCbnSelchangeComboSampleform();
	afx_msg void OnCbnEditchangeComboSampleform();
	afx_msg void OnCbnSelchangeComboSampletreatment();
	afx_msg void OnCbnEditchangeComboSampletreatment();
	afx_msg void OnCbnSelchangeComboCounttype();
	afx_msg void OnCbnSelchangeComboShortdetector();
	afx_msg void OnCbnSelchangeComboLongdetector();
	afx_msg void OnCbnSelchangeComboReportunits();
	afx_msg void OnBnClickedButtonShortbackgnd();
	afx_msg void OnBnClickedButtonLongbackgnd();
	afx_msg void OnBnClickedButtonAppendirrad();
	afx_msg void OnBnClickedButtonInsertirrad();
	afx_msg void OnBnClickedButtonRemoveirrad();
	afx_msg void OnBnClickedButtonRemoveallirrad();
	afx_msg void OnBnClickedButtonAdddata();
	afx_msg void OnBnClickedButtonRemovedata();
	afx_msg void OnBnClickedButtonRemovealldata();
	afx_msg void OnBnClickedButtonAnalyze();
	DECLARE_MESSAGE_MAP()

private:
	CListBox ListBox_AnalysisFiles;
	CListBox ListBox_DataFiles;
	CListBox ListBox_ElementLibraries;
	CListBox ListBox_NulcideLibraries;
	CListBox ListBox_Irradiations;
	CComboBox ComboBox_CountType;
	CComboBox ComboBox_LongCountDetector;
	CComboBox ComboBox_SampleMassUnit;
	CComboBox ComboBox_OutputReportUnit;
	CComboBox ComboBox_SampleForm;
	CComboBox ComboBox_SampleMaterial;
	CComboBox ComboBox_SampleTreatment;
	CComboBox ComboBox_ShortCountDetector;
	CDateTimeCtrl DateTime_IrradiationStartDate;
	CDateTimeCtrl DateTime_IrradiationStartTime;
	CDateTimeCtrl DateTime_IrradiationStopDate;
	CDateTimeCtrl DateTime_IrradiationStopTime;
	CEdit EditBox_Analyst;
	CEdit EditBox_Customer;
	CEdit EditBox_LongCountBackground;
	CEdit EditBox_FastNeutronFlux;
	CEdit EditBox_NeutronFluxRatio;
	CEdit EditBox_ThermalNeutronFlux;
	CEdit EditBox_SampleMass;
	CEdit EditBox_ShortCountBackground;
	CButton Button_ShortBackgroundSelect;
	CButton Button_LongBackgroundSelect;

	std::vector<camType::Irradiation> Irradiations;
	std::vector<CString> IrradiationList;
	std::vector<CString> AnalysisListboxDirectoryList;
	std::vector<CString> NuclideLibListboxDirectoryList;
	std::vector<CString> ElementLibListboxDirectoryList;
	std::vector<CString> DatafileListboxDirectoryList;

	// Generic handling function used to return a directory listing into a vector
	// container; also populates the associated ListBoxes on the dialog.
	std::vector<CString> ReturnFilteredFilename(const camType::FileType file_type);
	camType::FileSearchParams ReturnFilenameFilteringParams(const camType::FileType file_type);
	std::vector<CString> ReturnVectorDirectoryFileListing(const camType::FileSearchParams params);
	std::vector<CString> PopulateListboxDirectoryListing(CListBox& list_box, const camType::FileType param);
	CString ReturnFilterSearchPathname(const camType::FileSearchParams search_param);
	void RemoveVectorItem(std::vector<CString>& directory_listing, const size_t selected_item);
	void RemoveAllVectorItems(std::vector<CString>& vector_data);
	void UpdateCListBoxContents(const std::vector<CString>& vector_data, CListBox& list_box);
	void AppendVectorItem(std::vector<CString>& vector_data, const CString& item);
	void AppendVectorItem(std::vector<CString>& vector_data, const std::vector<CString>& item);
	void InsertVectorItem(std::vector<CString>& vector_data, const CString& item, const size_t position);

	void InitializeDirectoryLists();
	void InitializeComboBoxValues();
	void InitializeDateTimePickers();
	void InitializeCountProperties();

	void CreateComboBoxValues(CComboBox& combo_box, const camType::ComboType combo_type);

	camType::Irradiation CreateIrradiation();
	CTime ReturnCTimeObject(const CDateTimeCtrl& picker_control);
	CTime ReturnCombinedCTimeObjects(const CTime& date, const CTime& time);
	camType::Irradiation ReturnIrradiationInstance(const CTime& start, const CTime& stop);
	CString ReturnIrradiationVectorString(const camType::Irradiation vector_item);

	void EnableCount(const camType::DetectorMode detector);
	void DisableCount(const camType::DetectorMode detector);
	std::vector<CString> ReturnSelectedFiles(const camType::FileType file_type, const camType::FileSelectMode mode);
	DWORD SetFileOpenDlgModeFlag(const camType::FileSelectMode custom_mode);
	std::vector<CString> VectorizeFileSelections(const CFileDialog& file_dialog);
	bool IsUniqueVectorEntry(const std::vector<CString> string_vector, const CString test_string);
	TCHAR* ReturnFilePathName(const CFileDialog& file_dialog);
};
