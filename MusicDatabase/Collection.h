#ifndef COLLECION_H
#define COLLECTION_H

#include <vector>
#include "Album.h"

class Collection
{
	vector<Album*> albums;

public:
	Collection();
	Collection(vector<Album*> album);
	~Collection();
	vector<Album*> getAlbums() const;
	void addAlbum(Album* a);
	void sortAlbums(bool(*a)(const Album* a1, const Album* a2));
	void displayAlbum(bool(*a)(const Album* a1, const Album* a2));
	Duration getTotalPlayTime(string artist);
	Album getAlbumMostTracks();
	Track getLongestTrack();
};

inline Collection::Collection()
{
	albums = vector<Album*>();
}

inline Collection::Collection(vector<Album*> album)
{
	albums = album;
}

inline Collection::~Collection()
{
	for (Album* a : albums)
	{
		delete a;
	}
	albums.clear();

}

//--------------- get methods -----//
inline vector<Album*> Collection::getAlbums() const
{
	return albums;
}

inline void Collection::addAlbum(Album *a)
{
	albums.push_back(a);
}


std::ostream& operator<<(std::ostream& out, const Collection &c);
std::istream& operator >> (std::istream& in, Collection &c);

#endif // COLLECION_H

