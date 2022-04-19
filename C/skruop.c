#include <stdio.h>
#include <string.h>

int main()
{
    // Temperature the thermostat is automatically set to
    int n = 7;

    // Maximum length of a string in this case is 10
    char instruction[5];

    // Because C cannot read in spaces, we need to make sure the "Skru" doesn't break it
    char unnecessary[4];

    int loops;
    scanf("%d", &loops);
    for (int i = 0; i < loops; i++)
    {
        scanf("%s %s", unnecessary, instruction);

        // If the request says to turn the temp up and we are not at the maximum temp
        if (strcmp(instruction, "op!") == 0)
        {
            if (n != 10)
            {
                n++;
            }
        }
        else
        {
            // Checks if we are not at the minimum temp
            if (n != 0)
            {
                n--;
            }
        }
    }
    printf("%d", n);
}
