#include "Album.h"
#include <algorithm>
#include <locale>
#include <string>
using namespace std;
std::istream& operator >> (std::istream& in, Album& a)
{
	char artist[64], title[64];

	//get album data
	in.getline(artist, 64, ':');
	in.getline(title, 64, '\n');
	std::string a_artist = artist;
	std::string a_title = title;
	a = Album(a_artist, a_title);

	while (!in.eof())
	{
		Track *t = new Track();
		if (in >> *t)
		{
			a.addTrack(t);
		}
		else
		{
			in.clear();
			return in;
		}
	}
	in.clear(std::ios_base::eofbit);
	return in;
}


std::ostream& operator<<(std::ostream& out, const Album &a)
{
	std::vector<Track*> tracks = a.getTracks();
	out << a.getArtist() << " --:" << a.getTitle() << " (" << a.getNumberSongs()
		<< a.getTotal() << ")" << std::endl;

	for (Track* track : tracks)
	{
		out << "\t" << track << endl;
	}

	return out;
}

/*
* Alphabetically ascending
*
*/
bool Album::ascending(const Album* a1, const Album* a2)
{
	if (a1->getArtist() == a2->getArtist())
	{
		return (a1->getTitle() < a2->getTitle());
	}


	return (a1->getArtist() < a2->getArtist());
}


/*
* Alphabetically descending
*
*/
bool Album::descending(const Album* a1, const Album* a2)
{
	if (a1->getArtist() == a2->getArtist())
	{
		return (a1->getTitle() > a2->getTitle());
	}
	return (a1->getArtist() > a2->getArtist());
}


Track* Album::getLongestTrack() const
{
	Track* longest = tracks.at(0);
	for (Track* track : tracks)
	{
		if (*track > *longest)
		{
			longest = track;
		}
	}
	return longest;
}

Duration Album::getTotal() const
{
	//default duration
	Duration a;
	for (Track* t : tracks)
	{
		a + t->getDuration();
	}
	return a;
}


