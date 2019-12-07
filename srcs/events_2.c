/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <abenani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:41:20 by abenani           #+#    #+#             */
/*   Updated: 2019/12/07 16:40:26 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	key_change(int keycode, t_event *event)
{
	if (keycode == 46)
		call_the_fractal(1, event);
	if (keycode == 38)
		call_the_fractal(2, event);
	if (keycode == 11)
		call_the_fractal(3, event);
	if (keycode == 17)
		call_the_fractal(4, event);
	if (keycode == 0)
		call_the_fractal(5, event);
	if (keycode == 6)
		call_the_fractal(6, event);
}

void	key_color(int keycode, t_event *event)
{
	if (keycode == 83)
		event->c = 0x030449;
	if (keycode == 84)
		event->c = 0x232324;
	if (keycode == 85)
		event->c = 0x0034b8;
	if (keycode == 86)
		event->c = 0x4d0800 / 5;
	if (keycode == 87)
		event->c = 0x0655350;
	if (keycode == 88)
		event->c = 0x1F00B9;
}

void	zoom_out(int x, int y, t_event *event)
{
	double		cx;
	double		cy;
	double		nx;
	double		ny;

	x += event->trx;
	y += event->try;
	cx = x / event->zoom;
	cy = y / event->zoom;
	event->zoom /= 1.4;
	nx = x / event->zoom;
	ny = y / event->zoom;
	event->mvx -= nx - cx;
	event->mvy -= ny - cy;
	event->it -= 2;
}

void	zoom_in(int x, int y, t_event *event)
{
	double		cx;
	double		cy;
	double		nx;
	double		ny;

	x += event->trx;
	y += event->try;
	cx = x / event->zoom;
	cy = y / event->zoom;
	event->zoom *= 1.4;
	nx = x / event->zoom;
	ny = y / event->zoom;
	event->mvx -= nx - cx;
	event->mvy -= ny - cy;
	event->it += 2;
}
