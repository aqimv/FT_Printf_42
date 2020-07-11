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
	long long double num;

	if (data->fs.size.bigL)
		num = (long double)va_arg(data->args, long double);
	else
		num = (long double)va_arg(data->args, double);
}
