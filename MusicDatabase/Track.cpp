#include "Track.h"
#include <string>

std::istream& operator >> (std::istream& in, Track& t)
{
	char delim;
	Duration d;
	char title[256];

	//input stream
	if (in >> d >> delim)
	{
		if (delim == '-')
		{
			in.getline(title, 256, '\n');
			string t_title = title;
			t = Track(title, d);
		}
		else
		{
			in.clear(std::ios_base::failbit);
		}
	}
	return in;

}



