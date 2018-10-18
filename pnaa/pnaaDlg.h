
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

};
