#include "includes/ft_printf.h"
#include <stdio.h>
int main() {
	double a = 163.123456;
	char *b = "xxx";
	double c = 31.92;
	char a1 = 'g';
	int a2 = 163;

	static char	a01;
	static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12;
	ft_printf("%.o", 0);

	return 0;
}
