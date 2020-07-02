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

static void newfs(t_pfstruct *data)
{

}

static char *pars_fs(char *flag, t_pfstruct *data)
{
	char *dup;
	int i;

	i = 0;
	dup = ft_strnew(sizeof(flag));
	data->fs->str = ft_strnew(1);
	while (!ft_strchr(FLAGS, *flag) && *flag && ft_strchr(SYMBOLSINFS, *flag))
	{
		dup[i++] = *flag;
		flag++;
	}
	if (*flag && ft_strchr(SYMBOLSINFS, *flag))
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
				newfs(data);
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
