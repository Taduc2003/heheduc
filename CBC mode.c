#include<openssl/aes.h>
#include<stdio.h>

int main() {
    unsigned char input[] = "Hello, world!";
    unsigned char key[] = "mykey";
    unsigned char output[128];

    // M? hóa
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key, NULL);
    EVP_EncryptUpdate(ctx, output, &len, input, sizeof(input)-1);
    ciphertext_len = len;
    EVP_EncryptFinal_ex(ctx, output + len, &len);
    ciphertext_len += len;
    EVP_CIPHER_CTX_free(ctx);

    printf("Ciphertext: %s\n", output);

    // Gi?i m?
    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_128_ecb(), NULL, key, NULL);
    EVP_DecryptUpdate(ctx, output, &len, output, ciphertext_len);
    int plaintext_len = len;
    EVP_DecryptFinal_ex(ctx, output + len, &len);
    plaintext_len += len;
    EVP_CIPHER_CTX_free(ctx);

    printf("Plaintext: %s\n", output);

    return 0;
}

