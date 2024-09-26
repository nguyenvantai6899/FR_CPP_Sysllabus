#include <stdio.h>
#include <stdlib.h>

struct Person
{
    char name[10];
    int age;
};
int main()
{
    int n;
    struct Person *person_ptr;
    printf("Enter total person: ");
    scanf("%d", &n);
    person_ptr = (struct Person *)malloc(n * sizeof(struct Person));
    for (size_t i = 0; i < n; i++)
    {
        `` printf("Enter name: ");
        scanf("%s", &(person_ptr + i)->name);
        printf("Enter age: ");
        scanf("%d", &(person_ptr + i)->age);
    }

    for (size_t i = 0; i < n; i++)
    {
        printf("%s %d \n", (person_ptr + i)->name, (person_ptr + i)->age);
    }
    free(person_ptr);
}