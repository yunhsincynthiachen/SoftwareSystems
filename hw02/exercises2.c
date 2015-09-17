#include <stdio.h>
#include <stdlib.h>

// int y =1;

// int main()
// {
// 	int x = 4;
// 	printf("%p\n", &x);
// 	return 0;
// }

void go_south_east(int *lat, int *lon)
{
	*lat = *lat -1;
	*lon = *lon +1;
}

int print_lon_lat()
{
	int latitude = 32;
	int longitude = -64;
	go_south_east(&latitude, &longitude);
	printf("Avast! Now at: [%i, %i]\n", latitude, longitude);
	return 0;
}

void fortune_cooke(char *msg)
{
	printf("Message reads: %s\n", msg);
	printf("Message size: %lu bytes\n", sizeof(msg));
}


int main()
{
	char quote[] = "Cookies make you fat";
	char *t = quote;
	fortune_cooke(t);
	printf("%s\n",t);
	print_lon_lat();

	char food[256];
	char *foods = food;
	printf("Enter favorite food: ");
	fgets(foods, sizeof(foods), stdin);
	printf("Food: %s\n", foods);
	return 0;
}