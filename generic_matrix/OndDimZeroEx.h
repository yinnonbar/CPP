/**
 ==================================================================================================
 Name        : OndDimZeroEx.h
 Author      : Yinnon Bratspiess
 Description : Exception for a given dims that 1 is zero and the another is not
 ==================================================================================================
 **/
#ifndef _ONEDIMZERO_H_
#define _ONEDIMZERO_H_
#include <iostream>
#include <exception>
using namespace std;
/**
 * Exception for a given dims that doesn't matchs for the num of elements in the given vector
 **/
class OndDimZeroEx: public exception
{
	/**
	 * returns err mesage
	 **/
	virtual const char* what() const throw()
	{ 
		return "if 1 of the dimension is 0 than there other had to be 0 too"; 
	}
};
#endif // _ONEDIMZERO_H_
