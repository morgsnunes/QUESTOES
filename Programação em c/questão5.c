#include <stdio.h>
#include <string.h>
#include <ctype.h>

int valores[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
};

// Função para calcular a pontuação de uma palavra
int Calc_Pont(const char* palavra)
{
    int pontuacao = 0;
    for (int i = 0; i < strlen(palavra); i++)
    {
        char letra = toupper(palavra[i]); 
        if (letra >= 'A' && letra <= 'Z')
        {
            pontuacao += valores[letra - 'A']; 
        }
    }
    return pontuacao;
}

int main(void)
{
    char Plv_1[100];
    char Plv_2[100];

    printf("Jogador 1, insira sua palavra: ");
    fgets(Plv_1, sizeof(Plv_1), stdin);
    Plv_1[strcspn(Plv_1, "\n")] = '\0'; 

    printf("Jogador 2, insira sua palavra: ");
    fgets(Plv_2, sizeof(Plv_2), stdin);
    Plv_2[strcspn(Plv_2, "\n")] = '\0'; 

    // Calcula a pontuação das palavras
    int Pnt_1 = Calc_Pont(Plv_1);
    int Pnt_2 = Calc_Pont(Plv_2);

    if (Pnt_1 > Pnt_2)
    {
        printf("Jogador 1 venceu!\n");
    }
    else if (Pnt_2 > Pnt_1)
    {
        printf("Jogador 2 venceu!\n");
    }
    else
    {
        printf("Empate!\n");
    }

    return 0;
}
