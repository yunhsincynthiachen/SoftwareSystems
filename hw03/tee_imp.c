#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 80

void writing_to_file(char words[80], char *fp) {

	FILE *filename;

	filename = fopen(fp, "a");

	fprintf(filename, "%s\n", words);

	fclose(filename);
}


int main (int argc, char *argv[])
{

	int i;

	char ch;
	char *write_type;
	char word[MAX]= "";
	char *fp;

	while ((ch = getopt(argc, argv, "a:w:")) != EOF) {
		switch(ch){
			case 'a': {
				write_type = "a";
				break;
			}
			case 'w': {
				write_type = "w";
				break;
			}
			default:{
				write_type = "w";
				break;
			}
		}
	}

	FILE *filename;

	filename = fopen(argv[2], write_type);

	fp = argv[2];

	printf("%s\n", fp);

	while (scanf("%[^\n]%*c", word) == 1){

		writing_to_file(word, fp);
		printf("%s\n", word);
	}


    return 0;
}
