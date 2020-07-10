/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsignedint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:39:01 by skennith          #+#    #+#             */
/*   Updated: 2020/07/10 12:39:03 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void printUInt3(t_pfstruct *data)
{
	if (data->fs.flag.zero)
	{
		if (data->fs.sign)
		{
			data->pfreturn += write(1, &data->fs.sign, 1);
			data->fs.wid -= 1;
		}
		data->pfreturn += writeChars(data->fs.wid - \
			(int)ft_strlen(data->fs.fnl), '0');
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	}
	else
	{
		data->pfreturn = writeChars(data->fs.wid - \
			ft_strlen(data->fs.fnl) - (data->fs.sign ? 1 : 0), ' ');
		if (data->fs.sign)
		{
			data->pfreturn += write(1, &data->fs.sign, 1);
			data->fs.wid -= 1;
		}
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	}
}

void printUInt2(t_pfstruct *data)
{
	precisionZero(data);
	if (!data->fs.wid)
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
				data->fs.wid -= 1;
			}
			data->pfreturn += ft_putstrcount(data->fs.fnl);
			data->fs.wid -= ft_strlen(data->fs.fnl);
			data->pfreturn += writeChars(data->fs.wid, ' ');
		}
		else
			printUInt3(data);
	}
}

void	printUnsignedInt(t_pfstruct *data)
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
	!data->fs.precision ? ft_strnew(1) : ft_itoa_base(num, 10);
	if (data->fs.sign)
		data->fs.flag.space = 0;
	if (data->fs.flag.minus || data->fs.precision)
		data->fs.flag.zero = 0;
	if (data->fs.precision + (data->fs.sign ? 1 : 0) >= data->fs.wid || \
	(int)ft_strlen(data->fs.fnl) + (data->fs.sign ? 1 : 0) >= data->fs.wid)
		data->fs.wid = 0;
	printUInt2(data);
}