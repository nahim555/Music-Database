#include <iostream>
#include <fstream>
#include "Duration.h"
#include "Track.h"
#include "Album.h"
#include "Collection.h"

// question 1 - 5

using namespace std;

int main()
{
	//Q1 Read in a Collection from the file albums.txt
	Collection a;
	ifstream in;
	in.open("album.text");
	in >> a;

	//Q2 Display the entire album Collection,arranged in alphabetical order of the album artist.
	cout << "Ascending Order" << endl << "-----------" << endl;
	a.displayAlbum(Album::ascending); // c.displayAlbum(Album::descending);
	cout << "-----------" << endl;

	//Q3 Display Total Playtime of all Pink FLoyd albums in the collection.
	cout << "Total Playtime" << endl << "----------" << endl;
	cout << a.getTotalPlayTime("Pink Floyd") << endl;
	cout << "-----------" << endl;

	//Q4 Display album with largest number of tracks
	cout << "Album with most tracks" << endl << "----------" << endl;
	cout << a.getAlbumMostTracks() << endl;
	cout << "-----------" << endl;

	//Q5 Display the details of the longest track in the album collection.
	cout << "Longest track in collection" << endl << "---------" << endl;
	cout << a.getLongestTrack() << endl;
	cout << "-----------" << endl;

}
