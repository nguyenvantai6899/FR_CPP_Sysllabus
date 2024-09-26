#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *f;
    f = fopen("D:/C++/FPT/Learn/file/test.txt", "r");
    if (f == NULL)
    {
        printf("Error: Couldn't open");
    }
    else
    {
        int *ptr;
        int number = 0;
        // allocate memory
        ptr = (int *)malloc(100 * sizeof(int));
        // check null
        if (ptr == NULL)
        {
            printf("Error: Couldn't allocate");
        }
        // read the last character form file, EOF check the last character
        // fscanf get character, insert into the array
        while (fscanf(f, "%d", &ptr[number]) != EOF)
        {
            number++;
        }
        for (size_t i = 0; i < number; i++)
        {
            printf("%d \t", ptr[i]);
        }

        printf("Memory: %d", number);

        free(ptr);
    }
    return 0;
}