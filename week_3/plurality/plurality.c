#include <cs50.h>
#include <stdio.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

void vote(int quantidade_votos, candidate candidates[]);


int main(int argc, string argv[])
{
    // Verificar se a mais de um argumento fornecido pelo usuário.
    if (argc < 2)
    {
        printf("Usage: ./plurality [Candidates...]\n");
        return 1;
    }
    else if (argc == 2)
    {
        printf("%s\n", argv[1]);
        return 2;
    }
    else if (argc > 10)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 3;
    }

    candidate candidates[MAX];

    for (int i = 0; i < MAX; i++)
    {
        candidates[i].name = argv[i+1];
        candidates[i].votes = 0;
    }

    // Receber a quantidade de pessoas a votar
    int quantidade_votos = get_int("Number of voters: ");

    // Chamar a função votar
    vote(quantidade_votos, candidates);
}

void vote(int quantidade_votos, candidate candidates[])
{
    // Verificar se a quantidade de votos chegou em zero
    if (quantidade_votos <= 0)
    {
        return;
    }

    //Recursividade do vote
    vote(quantidade_votos - 1, candidates);

    // Fazer a votação e validação do voto
    string voto = get_string("Vote: ");

    // Adicionar o voto ao candidato selecionado
    for (int i = 0; i < MAX; i++)
    {
                                                                    
    }
}
