#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include <vector>
#include "Track.h"
#include <iostream>

class Album
{
	string title;
	string artist;
	vector<Track*> tracks;

public:
	Album();
	Album(string t_title, string t_artist);
	Album(string t_title, string t_artist, vector<Track*> t_tracks);
	~Album();
	string getTitle() const;
	string getArtist() const;
	vector<Track*> getTracks() const;
	void addTrack(Track* t);
	int getNumberSongs() const;
	Track* getLongestTrack() const;
	Duration getTotal() const;
	static bool ascending(const Album* a1, const Album* a2);
	static bool descending(const Album* a1, const Album* a2);
};

inline Album::Album()
{
	title = "null";
	artist = "null";
	tracks = vector<Track*>();
}

inline Album::Album(string t_title, string t_artist)
{
	title = t_artist;
	artist = t_artist;
	tracks = vector<Track*>();
}

inline Album::Album(string t_title, string t_artist, vector<Track*> t_tracks)
{
	title = t_title;
	artist = t_artist;
	tracks = t_tracks;
}

inline Album::~Album()
{
		for (Track* t : tracks) 
		{ 
			delete t;
		}
		tracks.clear();
	
}

// Get and Set Methods

inline string Album::getTitle() const
{
	return title;
}

inline string Album::getArtist() const
{
	return artist;
}

inline vector<Track*> Album::getTracks() const
{
	return tracks;
}

inline int Album::getNumberSongs() const
{
	return (int)tracks.size();
}

inline void Album::addTrack(Track *t)
{
	this->tracks.push_back(t);
}

//operators overloading-----//

inline int operator<(const Album& a1, const Album& a2)
{
	return a1.getNumberSongs() < a2.getNumberSongs();
}

inline int operator>(const Album& a1, const Album& a2)
{
	return a1.getNumberSongs() > a2.getNumberSongs();
}

inline int operator>=(const Album& a1, const Album& a2)
{
	return !(a1<a2);
}

inline int operator<=(const Album& a1, const Album& a2)
{
	return !(a1>a2);
}

inline int operator==(const Album& a1, const Album& a2)
{
	return (a1.getArtist() == a2.getArtist() && a1.getTitle() == a2.getTitle());
}

inline int operator!=(const Album& a1, const Album& a2)
{
	return !(a1 == a2);
}

std::ostream& operator<<(std::ostream& out, const Album &a);
std::istream& operator >> (std::istream& in, Album &a);




#endif // ALBUM_H

