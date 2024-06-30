#include <stdio.h>
#include <stdint.h>

#define ROUNDS 16

void des_decrypt(uint8_t *block, uint8_t *key) {
    for (int i = 0; i < 64; i++) {
        block[i] ^= key[i % 8];
    }
}

int main() {
    uint8_t block[64] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 
                         0x09, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 
                         0x17, 0x18, 0x19, 0x20, 0x21, 0x22, 0x23, 0x24, 
                         0x25, 0x26, 0x27, 0x28, 0x29, 0x30, 0x31, 0x32, 
                         0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x40 };
    uint8_t key[64] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 
                         0x09, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 
                         0x17, 0x18, 0x19, 0x20, 0x21, 0x22, 0x23, 0x24, 
                         0x25, 0x26, 0x27, 0x28, 0x29, 0x30, 0x31, 0x32, 
                         0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x40 };
    des_decrypt(block, key);
    for (int i = 0; i < 64; i++) {
        printf("%02x", block[i]);
    }
    printf("\n");
    return 0;
}
