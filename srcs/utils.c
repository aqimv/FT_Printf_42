
#include "ft_printf.h"

int writeChars(int i, char ch)
{
	char count;

	count = 0;
	while (i != 0)
	{
		write(1, &ch, 1);
		i--;
		count++;
	}
	return (count);
}
