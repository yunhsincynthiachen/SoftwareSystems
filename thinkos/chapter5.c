#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

void number_one() {
	int a = 0b1100;
	int b = -1;

	int complement = a^b;
	int final = complement + 1;
	printf("%d\n", final);
}

void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

void make_upper(char word[80]) {
	int i;
	int length_word = strlen(word);	
	char res[80] = {0};
	strcpy(res,"");

	for (i=0; i<length_word; i++) {
		char letter = word[i];
		int c, k;
		int n = (int) letter;

		if (letter == '\0'){
			break;
		}
		if ((n >> 5) & 1){  //checks if the 6th bit is 1, means lower-case
    		  n ^= (1u << 5);    //flips the value of the 6th bit to 0 if 1
    	}
    	char n_string = n;

    	append(res, n_string);
    }
    printf("%s\n", res);
}


int main() {
	char word[80];
	// number_one();
	scanf("%s", word);
	make_upper(word);

	return 0;
}