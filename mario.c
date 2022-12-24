#include <cs50.h>
#include <stdio.h>

int get_height(void);

int main(void)
{
    // Gets the height from the user
    int height = get_height();

    for (int i = 0; i < height; i++)
    {
        // Adds the spacing required to right align the first pyramid
        for (int k = height - i; k > 1; k--)
        {
            printf(" ");
        }

        // Creating first pyramind
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // Adds the gap between the two pyraminds
        printf("  ");

        // Creating second pyramid
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int get_height(void)
{
    int n;
    do
    {
        n = get_int("Enter height: ");
    }
    while (n > 8 || n < 1);
    return n;
}