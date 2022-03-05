#include <iostream>
#include <stack>
#include <string>
using namespace std;


int priority(char c)
{
    if (c == '-' || c == '+')
        return 1;

    else if (c == '*' || c == '/')
        return 2;

    else if (c == '^')
        return 3;

    else
        return 0;
}


string infixToPrefix(string exp)
{
    stack<char> stk;
    string outPut = "";

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == ' ') continue;

        else if (isdigit(exp[i]) || isalpha(exp[i]))
            outPut += exp[i];

        else if (exp[i] == '(')
            stk.push(exp[i]);

        else if (exp[i] == ')')
        {
            while (stk.top() != '(')
            {
                outPut += stk.top();
                stk.pop();
            }
            stk.pop();
        }

        else
        {
            while (!stk.empty() && priority(exp[i]) <= priority(stk.top()))
            {
                outPut += stk.top();
                stk.pop();
            }

            stk.push(exp[i]);
        }
        
    }

    while (!stk.empty())
    {
        outPut += stk.top();
        stk.pop();
    }

    return outPut;
}

int main()
{
    string exp = ("(3+2)+7/2*((7+3)*2)");

    cout << infixToPrefix(exp);

    system("pause>0");
}
