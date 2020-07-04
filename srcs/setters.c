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
	int count;
	int i;

	count = 0;
	i = 0;
	while (data->fs->flag[count])
		count++;
	if (count != 0)
	{

		buf = data->fs->flag;
		data->fs->flag = ft_strnew(ft_strlen(buf) + 1);
		while (buf[i])
		{
			data->fs->flag[i] = buf[i];
			i++;
		}
		data->fs->flag[i] = ch;
		ft_strdel(&buf);
	}
	else
		data->fs->flag[0] = ch;
}

void setSize(t_pfstruct *data, char ch)
{
	char *buf;
	int count;
	int i;

	count = 0;
	i = 0;
	while (data->fs->size[count])
		count++;
	if (count != 0)
	{

		buf = data->fs->size;
		data->fs->size = ft_strnew(ft_strlen(buf) + 1);
		while (buf[i])
		{
			data->fs->size[i] = buf[i];
			i++;
		}
		data->fs->size[i] = ch;
		ft_strdel(&buf);
	}
	else
		data->fs->size[0] = ch;
}

void setWidth(t_pfstruct *data, char ch)
{
	if (ch == '*')
		data->fs->width = va_arg(data->args, int);
	else if (data->fs->width == 0)
		data->fs->width += ft_atoi(&ch);
	else
		data->fs->width = (data->fs->width * 10) + ft_atoi(&ch);
}
void setAccuracy(t_pfstruct *data, char ch)
{
	if (ch == '*')
		data->fs->accuracy = va_arg(data->args, int);
	else if (data->fs->accuracy == 0)
		data->fs->accuracy += ft_atoi(&ch);
	else
		data->fs->accuracy = (data->fs->accuracy * 10) + ft_atoi(&ch);
}