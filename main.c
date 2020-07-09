#include "includes/ft_printf.h"
#include <stdio.h>
int main() {
	double a = 163.123456;
	char *b = "xxx";
	double c = 31.92;
	char a1 = 'g';
	int a2 = 163;

//	printf("Hello, World! %010.3f, %s, %f\n", a, b, c);
//	printf("Hello, World! %f, %s, %f\n", a, b, c);

//	int x = printf("3 - %,d", 13);
//	printf("%d", x);
//	ft_printf("Hello, World! %-0-+10.0000003lllf, %s, %-f\n", a, b, 10, 3, c);
//	ft_printf("Hello, World! %-0-+10.003llhf\n", a);
//	ft_printf("Hello, World! %#010.003llhc, %+010.10d\n", 'g', 163);
//	printf("Hello, World! %#010.003llhc, %+010.10d\n", 'g', 163);
//	printf("Hello, World! %0-10.10d, %.3d\n", 2, 163);
	ft_printf("%.*d", -1, 12345);
	return 0;
}
