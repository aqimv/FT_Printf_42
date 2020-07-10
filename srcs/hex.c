/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:28:36 by skennith          #+#    #+#             */
/*   Updated: 2020/07/10 15:28:38 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void big_x(t_pfstruct *data)
{
	int i;

	i = 0;
	while (data->fs.fnl[i])
	{
		if (data->fs.fnl[i] >= 'a' && data->fs.fnl[i] <= 'z')
			data->fs.fnl[i] = data->fs.fnl[i] - 32;
		i++;
	}
}

void printHex3(t_pfstruct *data)
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

void printHex2(t_pfstruct *data)
{
	precisionZero(data);
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
			printHex3(data);
	}
}

void printHex(t_pfstruct *data)
{
	intmax_t num;

	if (data->fs.size.ll)
		num = (unsigned long long int)va_arg(data->args, unsigned long long int);
	else if (data->fs.size.l)
		num = (unsigned long int)va_arg(data->args, unsigned long int);
	else if (data->fs.size.h)
		num = (unsigned short int)va_arg(data->args, unsigned int);
	else if (data->fs.size.hh)
		num = (unsigned char)va_arg(data->args, unsigned int);
	else
		num = (unsigned int)va_arg(data->args, unsigned int);
	data->fs.sign = data->fs.flag.plus ? '+' : 0;
	data->fs.fnl = num == 0 && data->fs.prZ && \
	!data->fs.precision ? ft_strnew(1) : ft_itoa_base(num, 16);
	if (data->fs.type == 'X')
		big_x(data);
	if (data->fs.sign)
		data->fs.flag.space = 0;
	if (data->fs.flag.minus || data->fs.precision)
		data->fs.flag.zero = 0;
	if (data->fs.precision + (data->fs.sign ? 1 : 0) >= data->fs.width || \
	(int)ft_strlen(data->fs.fnl) + (data->fs.sign ? 1 : 0) >= data->fs.width)
		data->fs.width = 0;
	printHex2(data);
}
