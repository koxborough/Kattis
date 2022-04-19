#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// maximum size of sky
#define MAX 100

// number of cardinal directions
#define NUM_MOVES 4

// Cardinal directions
const int DX[] = {-1,0,0,1};
const int DY[] = {0,-1,1,0};

int solve(char map[][MAX+1], int rows, int cols);
void floodfill(char map[][MAX+1], int rows, int cols, int x, int y, char oldfill, char newfill);

int main()
{
    int loop;

    // Maximum number of test cases
    for (loop = 1; loop <= 50; loop++)
    {
        int m, n;

        // way to check if more information will be input
        if ((scanf("%d", &m)) != 1)
            break;

        // way to check if more information will be input
        if ((scanf("%d", &n)) != 1)
            break;

        // Reads in the sky
        char sky[MAX][MAX+1];
        for (int i = 0; i < m; i++)
            scanf("%s", sky[i]);

        // Prints the number of stars
        int stars = solve(sky, m, n);
        printf("Case %d: %d\n", loop, stars);
    }

    return 0;
}

int solve(char map[][MAX+1], int rows, int cols) {

    int i, j, numregions = 0;

    // Go through each pixel.
    for (i=0; i<rows; i++) {

        for (j=0; j<cols; j++) {

            // Found a new piece of star, so run a floodfill
            if (map[i][j] == '-') {
                numregions++;
                floodfill(map, rows, cols, i, j, '-', 'X');
            }
        }
    }
    return numregions;
}

// Fills the region adjacent to (x, y) in map that was previously marked by
// oldfill with newfill.
void floodfill(char map[][MAX+1], int rows, int cols, int x, int y, char oldfill, char newfill) {

    // Deal with out of bounds here easily.
    if (x < 0 || x >= rows || y < 0 || y >= cols)
        return;

    // Not the character we're filling.
    if (map[x][y] != oldfill)
        return;

    // Fill this slot with the new character.
    map[x][y] = newfill;

    // Here's the recursion - note that we need no if statements because
    // we check for everything up front in our base cases.
    int i;
    for (i=0; i<NUM_MOVES; i++)
        floodfill(map, rows, cols, x+DX[i], y+DY[i], oldfill, newfill);
}
