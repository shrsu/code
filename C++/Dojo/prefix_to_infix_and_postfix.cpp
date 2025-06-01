#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string prefixToInfix(const string &prefix)
{
    stack<string> operands;

    // Traverse the prefix expression from right to left
    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        char c = prefix[i];
        if (isOperator(c))
        {
            // Pop two operands and concatenate them with the operator
            string operand1 = operands.top();
            operands.pop();
            string operand2 = operands.top();
            operands.pop();
            string expression = "(" + operand1 + c + operand2 + ")";
            operands.push(expression);
        }
        else if (isalnum(c))
        {
            // If operand, push it onto the stack
            operands.push(string(1, c));
        }
    }

    // The result is at the top of the stack
    return operands.top();
}

string prefixToPostfix(const string &prefix)
{
    stack<string> operands;

    // Traverse the prefix expression from right to left
    for (int i = prefix.size() - 1; i >= 0; i--)
    {
        char c = prefix[i];
        if (isOperator(c))
        {
            // Pop two operands and concatenate them with the operator
            string operand1 = operands.top();
            operands.pop();
            string operand2 = operands.top();
            operands.pop();
            string expression = operand1 + operand2 + c;
            operands.push(expression);
        }
        else if (isalnum(c))
        {
            // If operand, push it onto the stack
            operands.push(string(1, c));
        }
    }

    // The result is at the top of the stack
    return operands.top();
}

int main()
{
    string prefix_expression = "-+AB*CD";
    string infix_expression = prefixToInfix(prefix_expression);
    cout << "Prefix Expression: " << prefix_expression << endl;
    cout << "Infix Expression: " << infix_expression << endl;
    return 0;
}
