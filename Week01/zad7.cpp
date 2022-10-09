#include <iostream>

int main()
{

    int n = 0;

    std::cin >> n;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < i)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << j;
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= n - (i + 2))
            {
                std::cout << " ";
            }
            else
            {
                std::cout << j;
            }
        }
        std::cout << std::endl;
    }
}