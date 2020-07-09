
#include "ft_printf.h"

void precisionZero(t_pfstruct *data)
{
	int precision;
	char *buf;

	precision = data->fs.precision - (int)ft_strlen(data->fs.finalstr);
	while (precision > 0)
	{
		buf = data->fs.finalstr;
		data->fs.finalstr = ft_strjoin("0", data->fs.finalstr);
		ft_strdel(&buf);
		precision--;
	}
}

void printInt3(t_pfstruct *data)
{
	if (data->fs.flag.zero)
	{
		if (data->fs.sign)
		{
			data->pfreturn += write(1, &data->fs.sign, 1);
			data->fs.width -= 1;
		}
		data->pfreturn += writeChars(data->fs.width - \
			(int)ft_strlen(data->fs.finalstr), '0');
		ft_putstr(data->fs.finalstr);
		data->pfreturn += ft_strlen(data->fs.finalstr);
	}
	else
	{
		data->pfreturn = writeChars(data->fs.width - \
			ft_strlen(data->fs.finalstr) - (data->fs.sign ? 1 : 0), ' ');
		if (data->fs.sign)
		{
			data->pfreturn += write(1, &data->fs.sign, 1);
			data->fs.width -= 1;
		}
		ft_putstr(data->fs.finalstr);
		data->pfreturn += ft_strlen(data->fs.finalstr);
	}
}

void printInt2(t_pfstruct *data)
{
	precisionZero(data);
	if (!data->fs.width)
	{
		if (data->fs.sign)
			data->pfreturn += write(1, &data->fs.sign, 1);
		ft_putstr(data->fs.finalstr);
		data->pfreturn += ft_strlen(data->fs.finalstr);
	} else
	{
		if (data->fs.flag.minus)
		{
			if (data->fs.sign)
			{
				data->pfreturn += write(1, &data->fs.sign, 1);
				data->fs.width -= 1;
			}
			ft_putstr(data->fs.finalstr);
			data->pfreturn += ft_strlen(data->fs.finalstr);
			data->fs.width -= ft_strlen(data->fs.finalstr);
			data->pfreturn += writeChars(data->fs.width, ' ');
		}
		else
			printInt3(data);
	}
}

void printInt(t_pfstruct *data)
{
	intmax_t num;

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
	if ((num < 0 || data->fs.flag.plus) && num != 0)
		data->fs.sign = num > 0 ? '+' : '-';
	num < 0 ? num *= -1 : num;
	data->fs.finalstr = num == 0 && data->fs.prZ && \
	!data->fs.precision ? ft_strnew(1) : ft_itoa(num);
	if (data->fs.sign)
		data->fs.flag.space = 0;
	if (data->fs.flag.minus || data->fs.precision)
		data->fs.flag.zero = 0;
	if (data->fs.precision + (data->fs.sign ? 1 : 0) >= data->fs.width || \
	(int)ft_strlen(data->fs.finalstr) + (data->fs.sign ? 1 : 0) >= data->fs.width)
		data->fs.width = 0;
	printInt2(data);
}