********************************************************************
POSTFIX EVALUATOR PROGRAM
********************************************************************

DESCRIPTION
********************************************************************
The following is the submitted assignment for Computer Science 2720: 
Practical Software Development.The assignment revolves around the 
concept of test driven developement as well as the concept of git and 
it's subsidaries. I felt it necessary to change the Tokenizer class to 
one that was more suitable for develepment. I felt that the old
Tokenizer didn't open up the potential to my TDD molding until it was 
modified in such a way that it was completely accessible to me for 
testing. As for testing, the only thing I could not get to succeed was 
the final evaluation test. The numbers popped out as identical twins, 
but the CPPUNIT comparision failed every single time. Thus, I have
left it as a sentiment to my head banging as I have yet to conclude what 
this crazinessthat is bestowed upon this program be.

HOW TO USE
*********************************************************************
The program doesn't provide any user prompt to (as that is what is
defined in the assignment protocol). However, upon initial evaluation of
required standards, it was quite convaluted to the nature of the 
how the user was supposed to input, whether it be via a fileName or
actual standard input. So, upon much deliberation, I've concluded to
add functionality for both options into the program. Here's how it
works:

To begin by using a file, you start by typing the following exactly
as it is shown:

file

Once you type this, you will be prompted to enter in a fileName for
which to grab information from which is pretty standard. Ensure the
file is properly formatted, or you will receive errors. Each postfix
expression must be concluded by the '\n' symbol (known in the common
language as the ENTER or RETURN key), so forgetting to conclude a
statement in that will throw up an exception.

To begin using regular user input, you start by typing the following
exactly as it is shown:

input

Once you type this, you will be prompted to type in your first
expression, which again, must be in perfect postfix form or an error
will be thrown. Here's an example of a well formed solvable postfix
expression:

1 3 + 9 -

This will equate to -5.

To stop this program, one of three things can happen:
A) The end of the file can be reached
B) Using CTRL+D to close the terminal
C) Using CTRL+C to kill the current process

Any other questions or concerns can be shot towards my email at
josh.tymburski@uleth.ca
