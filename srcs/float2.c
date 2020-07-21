/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:53:12 by skennith          #+#    #+#             */
/*   Updated: 2020/07/21 22:53:20 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*sum2(char *s1, char *s2, char *res)
{
	int		carry;
	int		sum;
	int		i;

	i = ft_strlen(s1) - 1;
	carry = 0;
	while (i >= 0)
	{
		sum = (s1[i] - '0') + (s2[i] - '0');
		sum += carry;
		if (sum >= 10)
		{
			sum -= 10;
			res = ft_strjoin(ft_itoa(sum), res);
			carry = 1;
		}
		else
		{
			res = ft_strjoin(ft_itoa(sum), res);
			carry = 0;
		}
		i = i - 1;
	}
	return (res);
}

char		*sum1(char *s1, char *s2)
{
	char	*str;
	char	*result;

	result = ft_strnew(0);
	str = (char *)malloc(sizeof(char) * \
	(ft_abs(ft_strlen(s1), ft_strlen(s2)) + 1));
	str[ft_abs(ft_strlen(s1), ft_strlen(s2)) + 1] = '\0';
	ft_memset(str, '0', ft_abs(ft_strlen(s1), ft_strlen(s2)));
	if (ft_strlen(s1) > ft_strlen(s2))
		s2 = ft_strjoin(s2, str);
	else if (ft_strlen(s1) < ft_strlen(s2))
		s1 = ft_strjoin(s1, str);
	return (sum2(s1, s2, result));
}

char		*from_bin(char *str)
{
	char	*k;
	int		i;

	k = ft_strnew(0);
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] - '0') == 1)
			k = sum1(k, power2(i + 1));
		i++;
	}
	return (k);
}
