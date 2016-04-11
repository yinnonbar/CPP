/**
 ==================================================================================================
 Name        : Song.h
 Author      : Yinnon Bratspiess
 Description : This is the header file for the Song class which is the base class for instrumental
 *             song and lyrics song.
 ==================================================================================================
 **/

#ifndef _SONG_H_
#define _SONG_H_
// ------------------------------ includes --------------------------------------------------------
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "Parameters.h"
#include <cassert>
using namespace std;
/**
 * Song class is a class represents a song which can be either an instrumental song or a lyrics song
 **/
class Song
{
	public:

		//ctor & dtor
		/**
		 * ctor for creating a song containing a title and a map of tags mapping between tag's name
		 * and it's weight
		 **/
		Song(string title, std::map <string, int> tags);
		/**
		 * a virtual dtor
		 **/
		virtual ~Song();
		
		//methods
		/**
		 * a method relevant for the two dreiving classes which calculate the tag match score
		 * based on the requested word and the given tag match score
		 * @param const string searchWord - requested word 
		 * @param const int tagMatchScore - tag match score
		 * @return tag match score
		 **/
		int matchTagScore (const string searchWord, const int tagMatchScore);
		/**
		 * a pure virtual func to calculate a song score based on relevant parameters for lyrics 
		 * song or for an instrumental song. implemented by derives classes
		 * @param const string word - requested word 
		 * @param const Parameters parameters - parameters for scoring the song
		 * @return song's score
		 **/
		virtual int songScore (const string word, Parameters parameters) = 0;
		/**
		 * a pure virtual func that prints the song in the matching template for it derives class. 
		 * implemented by derives classes
		 * @param const string query - requested word 
		 * @param const Parameters parameters - parameters for scoring the song
		 **/
		virtual void printSong (const string query, const Parameters parameters) = 0;
		
		//getters
		/**
		 * a getter for the title.
		 * @return song's title
		 **/
		string getTitle();   
		//int getSongScore () const;
	
	protected:
		string _title;
		//a map mapping between tags name and their weight
		map<std::string, int> _tagsMap;	
};

#endif // _SONG_H_
