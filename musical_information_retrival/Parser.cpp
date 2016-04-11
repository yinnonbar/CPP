/**
 ==================================================================================================
 Name        : Parser.cpp
 Author      : Yinnon Bratspiess
 Description : This is the cpp file for the namespace Parser which parsing all the given text files
 ==================================================================================================
 **/
// ------------------------------ includes --------------------------------------------------------
#include "Parser.h"
// ------------------------------ defines ---------------------------------------------------------
const std::string SEPARATOR = "=";
const std::string END_OF_SONGS = "***";
const std::string TITLE = "title";
const std::string TAGS = "tags";
const std::string LYRICS = "lyrics";
const std::string LYRICS_BY = "lyricsBy";
const std::string INSTRUMENTS = "instruments";
const std::string PERFORMED_BY = "performedBy";
const std::string BPM = "bpm";
#define SPACE " "
#define COLON ":"
#define COMMA ","
#define NO_BPM 0
#define STRING_BEGIN 0
	

/**
 * namespace Parser functioning as a "static class" which has function for parsing the files
 **/
namespace Parser
{
	
// ------------------------------ functions -------------------------------------------------------
	/**
	* return all the line between {}
	**/
	string getWordList(const string line)
	{
	
	    size_t pos1 = line.find("{");
	    size_t pos2 = line.find("}");
	
	    return line.substr(pos1 + 1, pos2 - pos1 - 1);
	}
	
	/**
	* songs parser
	* This can either be a basis for a member function of some class or static function or whatever
	*/
	vector<Song*> readSongsFromFile(string songsFileName)
	{
		vector<Song*> songsList;
	    ifstream instream(songsFileName.c_str());
	    if (!instream.is_open())
	    {
	        cerr << "Error! Can't open file: " << songsFileName << "." << endl;
	    }
	    std::string line = "";
	    int lastSong = 0;
	    while(instream.good() && !lastSong)
	    {
	        if (line.compare(SEPARATOR) != 0)
	        {
	            getline(instream, line);
	            // Expect a line of "="
	            if (END_OF_SONGS.compare(line) == 0)
	            {
	                lastSong = 1;
	                break;
	            }
	        }
	        getline(instream, line);
	        // Expect a line of "title: ..."
	        size_t pos = TITLE.size() + 2;
	        std::string title = line.substr(pos);
	        getline(instream, line);
	        // Expect a line of "tags: {...}"
	        std::string tags = getWordList(line);
			// a map containing all the tags and their weights
			map<string, int> tagsMap;
			string tagName;
			string tagNum;
			//running on the given line of tags and sub from it with spaces the name and the weight
			//of the tag
			for (unsigned int i = 0; i < tags.length() ; i++)
			{
				tagName = tags.substr(STRING_BEGIN, tags.find(SPACE));
				tags = tags.substr(tags.find(SPACE) + 1, tags.length() -1);
				tagNum =  tags.substr(STRING_BEGIN , tags.find(SPACE));
				tags = tags.substr(tags.find(SPACE) + 1 , tags.length() -1);
				tagsMap.insert(pair<string, int>(tagName, atoi(tagNum.c_str())));
			}
			//remain the last tag and its weight
			tagName = tags.substr(STRING_BEGIN, tags.find(SPACE));
			tags = tags.substr(tags.find(SPACE) + 1, tags.length() -1);
			tagNum =  tags.substr(STRING_BEGIN , tags.find(SPACE));
			tagsMap.insert(pair<string, int>(tagName, atoi(tagNum.c_str())));
	        std::string lyrics = "";
	        std::string lyricsBy = "";
	        std::string instruments = "";
	        std::string performedBy = "";
	        std::string bpmStr = "";
	        getline(instream, line);
	        // Expect either lyrics or instruments.
	        //case of lyrics song
	        if (line.substr(STRING_BEGIN, LYRICS.size()).compare(LYRICS) == 0)
	        {
	            // Then we have a lyric song
	            // Lets get the lyrics:
	            lyrics = getWordList(line);
	            // Lets get the lyricsBy:
	            getline(instream, line);
	            pos = LYRICS_BY.size() + 2;
	            lyricsBy = line.substr(pos);
				// creating a new lyrics song pushing it to the songs vector
	            LyricalSong *lyricsSong = new LyricalSong (title, tagsMap, lyrics, lyricsBy);
	            songsList.push_back(lyricsSong);
	        }
	        //case of instrument song
	        else
	        {
	            // Then we have an instrumental song
	            // Lets get the instruments:
	            instruments = getWordList(line);
	            // Lets get the performedBy:
	            getline(instream, line);
	            pos = PERFORMED_BY.size() + 2;
	            performedBy = line.substr(pos);
	            // Lets see if we have bpm:
	            if (!instream.good())
	            {
	                break;
	            }
	            getline(instream, line);
	            if (END_OF_SONGS.compare(line) == 0)
	            {
	                lastSong = 1;
	            }
	            //bpm != 0
	            if (line.substr(STRING_BEGIN, BPM.size()).compare(BPM) == 0)
	            {
	                pos = BPM.size() + 2;
	                bpmStr = line.substr(pos);
					double doubleBpm = atof(bpmStr.c_str());
	                // creating a new instrumental song pushing it to the songs vector with bpm
	                InstrumentalSong *instrumentSong = new InstrumentalSong (title, tagsMap, 
	                instruments, performedBy, doubleBpm);
					songsList.push_back(instrumentSong); 
	            }
	            else
	            {
	                 assert ( (line.compare(SEPARATOR) == 0) || (line.compare(END_OF_SONGS) == 0));
	                 //bpm == 0
	                 // creating a new instrumental song pushing it to the songs vector with bpm 0
	                 InstrumentalSong *instrumentSong = new InstrumentalSong (title, tagsMap, 
	                 instruments, performedBy, NO_BPM);
	                 songsList.push_back(instrumentSong);
	            }
	        }
	    }
	    instream.close();
	    return songsList;
	}
	
	 /**
	 * this function reads from the file and returns a Parameter holding the parameters given
	 * on the file
	 * @param string parametersFileName - parameters file name
	 * @return Parameters - a parameters class 
	 **/
	Parameters readParametersFromFile(const string parametersFileName)
	{
		Parameters parameters;
		//vars for the parameters as given on the parameters file
		string num, wordName, wordAverage, wordStd;
		double doubleWordAverage, doubleWordStd;
		int intNum;
		ifstream instream(parametersFileName.c_str());
	    if (!instream.is_open())
	    {
	        cerr << "Error! Can't open file: " << parametersFileName << "." << endl;
	    }
	    string line = "";
			//tag match score
			getline(instream, line);
			num = line.substr(line.find(SPACE) + 1, line.length() -1);
			intNum = atoi(num.c_str());
			parameters.setTagMatchScore(intNum);
			//lyrics match score
			getline(instream, line);
			num = line.substr(line.find(SPACE) + 1, line.length() -1);
			intNum = atoi(num.c_str());
			parameters.setlyricsMatchScore(intNum);
			//instrument match score
			getline(instream, line);
			num = line.substr(line.find(SPACE) + 1, line.length() -1);
			intNum = atoi(num.c_str());
			parameters.setInstrumentMatchScore(intNum);
			//bpm likelihood weight
			getline(instream, line);
			num = line.substr(line.find(SPACE) + 1, line.length() -1);
			intNum = atoi(num.c_str());
			parameters.setBpmLikelihoodWheight(intNum);
			while(!instream.eof())
			{
				getline(instream, line);
				//ignore the empty line
				if (line.empty())
				{
					break;
				}
				// subing the name of the well known queries, theire average and std
				wordName = line.substr(0, line.find(COLON));
				line = line.substr(line.find(SPACE) + 1, line.length() - 1);
				wordAverage = line.substr(0, line.find(SPACE));
				line = line.substr(line.find(COMMA) + 2, line.length() - 1);
				wordStd = line.substr(0, line.length());
				doubleWordAverage = atof(wordAverage.c_str());
				doubleWordStd = atof(wordStd.c_str());
				//setting in the maps of words bpm average and words bpm std
				parameters.setWordsBpmAverage(wordName, doubleWordAverage);
				parameters.setWordsBpmStd(wordName, doubleWordStd);
			}
		return parameters;
	}
	/**
	 * this function reads from the file and returns a vector of strings holding the queries as 
	 * given on the file
	 * @param string queriesFileName - queries file name
	 * @return vector<string> 
	 **/
	vector<string> readQueriesFromFile(const string queriesFileName)
	{
		vector<string> queries;
		ifstream instream(queriesFileName.c_str());
	    if (!instream.is_open())
	    {
	        cerr << "Error! Can't open file: " << queriesFileName << "." << endl;
	    }
	    string line = "";
	    //while not EOF getline and push it as a query
	    while(!instream.eof())
		{
			getline(instream, line);
			if (line.empty())
			{
				break;
			}
			queries.push_back(line);
		}
		return queries;
	}
}
