/**
 ==================================================================================================
 Name        : InstrumentalSong.cpp
 Author      : Yinnon Bratspiess
 Description : a cpp file for an instrumental song which is a song that contains lyrics. 
			   derive Song
 ==================================================================================================
 **/

// ------------------------------ includes --------------------------------------------------------
#include "InstrumentalSong.h"
// ------------------------------ defines --------------------------------------------------------
#define NO_BPM 0

//ctors & dtors
/**
 * ctor for lyrics song
 * @param string title
 * @param map<std::string, int> tags
 * @param string instruments
 * @param string performedBy
 * @param double doubleBpm
 **/
InstrumentalSong::InstrumentalSong(string title, map<string, int> tags, string instruments, 
								   string performedBy, double doubleBpm) : Song(title, tags), 
								   _instruments(instruments),
_performedBy(performedBy), _bpm(doubleBpm) 
{
}
/**
 * dtor
 **/
InstrumentalSong::~InstrumentalSong()
{
}

//getters
/**
 * getPerformedBy getter
 **/
string InstrumentalSong::getPerformedBy() const
	{
		return _performedBy;
	}
//methods
/**
 * this function calculates the match instrument score
 * @param const string searchWord
 * @param const int instrumentMatchScore
 * @return int - match instrument score
 **/
int InstrumentalSong::matchInstrumentsScore(const string searchWord, const int instrumentMatchScore)
{
	// check word by word if the instrument is in the song's instrument
	stringstream stStream(this -> _instruments);
	string str;
	while(stStream >> str) 
	{
		if (str == searchWord)
		{
			return instrumentMatchScore;
		}
	}
	return 0;
}

/**
 * this function calculates the match BPM score
 * @param const string searchWord
 * @param Parameters parameters 
 * @return int - match BPM score
 **/
int InstrumentalSong::matchBpmScore (const string searchWord, Parameters parameters)
{
	//case that the bpm is not 0
	if (this -> _bpm != NO_BPM)
	{
		//finding the avg and STD and if they exists calculate as the given formula
		map<string, double> &mymap = parameters.getWordsBpmAverage();
		map<string, double>::iterator it = mymap.find(searchWord);
		if (it == mymap.end())
		{
			return NO_BPM;	
		}
		else
		{
			double average = it -> second;
			double std = parameters.getWordsBpmStd().at(searchWord);
			return (int)(floor(exp(-((_bpm - average) * (_bpm - average)) / (2 * (std * std)))
			 * parameters.getBpmLikelihoodWheight()));
		}
	}
	return NO_BPM;
}

/**
 * this function calculates the song score for an instrumental song
 * @param const string searchWord
 * @param Parameters parameters 
 * @return int - instrumental song score
 **/
int InstrumentalSong::songScore (const string word, Parameters parameters)
{
	//sum of match tag score + instruments match score + bpm score
	return matchTagScore(word, parameters.getTagMatchScore()) + matchInstrumentsScore(word, 
	parameters.getInstrumentMatchScore()) + matchBpmScore(word, parameters);
}
/**
 * this method prints an instrumental song as needed by the template
 * @param string query - query
 * @param Parameters parameters - parameters 
 **/
void InstrumentalSong::printSong (const string query, Parameters parameters)
{
	cout << getTitle() << "\t" << songScore(query, parameters) << "\t" << "performed by: " 
	<< getPerformedBy() << endl;
}		


