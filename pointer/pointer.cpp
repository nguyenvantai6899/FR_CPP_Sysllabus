#include <iostream>
#include <cstdlib>
int main()
{
    int *p = (int *)malloc(2 * sizeof(int));
    int **ptr = &p;
    for (int i = 0; i < 2; i++)
    {
        *(*ptr + i) = i;
        std::cout << (*ptr)[i] << std::endl;
    }
    for (int i = 0; i < 2; i++)
    {
        std::cout << "a:  " << *(p + i) << std::endl;
    }
    free(p);
}