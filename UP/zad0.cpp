#include <iostream>

int main()
{
    int number = 0;
    std::cin >> number;

    int binary = 0;

    int binaryNumberArray[32];

    int i = 0;
    while (number > 0)
    {
        binaryNumberArray[i] = number % 2;
        number = number / 2;
        i++;
    }

    int longestSequenceOfOnes = -1;
    int currentSequence = 0;

    for (int j = 0; j < i; j++)
    {
        if (binaryNumberArray[j] == 1)
        {
            currentSequence++;
        }
        else
        {
            if (currentSequence > longestSequenceOfOnes)
            {
                longestSequenceOfOnes = currentSequence;
            }
            currentSequence = 0;
        }
    }

    if (currentSequence > longestSequenceOfOnes)
    {
        longestSequenceOfOnes = currentSequence;
    }

    std::cout << longestSequenceOfOnes << std::endl;
}
