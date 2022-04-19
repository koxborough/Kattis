#include <stdio.h>
#include <stdlib.h>

void MergeSort(int values[], int start, int end);
void Merge(int values[], int start, int middle, int end);
int Find(int array[], int num);

int main()
{
    int num, min;

    scanf("%d", &num);

    int *array = malloc(num * sizeof(int));

    // Reads in the book prices
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
    }

    // Sorts the array
    MergeSort(array, 0, (num-1));

    // Find the optimal price of the books
    min = Find(array, num);
    printf("%d", min);

    // Free the dynamic memory
    free(array);

    return 0;
}

void MergeSort(int values[], int start, int end) 
{
    int mid;
  
    // Check if our sorting range is more than one element.
    if (start < end) {

        mid = (start+end)/2;
    
        // Sort the first half of the values.
        MergeSort(values, start, mid);
    
        // Sort the last half of the values.
        MergeSort(values, mid+1, end);
    
        // Put it all together.
        Merge(values, start, mid+1, end);
    }
}

void Merge(int values[], int start, int middle, int end) {

    int *temp, i, length, count1, count2, mc;
  
    // Allocate the proper amount of space for our auxiliary array.
    length = end - start + 1;
    temp = (int*)calloc(length, sizeof(int));

    // These will be our indexes into our two sorted lists.
    count1 = start;
    count2 = middle;
  
    // Keeps track of our index into our auxiliary array.
    mc = 0;

    // Here we copy values into our auxiliary array, so long as there are 
    // numbers from both lists to copy.
    while ((count1 < middle) || (count2 <= end)) {

        // Next value to copy comes from list one - make sure list
        // one isn't exhausted yet. Also make sure we don't access index
        // count2 if we aren't supposed to.
        if (count2 > end || (count1 < middle && values[count1] < values[count2])) {
            temp[mc] = values[count1];
            count1++;
            mc++;
        }
    
        // We copy the next value from list two.
        else {
            temp[mc] = values[count2];
            count2++;
            mc++;
        }
    }

    // Copy back all of our values into the original array.
    for (i=start; i<=end; i++)
        values[i] = temp[i - start];

    // Don't need this space any more!
    free(temp);
}

int Find(int array[], int num)
{
    int min = 0, val = num - 1;

    // If there is only one book
    if (num == 1)
    {
        min = array[0];
        return min;
    }

    // There are two books
    else if (num == 2)
    {
        min += array[0];
        min += array[1];
        return min;
    }

    // Add the price of books together
    while (val > 0)
    {
        min += array[val];
        min += array[val-1];
        val -= 3;
    }

    // Make sure the first book is added
    if (num % 3 == 1)
    {
        min += array[0];
    }

    return min;
}
