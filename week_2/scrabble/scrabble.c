#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void computer_score(int length, string players[]);

int main(void)
{
    // Get players input
    const int N = 2;
    string players[N];
    for (int i = 0; i < N; i++)
    {
        players[i] = get_string("Player %i: ", i + 1);
    }

    // Determinate the winner
    computer_score(N, players);
}

void computer_score(int length, string players[])
{
    // Points per character
    const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1,
                         3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int scores[length];

    // Calculates the total points for each player
    for (int i = 0; i < length; i++)
    {
        scores[i] = 0;
        for (int j = 0, n = strlen(players[i]); j < n; j++)
        {
            scores[i] += POINTS[tolower(players[i][j]) - 97];
        }
    }


    // Calculate who is the winner
    int vencedor = 1;
    int tie = 0;

    for (int i = 1; i < length; i++)
    {
        if (scores[i - 1] < scores[i])
        {
            vencedor = i + 1;
        }
        else if (scores[i - 1] == scores[i])
        {
            tie++;
        }
    }

    if (tie == length - 1)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player %i wins!\n", vencedor);
    }
}
