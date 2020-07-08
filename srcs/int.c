
#include "ft_printf.h"

void printInt2(t_pfstruct *data, char *numStr)
{
	char *buf;

	buf = numStr;
	if (data->fs.sign)
		data->fs.flag.space = 0;
	if (data->fs.flag.minus)
		data->fs.flag.zero = 0;
	if (data->fs.sign && numStr[0] != '-')
	{
		numStr = ft_strjoin("+", numStr);
		ft_strdel(&buf);
	}
	if (data->fs.flag.zero && (int)ft_strlen(numStr) < data->fs.width)
		data->pfreturn += writeChars(data->fs.width - \
		(int)ft_strlen(numStr), '0');
	ft_putstr(numStr);
	data->pfreturn += (int)ft_strlen(numStr);
	if (data->fs.flag.minus && (int)ft_strlen(numStr) < data->fs.width)
		data->pfreturn += writeChars(data->fs.width - \
		(int)ft_strlen(numStr), ' ');
}

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
	printInt2(data, numStr);
}