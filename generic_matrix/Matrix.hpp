/**
 ==================================================================================================
 Name        : Matrix.hpp
 Author      : Yinnon Bratspiess
 Description : class file for Matrix. Represents a generic class type of matrix containing a 
 * 			   vector from type T represnting the template generic type.
 ==================================================================================================
 **/

#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_
// ------------------------------ includes --------------------------------------------------------
#include <iostream>
#include <vector>
#include "Complex.h"
#include <thread>
#include "NotSquareMatrixEx.h"
#include "AddDimsEx.h"
#include "SubDimsEx.h"
#include "MultiplyEx.h"
#include "NotMatchingVectorSizeEx.h"
#include "OndDimZeroEx.h"
#define NO_DIM 0

using namespace std;

/**
 * Matrix class is a class represents a generic class type of matrix and provides methods and 
 * operators that can be performed on matricies.
 **/
template <class T> class Matrix 
{
	private:
// ------------------------------ members --------------------------------------------------------
		unsigned int _rows, _cols;
		// the vector that contains the elements in the matrix. a flatten vector in size of 
		// (rows * cols) and represents a 2-dims matrix
		vector <T> _matrix;
		static bool _isParallel;
		
// ------------------------------ methods --------------------------------------------------------		
		/**
		 * the function for parallel calculating add
		 * @param Matrix& newMatrix - a ref to the result matrix
		 * @param const Matrix other - the other matrix
		 * @param const unsigned int row - current row
		 **/
		void _plusCalculate(Matrix& newMatrix, const Matrix other, const unsigned int row) const
		{
			for (unsigned int i = 0; i < _cols ; i++)
			{
				newMatrix(row, i) = (*this)(row, i) + other(row, i);
			}
		}
		
		/**
		 * the function for parallel calculating multiply
		 * @param Matrix& newMatrix - a ref to the result matrix
		 * @param const Matrix other - the other matrix
		 * @param const unsigned int row - current row
		 **/
		void _multiplyCalculate(Matrix& newMatrix, const Matrix other, const unsigned int row) const
		{
			for (unsigned int j = 0; j < other. _cols; ++j)
			{
				for (unsigned int k = 0; k < this -> _cols; ++k)
				{
					newMatrix(row, j) += ((*this)(row, k) * other(k, j));
				}
			}
		}
		
		/**
		 * a function that checks if only one of the dims given is zero
		 * @param const unsigned int rows
		 * @param const unsigned int cols
		 * @returns true iff rows xor cols == 0
		 **/
		bool _oneDimZero(const unsigned int rows, const unsigned int cols)
		{
			if ((rows == NO_DIM) ^ (cols == NO_DIM))
			{
				return true;
			}
			return false;
		}
		
		/**
		 * exchanges the given values
		 * @param Matrix& first
		 * @param Matrix& second
		 **/
		void _matriciesSwap (Matrix& first, Matrix& second)
		{
			//swapping the members of the matricies
			swap(first._rows, second._rows);
			swap(first._cols, second._cols);
			swap(first._matrix, second._matrix);
		}
		
	public:
		typedef typename vector<T>:: const_iterator const_iterator;
// ------------------------------ ctors & dtors ---------------------------------------------------
		/**
		* default ctor creating a matrix in the size of 1*1 with 0 - element in it
		* **/
		Matrix() : _rows(1), _cols(1)
		{
			_matrix.push_back(T());
		}
		
		/**
		* copy ctor - gets as input other matrix and copies it
		* @param const Matrix& other - matrix to copy from
		* **/
		Matrix(const Matrix& other) : _rows(other._rows), _cols(other._cols), _matrix(other._matrix)
		{
			if (_oneDimZero(_rows, _cols))
			{
				throw(OndDimZeroEx());
			}
			
		}
		
		/**
		* move ctor 
		* @param const Matrix& other - matrix to copy move from
		* **/
		Matrix(const Matrix && other) : _rows(move(other._rows)), _cols(move(other._cols)),
		       _matrix(move(other._matrix))
		{
			if (_oneDimZero(_rows, _cols))
			{
				throw(OndDimZeroEx());
			}
		}
		
		
		/**
		* constructor for creating an empty matrix (filled with T()) in the size of rows * cols
		* @param const unsigned int rows
		* @param const unsigned int cols
		* **/
		Matrix(const unsigned int rows, const unsigned int cols) : _rows(rows), _cols(cols)
		{
			if (_oneDimZero(_rows, _cols))
			{
				throw(OndDimZeroEx());
			}
			for (unsigned int i = 0; i < _rows * _cols; i++)
			{
				_matrix.push_back(T());
			}
		}
		
		/**
		* a ctor that gets a vector and dims and copy the vecotr
		* @param const unsigned int rows
		* @param const unsigned int cols
		* @param const vector<T> &matrix - the vector to copy 
		* **/
		Matrix(const unsigned int rows, const unsigned int cols, const vector<T> &matrix) :
		       _rows(rows), _cols(cols)
		{			
			if (_oneDimZero(_rows, _cols))
			{
				throw(OndDimZeroEx());
			}
			// case that the dims that were given are not matches to the elements in the vector
			if (rows * cols != matrix.size())
			{
				throw (NotMatchingVectorSizeEx());
			}
			else
			{
				_matrix = matrix;
			} 
		}
		
		/**
		* destructor
		* **/
		~Matrix()
		{
		}
		
// ------------------------------ operators -------------------------------------------------------
		
		/**
		 * () const operator get the element in the matrix in the place of (row, col)
		 * @param const unsigned int row
		 * @param const unsigned int col
		 * @returns the element
		 * **/
		T operator()(const unsigned int row, const unsigned int col) const
		{
			return _matrix[row * _cols + col];
		}
		
		 /**
		 * () non-const operator let change the element in the place of (row, col) 
		 * @param const unsigned int row
		 * @param const unsigned int col
		 * @returns a ref to the element
		 * **/
		T& operator()(const unsigned int row, const unsigned int col) 
		{
			return _matrix[row * _cols + col];
		}
		
		/**
		 * = operator
		 * @param Matrix other - the matrix to use
		 * returns a ref to a Matrix which was assigned from the other matrix
		 * **/
		Matrix& operator=(Matrix other) 
		{
			_matriciesSwap(*this, other);
			return *this;
		}
		
		/**
		 * == operator
		 * @param const Matrix& other
		 * @returns true if matrix == other
		 * **/
		bool operator==(const Matrix& other) const
		{
			// if rows or cols doesn't matches or there is an element that doesn't match return 
			// false
			if (_rows != other._rows || _cols != other._cols)
			{
				return false;
			}
			for (unsigned int i = 0; i < _rows * _cols; i++)
			{
				if (_matrix[i] != other._matrix[i])
				{
					return false;
				}
			}
			return true;
		}
		
		/**
		 * != operator
		 * @param const Matrix& other
		 * @returns true if matrix != other
		 * **/
		bool operator!=(const Matrix& other) const
		{
			//negation of == operator
			return !(*this == other);
		}
		
		/**
		* + operator
		* @param const Matrix& other - a ref to another matrix
		* @returns a new Matrix containing the + of the 2 matricies
		* **/
		const Matrix operator+(const Matrix& other) const
		{
			//case that the dims of the 2 matricies are not equals
			if (_rows != other._rows || _cols != other._cols)
			{
				throw (AddDimsEx());
			}
			Matrix newMatrix = Matrix(_rows, _cols);
			//case of sequential calculating
			if (!_isParallel)
			{
				
				// running on all the vector and adding one by one
				for (unsigned int i = 0; i < _rows * _cols; i++)
				{
					newMatrix._matrix[i] = _matrix[i] + other._matrix[i]; 
				}
			}
			//case of parallel calculating
			else
			{
				// a vector that contains the threads
				vector<thread> threadsVector;
				// creating for each row a thread, push it to the vector 
				// and sending to the claculation func
				for (unsigned int i = 0; i < _rows; i++)
				{
					threadsVector.push_back(thread (&Matrix<T>::_plusCalculate, this, ref(newMatrix),
					                        other, i));	
				}
				// blocks all executions till threadsvector[i] finishes
				for (unsigned int i = 0; i < threadsVector.size(); i++)
				{
					threadsVector[i].join();
				}
			}
			return newMatrix;
		}

		/**
		* - operator
		* @param const Matrix& other - a ref to another matrix
		* @returns a new Matrix containing the - of 2 matricies
		* **/
		const Matrix operator-(const Matrix& other) const
		{
			//case that the dims of the 2 matricies are not equals
			if (_rows != other._rows || _cols != other._cols)
			{
				throw (SubDimsEx());
			}
			Matrix newMatrix = Matrix(_rows, _cols);
			// running on all the vector and subbing one by one
			for (unsigned int i = 0; i < _rows * _cols; i++)
			{
				newMatrix._matrix[i] = _matrix[i] - other._matrix[i]; 
			}
			return newMatrix;	
		}

		/**
		* * operator
		* @param const Matrix& other - a ref to another matrix
		* returns a new Matrix containing the * of 2 matricies
		* **/
		const Matrix operator*(const Matrix& other) const
		{
			// if the matrices dims doesnt fits for matricies multiply
			if (_cols != other._rows)
			{
				throw (MultiplyEx());
			}
			
			Matrix newMatrix = Matrix(this -> _rows, other._cols);
			//case of sequential calculating
			if (!_isParallel)
			{
				for (unsigned int i = 0; i < this -> _rows; ++i)
				{
					for (unsigned int j = 0; j < other. _cols; ++j)
					{
						for (unsigned int k = 0; k < this -> _cols; ++k)
						{
							newMatrix(i, j) += ((*this)(i, k) * other(k, j));
						}
					}
				}
			}
			//case of parallel calculating
			else
			{
				// a vector that contains the threads
				vector<thread> threadsVector;
				// creating for each row a thread, push it to the vector 
				// and sending to the claculation func
				for (unsigned int i = 0; i < _rows; i++)
				{
					threadsVector.push_back(thread (&Matrix<T>::_multiplyCalculate, this, 
					                        ref(newMatrix), other, i));
				}
				// blocks all executions till threadsvector[i] finishes
				for (unsigned int i = 0; i < threadsVector.size(); i++)
				{
					threadsVector[i].join();
				}
			}
			return newMatrix;
		}
		
		/**
		* << operator - print matrix
		* @param ostream& printStream - an output stream
		* @param const Matrix& matrix
		* **/
		friend ostream& operator<<(ostream& printStream, const Matrix& matrix) 
		{
			for (unsigned int i = 0; i < matrix._rows; i++)
			{	
				for (unsigned int j = 0; j < matrix._cols; j++)
				{
					printStream << matrix(i, j) << "\t";
				}				
				printStream << "\n";
			}
			return printStream;
		}
		
// ------------------------------ getters & setters -----------------------------------------------
		/**
		* a getter for rows
		* returns num of rows in the matrix
		* **/
		unsigned int rows() const
		{
			return _rows;
		}
		
		/**
		* a getter for cols
		* returns num of cols in the matrix
		* **/
		unsigned int cols() const
		{
			return _cols;
		}
		
		/**
		 * satic method that set _isParallel with the given bool
		 **/
		static void setParallel(const bool isPar)
		{
			//in case a change is needed
			if(_isParallel != isPar)
			{
				//change to true and to parallel mode
				if (!_isParallel)
				{
					_isParallel = !_isParallel;
					cout << "‫‪Generic Matrix mode changed to parallel mode. ‬‬" << endl;
				}
				else
				{
					_isParallel = !_isParallel;
					cout << "‫‪Generic Matrix mode changed to non­parallel mode. ‬‬" << endl;
				} 
			}
		}
		
// ------------------------------ methods ---------------------------------------------------------
		/**
		 * a function that checks if the matrix is square
		 * @returns true if _rows == _cols, else false
		 **/ 
		bool isSquareMatrix()
		{
			return (rows() == cols());
			
		}
		
		/**
		 * const iterator begin
		 **/
		const_iterator begin() const
		{
			return _matrix.begin();
		}
		
		/**
		 * const iterator end
		 **/
		const_iterator end() const
		{
			return _matrix.end();
		}
		
		/**
		* trans the matrix
		* @returns a Matrix which is the transed matrix
		* **/
		Matrix trans() const
		{
			Matrix transedMatrix = Matrix(_cols, _rows);
			for (unsigned int i = 0; i < _rows; i++)
			{
				for (unsigned int j = 0; j < _cols; j++)
				{
					transedMatrix(j, i) = (*this)(i, j);
				}		
			}
			return transedMatrix;	
		}
		
		/**
		* @returns trace - return the sum of the vals on the diagonal
		* **/
		T trace() const
		{
			// not a square matrix
			if (cols() != rows())
			{
				throw (NotSquareMatrixEx());
			}
			
			T traceSum = T();
			for (unsigned int i = 0; i < _rows; i++)
			{
				traceSum += (*this)(i, i);
			}
			return traceSum;	
		}
		

			
};

/**
* trans a Complex matrix
* @returns a matrix which is the transed matrix
* **/
template <> Matrix<Complex> Matrix<Complex>::trans() const
{
	Matrix transedMatrix = Matrix(_cols, _rows);
	for (unsigned int i = 0; i < _rows; i++)
	{
		for (unsigned int j = 0; j < _cols; j++)
		{
			transedMatrix(j, i) = (*this)(i, j).conj();
			
		}		
	}
	return transedMatrix;
}
template <class T> bool Matrix<T>::_isParallel = false;

#endif // _MATRIX_HPP_
