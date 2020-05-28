#include "collection.h"
#include <algorithm>
#include<vector>

Duration Collection::getTotalPlayTime(string artist)
{
	Duration totalD;
	for (Album *a : albums)
	{
		if (a->getArtist() == artist)
		{
			totalD = totalD + a->getTotal();
		}
	}
	return totalD;
}

Album Collection::getAlbumMostTracks()
{
	Album *MostAlbum = albums.at(0);
	for (Album *album : albums)
	{
		if (*album > *MostAlbum)
		{
			MostAlbum = album;
		}
	}

	return Album(*MostAlbum);
}

Track Collection::getLongestTrack()
{

	Track* longest = albums.at(0)->getLongestTrack();

		
	for (Album *album : albums)
	{
		Track* t;
		if (*(t = album->getLongestTrack()) > *longest) {
			longest = t;
		}
	}

	return Track(*longest);
}

void Collection::sortAlbums(bool(*a)(const Album* a1, const Album* a2))
{
	std::sort(albums.begin(), albums.end(), a);
}

void Collection::displayAlbum(bool(*a)(const Album* a1, const Album* a2))
{
	sortAlbums(a);
	cout << *this;

}

std::ostream& operator<<(std::ostream& out, const Collection &a)
{
	std::vector<Album*> albums = a.getAlbums();
	for (Album *album : albums)
	{
		out << *album;
	}

	return out;
}

std::istream& operator >> (std::istream& in, Collection &c)
{

	while (!in.eof())
	{
		Album *a = new Album();
		if (in >> *a)
		{
			c.addAlbum(a);
		}
		else
		{
			in.clear();
			return in;
		}
	}

	return in;

}
