#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void encrypting(string plaintext, int key);
bool only_digits(string key);

int main(int argc, string argv[])
{
    // Verifying the input
    if (argc != 2 || atoi(argv[1]) < 0 || !(only_digits(argv[1])))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Get input

    string text = get_string("plaintext:  ");

    // Encrypting
    encrypting(text, atoi(argv[1]) % 26);
    return 0;
}

void encrypting(string plaintext, int key)
{
    int n = 0;

    printf("ciphertext: ");
    while (plaintext[n] != '\0')
    {
        // Verifying if is a letter
        if (isalpha(plaintext[n]))
        {
            // Verifyng if is lower
            if (islower(plaintext[n]))
            {
                printf("%c", (plaintext[n] - 97 + key) % 26 + 97);
            }
            // If not lower, then
            else
            {
                printf("%c", (plaintext[n] - 65 + key) % 26 + 65);
            }
        }
        // If not a letter
        else
        {
            printf("%c", plaintext[n]);
        }
        n++;
    }
    printf("\n");
}

bool only_digits(string key)
{
    int n = 0;
    while (key[n] != '\0')
    {
        if (isalpha(key[n]))
        {
            return false;
        }
        n++;
    }

    return true;
}
