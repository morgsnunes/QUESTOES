#include <stdio.h>
#include <math.h>

int main() {
    int A, B, C;
    
    while (1) {
        // Leitura dos valores A, B e C
        scanf("%d %d %d", &A, &B, &C);
        
        // Verifica o valor de A para parar o loop
        if (A == 0) {
            break;
        }
        
        // Calcula a área da casa
        int area_casa = A * B;
        
        // Calcula a área do terreno necessária
        double area_terreno = (double)area_casa * 100 / C;
        
        // Calcula o lado do terreno e trunca o valor
        int lado = (int)trunc(sqrt(area_terreno));
        
        // Imprime o resultado
        printf("%d\n", lado);
    }
    
    return 0;
}
