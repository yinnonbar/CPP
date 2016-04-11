/**
 ==================================================================================================
 Name        : Parameters.cpp
 Author      : Yinnon Bratspiess
 Description : a cpp file for parameter class holding all the parameters as given in the 
 * 			   parameter file
 ==================================================================================================
 **/

// ------------------------------ includes --------------------------------------------------------
#include "Parameters.h"

//ctor & dtor
/**
 * default ctor
 **/
Parameters::Parameters() : _tagMatchScore(0), _lyricsMatchScore(0), _instrumentMatchScore(0),\
_bpmLikelihoodWheight(0)
{
}

/**
 * dtor
 **/
Parameters::~Parameters()
{
}

/**
 * ctor
 * @param const int tagMatchScore - tag match score
 * @param const int lyricsMatchScore - lyrics match score
 * @param const int instrumentMatchScore - instruments match score
 * @param const int bpmLikelihoodWheight - bpm liklihood weight
 **/
Parameters::Parameters(int tagMatchScore, int lyricsMatchScore, int instrumentMatchScore,
					   int bpmLikelihoodWheight) : _tagMatchScore(tagMatchScore), 
_lyricsMatchScore(lyricsMatchScore), _instrumentMatchScore(instrumentMatchScore),
_bpmLikelihoodWheight(bpmLikelihoodWheight)
{
}

//getters
/**
 * tag match score getter
 **/
int Parameters::getTagMatchScore() 
{
	return _tagMatchScore;
}
/**
 * lyrics match score getter
 **/
int Parameters::getlyricsMatchScore() 
{
	 return _lyricsMatchScore;
}
/**
 * instrument match score getter
 **/
 int Parameters::getInstrumentMatchScore()
{
	return _instrumentMatchScore;
}
/**
 * BPM liklihood weight score getter
 **/
int Parameters::getBpmLikelihoodWheight()
{
	return _bpmLikelihoodWheight;
}
/**
 * words to average map getter
 **/
map<string, double>& Parameters::getWordsBpmAverage()
{
	return _wordsBpmAverage;
}
/**
 * words to STD map getter
 **/
map<string, double> Parameters::getWordsBpmStd()
{
	return _wordsBpmStd;
}
//setters
/**
 * tag match score getter
 **/
void Parameters::setTagMatchScore(const int tagMatchScore)
{
	_tagMatchScore = tagMatchScore;
}
/**
 * lyrics match score setter
 **/
void Parameters::setlyricsMatchScore(const int lyricsMatchScore)
{
	_lyricsMatchScore = lyricsMatchScore;
}
/**
 * instrument match score setter
 **/
void Parameters::setInstrumentMatchScore(const int instrumentMatchScore)
{
	_instrumentMatchScore = instrumentMatchScore;
}
/**
 * BPM liklihoodWeight match score setter
 **/
void Parameters::setBpmLikelihoodWheight(const int bpmLikelihoodWheight)
{
	_bpmLikelihoodWheight = bpmLikelihoodWheight;
}
/**
 * words to average map setter
 **/
void Parameters::setWordsBpmAverage(const string word, const double wordAverage)
{
	_wordsBpmAverage.insert(pair<string, double>(word, wordAverage));
}
/**
 * words to STD map setter
 **/
void Parameters::setWordsBpmStd(const string word, const double wordStd)
{
	_wordsBpmStd.insert(pair<string, double>(word, wordStd));
}


    
		


