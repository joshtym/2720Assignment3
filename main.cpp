// Program Information
/*
 * Course: CPSC2720 Spring 2014
 * Name: Josh Tymburski
 * Assignment #3
 * Main Running File
 * Professor: Robert  Benkoczi
 * Program Name: main.cpp
 * Software Used: Geany
*/
#include "PostfixExpr.h"
#include <fstream>
#include <iostream>

/// Prototype Function to help process the string
void processExpression(std::string);

/// Main Function
int main()
{
	// Variable Declarions
	std::string expression, fileName, choice;
	std::ifstream inFile;
	
	/**
	 * Introduction to the program
	 * Gives a layout of where to head to to understand how
	 * to best utilize this specific program
	**/
	std::cout << "*************************************************";
	std::cout << std::endl;
	std::cout << "Welcome to the Postfix Evaluator Program. Please view";
	std::cout << std::endl;
	std::cout << "the README.txt file for full information on how to";
	std::cout << std::endl;
	std::cout << "properly utilize this program." << std::endl;
	std::cout << "*************************************************";
	std::cout << std::endl;
	
	// User chooses what interface he would like
	std::cin >> choice;
	
	if (choice == "file")
	{
		// Get file name
		std::cout << "Please enter the file name you want to use: ";
		
		// Open file
		std::cin >> fileName;
		inFile.open(fileName.c_str());
		
		// Loop through until end of file
		while (!inFile.eof())
		{
			// Get input and process
			std::getline(inFile, expression, '\n');
			processExpression(expression);
		}
	}
	else if (choice == "input")
	{
		// Keep looping through till user forcefully closes program
		while (choice == "input")
		{
			// Get input and process expression
			std::cout << "Please enter a postfix expression to evaluate: ";
			std::getline(std::cin, expression, '\n');
			processExpression(expression);
		}
	}
	
	return 0;
}

/// Function Definition
/** 
 * Does the actual processesing by using exceptions to catch bad
 * equations. Evaluates expressions and prints to screen
**/
void processExpression(std::string givenExpression)
{
	// Local Variables
	PostfixExpr* Evaluator = new PostfixExpr();
	
	// Ensure we're not trying to process an empty string which
	// can occur at the end of an input or file
	if (!givenExpression.empty())
	{
		// Try the following statements, throwing an exception if
		// we run across a Lexical error or Syntax error
		try
		{
			// Repeat given input to user
			std::cout << "The given expression is as follows:" << std::endl;
			std::cout << givenExpression << std::endl << std::endl;
			
			// Evaluate given input to user
			std::cout << "Evaluated value equates to the following:" << std::endl;
			std::cout << Evaluator->evaluate(givenExpression) << std::endl;
			std::cout << std::endl;
		}
		catch (const SyntaxError& se)
		{
			// Print out error message
			std::cout << se.what() << std::endl;
		}
		catch (const LexicalError& le)
		{
			std::cout << le.what() << std::endl;
		}
	}
	// Deallocate allocated memory
	delete Evaluator;
}
