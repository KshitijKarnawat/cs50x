#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int start_number, end_number, count;

    // Get starting number and reject any integer less than 9
    do
    {
        start_number = get_int("Start size: ");
    }
    while (start_number < 9);

    // Get ending number and reject any integer less than starting number
    do
    {
        end_number = get_int("End size: ");
    }
    while (end_number < start_number);

    // Calculate the number of years required to reach end number
    count = 0;
    while (start_number < end_number)
    {
        start_number = start_number + (start_number / 3) - (start_number / 4);
        count++;
    }

    // Display the number of Years it takes to reach the end number i.e. count
    printf("Years: %i \n", count);
}