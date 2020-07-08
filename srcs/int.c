
#include "ft_printf.h"

void printInt(t_pfstruct *data)
{
	intmax_t num;
	char *numStr;

	if (data->fs.size.ll)
		num = (long long int)va_arg(data->args, long long int);
	else if (data->fs.size.l)
		num = (long int)va_arg(data->args, long int);
	else if (data->fs.size.h_size)
		num = (short int)va_arg(data->args, int);
	else if (data->fs.size.hh)
		num = (signed char)va_arg(data->args, int);
	else
		num = (int)va_arg(data->args, int);
	numStr = ft_itoa(num);
	if (num < 0 || data->fs.flag.plus)
		data->fs.sign = 1;
	ft_putstr(numStr);
}