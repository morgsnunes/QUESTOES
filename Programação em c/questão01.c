#include <stdio.h>

// calcular array 
int soma_array(int array[], int tamanho) {
    int soma = 0;
    for(int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma;
}

int main() {
    int n;

    // tamanho
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int array[n];

    // elementos
    printf("Digite %d números inteiros:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // soma dos elementos
    int soma = soma_array(array, n);

    // resultado
    printf("A soma dos elementos do array é: %d\n", soma);

    return 0;
}
