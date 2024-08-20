#include <stdio.h>

int calcular_nicas(int troco)
{
    // Valores das moedas disponíveis (em centavos)
    int nicas[] = {25, 10, 5, 1};
    int totalNicas = 0;

    for (int i = 0; i < 4; i++)
    {
        totalNicas += troco / nicas[i];
        troco = troco % nicas[i];
    }

    return totalNicas;
}

int main(void)
{
    int troco;

    do
    {
        printf("Troco devido: ");
        scanf("%d", &troco);

        if (troco < 0)
        {
            printf("Valor inválido. O troco deve ser maior ou igual a 0.\n");
        }
    } while (troco < 0);

    int numero_nicas = calcular_nicas(troco);
    printf("%d\n", numero_nicas);

    return 0;
}
