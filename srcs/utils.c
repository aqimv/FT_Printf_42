/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:38:33 by skennith          #+#    #+#             */
/*   Updated: 2020/07/09 14:38:34 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_putstrcount(char const *s)
{
	int count;

	count = 0;
	if (!s)
		return (count);
	while (*s)
	{
		ft_putchar(*s);
		s++;
		count++;
	}
	return (count);
}

int writeChars(int i, char ch)
{
	char count;

	count = 0;
	while (i != 0)
	{
		write(1, &ch, 1);
		i--;
		count++;
	}
	return (count);
}
