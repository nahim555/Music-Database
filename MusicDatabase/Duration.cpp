#include "Duration.h"
#include <iostream>

Duration::operator int() const {
	return (hours * 3600 + minutes * 60 + seconds);
}

//input stream
std::istream& operator >> (std::istream& in, Duration& d)
{
	char delim;
	int hours, minutes, seconds;

	//read from input stream
	if (in >> hours >> delim >> minutes >> delim >> seconds)
	{
		if (delim == ':')
		{
			d = Duration(hours, minutes, seconds);
		}
		else
		{
			in.clear(std::ios_base::failbit);
		}
	}
	return in;
}
