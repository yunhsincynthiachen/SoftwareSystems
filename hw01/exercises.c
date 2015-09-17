#include <stdio.h>
#include <stdlib.h>

// int main() {
// int drinks[] = {4,2,3};

// printf("1st order: %i drinks\n", *drinks);
// }

// void skip(char *msg)
// {
// 	puts(msg+6);
// }

// char *msg_from_amy = "Don't call me";

// int main() {
// 	skip(msg_from_amy);
// }

int main()
{
	char cards[] = "JQK";
	char a_card = cards[2];
	cards[2] = cards[1];
	cards[1] = cards[0];
	cards[0] = cards[2];
	cards[2] = cards[1];
	cards[1] = a_card;
	puts(cards);
	return 0;
}

