#pragma once

// Namespaced enum-classes to better manage property selections.

namespace camType
{
	enum class FileType
	{
		data = 3000,
		library_nuclide,
		library_element,
		library_element2,
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


	struct Irradiation
	{
		CTime irradiation_start;
		CTime irradiation_end;
		LONGLONG irradiation_duration;
	};


	struct DateTimePair
	{
		CDateTimeCtrl start_time;
		CDateTimeCtrl stop_time;
	};

	enum class ComboType
	{
		mass_unit = 3100,
		sample_material,
		sample_form,
		measurement_treatment_type,
		measurement_count_type,
		measurement_detector,
		output_report_units,
		other
	};

	enum class DateTimeMode
	{
		date = 3200,
		time
	};

	enum class DetectorMode
	{
		short_cnt = 3300,
		long_cnt
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