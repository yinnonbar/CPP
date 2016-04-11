/**
 ==================================================================================================
 Name        : MultiplyEx.h
 Author      : Yinnon Bratspiess
 Description : Exception for two matricies does not fits for matricies multiplation - first's cols
 *             != second's row
 ==================================================================================================
 **/
#ifndef _MULTIPLYEX_H_
#define _MULTIPLYEX_H_
#include <iostream>
#include <exception>
using namespace std;
/**
 * Exception for two matricies does not fits for matricies multiplation - 
 * first's cols != second's row
 **/
class MultiplyEx: public exception
{
	/**
	 * returns err mesage
	 **/
	virtual const char* what() const throw()
	{ 
		return "the matricies dims are not matches for multiply"; 
	}
};
#endif // _MULTIPLYEX_H_
