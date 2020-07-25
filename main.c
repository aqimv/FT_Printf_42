#include "includes/ft_printf.h"
#include <stdio.h>

int main() {

	ft_printf("%#7x\n", 33);

//	ft_printf("%2$s %f %1$i %s %f %2$s %1$i %s %1$i %3$f %1$i %s %f %2$s", 5, "abc", 5.75); // !!!!!!!!!!!

//	ft_printf("Lalalala, %d%% des gens qui parlent %C Ly adorent %s. Ou Presque. %d, %u, %X, %c", 100, L'√†', "Ly", 2, 10, 100); // !!!!!!!!!!!

//	printf("%.5f\n", 0.987654321);
//	printf("%f\n", 5.99999999999);
//	printf("%.3f\n", -33.9999);




	ft_printf("%.3f, %1$i, %s, skdjbjv\n", -33.9999, "abc");
	ft_printf("%.15f\n", -33.1231231230002);
	ft_printf("%.12f", 0.000000000001000000);
	ft_printf("%.*f", -3, 3.1415926535);
	ft_printf("%- 5.6f", 7.3);
	ft_printf("%.0f", 0.000039);





	//printf("%s\n", sum1("0625", "25"));
//	char *ch = mul("000039");
//	printf("%s\n", ch);

	ft_printf("% #-05.0f", -0.0);
//	ft_printf("%s\n", fromBin(ft_ftoa_base2(0.999999)));

	ft_printf("%.*f", -1, 3.1415926535);




	return 0;
}

