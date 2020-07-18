/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:56:02 by skennith          #+#    #+#             */
/*   Updated: 2020/07/11 15:56:04 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void printFloat(t_pfstruct *data)
{
	long double num;
	long double f;

	if (data->fs.size.bigL)
		num = (long double)va_arg(data->args, long double);
	else
		num = (long double)va_arg(data->args, double);
	data->fl.str1 = ft_itoa_base(num, 10);
	num = num - (int)num;
	data->fl.precision = 6;
	if (data->fs.precision)
		data->fl.precision = data->fs.precision;
	if (num != 0)
	{
//		num = num * power(10, data->fl.precision);
		f = (num >= 0) ? (long)(num + 0.5) : (long)(num - 0.5);
		data->fl.str2 = ft_itoa_base(f, 10);
	}
	ft_putstr(data->fl.str1);
	ft_putchar('.');
	ft_putstr(data->fl.str2);
}

