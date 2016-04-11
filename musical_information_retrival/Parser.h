/**
 ==================================================================================================
 Name        : Parser.h
 Author      : Yinnon Bratspiess
 Description : This is header file for the namespace Parser which parsing all the given text files
 ==================================================================================================
 **/
#ifndef _PARSER_H_
#define _PARSER_H_
// ------------------------------ includes --------------------------------------------------------
#include <string>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include "LyricalSong.h"
#include "InstrumentalSong.h"
#include "Parameters.h"

/**
 * namespace Parser functioning as a "static class" which has function for parsing the files
 **/
namespace Parser
{
// ------------------------------ functions -------------------------------------------------------
		/**
		* return all the line between {}
		**/
		string getWordList(const string line);
		/**
		* songs parser
		*  This can either be a basis for a member function of some class or static function or 
		*  whatever...
		*/
		vector<Song*> readSongsFromFile(string songsFileName);
		
		/**
		 * this function reads from the file and returns a Parameter holding the parameters given
		 * on the file
		 * @param string parametersFileName - parameters file name
		 * @return Parameters - a parameters class 
		 **/
		Parameters readParametersFromFile(const string parametersFileName);
		
		/**
		 * this function reads from the file and returns a vector of strings holding the queries as 
		 * given on the file
		 * @param string queriesFileName - queries file name
		 * @return vector<string> 
		 **/
		vector<string> readQueriesFromFile(const string queriesFileName);
};

#endif // _PARSER_H_
