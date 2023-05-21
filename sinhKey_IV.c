#include<stdio.h>
#include<string.h>
#include<time.h>

int main(){
	int i;
	unsigned char iv[80];
	unsigned char key[80];
	srand(time(NULL));
	FILE *f1;
	
	// sinh IV
	f1 = fopen("iv.txt","w");
	for(i = 0;i < 80; i++){
		iv[i] = rand() % 2;
		fprintf(f1,"%c",iv[i]);
	} 
	fclose(f1);
	
	// sinh key
	f1 = fopen("key.txt","w");
    for(i = 0; i< 80;i++){
    	key[i] = rand() % 2;
    	fprintf(f1,"%c",key[i]);
	}
	fclose(f1);
	return 1;
	
	
}
