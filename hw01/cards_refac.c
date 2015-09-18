#include <stdio.h>
#include <stdlib.h>


/* First, the card name is entered, so the following function checks out what the card name is and then assigns val to be a value
depending on the card entered. Default indicates that if the value doesn't make sense, it'll put "I don't understand that value!"*/
int cases(char *card_name, int val){
	switch (card_name[0]) {
		case 'K':
		case 'Q':
		case 'J':
			val = 10; //for all of the above cases, the value will be set to 10
			break;
		case 'A':
			val = 11; //if card is A, the value will be set to 11
			break;
		case 'X':
			break; //breaks if caed is X
		default:
			val = atoi(card_name); 
			if ((val<1) || (val>10)) {
				puts("I don't understand that value!");
				break;
			}
	}
	return val;
}

/*Counter increments the count depending on the value that was assigned to the card*/
int counter(int val, int count) {
	if ((val > 2) && (val < 7)) {
		count++;
	} else if (val == 10) {
		count--;
	}
	return count;
}

/*Main function that runs cases and then counter to print out the current count*/
int main()
{
	char card_name[3];
	int count = 0;
	while (card_name[0] != 'X') {
		int val = 0;
		puts("Enter the card_name: ");
		scanf("%2s", card_name);
		val = cases(card_name, val); //gets the value of the card from the function cases
		count = counter(val, count); //the counter function will return a lower or higher count, depending on the value of card
		printf("Current count: %i\n", count);
	}
	return 0;
}