#include "includes/ft_printf.h"
#include <stdio.h>
int main() {
	double a = 163.123456;
	char *b = "xxx";
	double c = 31.92;

	printf("Hello, World! %010.3f, %s, %f\n", a, b, c);
	printf("Hello, World! %f, %s, %f\n", a, b, c);

//	int x = printf("3 - %,d", 13);
//	printf("%d", x);
	ft_printf("Hello, World! %-0-+10.0000003lllf, %s, %-f\n", a, b, 10, 3, c);
//
	return 0;
}
