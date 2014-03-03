// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #3
 * Class Interface
 * Professor: Robert  Benkoczi
 * Program Name: Tokenizer.h
 * Software Used: Geany
*/
#ifndef __TOKENIZER_H
#define __TOKENIZER_H

#include <string>
#include <vector>

/// A simple lexical analyzer
/**
 * Tokenizer parses string values and recognizes floating point
 * values and arithmetic operators. 
**/

class Tokenizer
{
	public:
		/// Identifiers for the kinds of tokens recognized
		enum class Tokens
		{
			LITERAL,   /**< the token is a value */
			OPERATOR,  /**< the token is an operator */
			UNKNOWN,   /**< the token is unrecognized */
			THEEND     /**< no token, the end of the string has been 
			            **<  reached */
		};
		
		/// Identifiers for the three different operators recognized
		enum class OperatorValue
		{
			STAR,   /**< the operator is multiplication (*) */
			PLUS,   /**< the operator is addition (+) */
			MINUS,  /**< the operator is subtraction (-) */
			SLASH   /**< the operator is fractional division (/) */
		};
		
		/// Type used for the value associated with a token
		union TokenValue
		{
			double literalVal;   /**< the value of a token if 
			                      **< it is a literal */
			OperatorValue opVal;
			
			/// Constructors
			/** With these contructors, one can use TokenValue
			 * expressions directly as in TokenValue(OperatorValue::PLUS)
			 * \param op the value for a operator token
			**/
			
			TokenValue(OperatorValue op) : opVal(op) {};
			/** Constructor allowing the use of TokenValue expressions
			 * directly as in TokenValue(2.5)
			 * \param val the value of a token representing a literal
			 * or value
			**/
			
			TokenValue(double val) : literalVal (val) {};
			/**
			 * By default, a TokenValue represents value 0.0 for a
			 * literal token
			**/
			
			TokenValue() : TokenValue(0.0) {}
		};
		
		/// Call to specify the string to be parsed
		/**
		 * \param str the string that will be parsed. After the call,
		 * the string will be successfully broken down into it's tokens
		 * and stored in the vector that will be returned by utilizing
		 * the other functions. This is done by determining possible
		 * delimiteres that would fall in a post fix expression. 
		 * IE, if the current value is a number, then a delimiter will
		 * consist of either a space or an operator. If it is an
		 * operator, than the delimiter consists of a space, number, 
		 * or another operator
		**/
		std::vector<std::string> parse(const std::string str);
		
		/// Current token type, operator, or literal
		/**
		 * \return a Tokens enum value representing the type of token
		 * parsed.
		**/
		Tokens crtTokenType(const std::string str);
		
		/// The value associated with the current token
		/**
		 * \return a TokenValue union representing the value of the
		 * token. If the current token is a literal, then the literalVal
		 * field equals the value of the literal. If the token is an 
		 * operator, then the opVal field identifies the operation
		**/
		
		TokenValue crtTokenValue(const std::string str);
		
		/// Determines next delimiter in the expression
		/**
		 * The string is evaluated from it's last delimiter and the
		 * next position of the delimiter is evaluated. and returned
		 * so that the actual parsing function can parse what the next 
		 * token will be
		**/
		int nextToken(const std::string str, int startingPos);
		
		private:
			/// Converts current string to a double
			/**
			 * Takes value of the current string and converts it,
			 * using a number of methods, to a usuable equivalent
			 * double value.
			**/
			double convertStringToDouble(const std::string);
		
			// Private data member
			bool delimiterIsSpace;
};

#endif
			                     
