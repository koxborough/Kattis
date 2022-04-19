#include <stdio.h>
#include <stdlib.h>

int sumOfDivisors(int num);

int main()
{
    int num;
    while (scanf("%d", &num) == 1)
    {
        // Calls the function to find the sum of the divisors
        int sum = sumOfDivisors(num);

        if (sum == num)
        {
            printf("%d perfect", num);
        }
        else if (abs(sum - num) <= 2) // Can use the absolute value to find the net difference
        {
            printf("%d almost perfect", num);
        }
        else
        {
            printf("%d not perfect", num);
        }
        printf("\n");
    }

    return 0;
}

int sumOfDivisors(int num)
{
    // No matter what, 1 divides into any number
    int sum = 1;

    // Only need to check the first half of the numbers because a number
    // will never be divisible by more than half of it
    int j = (num / 2) + 1;

    for (int i = 2; i < j; i++)
    {
        // It goes in perfectly, so add it to the sum
        if (num % i == 0)
        {
            sum += i;

            // The for loop does not need to check any numbers above it 
            j = (num / i);

            // Checks if the divisor is a square as to not count it twice (4*4)
            if (i != j)
                sum += j;
        }
    }
    return sum;
}
