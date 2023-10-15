#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

string expressionToPolish(string input)
{
    queue<char> out;
    stack<char> sign;

    for (int i = 0; i < input.length(); i++)
    {
        char current = input[i];
        if (current >= '0' && current <= '9')
        {
            out.push(current);
        }
        else if (current != ' ')
        {
            if (current == '*' || current == '/' || current == '(')
            {
                sign.push(current);
            }
            else if (current == '+' || current == '-')
            {
                if (!sign.empty())
                {
                    if (sign.top() == '*' || sign.top() == '/')
                    {
                        out.push(sign.top());
                        sign.pop();
                        sign.push(current);
                    }
                    else
                    {
                        sign.push(current);
                    }
                }
                else
                {
                    sign.push(current);
                }
            }
            else if (current == ')')
            {
                while (sign.top() != '(')
                {
                    out.push(sign.top());
                    sign.pop();
                }
                sign.pop();
            }
        }
    }

    while (!sign.empty())
    {
        out.push(sign.top());
        sign.pop();
    }

    string result = "";
    while (!out.empty())
    {
        // cout << out.front() << " ";
        result = result + out.front() + " ";
        out.pop();
    }
    return result;
}

int evaluatePolish(string input)
{
    stack<double> mystack;
    bool isPrevNum = false;
    // int currentNum;
    for (int i = 0; i < input.length(); i++)
    {
        char current = input[i];
        if (current >= '0' && current <= '9')
        {
            // if(isPrevNum){

            //}else{

            mystack.push(current - '0');
            // }
        }
        else if (current != ' ')
        {
            int a = mystack.top();
            mystack.pop();
            int b = mystack.top();
            mystack.pop();

            if (current == '-')
            {
                mystack.push(b - a);
            }

            if (current == '+')
            {
                mystack.push(b + a);
            }

            if (current == '*')
            {
                mystack.push(b * a);
            }

            if (current == '/')
            {
                mystack.push(b / a);
            }
        }
    }

    return mystack.top();
}

int main()
{
    string input;
    // getline(cin, input);
    cout << evaluatePolish(expressionToPolish("(1+2)*3+4"));
}
