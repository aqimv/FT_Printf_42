
#include "ft_printf.h"

void printFloat(t_pfstruct *data)
{
	long long double num;

	if (data->fs.size.bigL)
		num = (long double)va_arg(data->args, long double);
	else
		num = (long double)va_arg(data->args, double);
}
