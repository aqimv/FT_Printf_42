/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:58:06 by skennith          #+#    #+#             */
/*   Updated: 2020/07/01 19:58:09 by skennith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void pf_init(t_pfstruct *data)
{
	data->str = NULL;
	data->fs.flag = NULL;
	data->fs.size = NULL;
	data->fs.str = NULL;
	data->fs.finalstr = NULL;
	data->fs.type = 0;
}