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

char		*sum1(char *s1, char *s2)
{
	int		carry;
	int		sum;
	int		i;

	i = ft_strlen(s1) - 1;
	carry = 0;
	while (i >= 0)
	{
		sum = (s2[i] - '0') + (s1[i] - '0');
		sum += carry;
		if (sum >= 10)
		{
			sum -= 10;
			s2[i] = (char)(sum + '0');
			carry = 1;
		}
		else
		{
			s2[i] = (char)(sum + '0');
			carry = 0;
		}
		i = i - 1;
	}
	ft_strdel(&s1);
	return (s2);
}

char		*from_bin(char *str)
{
	char	*k;
	int		i;
	char 	*pow;

	k = ft_strnew(0);
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] - '0') == 1)
		{
			pow = power2(i + 1);
			k = sum1(k, pow);
		}
		i++;
	}
	ft_strdel(&str);
	return (k);
}
