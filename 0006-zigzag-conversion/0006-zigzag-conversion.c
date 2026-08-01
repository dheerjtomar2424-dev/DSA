#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows)
{
    int len = strlen(s);

    if (numRows == 1 || numRows >= len)
        return strdup(s);

   
    char **rows = (char **)malloc(numRows * sizeof(char *));
    int *sizes = (int *)calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++)
        rows[i] = (char *)malloc((len + 1) * sizeof(char));

    int currentRow = 0;
    int direction = 1;

    for (int i = 0; i < len; i++)
    {
        rows[currentRow][sizes[currentRow]++] = s[i];

        if (currentRow == 0)
            direction = 1;
        else if (currentRow == numRows - 1)
            direction = -1;

        currentRow += direction;
    }

    // Combine all rows
    char *result = (char *)malloc((len + 1) * sizeof(char));
    int index = 0;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
            result[index++] = rows[i][j];

        free(rows[i]);
    }

    result[index] = '\0';

    free(rows);
    free(sizes);

    return result;
}