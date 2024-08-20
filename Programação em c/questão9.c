#include <stdio.h>
#include <string.h>

// Função para determinar o resultado do jogo
const char* resultado(const char* sheldon, const char* raj) {
    // Regras do jogo definidas em um array de pares
    const char* regras[5][2] = {
        {"tesoura", "papel"},
        {"papel", "pedra"},
        {"pedra", "lagarto"},
        {"lagarto", "spock"},
        {"spock", "tesoura"}
    };
    
    // Verifica se Sheldon ganhou
    for (int i = 0; i < 5; i++) {
        if (strcmp(sheldon, regras[i][0]) == 0 && strcmp(raj, regras[i][1]) == 0) {
            return "Bazinga!";
        }
    }
    
    // Verifica se Raj ganhou
    for (int i = 0; i < 5; i++) {
        if (strcmp(sheldon, regras[i][1]) == 0 && strcmp(raj, regras[i][0]) == 0) {
            return "Raj trapaceou!";
        }
    }
    
    // Se não é vitória de Sheldon nem de Raj, é um empate
    return "De novo!";
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        char sheldon[10], raj[10];
        scanf("%s %s", sheldon, raj);
        
        // Determina o resultado e imprime
        printf("Caso #%d: %s\n", t, resultado(sheldon, raj));
    }
    
    return 0;
}
