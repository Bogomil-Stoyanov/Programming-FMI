#include <iostream>

int main()
{

    double x, y;

    std::cin >> x >> y;

    // uravnenieto na ednata prava e (x+1)-y=0,
    // a na drugata e (x+3)-3y=0

    double distance = (x - (-1)) * (x - (-1)) + (y - 1) * (y - 1);
    if (distance < 1 && (x + 1) - y < 0 && (x + 3) - 3 * y > 0)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
}
