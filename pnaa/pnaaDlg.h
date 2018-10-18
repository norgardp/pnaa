
// pnaaDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxdtctl.h"


#include "ProgramDefaults.h"

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

public:
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
};
