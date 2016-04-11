/**
 ==================================================================================================
 Name        : Parameters.h
 Author      : Yinnon Bratspiess
 Description : a header file for parameter class holding all the parameters as given in the 
 * 			   parameter file
 ==================================================================================================
 **/

#ifndef _PARAMETERS_H_
#define _PARAMETERS_H_
// ------------------------------ includes --------------------------------------------------------
#include <string>
#include <map>
#include <iostream>

using namespace std;
/**
 * Parameters class represents the parameters as given in the parameters file
 **/
class Parameters
{
	public:
		//ctor & dtor
		/**
		 * default ctor
		 **/
		 Parameters();
		/**
		 * ctor
		 * @param const int tagMatchScore - tag match score
		 * @param const int lyricsMatchScore - lyrics match score
		 * @param const int instrumentMatchScore - instruments match score
		 * @param const int bpmLikelihoodWheight - bpm liklihood weight
		 **/
		Parameters(const int tagMatchScore, const int lyricsMatchScore,\
				   const int instrumentMatchScore, const int bpmLikelihoodWheight);
		/**
		 * dtor
		 **/
		~Parameters();
		//getters
		/**
		 * tag match score getter
		 **/
		int getTagMatchScore();
		/**
		 * lyrics match score getter
		 **/
		int getlyricsMatchScore();
		/**
		 * instrument match score getter
		 **/
		int getInstrumentMatchScore();
		/**
		 * BPM liklihood weight score getter
		 **/
		int getBpmLikelihoodWheight();
		/**
		 * words to average map getter
		 **/
		map<string, double>& getWordsBpmAverage();
		/**
		 * words to STD map getter
		 **/
		map<string, double> getWordsBpmStd();
		//setters
		/**
		 * tag match score setter
		 **/
		void setTagMatchScore(const int tagMatchScore);
		/**
		 * lyrics match score setter
		 **/
		void setlyricsMatchScore(const int lyricsMatchScore);
		/**
		 * instrument match score setter
		 **/
		void setInstrumentMatchScore(const int instrumentMatchScore);
		/**
		 * BPM liklihoodWeight match score setter
		 **/
		void setBpmLikelihoodWheight(const int bpmLikelihoodWheight);
		/**
		 * words to average map setter
		 **/
		void setWordsBpmAverage(const string word, const double wordAverage);
		/**
		 * words to STD map setter
		 **/
		void setWordsBpmStd(const string word, const double wordStd);
		  
	private:
		int _tagMatchScore, _lyricsMatchScore, _instrumentMatchScore, _bpmLikelihoodWheight;	  
		map<string, double> _wordsBpmAverage;
		map<string, double> _wordsBpmStd;	
		
};

#endif // _PARAMETERS_H_
