#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Verifica se a chave é válida
int is_valid_key(const char *key) {
    int length = strlen(key);

    // Verifica se a chave tem exatamente 26 caracteres
    if (length != 26) {
        return 0;
    }

    int letter_count[26] = {0};

    // Verifica se todos os caracteres são letras e se há duplicatas
    for (int i = 0; i < length; i++) {
        if (!isalpha(key[i])) {
            return 0;
        }

        int index = tolower(key[i]) - 'a';
        if (letter_count[index] > 0) {
            return 0; // Letra duplicada
        }
        letter_count[index]++;
    }

    return 1; // A chave é válida
}

// Função para criptografar o texto claro usando a chave
void encrypt(const char *plaintext, const char *key, char *ciphertext) {
    int length = strlen(plaintext);

    for (int i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            int is_upper = isupper(plaintext[i]);
            int index = tolower(plaintext[i]) - 'a';
            char cipher_char = is_upper ? toupper(key[index]) : tolower(key[index]);
            ciphertext[i] = cipher_char;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[length] = '\0';
}

int main(int argc, char *argv[]) {
    // Verifica se o número de argumentos está correto
    if (argc != 2) {
        printf("Uso: ./substitution chave\n");
        return 1;
    }

    char *key = argv[1];

    // Verifica se a chave é válida
    if (!is_valid_key(key)) {
        printf("Chave inválida. A chave deve conter 26 caracteres alfabéticos únicos.\n");
        return 1;
    }

    // Solicita o texto claro ao usuário
    char plaintext[100];
    printf("Texto claro: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove a nova linha, se existir
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Criptografa o texto claro
    char ciphertext[100];
    encrypt(plaintext, key, ciphertext);

    // Exibe o texto criptografado
    printf("Texto cifrado: %s\n", ciphertext);

    return 0;
}
