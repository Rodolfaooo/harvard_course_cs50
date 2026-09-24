#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void encrypting(string text, string key);
bool valid_key(string key);

int main(int argc, string argv[])
{
    // Checking if the user entered only one argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Checking if the user input has 26 characters
    if (!valid_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string text = get_string("plaintext:  ");

    // Encrypting
    encrypting(text, argv[1]);
    return 0;
}

void encrypting(string text, string key)
{
    printf("ciphertext: ");
    int n = 0;
    while (text[n] != '\0')
    {
        if (islower(text[n]))
        {
            printf("%c", tolower(key[text[n] - 97]));
        }
        else if (isupper(text[n]))
        {
            printf("%c", toupper(key[text[n] - 65]));
        }
        else
        {
            printf("%c", text[n]);
        }
        n++;
    }
    printf("\n");
}

bool valid_key(string key)
{
    int n = 0;
    while (key[n] != '\0')
    {
        // Checking if the itens in the key is valid
        if (!(isalpha(key[n])))
        {
            return false;
        }
        n++;
    }

    // Cheking if the key has 26 characters
    if (n != 26)
    {
        return false;
    }

    // Checking duplicate characters
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = 0; j <= strlen(key); j++)
        {
            if (tolower(key[i]) == tolower(key[j]) && i != j)
            {
                return false;
            }
        }
    }

    return true;
}
