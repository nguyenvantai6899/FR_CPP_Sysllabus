#include <stdio.h>
#include <math.h>

bool is_prime_int(int prime)
{
    for (size_t i = 2; i <= sqrt(prime); i++)
    {
        if (prime % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 200, count = 0;
    FILE *f;
    f = fopen("D:/C++/FPT/Learn/file/test.txt", "w");
    for (int i = 2; i < n; i++)
    {
        if (is_prime_int(i))
        {
            fprintf(f, "%d \t", i);
            count++;
        }
        if (count == 10)
        {
            fprintf(f, "\n");
            count = 0;
        }
    }

    // char s[100] = "28tech.com.vn";
    // fprintf(f, "%d %.2lf %.c %s\n", 100, 3.14, '@', s);
    fclose(f);
    return 0;
}