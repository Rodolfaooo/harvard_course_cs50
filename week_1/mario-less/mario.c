#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int tags);

int main(void)
{
    //get user input
    int height;
    do
    {
        height = get_int("What's the height? ");
    }
    while (height <= 0);

    for (int column = 1; column <= height; column++)
    {
        // Print row
        print_row(height - column, column);
    }
}

void print_row(int spaces, int tags)
{
    for (int i = spaces; i > 0; i--)
    {
        printf(" ");
    }

    for (int i = tags; i > 0; i--)
    {
        printf("#");
    }

    printf("\n");
}
