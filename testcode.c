#include <stdio.h>

void charToHexAndXOR(char* input) {
    printf("Input: %s\n", input);

    int len = strlen(input);
    printf("Length: %d\n", len);

    printf("Hex: ");
    int i;
    for (i = 0; i < len; i++) {
        printf("%02X ", (unsigned char)input[i]);
    }
    printf("\n");

    unsigned char xorResult = 0 ;
    char space = ' ';
    for (i = 0; i < len; i++) {
        xorResult ^= (unsigned char)input[i];
       
    }
 printf("XOR result: 0x%02x\n", xorResult);
    
}
//abcdefghijklnmopqrstuvwxyzABCDEF
int main() {
    char input[] = "lw ";
    //charToHexAndXOR(input);
    printf("%x",0xc^0xe);
    return 0;
}


