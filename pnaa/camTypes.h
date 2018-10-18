#pragma once


namespace camType
{

	namespace SampleProperty
	{
		enum class MassUnit
		{
			g = 2000,
			mg,
			ug,
			ng,
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

}