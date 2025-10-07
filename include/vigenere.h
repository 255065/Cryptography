/**
 * @file vigenere.h
 * @brief Vigenère cipher encryption and decryption functions.
 */

#ifndef VIGENERE_H
#define VIGENERE_H

char *vigenere_encrypt(char *plaintext, const char *key);
char *vigenere_decrypt(char *ciphertext, const char *key);

#endif
