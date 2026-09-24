#include <cs50.h>
#include <stdio.h>

int coins(int change);

int main(void)
{
    //Get change user input
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    //Calculating number of coins
    printf("%i\n", coins(change));
}


int coins(int change)
{
    int number_coins = 0;

    do
    {
        if (change >= 25)
        {
            number_coins += change / 25;
            change = change % 25;
        }
        else if (change >= 10)
        {
            number_coins += change / 10;
            change = change % 10;
        }
        else if (change >= 5)
        {
            number_coins += change / 5;
            change = change % 5;
        }
        else
        {
            number_coins += change / 1;
            change = change % 1;
        }
    }
    while (change > 0);

    return number_coins;
}
