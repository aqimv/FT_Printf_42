/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 18:54:21 by skennith          #+#    #+#             */
/*   Updated: 2020/07/10 18:54:23 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void printPointer(t_pfstruct *data)
{
	intmax_t p;
	int len;

	p = (unsigned long long int)va_arg(data->args, void *);
	data->fs.fnl = p == 0 && data->fs.prZ && \
	!data->fs.precision ? ft_strnew(1) : ft_itoa_base(p, 16);
	len = ft_strlen(data->fs.fnl);
	if (data->fs.wid - len - 2 < 1)
	{
		data->pfreturn += writeChars(data->fs.precision - len, '0');
		data->pfreturn += ft_putstrcount("0x");
		data->pfreturn += ft_putstrcount(data->fs.fnl);
	}
	else
	{
		if (data->fs.flag.minus)
		{
			data->pfreturn += writeChars(data->fs.precision - len, '0');
			data->pfreturn += ft_putstrcount("0x");
			data->pfreturn += ft_putstrcount(data->fs.fnl);
			data->pfreturn += writeChars(data->fs.wid - len - 2, ' ');
		}
		else
		{
			data->pfreturn += writeChars(data->fs.wid - len - 2, ' ');
			data->pfreturn += writeChars(data->fs.precision - len, '0');
			data->pfreturn += ft_putstrcount("0x");
			data->pfreturn += ft_putstrcount(data->fs.fnl);
		}
	}

}

