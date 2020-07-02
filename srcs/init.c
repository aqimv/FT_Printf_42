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

t_fstring *fs_init()
{
	t_fstring *fs;

	fs = (t_fstring*)malloc(sizeof(t_fstring));
	fs->width = 0;
	fs->accuracy = 0;
	fs->size = 0;
	return (fs);
}

t_pfstruct *pf_init()
{
	t_pfstruct *pf;

	pf = (t_pfstruct*)malloc(sizeof(t_pfstruct));
	pf->pfreturn = 0;
	pf->fs = fs_init();
	return (pf);
}