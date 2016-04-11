/**
 ==================================================================================================
 Name        : MIR.cpp
 Author      : Yinnon Bratspiess
 Description : This is the driver file for a musical information retrieval unit holding the main
 * 			   function which deals with the given files consists the songs, parameters given on
 *             them and the queries. 
 ==================================================================================================
 **/
 
// ------------------------------ includes --------------------------------------------------------
#include <iostream>
#include "Parser.h"
#include "LyricalSong.h"
#include "InstrumentalSong.h"
#include "Parameters.h"
#include <algorithm>
#include "SortHelper.h"
// ------------------------------ defines ---------------------------------------------------------
#define POSITIVE_NUM 0
#define LEGAL_INPUT_NUM 4
#define SONGS_FILE 1
#define PARAMETERS_FILE 2
#define QUERIES_FILE 3

// ------------------------------ functions -------------------------------------------------------
/**
 * a function that prints the query's preface
 * @param const string query - the given query
 **/
void queryPrint (const string query) 
{
	cout << "----------------------------------------" << endl;
	cout << "Query word: " << query << endl;
	cout << endl;
}

/**
 * a function that sorts a vector of songs and print them in desecnding order per query
 * @param const string query - the given query we want to sort by
 * @param vector<Song*> &songsList - the songs list
 * @param const Parameters parameters - the instance of the parameters
 **/
void sort (const string query, vector<Song*> &songsList, const Parameters parameters)
{
	SortHelper sortHelper = SortHelper();
	vector<Song*>::iterator iter;
	//iteraiting on song's list and adding song's score by using query and parameters with
	//addItem (insertion sort)
	for (iter = songsList.begin(); iter != songsList.end() ; iter++)
	{
		const int score = (*iter) -> songScore(query, parameters);
		sortHelper.addItem(score);
	}
	//returns a vector of ints which indicates the orderd indices
	vector<int> sortedVec = sortHelper.getSortedOrderInVector();
	queryPrint (query);
	for (unsigned int i = 0; i < songsList.size(); i++)
	{
		int index = sortedVec[i];
		//prints only songs positive score
		if((*songsList[index]).songScore(query, parameters) > POSITIVE_NUM)
		{
			(*songsList[index]).printSong(query, parameters);
		}
	}
}
int main(int argc, char *argv[])
{
	//wrong usage
	if (argc != LEGAL_INPUT_NUM)
	{
		cout << "Usage: MIR < songs file name > < parameters file name > < queries file name >" 
		<< endl;
	}
	vector <Song*> songsList = Parser::readSongsFromFile(argv[SONGS_FILE]);
	Parameters parameters = Parser::readParametersFromFile(argv[PARAMETERS_FILE]);
	vector<string> queries = Parser::readQueriesFromFile(argv[QUERIES_FILE]);
	//for each query use the sort function to sort and print as needed
	for (unsigned int i = 0; i < queries.size(); i++)
	{
		sort(queries[i], songsList, parameters);		
	}
	for (unsigned int i = 0; i < songsList.size(); i++)
	{
		delete songsList[i];
	}
	return EXIT_SUCCESS;
}


