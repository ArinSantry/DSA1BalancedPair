#include <fstream>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// check that punctuation are in correct pairs
bool ArePair(char opening, char closing)
{
	if (opening == '(' && closing == ')')
		return true;
	else if (opening == '[' && closing == ']')
		return true;
	else if (opening == '{' && closing == '}')
		return true;
	else if (opening == '<' && closing == '>')
		return true;
	else
		return false;
}

// STACKS!
bool AreBalanced(string exp)
{
	stack<char> parStack;
	for (int i = 0; i < exp.length(); i++)
	{
		// if there is an opening punctuation, push it onto the stack
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{' || exp[i] == '<')
			parStack.push(exp[i]);
		// if there is a closing punctuation...
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}' || exp[i] == '>')
		{
			// if the stack is empty or the top of the stack is not a pair with the character, 
			// then the string is not balanced
			if (parStack.empty() || !ArePair(parStack.top(), exp[i]))
				return false;
			else // otherwise, pop the top of the stack
				parStack.pop();
		}
	}
	// if the stack is empty by the end of this function, then the string is balanced
	// if not, the string is not balanced
	return parStack.empty() ? true : false;
}

int main()
{
	ifstream inStream;
	ofstream outStream;
	inStream.open("testme.txt"); // test input file
	outStream.open("results.txt"); // where the results will be stored
	string expression;

	if (inStream.fail())
	{
		cout << "File not found \n";
	}
	else 
	{
		while (getline (inStream, expression))
		{
			outStream << expression;
			if (AreBalanced(expression))
				outStream << " --- correct" << endl;
			else
				outStream << " --- incorrect" << endl;
		}
	}

	do // so console does not close immediately
	{
		cout << '\n' << "Press a key to continue...";
	} while (cin.get() != '\n');

	// close the streams!!
	inStream.close();
	outStream.close();
	return 0;
}