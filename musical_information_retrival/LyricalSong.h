/**
 ==================================================================================================
 Name        : LyricalSong.h
 Author      : Yinnon Bratspiess
 Description : a header file for a lyrical song which is a song that contains lyrics. derive Song
 ==================================================================================================
 **/

#ifndef LYRICALSONG_H
#define LYRICALSONG_H
// ------------------------------ includes --------------------------------------------------------
#include <iostream>
#include <string>
#include <map>
#include <bits/stdc++.h>
#include "Song.h"
#include "Parameters.h"

/**
 * this class is the class of the lyrical songs derived from Song class
 **/
class LyricalSong : public Song
{
	public:
		//ctors & dtors
		/**
		 * ctor for lyrics song
		 * @param string title
		 * @param map<string, int> tags
		 * @param string lyrics
		 * @param string lyricsBy
		 **/
		LyricalSong(string title, map<string, int> tags, string lyrics, string lyricsBy);
		/**
		 * dtor
		 **/
		~LyricalSong();
		//getters
		/**
		 * lyrics getter
		 **/
		string getLyrics ();
		/**
		 * lyricsBy getter
		 **/
		string getLyricsBy ();
		//methods
		/**
		 * this method calculates the match lyrics score
		 * @param const string searchWord - query
		 * @param int lyricsMatchScore - lyrics match score
		 * @return int - match lyrics score 
		 **/
		int matchLyricsScore (const string searchWord, const int lyricsMatchScore);   
		/**
		 * this method calculates the song's score for a lyrics song
		 * @param string word - query
		 * @param Parameters parameters - parameters
		 * @return int - the song score 
		 **/
		int songScore (const string word, Parameters parameters);
		/**
		 * this method prints a lyrics song as needed by the template
		 * @param string query - query
		 * @param Parameters parameters - parameters 
		 **/
		void printSong (const string query, Parameters parameters);

	private:
		string _lyrics;
        string _lyricsBy;
        
		
};


#endif // LYRICALSONG_H
