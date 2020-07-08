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

void initSize(t_pfstruct *data)
{
	data->fs.size.l = 0;
	data->fs.size.ll = 0;
	data->fs.size.h_size = 0;
	data->fs.size.hh = 0;
	data->fs.size.j = 0;
	data->fs.size.z = 0;
	data->fs.size.t = 0;
	data->fs.size.bigL = 0;
}

void pf_init(t_pfstruct *data)
{
	data->str = NULL;
	data->fs.str = NULL;
	data->fs.finalstr = NULL;
	data->fs.type = 0;
	data->fs.width = 0;
	data->fs.precision = 0;
	data->fs.sign = 0;
	data->fs.prZ = 0;

	data->fs.flag.zero = 0;
	data->fs.flag.minus = 0;
	data->fs.flag.plus = 0;
	data->fs.flag.space = 0;
	data->fs.flag.sharp = 0;

	initSize(data);
}

void deinitSize(t_pfstruct *data)
{
	data->fs.size.l = 0;
	data->fs.size.ll = 0;
	data->fs.size.h_size = 0;
	data->fs.size.hh = 0;
	data->fs.size.j = 0;
	data->fs.size.z = 0;
	data->fs.size.t = 0;
	data->fs.size.bigL = 0;
}

void deinit(t_pfstruct *data)
{
	if (data->fs.str != NULL)
		ft_strdel(&data->fs.str);
	data->fs.str = NULL;
	if (data->fs.finalstr != NULL)
		ft_strdel(&data->fs.finalstr);
	data->fs.type = 0;
	data->fs.width = 0;
	data->fs.precision = 0;
	data->fs.sign = 0;
	data->fs.prZ = 0;

	data->fs.flag.zero = 0;
	data->fs.flag.minus = 0;
	data->fs.flag.plus = 0;
	data->fs.flag.space = 0;
	data->fs.flag.sharp = 0;

	deinitSize(data);
}
