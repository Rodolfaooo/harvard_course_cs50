#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float calculate_grade(string text);
void print_grade(int grade);

int main(void)
{
    // Get user input text
    string text = get_string("Text: ");

    // Calculating the grade
    float grade = round(calculate_grade(text));

    // Printing the grade
    print_grade(grade);
}

float calculate_grade(string text)
{
    // Count the words, sentences and letters: 0 - words, 1 - sentences, 2 - letters
    float counts[] = {1, 0, 0};

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            counts[0]++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            counts[1]++;
        }
        else if (isalpha(text[i]))
        {
            counts[2]++;
        }
    }

    return 0.0588 * ((counts[2] / counts[0]) * 100.0) - 0.296 * ((counts[1] / counts[0]) * 100.0) - 15.8;
}

void print_grade(int grade)
{
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 1 && grade <= 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
