#include <stdio.h>

int main()
{
    long long int first, second, answer;

    // Continue until there is no input
    while (scanf("%lld %lld", &first, &second) == 2)
    {
        answer = first - second;

        // Answer cannot be negative
        if (answer < 0)
            answer *= -1;

        printf("%lld\n", answer);
    }

    return 0;
}
