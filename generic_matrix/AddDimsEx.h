/**
 ==================================================================================================
 Name        : AddDimsEx.h
 Author      : Yinnon Bratspiess
 Description : Exception for two matricies does not matches for add. one or two of their dims does
 * 			   not equal
 ==================================================================================================
 **/
#ifndef _ADDDIMSEX_H_
#define _ADDDIMSEX_H_
#include <iostream>
#include <exception>
using namespace std;
/**
 * Exception for two matricies does not matches for add. one or two of their dims does not equal
 **/
class AddDimsEx: public exception
{
	/**
	 * returns err mesage
	 **/
	virtual const char* what() const throw()
	{ 
		return "cannot addition matrices of different sizes."; 
	}
};
#endif // _ADDDIMSEX_H_
