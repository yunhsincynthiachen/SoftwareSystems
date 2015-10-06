#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 80


int main (int argc, char *argv[])
{

	int i;

	char ch;
	char *write_type;
	char word[MAX]= "";
	FILE *filename;

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


	while (scanf("%[^\n]%*c", word) == 1){

		filename = fopen(argv[2], write_type);

		fprintf(filename, "%s\n", word);

		printf("%s\n", word);

		fclose(filename);
	}
	

    return 0;
}
