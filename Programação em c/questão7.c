#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Verifica se a quantidade de argumentos é 2 (nome do programa e a chave)
    if (argc != 2)
    {
        printf("Uso: ./caesar chave\n");
        return 1; // Sai do programa se a condição não for atendida
    }

    // Converte a chave de string para inteiro
    int chave = atoi(argv[1]);

    // Verifica se a chave é positiva
    if (chave < 0)
    {
        printf("A chave deve ser um número positivo.\n");
        return 1; // Sai do programa se a condição não for atendida
    }

    // Pede ao usuário para digitar o texto simples
    string texto = get_string("Texto simples: ");

    printf("Texto cifrado: ");

    // Percorre cada caractere do texto
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        // Verifica se o caractere é uma letra maiúscula
        if (isupper(texto[i]))
        {
            printf("%c", (texto[i] - 'A' + chave) % 26 + 'A');
        }
        // Verifica se o caractere é uma letra minúscula
        else if (islower(texto[i]))
        {
            printf("%c", (texto[i] - 'a' + chave) % 26 + 'a');
        }
        // Se não for uma letra, imprime o caractere como está
        else
        {
            printf("%c", texto[i]);
        }
    }

    printf("\n");
    return 0;
}
