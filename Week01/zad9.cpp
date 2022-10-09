#include <iostream>

int main()
{

    int a, b;

    std::cin >> a >> b;

    for (int i = a + 1; i < b; i++)
    {
        // std::cout<<i<<std::endl;
        int num = i;

        int evenSum = 0;
        int oddSum = 0;
        int evenProduct = 1;
        int oddProduct = 1;

        bool isEven = false;

        while (num > 0)
        {
            int digit = num % 10;
            num /= 10;

            if (isEven)
            {
                evenSum += digit;
                evenProduct *= digit;
            }
            else
            {
                oddSum += digit;
                oddProduct *= digit;
            }

            isEven = !isEven;
        }

        if (evenProduct == oddProduct && evenSum == oddSum)
        {
            std::cout << i << std::endl;
        }
    }
}