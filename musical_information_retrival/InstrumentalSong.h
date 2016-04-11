/**
 ==================================================================================================
 Name        : InstrumentalSong.h
 Author      : Yinnon Bratspiess
 Description : a header file for an instrumental song which is a song that contains lyrics. 
			   derive Song
 ==================================================================================================
 **/

#ifndef INSTRUMENTALSONG_H
#define INSTRUMENTALSONG_H
// ------------------------------ includes --------------------------------------------------------
#include <iostream>
#include <string>
#include <map>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include "Song.h"
#include "Parameters.h"

/**
 * this class is the class of the lyrical songs derived from Song class
 **/
class InstrumentalSong : public Song
{
	public:
		//ctors & dtors
		/**
		 * ctor for lyrics song
		 * @param string title
		 * @param map<string, int> tags
		 * @param string instruments
		 * @param string performedBy
		 * @param double doubleBpm
		 **/
		InstrumentalSong(string title, map<string, int> tags, string instruments,
						 string performedBy, double doubleBpm);
		/**
		 * dtor
		 **/
		 ~InstrumentalSong();
		//methods
		/**
		 * this function calculates the match instrument score
		 * @param const string searchWord
		 * @param const int instrumentMatchScore
		 * @return int - match instrument score
		 **/
		int matchInstrumentsScore (const string searchWord, const int instrumentMatchScore);  
		/**
		 * this function calculates the match BPM score
		 * @param const string searchWord
		 * @param Parameters parameters 
		 * @return int - match BPM score
		 **/
		int matchBpmScore (const string searchWord, Parameters parameters);
		/**
		 * this function calculates the song score for an instrumental song
		 * @param const string searchWord
		 * @param Parameters parameters 
		 * @return int - instrumental song score
		 **/
		int songScore (const string word, Parameters parameters);
		/**
		 * this method prints an instrumental song as needed by the template
		 * @param string query - query
		 * @param Parameters parameters - parameters 
		 **/
		void printSong (const string query, Parameters parameters);
		//getters
		/**
		 * getPerformedBy getter
		 **/
		string getPerformedBy() const;
	private :
		string _instruments;
		string _performedBy;
		double _bpm;
};


#endif // INSTRUMENTALSONG_H
