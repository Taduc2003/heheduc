#include<stdio.h>

int main(){
	unsigned char a[93], b[84], c[111];
	unsigned char key[10], iv[10], keystream[100];
	unsigned int i, j;

	
	for(i = 0; i < 93; i++)
	    a[i] = 0;
	for(i = 0; i < 84; i++)
	    b[i] = 0;
	for(i = 0; i < 111; i++)
	    c[i] = 0;
	for(i = 0; i < 10; i++)
	{
	    a[i] = key[i];
	    b[i] = iv[i];
	}
	
	
	for(i = 0; i < 100; i++)
	{
	    unsigned char s = 0;
	    for(j = 0; j < 8; j++)
	    {
	        unsigned char t = ((a[65] & a[92]) ^ a[90]) + ((b[77] & b[82]) ^ b[81]) + ((c[68] & c[84]) ^ c[83]) + s;
	        keystream[i] |= ((t & 0x01) << j);
	        s = t >> 1;
	
	        unsigned char t1 = ((a[68] & a[92]) ^ a[90]) + ((b[80] & b[87]) ^ b[86]) + ((c[65] & c[110]) ^ c[109]) + s;
	        c[0] = ((a[91] & 0xFE) << 7) | (a[92] >> 1);
	        b[0] = ((c[83] & 0xFE) << 7) | (c[84] >> 1);
	        a[0] = ((b[68] & 0xFE) << 7) | (b[69] >> 1);
	        a[91] = t1;
	        b[83] = t1;
	        c[110] = t1;
	        s = t1 >> 8;
	    }
	}
	unsigned char plaintext[100] = "This is a plaintext message.";
	unsigned char ciphertext[100];
	
	for(i = 0; i < 100; i++)
	{
	    ciphertext[i] = plaintext[i] ^ keystream[i];
	    printf("%x",ciphertext[i]);
	}

}

