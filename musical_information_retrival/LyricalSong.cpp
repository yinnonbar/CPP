/**
 ==================================================================================================
 Name        : LyricalSong.h
 Author      : Yinnon Bratspiess
 Description : a cpp file for a lyrical song which is a song that contains lyrics. derive Song
 ==================================================================================================
 **/
// ------------------------------ includes --------------------------------------------------------
#include "LyricalSong.h"

//ctors & dtors
/**
 * ctor for lyrics song
 * @param string title
 * @param map<string, int> tags
 * @param string lyrics
 * @param string lyricsBy
 **/
LyricalSong::LyricalSong(string title, map<string, int> tags,
						 string lyrics, string lyricsBy) : Song(title, tags), _lyrics(lyrics), 
						 _lyricsBy(lyricsBy)
{
}
/**
 * dtor
 **/
LyricalSong::~LyricalSong()
{
}
//getters
/**
 * lyrics getter
 **/
string LyricalSong::getLyrics ()
{
	return _lyrics;
}
/**
 * lyricsBy getter
 **/
string LyricalSong::getLyricsBy ()
{
	return _lyricsBy;
}
//methods
/**
 * this method calculates the match lyrics score
 * @param const string searchWord - query
 * @param int lyricsMatchScore - lyrics match score
 * @return int - match lyrics score 
 **/
int LyricalSong::matchLyricsScore (const string searchWord, const int lyricsMatchScore)
{
	int counter = 0;
	stringstream stStream(_lyrics);
	string str;
	//count the amount of time the word is in the lyrics and multiply it by lyrics match score
	while (stStream >> str)
	{
		if(str == searchWord)
		{
			counter++;
		}
	}
	return counter * lyricsMatchScore;
}
/**
 * this method calculates the song's score for a lyrics song
 * @param string word - query
 * @param Parameters parameters - parameters
 * @return int - the song score 
 **/
int LyricalSong::songScore (const string word, Parameters parameters)
{
	return  matchTagScore(word, parameters.getTagMatchScore()) + matchLyricsScore(word, 
	parameters.getlyricsMatchScore());
}
/**
 * this method prints a lyrics song as needed by the template
 * @param string query - query
 * @param Parameters parameters - parameters 
 **/
void LyricalSong::printSong (const string query, Parameters parameters)
{
	cout << getTitle() << "\t" << songScore(query, parameters) << "\t" << "lyrics by: " 
	<< getLyricsBy() << endl;
}



