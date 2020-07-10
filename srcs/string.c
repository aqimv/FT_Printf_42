/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:37:48 by skennith          #+#    #+#             */
/*   Updated: 2020/07/09 14:37:50 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void precisionString(t_pfstruct *data)
{
	char *buf;

	buf = data->fs.fnl;
	if (data->fs.precision < (int)ft_strlen(data->fs.fnl) \
	&& data->fs.prZ != 0 && data->fs.precision >= 0)
	{
		data->fs.fnl = ft_strnew(data->fs.precision);
		data->fs.fnl = ft_strncpy(data->fs.fnl, buf, \
		data->fs.precision);
		ft_strdel(&buf);
	}
}

void printString(t_pfstruct *data)
{
	char ch;
	int lenCh;

	ch = data->fs.flag.zero ? '0' : ' ';
	data->fs.fnl = (char *)va_arg(data->args, char *);
	if (data->fs.fnl == NULL)
		data->fs.fnl = ft_strdup("(null)");
	else
		data->fs.fnl = ft_strdup(data->fs.fnl);
	precisionString(data);
	lenCh = data->fs.width - (int)ft_strlen(data->fs.fnl);
	if (lenCh > 0)
	{
		if (data->fs.flag.minus)
		{
			data->pfreturn += ft_putstrcount(data->fs.fnl);
			data->pfreturn += writeChars(lenCh, ch);
		}
		else
		{
			data->pfreturn += writeChars(lenCh, ch);
			data->pfreturn += ft_putstrcount(data->fs.fnl);
		}
	}
	else
		data->pfreturn += ft_putstrcount(data->fs.fnl);
}
