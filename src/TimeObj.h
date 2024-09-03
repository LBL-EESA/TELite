///////////////////////////////////////////////////////////////////////////////
///
///	\file    TimeObj.h
///	\author  Paul Ullrich
///	\version April 18, 2018
///
///	<remarks>
///		Copyright 2000- Paul Ullrich
///
///		This file is distributed as part of the Tempest source code package.
///		Permission is granted to use, copy, modify and distribute this
///		source code and its documentation under the terms of the GNU General
///		Public License.  This software is provided "as is" without express
///		or implied warranty.
///	</remarks>
///
///   Amanda Dufek
///   September 03, 2024
///   Removed some functions (IsSameDate, AddTime, SubtractTime, AddSeconds,
///   AddMinutes, AddHours, AddDays, AddMonth, AddYears, RoundToNearestSecond,
///   RoundToNearestMinute, RoundToNearestHour, IsLeapDay, IsLeapYear,
///   DeltaMinutes, DeltaHours, DeltaDays, IsZero, GetZeroIndexedMonth,
///   GetZeroIndexedDay, GetMicroSecond, GetCalendarType, GetTimeType,
///   SetMicroSecond, SetTimeType, ToDateString, ToShortString, ToLongString,
///   ToString, ToFreeString, FromCFCompliantUnitsOffsetInt,
///   FromCFCompliantUnitsOffsetDouble, GetCFCompliantUnitsOffsetDouble),
///   operators (==, !=, >, <=, >=, +=, -=, +, -)


#ifndef _TIMEOBJ_H_
#define _TIMEOBJ_H_

#include "Exception.h"
#include "STLStringHelper.h"

#include <string>
#include <cstdlib>
#include <cmath>

///////////////////////////////////////////////////////////////////////////////

///	<summary>
///		A class for storing a time as year, month, day, seconds and useconds.
///	</summary>
class Time {

public:
	///	<summary>
	///		Type of calendar.
	///	</summary>
	enum CalendarType {
		CalendarUnknown,
		CalendarNone,
		CalendarNoLeap,
		CalendarStandard,
		CalendarGregorian,
		Calendar360Day,
	};

	///	<summary>
	///		Type of time.
	///	</summary>
	enum TimeType {
		TypeFixed,
		TypeDelta
	};

public:
	///	<summary>
	///		Default constructor.
	///	</summary>
	Time(
		CalendarType eCalendarType = CalendarUnknown,
		TimeType eTimeType = TypeFixed
	) :
		m_iYear(0),
		m_iMonth(0),
		m_iDay(0),
		m_iSecond(0),
		m_iMicroSecond(0),
		m_eCalendarType(eCalendarType),
		m_eTimeType(eTimeType)
	{
	}

	///	<summary>
	///		Constructor.
	///	</summary>
	Time(
		int iYear,
		int iMonth,
		int iDay,
		int iSecond,
		int iMicroSecond,
		CalendarType eCalendarType = CalendarNoLeap,
		TimeType eTimeType = TypeFixed
	) :
		m_iYear(iYear),
		m_iMonth(iMonth),
		m_iDay(iDay),
		m_iSecond(iSecond),
		m_iMicroSecond(iMicroSecond),
		m_eCalendarType(eCalendarType),
		m_eTimeType(eTimeType)
	{
		if (m_eCalendarType == CalendarUnknown) {
			_EXCEPTIONT("Invalid CalendarType");
		}
		NormalizeTime();
	}

	///	<summary>
	///		Constructor from std::string.
	///	</summary>
	Time(
		const std::string & strTime,
		CalendarType eCalendarType = CalendarNoLeap,
		TimeType eTimeType = TypeFixed
	) :
		m_iYear(0),
		m_iMonth(0),
		m_iDay(0),
		m_iSecond(0),
		m_iMicroSecond(0),
		m_eCalendarType(eCalendarType),
		m_eTimeType(eTimeType)
	{
		if (m_eCalendarType == CalendarUnknown) {
			_EXCEPTIONT("Invalid CalendarType");
		}
		FromLongString(strTime);
	}

public:
	///	<summary>
	///		Returns the CalendarType associated with the given string.
	///	</summary>
	static CalendarType CalendarTypeFromString(
		const std::string & strCalendar
	) {
		std::string strCalendarTemp = strCalendar;
		STLStringHelper::ToLower(strCalendarTemp);

		if (strCalendarTemp == "none") {
			return CalendarNone;
		} else if (strCalendarTemp == "noleap") {
			return CalendarNoLeap;
		} else if (strCalendarTemp == "365_day"){
			return CalendarNoLeap;
		} else if (strCalendarTemp == "standard") {
			return CalendarStandard;
		} else if (strCalendarTemp == "gregorian") {
			return CalendarGregorian;
		} else if (strCalendarTemp == "proleptic_gregorian") {
			return CalendarGregorian;
		} else if (strCalendarTemp == "360_day") {
			return Calendar360Day;
		} else {
			return CalendarUnknown;
		}
	}

public:
	///	<summary>
	///		Less-than between Times.
	///	</summary>
	bool operator<(const Time & time) const;

protected:
	///	<summary>
	///		Verify that the Time is in accordance with the calendar.
	///	</summary>
	void VerifyTime();

	///	<summary>
	///		Normalize the Time, in accordance with the Calendar.
	///	</summary>
	void NormalizeTime();

public:
	///	<summary>
	///		Calculate the day number for this Time.
	///	</summary>
	int DayNumber() const;

	///	<summary>
	///		Convert a delta time into a number of seconds.
	///	</summary>
	double AsSeconds() const;

	///	<summary>
	///		Determine the number of seconds from this time to the given Time.
	///	</summary>
	double DeltaSeconds(const Time & time) const;

public:
	///	<summary>
	///		Get the year.
	///	</summary>
	inline int GetYear() const {
		return m_iYear;
	}

	///	<summary>
	///		Get the month.
	///	</summary>
	inline int GetMonth() const {
		if ((m_eTimeType == TypeFixed) && (m_eCalendarType != CalendarNone)) {
			return m_iMonth + 1;
		} else {
			return m_iMonth;
		}
	}

	///	<summary>
	///		Get the day.
	///	</summary>
	inline int GetDay() const {
		if ((m_eTimeType == TypeFixed) && (m_eCalendarType != CalendarNone)) {
			return m_iDay + 1;
		} else {
			return m_iDay;
		}
	}

	///	<summary>
	///		Get the number of seconds.
	///	</summary>
	inline int GetSecond() const {
		return m_iSecond;
	}

	///	<summary>
	///		Set the year.
	///	</summary>
	inline void SetYear(int iYear) {
		m_iYear = iYear;
	}

	///	<summary>
	///		Set the month.
	///	</summary>
	inline void SetMonth(int iMonth) {
		if ((m_eTimeType == TypeFixed) && (m_eCalendarType != CalendarNone)) {
			m_iMonth = iMonth - 1;
		} else {
			m_iMonth = iMonth;
		}
	}

	///	<summary>
	///		Set the day.
	///	</summary>
	inline void SetDay(int iDay) {
		if ((m_eTimeType == TypeFixed) && (m_eCalendarType != CalendarNone)) {
			m_iDay = iDay - 1;
		} else {
			m_iDay = iDay;
		}
	}

	///	<summary>
	///		Set the number of seconds.
	///	</summary>
	inline void SetSecond(int iSecond) {
		m_iSecond = iSecond;
	}

public:
	///	<summary>
	///		Set the Time using a long string: "YYYY-MM-DD-SSSSS-UUUUUU"
	///	</summary>
	void FromLongString(const std::string & strLongTime);

	///	<summary>
	///		Set the Time using a formatted string:
	///		- 15h (15 hours)
	///		- 15h30s (15 hours 30 seconds)
	///		- 7y (7 years)
	///		- 1500s (1500 seconds)
	///		- 2y1500u (2 years 1500 microseconds)
	///		- yyyy
	///		- yyyy-MM
	///		- yyyy-MM-dd
	///		- yyyy-MM-dd-sssss
	///		- yyyy-MM-dd-hh:mm:ss.uuuuuu
	///		- HH:MM:SS.UUUU
	///	</summary>
	void FromFormattedString(const std::string & strFormattedTime);

	///	<summary>
	///		Get the name of the calendar.
	///	</summary>
	std::string GetCalendarName() const;

private:
	///	<summary>
	///		The year.
	///	</summary>
	int m_iYear;

	///	<summary>
	///		The month.
	///	</summary>
	int m_iMonth;

	///	<summary>
	///		The day.
	///	</summary>
	int m_iDay;

	///	<summary>
	///		The second count.
	///	</summary>
	int m_iSecond;

	///	<summary>
	///		The microsecond count.
	///	</summary>
	int m_iMicroSecond;

	///	<summary>
	///		Calendar type.
	///	</summary>
	CalendarType m_eCalendarType;

	///	<summary>
	///		Time type.
	///	</summary>
	TimeType m_eTimeType;
};

///////////////////////////////////////////////////////////////////////////////

#endif

