#include <stdio.h>
#include <string.h>
#include<stdlib.h> 
#define max 5000
* hex_xor(char *a,char *b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    char dai[max];
	char ngan[max];
	
	// phan biet xau dai xau ngan
    if(len_a >= len_b){
    	 strcpy(dai,a);
		 strcpy(ngan,b);
	}else{
		strcpy(dai,b);
		strcpy(ngan,a);
	}
	
	// tinh do dai xau dai, xau ngan
	int c = strlen(ngan);
	// tinh tung ki tu
    int i;
    unsigned char xorchar[c];
    char space =' ';
    unsigned char xorspace[c],xor11[c],xorI[c];
    for(i = 0;i < c; i++){
	    xorchar[i]= (unsigned char)dai[i] ^ (unsigned char)ngan[i];
	    xorspace[i] = 0x20 ^ xorchar[i];
	    printf("%003d--%02x--%02x\n",i+1,xorchar[i],xorchar[i]);
		
	}
    
  printf("\n\n");  
}
void hex_to_string(const char* hex_string, char* output) {
    int len = strlen(hex_string);
    int i, j;
    char hex_digit[3];
    hex_digit[2] = '\0';

    for (i = 0, j = 0; i < len; i += 2, j++) {
        strncpy(hex_digit, &hex_string[i], 2);
        int byte;
        sscanf(hex_digit, "%x", &byte);
        output[j] = (char)byte;
    }

    output[j] = '\0';
}

void stringToHex(const char* str, char* hexStr) {
	int i;
    for (i = 0; str[i] != '\0'; i++) {
        sprintf(hexStr + i * 2, "%02x",str[i]);
    }
}

void convert_to_hex(unsigned char* h, unsigned char* hex) {
    int hex_len = strlen(h) /2;
    int i;
	for ( i = 0; i < strlen(h); i++) {
        int j = i / 2;
        if (i % 2 == 0 && j < hex_len) {
            hex[j] = h[i] << 4;
        } else if (j < hex_len) {
            hex[j] |= h[i];
        }
    }
}
int main(){
	char a[]= "32510ba9babebbbefd001547a810e67149caee11d945cd7fc81a05e9f85aac650e9052ba6a8 cd8257bf14d13e6f0a803b54fde9e77472dbff89d71b57bddef121336cb85ccb8f3315f4b52 e301d16e9f52f904";
	const char* input = "The secret message is: When using a stream cipher, never use the key more than once";
    char hexOutput[300] = {0};
    char output[200]; 
    char a2[100];
    stringToHex(input, hexOutput);
    //hex_to_string(a,output);
    convert_to_hex(hexOutput,output);
    convert_to_hex(a,a2);
    hex_xor(output,a2);
    hex_xor(a,hexOutput);
    printf("Hex string:   %s\n", hexOutput);
    printf("%d",strlen(hexput));
}
