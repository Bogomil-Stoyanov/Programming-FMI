#include <iostream>

int main()
{

    int n = 0;

    std::cin >> n;

    int onCurrentLine = 0;
    int currentLine = 1;

    for (int i = 1; i <= n; i++)
    {
        std::cout << i;
        onCurrentLine++;
        if (onCurrentLine == currentLine)
        {
            std::cout << std::endl;
            onCurrentLine = 0;
            currentLine++;
        }
    }
}