/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:56:02 by skennith          #+#    #+#             */
/*   Updated: 2020/07/11 15:56:04 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



char      *ft_ftoa_base2(double num)
{
	int       i;
	char   *ans;

	ans = (char *)malloc(sizeof(char) * 151);
	ans[150] = '\0';
	i = 0;
	while(num != 1.0 && i < 150)
	{
		num = num * 2;
		ans[i] = (int)num + '0';
		if (num > 1)
			num = num - 1;
		i++;
	}
	while (i < 150)
	{
		ans[i] = '0';
		i++;
	}
	return ans;
}

char      *rounding(char *num, int n)
{
	int       k;
	int       i;

	k = num[n] - '0';
	if (k >= 5)
	{
		k = num[n - 1] - '0';
		k += 1;
		if (k != 10)
			num[n - 1] = k + '0';
		i = n;
		while (num[i - 1] == '9')
		{
			num[i - 1] = '0';
			k = num[i - 2] - '0';
			k += 1;
			if (k != 10)
				num[i - 2] = k + '0';
			i--;
		}
	}
	num[n] = '\0';
	return num;
}

char      *floatToString(double num, int round)
{
	char   *integer;
	char   *fraction;
	int    whole;
	char   *str;

	whole = num;
	if (whole < 0)
		whole = whole * (-1);
	fraction = rounding(fromBin(ft_ftoa_base2(num - whole)), round);
	str = (char *)malloc(sizeof(char) * (round + 1));
	str[round + 1] = '\0';
	ft_memset(str, '0', round);
	if (ft_strcmp(str, fraction) == 0)
		whole += 1;
	integer = ft_itoa(whole);
	if ((int)ft_strlen(fraction) < round)
	{
		ft_bzero(str, ft_strlen(str));
		ft_memset(str, '0', round - (int)ft_strlen(fraction));
		fraction = ft_strjoin(fraction, str);
	}
	if (round != 0)
		integer = ft_strjoin(integer, ".");
	return ft_strjoin(integer, fraction);
}

void printFloat(t_pfstruct *data)
{
	long double num;
//	long double f;

	if (data->fs.size.bigL)
		num = (long double)va_arg(data->args, long double);
	else
		num = (long double)va_arg(data->args, double);
	if ((data->fs.precision == 0 && !data->fs.prZ) || data->fs.precision < 0)
		data->fs.precision = 6;
	ft_putstr(floatToString(num, data->fs.precision));
}

