/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 23:16:20 by skennith          #+#    #+#             */
/*   Updated: 2020/07/21 23:16:22 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int				md(int i)
{
	return (i >= 0 ? i : i * -1);
}

long double		md_double(long double i)
{
	return (i >= 0 ? i : i * -1);
}

char	*ft_strjoinfree(char **s1, char **s2)
{
	char *res;

	res = ft_strjoin(*s1, *s2);
	if (s1 != NULL)
		ft_strdel(s1);
	if (s2 != NULL)
		ft_strdel(s2);
	return (res);
}
