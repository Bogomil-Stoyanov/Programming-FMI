#include <iostream>
#include <cmath>

int main()
{
    // ideqta e log a b = log b / log a

    int a = 0, b = 0;

    std::cin >> a >> b;

    int logResult = floor(log(a) / log(b));

    std::cout << logResult << std::endl;
}