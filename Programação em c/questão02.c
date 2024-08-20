#include <stdio.h>

// Função para multiplicar duas matrizes n x n
void multiplica_matrizes(int n, int matriz1[n][n], int matriz2[n][n], int resultado[n][n]) {
    // Passo 1: Inicializa a matriz resultado com zero
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            resultado[i][j] = 0; // Cada elemento da matriz resultado começa com zero
        }
    }

    // Passo 2: Multiplica as matrizes
    for(int i = 0; i < n; i++) { // Percorre as linhas da primeira matriz
        for(int j = 0; j < n; j++) { // Percorre as colunas da segunda matriz
            for(int k = 0; k < n; k++) { // Realiza a multiplicação de cada linha da primeira com cada coluna da segunda
                // Soma o produto dos elementos correspondentes da matriz1 e matriz2
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int main() {
    int n;

    // Passo 3: Solicita o tamanho das matrizes ao usuário
    printf("Digite o tamanho das matrizes (n x n): ");
    scanf("%d", &n);

    // Passo 4: Declara as matrizes e a matriz resultado
    int matriz1[n][n], matriz2[n][n], resultado[n][n];

    // Passo 5: Solicita ao usuário que digite os elementos da primeira matriz
    printf("Digite os elementos da primeira matriz %d x %d:\n", n, n);
    for(int i = 0; i < n; i++) { // Percorre as linhas da matriz1
        for(int j = 0; j < n; j++) { // Percorre as colunas da matriz1
            scanf("%d", &matriz1[i][j]); // Lê cada elemento da matriz1
        }
    }

    // Passo 6: Solicita ao usuário que digite os elementos da segunda matriz
    printf("Digite os elementos da segunda matriz %d x %d:\n", n, n);
    for(int i = 0; i < n; i++) { // Percorre as linhas da matriz2
        for(int j = 0; j < n; j++) { // Percorre as colunas da matriz2
            scanf("%d", &matriz2[i][j]); // Lê cada elemento da matriz2
        }
    }

    // Passo 7: Chama a função para multiplicar as duas matrizes
    multiplica_matrizes(n, matriz1, matriz2, resultado);

    // Passo 8: Exibe a matriz resultante da multiplicação
    printf("Matriz Resultante:\n");
    for(int i = 0; i < n; i++) { // Percorre as linhas da matriz resultado
        for(int j = 0; j < n; j++) { // Percorre as colunas da matriz resultado
            printf("%d ", resultado[i][j]); // Imprime cada elemento da matriz resultado
        }
        printf("\n"); // Nova linha após imprimir uma linha completa da matriz
    }

    return 0; 
}
