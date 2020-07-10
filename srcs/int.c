/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:37:25 by skennith          #+#    #+#             */
/*   Updated: 2020/07/09 14:37:26 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

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
			(int)ft_strlen(data->fs.fnl), '0');
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	}
	else
	{
		data->pfreturn = writeChars(data->fs.width - \
			ft_strlen(data->fs.fnl) - (data->fs.sign ? 1 : 0), ' ');
		if (data->fs.sign)
		{
			data->pfreturn += write(1, &data->fs.sign, 1);
			data->fs.width -= 1;
		}
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	}
}

void printInt2(t_pfstruct *data)
{
	precisionZero(data);
	if (data->fs.flag.space)
		data->pfreturn += write(1, " ", 1);
	if (!data->fs.width)
	{
		if (data->fs.sign)
			data->pfreturn += write(1, &data->fs.sign, 1);
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	} else
	{
		if (data->fs.flag.minus)
		{
			if (data->fs.sign)
			{
				data->pfreturn += write(1, &data->fs.sign, 1);
				data->fs.width -= 1;
			}
			data->pfreturn += ft_putstrcount(data->fs.fnl);
			data->fs.width -= ft_strlen(data->fs.fnl);
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
	else if (data->fs.size.h)
		num = (short int)va_arg(data->args, int);
	else if (data->fs.size.hh)
		num = (signed char)va_arg(data->args, int);
	else
		num = (int)va_arg(data->args, int);
	if (num < 0 || data->fs.flag.plus)
		data->fs.sign = num >= 0 ? '+' : '-';
	num < 0 ? num *= -1 : num;
	data->fs.fnl = num == 0 && data->fs.prZ && \
	!data->fs.precision ? ft_strnew(1) : ft_itoa_base(num, 10);
	if (data->fs.sign)
		data->fs.flag.space = 0;
	if (data->fs.flag.minus || data->fs.precision)
		data->fs.flag.zero = 0;
	if (data->fs.precision + (data->fs.sign ? 1 : 0) >= data->fs.width || \
	(int)ft_strlen(data->fs.fnl) + (data->fs.sign ? 1 : 0) >= data->fs.width)
		data->fs.width = 0;
	printInt2(data);
}
