#include <stdio.h>
#include <string.h>

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

int main() {
    char hex_string[] = "32510ba9babebbbefd001547a810e67149caee11d945cd7fc81a05e9f85aac650e9052ba6a8cd8257bf14d13e6f0a803b54fde9e77472dbff89d71b57bddef121336cb85ccb8f3315f4b52e301d16e9f52f904";
	
    char output[100]; // Chu?i k?t qu?

    hex_to_string(hex_string, output);
    printf("Chu?i sau khi chuy?n ð?i: %s\n", output);
     
    return 0;
}

