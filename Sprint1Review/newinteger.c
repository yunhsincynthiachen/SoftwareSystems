#include <stdio.h>
#include <stdlib.h>

int new_integer() {
	int newint = 42; //declares actual variable
	int *newint_ptr = &newint; //declares pointer variable
	printf("%i\n", newint);
	printf("%p\n", newint_ptr);
	printf("%i\n", *newint_ptr);
	printf("%p\n", &newint); //both addresses and ints are the same, because the pointers are connected to each other
	return 0;
}

int main() {
	new_integer();
}