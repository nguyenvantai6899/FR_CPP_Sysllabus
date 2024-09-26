// khong xoa file cu
#include <stdio.h>

int main()
{
    FILE *f;
    f = fopen("D:/C++/FPT/Learn/file/test.txt", "a");
    fprintf(f, "\n28tech");
    fclose(f);
    return 0;
}