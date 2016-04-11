/**
 ==================================================================================================
 Name        : NotMatchingVectorSizeEx.h
 Author      : Yinnon Bratspiess
 Description : Exception for a given dims that doesn't matchs for the num of elements in the given
 * 			   vector
 ==================================================================================================
 **/
#ifndef _NOTMATCHINGVECTORSIZE_H_
#define _NOTMATCHINGVECTORSIZE_H_
#include <iostream>
#include <exception>
using namespace std;
/**
 * Exception for a given dims that doesn't matchs for the num of elements in the given vector
 **/
class NotMatchingVectorSizeEx: public exception
{
	/**
	 * returns err mesage
	 **/
	virtual const char* what() const throw()
	{ 
		return "the dims does not matchs to the given vectors size"; 
	}
};
#endif // _NOTMATCHINGVECTORSIZE_H_
