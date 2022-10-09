#include <iostream>

int main()
{

    int n = 0;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            printf("%*c", n - (i + 1), ' ');
        std::cout << "/";
        if (i != 0)
            printf("%*c", i * 2, ' ');
        std::cout << "\\\n";
    }

    for (int i = 0; i < n * 2; i++)
    {
        std::cout << "-";
    }

    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << "|";
        printf("%*c", n * 2 - 2, ' ');
        std::cout << "|" << std::endl;
    }

    for (int i = 0; i < n * 2; i++)
    {
        std::cout << "=";
    }

    std::cout << std::endl;
}