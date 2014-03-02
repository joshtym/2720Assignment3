#include "PostfixExpr.h"
#include <fstream>
#include <iostream>

int main()
{
	// Variable Declarions
	std::string expression, fileName;
	PostfixExpr* Evaluator = new PostfixExpr();
	std::ifstream inFile;
	
	std::cout << "Please enter the input file name: ";
	std::cin >> fileName;
	
	// Open file
	inFile.open(fileName.c_str());
	while (!inFile.eof())
	{
		std::getline(inFile, expression, '\n');
		if (expression != "")
		{
			try
			{
				std::cout << "The given expression is as follows:" << std::endl;
				std::cout << expression << std::endl << std::endl;
				std::cout << "Evaluated value equates to the following:" << std::endl;
				std::cout << Evaluator->evaluate(expression) << std::endl;
				std::cout << std::endl;
			}
			catch (const SyntaxError& se)
			{
				std::cout << se.what() << std::endl;
			}
			catch (const LexicalError& le)
			{
				std::cout << le.what() << std::endl;
			}
		}
	}
	
	delete Evaluator;
	
	return 0;
}
	
