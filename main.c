#include "includes/ft_printf.h"
#include <stdio.h>

int main() {

//	ft_printf("%#7x\n", 33);

//	ft_printf("% 0-8.5i\n", 0); // !!!!!!!!!!!

//	ft_printf("% 08.3i\n", 8375); // !!!!!!!!!!!

//	printf("%.5f\n", 0.987654321);
//	printf("%f\n", 5.99999999999);
//	printf("%.3f\n", -33.9999);
//	ft_printf("%.3f\n", -33.9999);
//	ft_printf("%.15f\n", -33.1231231230002);
	ft_printf("%05.1f", 7.3);
//	printf("this %f float\n", 1.5);
//	ft_printf("% #-5.0f", 7.3);
//	printf("% -5.0f", 7.3);

//	ft_printf("% #-05.0f", -0.0);
	printf("%s\n", fromBin(ft_ftoa_base2(0.999999)));

//	printf("%.*f", -1, 3.1415926535);




	return 0;
}

