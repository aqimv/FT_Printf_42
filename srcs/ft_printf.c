/* ************************************************************************** */
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

static void switchPrintValue(t_pfstruct *data)
{
	if (data->fs.type == 'd' || data->fs.type == 'i')
		printInt(data);
	else if (data->fs.type == 'c')
		printChar(data);
	deinit(data);
}

static int newfs(t_pfstruct *data, int step, int i, int r)
{
	if (data->fs.str[i] == '.')
		newfs(data, 3, i + 1, 0);
	else if (step == 1 && ft_strchr(FLAGSPF, data->fs.str[i]))
		newfs(data, step, i + 1, setFlag(data, data->fs.str[i]));
	else if (step == 2 && ft_strchr(WIDTHANDACCURACY, data->fs.str[i]))
		newfs(data, step, i + 1, setWidth(data, data->fs.str[i]));
	else if (step == 3 && ft_strchr(WIDTHANDACCURACY, data->fs.str[i]))
		newfs(data, step, i + 1, setAccuracy(data, data->fs.str[i]));
	else if (step == 4 && ft_strchr(SIZEPF, data->fs.str[i]))
	{
		setSize(data, &i);
		newfs(data, step, i + 1, 0);
	}
	else if (step == 5 && ft_strchr(TYPESPF, data->fs.str[i]))
		data->fs.type = data->fs.str[i];
	else if (step <= 5)
		newfs(data, step + 1, i, 0);
	return (data->fs.type + r);
}



static char *pars_fs(char *flag, t_pfstruct *data)
{
	char *dup;
	int i;

	i = 0;
	dup = (char *)ft_memalloc(sizeof(flag));
	while (ft_strchr(SYMBOLSINFS, *flag) && *flag)
	{
		dup[i++] = *flag;
		flag++;
	}
	if (*flag && ft_strchr(TYPESPF, *flag))
	{
		dup[i] = *flag++;
		data->fs.str = dup;
	}
//	ft_putchar('(');
//	ft_putstr(data->fs.str);
//	ft_putchar(')');
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
			if (data->fs.str)
				if (newfs(data, 1, 0, 0))
					switchPrintValue(data);
		}
	}
//	printf("| %d - width|", data->fs.width);
//	printf("| %d - accuracy|", data->fs.accuracy);
//
//	printf("| %c - type|", data->fs.type);
	return data->pfreturn;
}

/*  */

int		ft_printf(const char *format, ...)
{
	int result;
	t_pfstruct data;
	pf_init(&data);

	va_start(data.args, format);
	data.str = (char *)format;

	result = parsformat(&data);

	return (result);
}
