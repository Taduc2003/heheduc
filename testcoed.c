#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main() {
    unsigned char key[16] = "0123456789abcdef";
    unsigned char iv[16] = "abcdef0123456789";
    unsigned char plaintext[16] = "Hello, OpenSSL!";
    unsigned char ciphertext[16];
    unsigned char decrypted[16];

    // M? hóa AES CBC
    AES_KEY aesKey;
    AES_set_encrypt_key(key, 128, &aesKey);
    AES_cbc_encrypt(plaintext, ciphertext, sizeof(plaintext), &aesKey, iv, AES_ENCRYPT);

    // Gi?i m? AES CBC
    AES_set_decrypt_key(key, 128, &aesKey);
    AES_cbc_encrypt(ciphertext, decrypted, sizeof(ciphertext), &aesKey, iv, AES_DECRYPT);

    // In k?t qu?
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < sizeof(ciphertext); i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");
    printf("Decrypted: %s\n", decrypted);

    return 0;
}

