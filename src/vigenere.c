#include <ctype.h>
#include <string.h>
#include "vigenere.h"

char *vigenere_encrypt(char *plaintext, const char *key) {
    int keylen = strlen(key);
    for (int i = 0; plaintext[i] != '\0'; i++) {
        int shift = key[i % keylen] - 'A';
        plaintext[i] = ((plaintext[i] - 'A' + shift) % 26) + 'A';
    }
    return plaintext;
}

char *vigenere_decrypt(char *ciphertext, const char *key) {
    int keylen = strlen(key);
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        int shift = key[i % keylen] - 'A';
        ciphertext[i] = ((ciphertext[i] - 'A' - shift + 26) % 26) + 'A';
    }
    return ciphertext;
}
