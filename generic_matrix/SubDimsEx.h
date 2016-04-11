/**
 ==================================================================================================
 Name        : SubDimsEx.h
 Author      : Yinnon Bratspiess
 Description : Exception for two matricies does not matches for sub. one or two of their dims does
 * 			   not equal
 ==================================================================================================
 **/
#ifndef _SUBDIMSEX_H_
#define _SUBDIMSEX_H_
#include <iostream>
#include <exception>
using namespace std;
/**
 * Exception for two matricies does not matches for sub. one or two of their dims does not equal
 **/
class SubDimsEx: public exception
{
	/**
	 * returns err mesage
	 **/
	virtual const char* what() const throw()
	{ 
		return "cannot sub matrices of different sizes."; 
	}
};
#endif // _SUBDIMSEX_H_
