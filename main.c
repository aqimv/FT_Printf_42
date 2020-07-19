#include "includes/ft_printf.h"
#include <stdio.h>

int main() {

	ft_printf("%#7x", 33);

	ft_printf("% 0-8.5i", 0); // !!!!!!!!!!!
//	printf("%.5f\n", 0.987654321);
//	printf("%f\n", 5.99999999999);


	return 0;
}

