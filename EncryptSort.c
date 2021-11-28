#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 255

void encryption(char *, _Bool);
void readFile(char [*], char *);
void writeFile(char [*], char *);

int main(){
    char buffer[N+1];
    char *filename = "message.txt";
    char *eFile = "encrypted_message.txt";
    char *rFile = "result_message.txt";
    
    readFile(buffer, filename);
    encryption(buffer, false);
    writeFile(buffer, eFile);

    memset(buffer, 0, N+1);

    readFile(buffer, eFile);
    encryption(buffer, true);
    writeFile(buffer, rFile);

    return 0;
}

void readFile(char arr[], char *filename){
    FILE *mText = fopen(filename, "r");
    if (mText == NULL)
    {
        printf("An error has occured while reading this file.");
        exit(2);
    }
    fscanf(mText, "%s", arr);
    fclose(mText);
}


void writeFile(char arr[], char *filename){
    FILE *nText = fopen(filename, "w+");
    if (nText == NULL) {
		printf("An error has occured while writing this file.");
		exit(2);
	}
    fprintf(nText, "%s", arr);
    fclose(nText);  
}

void encryption(char *str, bool enc) {
	int mat[2][2]; // Encryption cipher matrix
    mat[0][1] = 5;
    mat[1][0] = 2;
	if (!enc) { // If it is not encrypted, use M
		mat[0][0] = 3;
        mat[1][1] = 3;
    }
	else { // If it is encrypted, use M'
		mat[0][0] = 23;
        mat[1][1] = 23;
    }

    // Go through the characters of the array and encrypt them	
	for (int i = 0; str[i] != '\0' && str[i+1] != '\0'; i+=2) {
		int msg[2] = {0, 0}; // To store the letters before ciphering
		int new[2] = {0, 0}; // To store the letters after ciphering
        str[i] = tolower(str[i]);
        str[i+1] = tolower(str[i+1]);
		// Turn the characters into numbers
		msg[0] = str[i] % 96;
		msg[1] = str[i+1] % 96;
		
		// Encrypt the number-letters
		for(int y = 0; y < 2; y++)
			for (int x = 0; x < 2; x++)
				new[x] += msg[y] * mat[y][x];

        
        for (int j = 0; j < 2; j++) {
			new[j] %= 26;
			if (new[j] == 0) new[j] = 26;
		}
		
		// Resize to be expected letter range; 0-25 = A-Z
        new[0] %= 26;
        new[1] %= 26;
		
		// Write the encrypted characters to the string
		str[i]   = new[0] - 1 + 'a';
		str[i+1] = new[1] - 1 + 'a';
	}
}
