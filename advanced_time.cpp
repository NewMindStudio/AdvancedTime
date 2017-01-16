#include "string"
#include "iostream"

#include "advanced_time.h"

/*
	Advanced Time
	Wrote by Edward Alexander, August 14, 2016.
	1.0

	Determine which day of the week a date falls on.
	For more information: https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
*/

namespace advanced_time
{

	///Get date details
	namespace check_day
	{
		
		///Gets the month code, version 2.0
		int get_month_code_new(int _month)
		{
			int months_codes[12] = { 0,3,3,6,1,4,6,2,5,0,3,5 };
			
			return months_codes[_month - 1];
		}

		///Gets the century code, version 2.0
		int get_century_code_new(int _year)
		{
			return 6 - 2 * ((_year / 100) % 4);
		}

		///Days of the week
		std::string days_of_week[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

		///Gets the day of the week as a string
		std::string advanced_time::check_day::time::get_day_of_week(int _month, int _day, int _year)
		{
			///Fix for leap years, as only January and February have a different code
			if ((_year & 3) == 0 && ((_year % 25) != 0 || (_year & 15) == 0))
			{
				if (_month == 1)
					_month = 4;
				else if (_month == 2)
					_month = 8;
			}

			///Gets the month code
			_month = get_month_code_new(_month);

			///Gets the century code
			int _century = get_century_code_new(_year);

			///Gets only the last two digits from the year
			_year %= 100;

			///Returns the day of the week based on : Day + Month (Code) + Year (Last two digits) + Year (Last two digits) / 4 + Century
			return days_of_week[(_day + _month + _year + _year / 4 + _century) % 7];
		}

		int advanced_time::check_day::time::get_day_of_week_new(int _month, int _day, int _year)
		{
			///Months codes
			int months_codes[12] = { 0,3,3,6,1,4,6,2,5,0,3,5 };

			///Fix for leap years, as only January and February have a different code
			if (_year % 4 == 0 && _year % 100 != 0 || _year % 400 == 0)
			{
				if (_month == 1)
					_month = 4;
				else if (_month == 2)
					_month = 8;
			}

			///Returns the day of the week based on : Day + Month (Code) + Year (Last two digits) + Year (Last two digits) / 4 + Century
			return (_day + months_codes[_month - 1] + _year % 100 + (_year % 100) / 4 + 6 - 2 * ((_year / 100) % 4)) % 7;
		}

	}

}