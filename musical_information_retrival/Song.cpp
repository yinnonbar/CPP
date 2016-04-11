/**
 ==================================================================================================
 Name        : Song.cpp
 Author      : Yinnon Bratspiess
 Description : This is the cpp file for the Song class which is the base class for instrumental
 *             song and lyrics song.
 ==================================================================================================
 **/

// ------------------------------ includes --------------------------------------------------------
#include "Song.h"
// ------------------------------ defines ---------------------------------------------------------
#define POSITIVE_NUM 0

//ctor & dtor
/**
* ctor for creating a song containing a title and a map of tags mapping between tag's name
* and it's weight
**/
Song::Song(string title, map <string, int> tags) : _title(title), _tagsMap(tags)
{
}
/**
* a virtual dtor
**/
Song::~Song()
{
}
//methods
/**
 * a method relevant for the two dreiving classes which calculate the tag match score
 * based on the requested word and the given tag match score
 * @param const string searchWord - requested word 
 * @param const int tagMatchScore - tag match score
 * @return tag match score
 **/
int Song::matchTagScore (const string searchWord, const int tagMatchScore)
{
	//if the requested word is one of the tags return it's weight * tag match score
	map<string, int>::iterator it = _tagsMap.find(searchWord);
	
	if (_tagsMap.count(searchWord) > POSITIVE_NUM)
	{
		return it -> second * tagMatchScore;
	}
	else
	{
		
		return EXIT_SUCCESS;
	}

}

//getters
/**
 * a getter for the title.
 * @return song's title
 **/
string Song::getTitle()
{
	return _title;
}
