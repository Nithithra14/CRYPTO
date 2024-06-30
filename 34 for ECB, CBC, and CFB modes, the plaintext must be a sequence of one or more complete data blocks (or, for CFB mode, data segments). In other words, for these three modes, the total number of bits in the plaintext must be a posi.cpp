#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 8 

void ecb_encrypt(unsigned char *plaintext, unsigned char *key, int size) {
    
    printf("ECB Encrypted Data:\n");
    
    for (int i = 0; i < size; i++) {
        printf("%02X ", plaintext[i] ^ key[i % BLOCK_SIZE]);
    }
    printf("\n");
}


void cbc_encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *iv, int size) {
    unsigned char prev_block[BLOCK_SIZE];
    memcpy(prev_block, iv, BLOCK_SIZE); 

    printf("CBC Encrypted Data:\n");

    for (int i = 0; i < size; i += BLOCK_SIZE) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            plaintext[i + j] ^= prev_block[j] ^ key[j];
        }
        memcpy(prev_block, plaintext + i, BLOCK_SIZE); // Update previous block
        for (int j = 0; j < BLOCK_SIZE; j++) {
            printf("%02X ", plaintext[i + j]);
        }
    }
    printf("\n");
}

// CFB Encryption
void cfb_encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *iv, int size) {
    unsigned char feedback[BLOCK_SIZE];
    memcpy(feedback, iv, BLOCK_SIZE); // Initialize feedback with IV

    printf("CFB Encrypted Data:\n");
    // Dummy output
    for (int i = 0; i < size; i += BLOCK_SIZE) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            feedback[j] ^= key[j];
            plaintext[i + j] ^= feedback[j];
        }
        memcpy(feedback, plaintext + i, BLOCK_SIZE); // Update feedback
        for (int j = 0; j < BLOCK_SIZE; j++) {
            printf("%02X ", plaintext[i + j]);
        }
    }
    printf("\n");
}

int main() {
    unsigned char plaintext[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
    unsigned char key[] = {0x0F, 0xE1, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD};
    unsigned char iv[] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0};

    int size = sizeof(plaintext);

    
    ecb_encrypt(plaintext, key, size);

    
    cbc_encrypt(plaintext, key, iv, size);

    
    cfb_encrypt(plaintext, key, iv, size);

    return 0;
}
