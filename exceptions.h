#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

// CPSC 2720 : Exception classes used in Assignment 3

#include <stdexcept>

/// Exception thrown in case a syntax error is discovered
/**
 * \sa {LexicalError}
**/
class SyntaxError : public std::runtime_error
{
	public:
		/// Constructs an error object by passing a message
		explicit SyntaxError(const std::string& msg) : 
		                     runtime_error(msg) {};
		
		/// Constructs an error object by passing a message
		explicit SyntaxError(const char* msg) : runtime_error(msg) {};
};


/// Exception thrown in case a lexical error is discovered
/**
 * Inherits from sttd::runtime_error.
 * Construct an object by passing a string or cstring as message. Use
 * the what function to access the message passed at consturction.
**/
class LexicalError : public std::runtime_error
{
	public:
		/// Constructs an error object by passing a message
		explicit LexicalError(const std::string& msg) : 
		                      runtime_error(msg) {};
		
		/// Constructs an error object by passing a message
		explicit LexicalError(const char* msg) : runtime_error(msg) {};
};

#endif
