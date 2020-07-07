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

int setFlag(t_pfstruct *data, char ch)
{
	if (ch == '-')
		data->fs.flag.minus = 1;
	else if (ch == '+')
		data->fs.flag.plus = 1;
	else if (ch == '0')
		data->fs.flag.zero = 1;
	else if (ch == ' ')
		data->fs.flag.space = 1;
	else if (ch == '#')
		data->fs.flag.sharp = 1;
}

int setSize(t_pfstruct *data, int *i)
{
	if (data->fs.str[*i] != data->fs.str[*i + 1])
	{
		if (data->fs.str[*i] == 'l')
			data->fs.size.l = 1;
		else if (data->fs.str[*i] == 'h')
			data->fs.size.h_size = 1;
		else if (data->fs.str[*i] == 'j')
			data->fs.size.j = 1;
		else if (data->fs.str[*i] == 'z')
			data->fs.size.z = 1;
		else if (data->fs.str[*i] == 't')
			data->fs.size.t = 1;
		else if (data->fs.str[*i] == 'L')
			data->fs.size.bigL = 1;
		*i = *i + 1;
	}
	else
	{
		if (data->fs.str[*i] == 'l' && data->fs.str[*i + 1] == 'l')
			data->fs.size.ll = 1;
		else if (data->fs.str[*i] == 'h' && data->fs.str[*i + 1] == 'h')
			data->fs.size.hh = 1;
		*i = *i + 2;
	}
	return (0);
}

//int setSize(t_pfstruct *data, char ch)
//{
//	char *buf;
//	char *buf2;
//
//	buf2 = ft_strnew(1);
//	buf2[0] = ch;
//	if (data->fs.size != NULL)
//	{
//		buf = ft_strjoin(data->fs.size, buf2);
////		ft_strdel(&data->fs.size);
//		data->fs.size = buf;
//	}
//	else
//	{
//		data->fs.size = ft_strnew(1);
//		data->fs.size[0] = ch;
//	}
//	return (0);
//}

int setWidth(t_pfstruct *data, char ch)
{
	if (ch == '*')
		data->fs.width = va_arg(data->args, int);
	else if (data->fs.width == 0)
		data->fs.width += ft_atoi(&ch);
	else
		data->fs.width = (data->fs.width * 10) + ft_atoi(&ch);
	return (0);
}
int setAccuracy(t_pfstruct *data, char ch)
{
	if (ch == '*')
		data->fs.accuracy = va_arg(data->args, int);
	else if (data->fs.accuracy == 0)
		data->fs.accuracy += ft_atoi(&ch);
	else
		data->fs.accuracy = (data->fs.accuracy * 10) + ft_atoi(&ch);
	return (0);
}