#include <stdio.h>

int main(void)
{
	int num;
	printf("Input num: ");
	scanf("%d", &num);
	
	if(num%2)
		printf("odd num\n");
	else
		printf("even num\n");
	return 0;
}

