#pragma once

// Namespaced enum-classes to better manage property selections.

namespace camType
{
	enum class FileType
	{
		data = 3000,
		library_nuclide,
		library_element,
		report_template,
		report,
		analysis_sequence,
		background,
		other
	};

	struct FileSearchParams
	{
		TCHAR* directory;
		TCHAR* extension;
		TCHAR* filter;
	};

	namespace SampleProperty
	{
		enum class MassUnit
		{
			g = 2000,		// gram
			mg,				// milligram
			ug,				// microgram
			ng,				// nanogram
			other
		};

		enum class Material
		{
			silicon = 2100,
			boron,
			quartz,
			graphite,
			other
		};

		enum class Form
		{
			rod = 2200,
			sheet,
			plate,
			cylinder,
			chunk,
			other
		};
	}

	namespace MeasurementProperty
	{
		enum class TreatmentType
		{
			etched = 2300,
			unetched,
			unspecified,
			other
		};

		enum class CountType
		{
			short_count = 2400,
			long_count,
			both_counts,
			other
		};

		enum class Detector
		{
			rear_1 = 2500,
			rear_2,
			rear_3,
			rear_4,
			other
		};
	}

	namespace OutputProperty
	{
		enum class ReportUnits
		{
			pph = 2600,		// parts per hundred
			ppt,			//           thousand
			ppm,			//           million
			ppb,			//           billion
			ppmb,			//           trillion
			other
		};
	}

}