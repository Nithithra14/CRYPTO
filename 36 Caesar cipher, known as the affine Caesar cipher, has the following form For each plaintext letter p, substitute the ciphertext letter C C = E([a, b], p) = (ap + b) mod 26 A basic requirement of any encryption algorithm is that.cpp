#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

char encryptChar(char p, int a, int b) {
    if (isalpha(p)) {
        p = toupper(p) - 'A';
        return (a * p + b) % 26 + 'A';
    }
    return p;
}

char decryptChar(char c, int a, int b) {
    if (isalpha(c)) {
        c = toupper(c) - 'A';
        int a_inv = modInverse(a, 26);
        if (a_inv == -1) {
            fprintf(stderr, "Multiplicative inverse not found. Decryption not possible.\n");
            exit(EXIT_FAILURE);
        }
        return (a_inv * (c - b + 26)) % 26 + 'A';
    }
    return c;
}

void encryptText(char *plaintext, char *ciphertext, int a, int b) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = encryptChar(plaintext[i], a, b);
    }
    ciphertext[strlen(plaintext)] = '\0';
}

void decryptText(char *ciphertext, char *plaintext, int a, int b) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        plaintext[i] = decryptChar(ciphertext[i], a, b);
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char plaintext[100], ciphertext[100];
    int a, b;

    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);

    if (gcd(a, 26) != 1) {
        printf("The value of a is not coprime with 26. Please choose a different value for a.\n");
        return 1;
    }

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    encryptText(plaintext, ciphertext, a, b);
    printf("Encrypted text: %s\n", ciphertext);

    decryptText(ciphertext, plaintext, a, b);
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}
