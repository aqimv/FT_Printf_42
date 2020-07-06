/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:21:56 by skennith          #+#    #+#             */
/*   Updated: 2020/07/03 18:22:06 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // убрать нахой

void setFlag(t_pfstruct *data, char ch)
{
	char *buf;
	char *buf2;

	buf2 = ft_strnew(1);
	buf2[0] = ch;
//	printf("|  %s  |", data->fs.str);
	ft_putstr(data->fs.str);
	if (data->fs.flag != NULL)
	{
		buf = ft_strjoin(data->fs.flag, buf2);
		free(data->fs.flag);
		data->fs.flag = buf;
	}
	else
	{
		data->fs.flag = ft_strnew(1);
		data->fs.flag[0] = ch;
	}
}

void setSize(t_pfstruct *data, char ch)
{
	char *buf;
	char *buf2;

	buf2 = ft_strnew(1);
	buf2[0] = ch;
	if (data->fs.size != NULL)
	{
		buf = ft_strjoin(data->fs.size, buf2);
		ft_strdel(&data->fs.size);
		data->fs.size = buf;
	}
	else
	{
		data->fs.size = ft_strnew(1);
		data->fs.size[0] = ch;
	}
}

void setWidth(t_pfstruct *data, char ch)
{
	if (ch == '*')
		data->fs.width = va_arg(data->args, int);
	else if (data->fs.width == 0)
		data->fs.width += ft_atoi(&ch);
	else
		data->fs.width = (data->fs.width * 10) + ft_atoi(&ch);
}
void setAccuracy(t_pfstruct *data, char ch)
{
	if (ch == '*')
		data->fs.accuracy = va_arg(data->args, int);
	else if (data->fs.accuracy == 0)
		data->fs.accuracy += ft_atoi(&ch);
	else
		data->fs.accuracy = (data->fs.accuracy * 10) + ft_atoi(&ch);
}