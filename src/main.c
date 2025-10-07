#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "caesar.h"
#include "vigenere.h"

void print_usage() {
    printf("Usage:\n");
    printf("  code-prj/crypto/crypto MODE ALGORITHM TEXT [KEY]\n\n");
    printf("Modes:\n");
    printf("  e, encrypt        Encrypt the input text\n");
    printf("  d, decrypt        Decrypt the input text\n\n");
    printf("Algorithms:\n");
    printf("  c, caesar         Caesar cipher\n");
    printf("  v, vigenere       Vigenère cipher\n\n");
    printf("Examples:\n");
    printf("  code-prj/crypto/crypto e c HELLO\n");
    printf("  code-prj/crypto/crypto d v LXFOPVEFRNHR LEMON\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage();
        return 1;
    }

    char *mode = argv[1];
    char *algo = argv[2];
    char *text = argv[3];
    char *key = (argc == 5) ? argv[4] : NULL;

    if ((strcmp(algo, "v") == 0 || strcmp(algo, "vigenere") == 0) && key == NULL) {
        printf("Error: Vigenère cipher requires a key.\n");
        return 1;
    }

    if (strcmp(mode, "e") == 0 || strcmp(mode, "encrypt") == 0) {
        if (strcmp(algo, "c") == 0 || strcmp(algo, "caesar") == 0) {
            printf("%s\n", caesar_encrypt(text));
        } else if (strcmp(algo, "v") == 0 || strcmp(algo, "vigenere") == 0) {
            printf("%s\n", vigenere_encrypt(text, key));
        } else {
            print_usage();
        }
    } else if (strcmp(mode, "d") == 0 || strcmp(mode, "decrypt") == 0) {
        if (strcmp(algo, "c") == 0 || strcmp(algo, "caesar") == 0) {
            printf("%s\n", caesar_decrypt(text));
        } else if (strcmp(algo, "v") == 0 || strcmp(algo, "vigenere") == 0) {
            printf("%s\n", vigenere_decrypt(text, key));
        } else {
            print_usage();
        }
    } else {
        print_usage();
    }

    return 0;
}
