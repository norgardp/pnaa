
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
	afx_msg void OnCbnEditchangeComboCounttype();
	afx_msg void OnCbnSelchangeComboShortdetector();
	afx_msg void OnCbnEditchangeComboShortdetector();
	afx_msg void OnCbnSelchangeComboLongdetector();
	afx_msg void OnCbnEditchangeComboLongdetector();
	afx_msg void OnCbnSelchangeComboReportunits();
	afx_msg void OnCbnEditchangeComboReportunits();
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
	CDateTimeCtrl DateTime_IrradiationDuration;
	CDateTimeCtrl DateTime_IrradiationStartDate;
	CDateTimeCtrl DateTime_IrradiationStartTime;
	CEdit EditBox_Analyst;
	CEdit EditBox_Customer;
	CEdit EdtiBox_LongCountBackground;
	CEdit EditBox_FastNeutronFlux;
	CEdit EditBox_NeutronFluxRatio;
	CEdit EditBox_ThermalNeutronFlux;
	CEdit EditBox_SampleMass;
	CEdit EditBox_ShortCountBackground;

	std::vector<CString> AnalysisListboxDirectoryList;
	std::vector<CString> NuclideLibListboxDirectoryList;
	std::vector<CString> ElementLibListboxDirectoryList;
	std::vector<CString> DatafileListboxDirectoryList;

	// Generic handling function used to call a file-open dialog and return the selected string(s) in a vector container
	std::vector<CString> ReturnFilteredFilename(const camType::FileType file_type);
	camType::FileSearchParams ReturnFilenameFilteringParams(const camType::FileType file_type);
	std::vector<CString> ReturnVectorDirectoryFileListing(const camType::FileSearchParams params);
	std::vector<CString> PopulateListboxDirectoryListing(CListBox& list_box, const camType::FileType param);
	void InitializeDirectoryLists();
};
