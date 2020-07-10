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

	buf = data->fs.finalstr;
	if (data->fs.precision < (int)ft_strlen(data->fs.finalstr) \
	&& data->fs.prZ != 0 && data->fs.precision >= 0)
	{
		data->fs.finalstr = ft_strnew(data->fs.precision);
		data->fs.finalstr = ft_strncpy(data->fs.finalstr, buf, \
		data->fs.precision);
		ft_strdel(&buf);
	}
}

void printString(t_pfstruct *data)
{
	char ch;
	int lenCh;

	ch = data->fs.flag.zero ? '0' : ' ';
	data->fs.finalstr = (char *)va_arg(data->args, char *);
	if (data->fs.finalstr == NULL)
		data->fs.finalstr = ft_strdup("(null)");
	else
		data->fs.finalstr = ft_strdup(data->fs.finalstr);
	precisionString(data);
	lenCh = data->fs.width - (int)ft_strlen(data->fs.finalstr);
	if (lenCh > 0)
	{
		if (data->fs.flag.minus)
		{
			data->pfreturn += ft_putstrcount(data->fs.finalstr);
			data->pfreturn += writeChars(lenCh, ch);
		}
		else
		{
			data->pfreturn += writeChars(lenCh, ch);
			data->pfreturn += ft_putstrcount(data->fs.finalstr);
		}
	}
	else
		data->pfreturn += ft_putstrcount(data->fs.finalstr);
}
