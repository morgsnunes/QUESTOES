#include <stdio.h>

/*
 * Programa para validar números de cartão de crédito usando o algoritmo de Luhn
 * e identificar o tipo de cartão: AMEX, MASTERCARD ou VISA.
 */

int main(void) {

    // Declaração da variável para armazenar o número do cartão de crédito

    long card;
    
    // Solicita ao usuário o número do cartão de crédito

    printf("Digite o número do cartão: ");
    scanf("%ld", &card);

    // Verifica se o número inserido é negativo (números negativos são inválidos)

    if (card < 0) {
        printf("INVALID\n");
        return 0;
    }

    // Inicializa variáveis para a soma e o comprimento do número do cartão

    int soma = 0;
    int length = 0;
    long number = card;

    // Loop para calcular a soma dos dígitos e contar a quantidade de dígitos
    
    while (number > 0) {
        // Extrai o último dígito do número atual
        int last_digit = number % 10;
        
        // Se a posição do dígito for par (contando a partir do penúltimo)
        if (length % 2 == 1) {
            // Dobra o valor do dígito e soma os dígitos resultantes
            int doubled = last_digit * 2;
            soma += (doubled / 10) + (doubled % 10);
        } else {
            // Adiciona o dígito diretamente à soma
            soma += last_digit;
        }
        
        // Remove o último dígito do número
        number /= 10;
        // Incrementa o comprimento do número
        length++;
    }

    // Validação final do número usando o algoritmo de Luhn
    if (soma % 10 != 0) {
        // Se a soma não for múltiplo de 10, o número é inválido
        printf("INVALID\n");
        return 0;
    }

    // Identificação do tipo de cartão baseado nos dígitos iniciais e comprimento
    long start_digits = card;
    
    // Reduz o número para os primeiros dois dígitos
    while (start_digits >= 100) {
        start_digits /= 10;
    }

    // Verifica se o número é um American Express (AMEX)
    if ((start_digits == 34 || start_digits == 37) && length == 15) {
        printf("AMEX\n");
    }
    // Verifica se o número é um MasterCard
    else if (start_digits >= 51 && start_digits <= 55 && length == 16) {
        printf("MASTERCARD\n");
    }
    // Verifica se o número é um Visa
    else if ((start_digits / 10) == 4 && (length == 13 || length == 16)) {
        printf("VISA\n");
    }
    // Caso contrário, o número é inválido
    else {
        printf("INVALID\n");
    }

    // Fim do programa
    return 0;
}
