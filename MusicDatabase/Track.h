
#ifndef TRACK_H
#define TRACK_H

#include "Duration.h"
#include <string>
using namespace std;

class Track {

	string title;
	Duration duration;

public:
	Track(string t_title, Duration t_duration);
	Track();
	Track(const Track& t);
	string getTitle() const;
	Duration getDuration() const;
	void setTitle(string aTitle);
	void setDuration(Duration aDuration);

	Track& operator=(const Track &t)
	{
		if (this != &t)
		{
			title = t.title;
			duration = t.duration;
		}
		return *this;
	}
};


//---- Constructors------//
inline Track::Track()
{
	title = "None";
	duration = Duration();
}

inline Track::Track(string t_title, Duration t_duration)
{
	title = t_title;
	duration = t_duration;
}

inline Track::Track(const Track &t)
{
	title = t.title;
	duration = t.duration;
}

//---- get and set methods

inline string Track::getTitle() const
{
	return title;
}

inline Duration Track::getDuration() const
{
	return duration;
}

inline void Track::setTitle(string aTitle)
{
	title = aTitle;
}

inline void Track::setDuration(Duration aDuration)
{
	duration = aDuration;
}

//----- operator overloading ----//

inline int operator<(const Track& t1, const Track& t2)
{
	return t1.getDuration() < t2.getDuration();
}

inline int operator>(const Track& t1, const Track& t2)
{
	return t1.getDuration() > t2.getDuration();
}

inline int operator>=(const Track& t1, const Track& t2)
{
	return !(t1 < t2);
}
inline int operator<=(const Track& t1, const Track& t2)
{
	return !(t1 > t2);
}

inline bool operator==(const Track& t1, const Track& t2)
{
	return (t1.getTitle() == t2.getTitle() && t1.getDuration() == t2.getDuration());
}

inline bool operator!=(const Track& t1, const Track& t2)
{
	return !(t1 == t2);
}

inline std::ostream& operator<<(std::ostream& out, const Track& t)
{
	// hh:mm:ss
	return out << t.getDuration() << " - " << t.getTitle();
}

std::istream& operator >> (std::istream& in, Track& t);


#endif // TRACK_H
