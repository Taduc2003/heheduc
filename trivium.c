#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
	unsigned char a[93], b[84], c[111];
    int i, j; 
    unsigned char iv[80];
    unsigned char key[80];
    
    // doc file luu iv, key
    FILE *f1;
	f1 = fopen("iv.txt","r");
	for(i=0;i < 80;i++){
	   fscanf(f1,"%c",&iv[i]);
	} 
	fclose(f1);
	f1 = fopen("key.txt","r");
    for(i = 0; i< 80;i++){
    	fscanf(f1,"%c",&key[i]);
	}
	fclose(f1);
    
    // khai bao cac gia tri thanh ghi dich a,b,c
    for(i = 0; i < 93; i++){
    	if( i < 80 ) a[i] = key[i];
    	else   a[i] = 0;
	}
	for(i = 0; i < 84; i++){
		if(i < 80) b[i] = iv[i];
		else b[i] = 0;
	}
	    
	for(i = 0; i < 111; i++){
		if ( i >= 108) c[i] = 1;
		else c[i] = 0;
	}
	
	// khai bao ban ro 
    char plaintext[100] = "This is a plaintext message.";
	int  len;
	len = strlen(plaintext) * 8;
	unsigned char keystream[len];
	unsigned char ciphertext[len];
	unsigned char binaryString[len+1];
	
	// chuyen ban ro ve xau nhi phan
	int k = 0 ;
    for (i = 0; i < strlen(plaintext) ; i++) {
        for (j = 7; j >= 0; j--) {
            binaryString[k] = ((plaintext[i] & (1 << j)) ? '1' : '0');
            k++;
        }
    }
    binaryString[k] = '\0';
    
    
	 
    // ma dong trivium
	for(i = 0; i < len; i++)
	{
	        unsigned char t1,t2,t3;
	        t1 = a[65] ^ a[92] ^ (a[90] * a[91]);
	        t2 = b[68] ^ b[83] ^ (b[81] * b[82]);
	        t3 = c[65] ^ c[110] ^ (c[108] * c[109]);
	        keystream[i] = t1 ^ t2 ^ t3; 
	        
	        // dich cac bit o thanh ghi
			for(j = 92; j >=  0 ; j--){
	        	if( j != 0 ) a[j] = a[j-1];
	        	else a[j] = a[69] ^ t3;
			}
			for(j = 83; j >=  0 ; j--){
	        	if( j != 0 ) b[j] = b[j-1];
	        	else a[j] = b[78] ^ t1;
			}
			for(j = 110; j >=  0 ; j--){
	        	if( j != 0 ) c[j] = c[j-1];
	        	else a[j] = c[87] ^ t2;
			}
	}
    
    // xor ban-ro-nhi-phan voi keystream va in ra ket qua 
	for(i = 0; i < len; i++)
	{
	    ciphertext[i] = binaryString[i] ^ keystream[i];
	    printf("%c",ciphertext[i]); 
	}
	
	// luu ket qua vao file
	FILE *fp;
	fp = fopen("ciphertext.txt", "w");
	
	for (i = 0; i < len; i++) {
	    fprintf(fp, "%c", ciphertext[i]);
	}
	
	fclose(fp);

}



