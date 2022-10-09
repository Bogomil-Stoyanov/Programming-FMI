#include <iostream>

int main()
{

    int a, b;

    std::cin >> a >> b;

    int equalPositions = 0;
    while (a > 0)
    {
        if (a % 10 == b % 10)
            equalPositions++;
        a /= 10;
        b /= 10;
    }

    std::cout<<equalPositions<<std::endl;
}