#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int tags, int beetween);

int main(void)
{
    //get height user input
    int height;
    do
    {
        height = get_int("What's the height? ");
    }
    while (height <= 0);

    //printing the pyramids
    for (int column = 1; column <= height; column++)
    {
        //printing row
        print_row(height - column, column, 2);
    }
}

void print_row(int spaces, int tags, int beetween)
{
    for (int i = spaces; i > 0; i--)
    {
        printf(" ");
    }

    for (int i = tags; i > 0; i--)
    {
        printf("#");
    }

    for (int i = beetween; i > 0; i--)
    {
        printf(" ");
    }

    for (int i = tags; i > 0; i--)
    {
        printf("#");
    }

    printf("\n");
}
