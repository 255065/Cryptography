#include <ctype.h>
#include "caesar.h"

#define SHIFT 3

char *caesar_encrypt(char *plaintext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            plaintext[i] = ((plaintext[i] - 'A' + SHIFT) % 26) + 'A';
        }
    }
    return plaintext;
}

char *caesar_decrypt(char *ciphertext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            ciphertext[i] = ((ciphertext[i] - 'A' - SHIFT + 26) % 26) + 'A';
        }
    }
    return ciphertext;
}
