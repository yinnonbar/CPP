/**
 ==================================================================================================
 Name        : NotSquareMatrixEx.h
 Author      : Yinnon Bratspiess
 Description : Exception for a matrix which is not square (rows != cols)
 ==================================================================================================
 **/
#ifndef _NOTSQAUREMATRIXEX_H_
#define _NOTSQAUREMATRIXEX_H_
#include <iostream>
#include <exception>
using namespace std;
/**
 * Exception for a matrix which is not square (rows != cols)
 **/
class NotSquareMatrixEx: public exception
{
	/**
	 * returns err mesage
	 **/
	virtual const char* what() const throw()
	{ 
		return "the matrix is not square"; 
	}
};
#endif // _NOTSQAUREMATRIXEX_H_
