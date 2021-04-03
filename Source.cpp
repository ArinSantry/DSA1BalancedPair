#include <fstream>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

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

bool AreBalanced(string exp)
{
	stack<char> parStack;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{' || exp[i] == '<')
			parStack.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}' || exp[i] == '>')
		{
			if (parStack.empty() || !ArePair(parStack.top(), exp[i]))
				return false;
			else
				parStack.pop();
		}
	}
	return parStack.empty() ? true : false;
}

int main()
{
	ifstream inStream;
	ofstream outStream;
	inStream.open("testme.txt");
	outStream.open("results.txt");
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

	inStream.close();
	outStream.close();
	return 0;
}