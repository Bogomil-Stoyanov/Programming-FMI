#include <iostream>

int main()
{

    int a = 0, b = 0;

    std::cin >> a >> b;

    int numCount = 0;

    for (int i = a; i <= b; i++)
    {
        int sumOfDigits = 0;
        int productOfDigits = 1;
        int number = i;

        while (number > 0)
        {
            int digit = number % 10;
            sumOfDigits += digit;
            productOfDigits *= digit;
            number /= 10;

           
        }
         if (sumOfDigits == productOfDigits)
                numCount++;
    }

    std::cout<<numCount<<std::endl;
}
