#include <stdio.h>
#include <stdlib.h>

int print_addr(int x) {
	printf("%p\n", &x);
	return 0;
}

int main() {
	int num = 5;
	printf("%p\n", &num); //prints out the address directly
	print_addr(num); //passes integer into print_addr to print our the address
}

//The two outputs are different,because it is passing in num to a different temporary address
