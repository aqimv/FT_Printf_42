#include "includes/ft_printf.h"
#include <stdio.h>
int main() {
	int a = 163;
	char *b = "xxx";
	double c = 31.929;

	printf("Hello, World! %  2.6i, % .2s, %f\n", a, b, c);
//	ft_printf("Hello, World! %i, %s, %f\n", a, b, c);

	return 0;
}
