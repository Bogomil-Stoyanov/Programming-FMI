#include <iostream>

int main()
{
    int n = 0;

    std::cin >> n;

    char empty = ' ';

    for (int i = 1; i <= n; i++)
    {
        if (i != n)
            printf("%*c", n - i, empty);
        for (int j = 0; j < i; j++)
        {
            std::cout << "# ";
        }
        std::cout << std::endl;
    }
}
