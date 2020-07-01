#include "includes/ft_printf.h"
#include <stdio.h>
int main() {
	double a = 163.123456;
	char *b = "xxx";
	double c = 31.929;

	printf("Hello, World! %010.3f, %s, %f, %     \n", a, b, c);
//	ft_printf("Hello, World! %010.3f, %s, %f\n", a, b, c);

	return 0;
}
