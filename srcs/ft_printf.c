/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:57:21 by skennith          #+#    #+#             */
/*   Updated: 2020/07/01 19:57:28 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h> // убрать нахой

static void formWidth(t_pfstruct *data, char ch)
{
	if (ch == '*')
		data->fs->width = va_arg(data->args, int);
	else if (data->fs->width == 0)
		data->fs->width += ft_atoi(&ch);
	else
		data->fs->width = (data->fs->width * 10) + ft_atoi(&ch);
}
static void formAccuracy(t_pfstruct *data, char ch)
{
	if (ch == '*')
		data->fs->accuracy = va_arg(data->args, int);
	else if (data->fs->accuracy == 0)
		data->fs->accuracy += ft_atoi(&ch);
	else
		data->fs->accuracy = (data->fs->accuracy * 10) + ft_atoi(&ch);
}

static void newfs(t_pfstruct *data)
{
	int i;
	int dotFlag;

	i = 0;
	dotFlag = 0;
	while(data->fs->str[i] && ft_strchr("0123456789.*# -+", data->fs->str[i]))
	{
		if (i == 0 && ft_strchr(FLAGSPF, data->fs->str[i]))
			data->fs->flag = data->fs->str[i];
		else if (data->fs->str[i] == '.')
			dotFlag++;
		else if ((data->fs->str[i] >= '0' && data->fs->str[i] <= '9') \
		|| data->fs->str[i] == '*')
		{
			if (!dotFlag)
				formWidth(data, data->fs->str[i]);
			else
				formAccuracy(data, data->fs->str[i]);
		}
		i++;
	}
	va_arg(data->args, int);
//	while(data->fs->str[i])
//	{
//
//	}
	printf("| %d - width|", data->fs->width);
	printf("| %d - accuracy|", data->fs->accuracy);
	printf("| %c - flag|", data->fs->flag);
//	ft_strdel(&data->fs->str);
//	free(data->fs);
}

static char *pars_fs(char *flag, t_pfstruct *data)
{
	char *dup;
	int i;

	i = 0;
	dup = ft_strnew(sizeof(flag));
	while (ft_strchr(SYMBOLSINFS, *flag) && *flag)
	{
		dup[i++] = *flag;
		flag++;
	}
	if (*flag && ft_strchr(TYPESPF, *flag))
	{
		dup[i++] = *flag++;
		dup[i] = '\0';
		ft_strdel(&data->fs->str);
		data->fs->str = dup;
	}
	ft_strdel(&dup);
	ft_putchar('(');
	ft_putstr(data->fs->str);
	ft_putchar(')');
	return flag;
}

static int parsformat(t_pfstruct *data)
{
	char *p;

	p = &data->str[0];
	while (*p)
	{
		if (*p && *p != '%')
		{
			data->pfreturn += write(1, p, 1);
			p++;
		}
		else if (p++)
		{
			p = pars_fs(p, data);
			if (*data->fs->str)
			{
				newfs(data);
				data->fs = fs_init();
			}
		}
	}
	return data->pfreturn;
}

int		ft_printf(const char *format, ...)
{
	int result;
	t_pfstruct *data;

	data = pf_init();
	va_start(data->args, format);
	data->str = (char *)format;

	result = parsformat(data);

	return (result);
}
