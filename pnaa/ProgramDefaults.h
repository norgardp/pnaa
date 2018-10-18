#pragma once
#include "stdafx.h"


namespace genie_defaults
{
	// Directories
	static constexpr TCHAR* directory_data = _T("c:\\genie2k\\camfiles\\");
	static constexpr TCHAR* directory_library = _T("c:\\genie2k\\camfiles\\");
	static constexpr TCHAR* directory_control = _T("c:\\genie2k\\ctlfiles\\");
	static constexpr TCHAR* directory_report = _T("c:\\genie2k\\repfiles\\");

	// File extensions
	static constexpr TCHAR* extension_data = _T("*.cnf");
	static constexpr TCHAR* extension_nuclidelib = _T("*.nlb");
	static constexpr TCHAR* extension_elementlib = _T("*.elb");
	static constexpr TCHAR* extension_analysisseq = _T("*.asf");
	static constexpr TCHAR* extension_report = _T("*.rpt");

	// File filters
	static constexpr TCHAR* filter_data = _T("Configuration Files(*.cnf)|*.cnf|");
	static constexpr TCHAR* filter_nuclidelib = _T("Nuclide Library Files (*.nlb)|*.nlb|");
	static constexpr TCHAR* filter_elementlib = _T("Element Library Files (*.elb)|*.elb|(*.nlb)|*.nlb|");
	static constexpr TCHAR* filter_analysisseq = _T("Analysis Sequence Files (*.asf)|*.asf|");
	static constexpr TCHAR* filter_reporttemplt = _T("Report Template Files (*.tpl)|*.tpl|");

	// Important constants
	static constexpr size_t MAXIMUM_PATH = 250;

}