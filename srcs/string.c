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

void printString(t_pfstruct *data)
{
	char ch;
	int lenCh;

	ch = data->fs.flag.zero ? '0' : ' ';
	data->fs.finalstr = ft_strdup((char *)va_arg(data->args, char *));
	if (data->fs.finalstr == NULL)
		data->fs.finalstr = ft_strdup("(null)");
	lenCh = data->fs.width - (int)ft_strlen(data->fs.finalstr);
//	if (data->fs.flag.minus)
//	{
//		if (lenCh > 0)
//		{
//			ft_putstr(data->fs.finalstr);
//			data->pfreturn += (int)ft_strlen(data->fs.finalstr);
//			writeChars(len, ch);
//		}
//		else
//		{
//			ft_putstr(data->fs.finalstr);
//			data->pfreturn += (int)ft_strlen(data->fs.finalstr);
//		}
//	}
//	else
//	{
//		if (lenCh > 0)
//		{
//			writeChars(len, ch);
//			ft_putstr(data->fs.finalstr);
//			data->pfreturn += (int)ft_strlen(data->fs.finalstr);
//		}
//		else
//		{
//			ft_putstr(data->fs.finalstr);
//			data->pfreturn += (int)ft_strlen(data->fs.finalstr);
//		}
//	}
	if (lenCh > 0)
	{
		if (data->fs.flag.minus)
		{
			ft_putstr(data->fs.finalstr);
			data->pfreturn += (int)ft_strlen(data->fs.finalstr);
			writeChars(lenCh, ch);
		}
		else
		{
			writeChars(lenCh, ch);
			ft_putstr(data->fs.finalstr);
			data->pfreturn += (int)ft_strlen(data->fs.finalstr);
		}
	}
	else
	{
		ft_putstr(data->fs.finalstr);
		data->pfreturn += (int)ft_strlen(data->fs.finalstr);
	}
}
