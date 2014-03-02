// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #3
 * Class Interface
 * Professor: Robert  Benkoczi
 * Program Name: PostfixExpr.h
 * Software Used: Geany
*/
#ifndef __POSTFIXEXPR_H
#define __POSTFIXEXPR_H

#include "exceptions.h"
#include "Tokenizer.h"
#include <string>

/// Reponsibility: Evaluating postfix expressions.
/**
 * Expressions consist only of literal fractional values and the four
 * arithmetic operators.
**/
class PostfixExpr
{
	public:
	
		/// Evaluates a postfix expression
		/**
		 * Evaluates a postfix expression consisting only of positive
		 * values and the four operators '+', '-', '/', and '*'.
		 * \param expr is the string containing the expression to be
		 * evaluated
		 * \return the value of the expression
		 * \throws SyntaxError if the expression is mal formed.
		 * \throws LexicalError if the expression contains illegal
		 * characters
		**/
		double evaluate(std::string expr);
		
	private:
		/// Helper function to check validity of string
		/**
		 * Views strings and performs a number of checks on it. Starts
		 * by going through the string and ensuring no invalid
		 * characters are located. 
		 * \param expr is the string containing the expression to check
		 * for validity
		 * Valid characters are numbers, decimal
		 * points, operators, and spaces. It then checks for syntactical
		 * malformation. If the first character is an operator, then
		 * it is malformed. If the last character is a number, then it
		 * is malformed. If the number of operators is not equal to the
		 * number of literals minus one, then it is malformed.
		**/
		void checkValidity(std::string expr);
};

#endif
