#include <cs50.h>
#include <stdio.h>

void number_verify(long long number);
bool number_valid(long long number);

int main(void)
{
    // Impute card number
    long long number;
    do
    {
        number = get_long_long("Number: ");
    }
    while (number < 0);

    // Verifying the number
    number_verify(number);
}

void number_verify(long long number)
{
    long long n = number;
    int count = 2;

    while (n > 100)
    {
        n /= 10;
        count++;
    }

    if (!number_valid(number))
    {
        printf("INVALID\n");
    }
    else if ((n == 34 || n == 37) && count == 15)
    {
        printf("AMEX\n");
    }
    else if (n >= 51 && n <= 55 && count == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (n / 10 == 4 && (count == 13 || count == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

bool number_valid(long long number)
{
    int sum = 0;

    while (number != 0)
    {
        int n = number % 100;

        sum += n % 10;

        if (n / 10 * 2 >= 10)
        {
            sum += (n / 10 * 2) % 10;
            sum += (n / 10 * 2) / 10;
        }
        else
        {
            sum += (n / 10) * 2;
        }

        number = number / 100;
    }

    if (sum % 10 == 0)
    {
        return true;
    }

    return false;
}
