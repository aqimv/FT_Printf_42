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

	printf("| - %s - |", data->fs->str);
	if (ft_strlen(data->fs->flag) != 0)
	{
		printf("| - %s - 2|", data->fs->str);
		buf = ft_strnew(ft_strlen(data->fs->flag) + 1); // ТУТ ЕБУЧИЙ БАГ КОТОРЫЙ Я НИХУЯ НЕ ПОЙМУ!!!!!

		buf = ft_strcpy(buf, data->fs->flag);
		buf[ft_strlen(data->fs->flag)] = ch;
		ft_strdel(&data->fs->flag);
		data->fs->flag = buf;
	}
	else
		data->fs->flag[0] = ch;
}

void setSize(t_pfstruct *data, char ch)
{
	char *buf;

	if (ft_strlen(data->fs->size) != 0)
	{
		buf = ft_strnew(ft_strlen(data->fs->size) + 1);
		buf = ft_strcpy(buf, data->fs->size);
		buf[ft_strlen(data->fs->size)] = ch;
		ft_strdel(&data->fs->size);
		data->fs->size = buf;
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