#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class Token
{
public:
    enum Operation
    {
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        OPEN_BRACKET,
        CLOSE_BRACKET,
        UNSPECIFIED
    };

    Token(char operation)
    {
        switch (operation)
        {
        case '+':
            op = PLUS;
            break;
        case '-':
            op = MINUS;
            break;
        case '*':
            op = MULTIPLY;
            break;
        case '/':
            op = DIVIDE;
            break;
        case '(':
            op = OPEN_BRACKET;
            break;
        case ')':
            op = CLOSE_BRACKET;
            break;
        default:
            op = UNSPECIFIED;
            break;
        }
    }

    Token(Operation op)
    {
        this->op = op;
    }
    Token(double num)
    {
        number = num;
        op = UNSPECIFIED;
    }

    bool isNumber()
    {
        return op == UNSPECIFIED;
    }

    bool isOperator()
    {
        return !isNumber();
    }

    double getNumber()
    {
        if (!isNumber())
        {
            throw "Not a number!";
        }
        return number;
    }

    Operation getOperator()
    {
        return op;
    }

    void printSymbol()
    {
        if (isNumber())
        {
            cout << number;
        }
        else
        {
            switch (op)
            {
            case PLUS:
                cout << "+";
                break;
            case MINUS:
                cout << "-";
                break;
            case MULTIPLY:
                cout << "*";
                break;
            case DIVIDE:
                cout << "/";
                break;
            default:
                break;
            }
        }
    }

private:
    Operation op;
    double number;
};

vector<Token> expressionToPolish(string input)
{
    queue<Token> out;
    stack<Token> sign;

    string currentNumber;

    for (int i = 0; i < input.length(); i++)
    {
        char current = input[i];
        if (current >= '0' && current <= '9')
        {
            currentNumber += current;
            if (i == input.length() - 1)
            {
                out.push(Token(stod(currentNumber)));
                currentNumber.clear();
            }
        }
        else
        {
            if (!currentNumber.empty())
            {
                out.push(Token(stod(currentNumber)));
                currentNumber.clear();
            }

            if (current != ' ')
            {
                if (current == '*' || current == '/' || current == '(')
                {
                    sign.push(Token(current));
                }
                else if (current == '+' || current == '-')
                {
                    if (!sign.empty())
                    {
                        if (sign.top().getOperator() == Token::MULTIPLY || sign.top().getOperator() == Token::DIVIDE)
                        {
                            out.push(sign.top());
                            sign.pop();
                            sign.push(Token(current));
                        }
                        else
                        {
                            sign.push(Token(current));
                        }
                    }
                    else
                    {
                        sign.push(Token(current));
                    }
                }
                else if (current == ')')
                {
                    while (sign.top().getOperator() != Token::OPEN_BRACKET)
                    {
                        out.push(sign.top());
                        sign.pop();
                    }
                    sign.pop();
                }
            }
        }
    }

    while (!sign.empty())
    {
        out.push(sign.top());
        sign.pop();
    }

    string result = "";
    vector<Token> tokens;

    while (!out.empty())
    {
        // cout << out.front() << " ";
        tokens.push_back(out.front());
        // tokens.pop_back()
        out.pop();
    }
    return tokens;
}

int evaluatePolish(vector<Token> tokens)
{
    stack<double> mystack;
    for (Token token : tokens)
    {

        if (token.isNumber())
        {
            mystack.push(token.getNumber());
        }
        else
        {
            double a = mystack.top();
            mystack.pop();
            double b = mystack.top();
            mystack.pop();

            if (token.getOperator() == Token::MINUS)
            {
                mystack.push(b - a);
            }

            if (token.getOperator() == Token::PLUS)
            {
                mystack.push(b + a);
            }

            if (token.getOperator() == Token::MULTIPLY)
            {
                mystack.push(b * a);
            }

            if (token.getOperator() == Token::DIVIDE)
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
    // cout << evaluatePolish(expressionToPolish("(1+2)*3+4"));
    // cout << evaluatePolish(expressionToPolish("(1+5)*2+4"));
    // vector<Token> res = expressionToPolish("(1+5)*2+4");
    // for (Token token : res)
    // {
    //     token.printSymbol();
    //     cout << " ";
    // }

    cout << evaluatePolish(expressionToPolish("(10+5)*2+4"));
}
