#ifndef DURATION_H
#define DURATION_H

#include <exception>
#include <iomanip>

class Duration
{
	int hours, minutes, seconds;

public:
	Duration(int hours, int minutes, int seconds);
	Duration(int totalSeconds);
	Duration();

	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;

	operator int() const;


};

//default constructor set to 00:00:00
inline Duration::Duration()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}


inline Duration::Duration(int t_hours, int t_minutes, int t_seconds)
{

	int totalSeconds = t_hours * 3600 + t_minutes * 60 + t_seconds; //seconds
	this->hours = totalSeconds / 3600; //hours
	int remain = totalSeconds % 3600;
	this->minutes = remain % 60; // minutes
	remain = remain % 60; //update
	this->seconds = remain; //seconds
};

inline Duration::Duration(int totalSeconds)
{
	if (totalSeconds == 0)
	{
		Duration();
	}
	else {
		hours = totalSeconds / 3600;
		int remain = totalSeconds % 3600;
		minutes = remain / 60;
		remain = remain % 60;
		seconds = remain;
	}
}

//---- get and set methods-----//

inline int Duration::getHours() const {
	return hours;
}

inline int Duration::getMinutes() const {
	return minutes;
}

inline int Duration::getSeconds() const {
	return seconds;
}

//------Operator Overloading--------//
inline std::ostream& operator<<(std::ostream& out, const Duration &a)
{
	// hh:mm:ss
	return out << std::setfill('0') << std::setw(2) << a.getHours() << ":" <<
		std::setfill('0') << std::setw(2) << a.getMinutes() << ":" <<
		std::setfill('0') << std::setw(2) << a.getSeconds();
}

std::istream& operator >> (std::istream& is, Duration& a);

inline bool operator==(const Duration& a1, const Duration& a2) {
	return static_cast<int>(a1) == static_cast<int>(a2);
}

inline bool operator!=(const Duration& a1, const Duration& a2)
{
	return !(a1 == a2);
}

inline int operator-(const Duration& a1, const Duration& a2)
{
	return static_cast<int>(a1) - static_cast<int>(a2);
}

inline int operator+(const Duration& a1, const Duration& a2)
{
	return static_cast<int>(a1) + static_cast<int>(a2);
}



inline int operator<(const Duration& a1, const Duration& a2)
{
	return static_cast<int>(a1) < static_cast<int>(a2);
}

inline int operator>(const Duration& a1, const Duration& a2)
{
	return static_cast<int>(a1) > static_cast<int>(a2);
}

inline int operator<=(const Duration& a1, const Duration& a2)
{
	return !(a1 > a2);
}

inline int operator>=(const Duration& a1, const Duration& a2)
{
	return !(a1 < a2);
}

inline int operator-=(Duration& a1, const Duration& a2)
{
	a1 = Duration(static_cast<int>(a1) - static_cast<int>(a2));
}

#endif // DURATION_H
