/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <abenani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 21:55:52 by abenani           #+#    #+#             */
/*   Updated: 2019/12/07 16:17:02 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	multibrot2_core(t_dep *dep, t_set var)
{
	var.x = 0;
	while (var.x < 600)
	{
		var.cr = (double)(var.x  + dep->event.trx) / (dep->event.zoom)
			+ dep->event.mvx;
		var.ci = (double)(var.y  + dep->event.try) / (dep->event.zoom)
			+ dep->event.mvy;
		var.zr = var.cr;
		var.zi = var.ci;
		var.i = 0;
		while (var.zr*var.zr+var.zi*var.zi < 4 && var.i < dep->event.it)
		{
			var.zr_nom = var.zr*var.zr - var.zi*var.zi;
			var.zr_den = var.zr*var.zr*var.zr*var.zr +
				var.zi*var.zi*var.zi*var.zi + 2 * var.zr*var.zr*var.zi*var.zi;
			var.zi_nom = -2* var.zr*var.zi;
			var.zr = var.zr_nom/var.zr_den + var.cr;
			var.zi = var.zi_nom/var.zr_den + var.ci;
			var.i++;
		}
		if (var.i < dep->event.it)
			dep->tab[var.x + var.y*600] = dep->event.c * var.i;
		var.x++;
	}
}

void	*multibrot2_part1(void *param)
{
	t_dep *dep;
	t_set var;

	dep = (t_dep *)param;
	var.y = 0;
	while (var.y < 150)
	{
		multibrot2_core(dep, var);
		var.y++;
	}
	return (NULL);
}

void	*multibrot2_part2(void *param)
{
	t_dep *dep;
	t_set var;

	dep = (t_dep *)param;
	var.y = 150;
	while (var.y < 300)
	{
		multibrot2_core(dep, var);
		var.y++;
	}
	return (NULL);
}

void	*multibrot2_part3(void *param)
{
	t_dep *dep;
	t_set var;

	dep = (t_dep *)param;
	var.y = 300;
	while (var.y < 450)
	{
		multibrot2_core(dep, var);
		var.y++;
	}
	return (NULL);
}

void	*multibrot2_part4(void *param)
{
	t_dep *dep;
	t_set var;

	dep = (t_dep *)param;
	var.y = 450;
	while (var.y < 600)
	{
		multibrot2_core(dep, var);
		var.y++;
	}
	return (NULL);
}
