/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <abenani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:02:59 by abenani           #+#    #+#             */
/*   Updated: 2019/12/04 13:02:53 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int     key_press(int keycode, void *param)
{
    t_event *event;
    
    event = (t_event*)param;
    if(keycode == 53)
    {
        free(event->img.data);
        exit(0);
    }
    if(keycode == 69)
        event->it += 10;
    if(keycode == 78 && event->it != 10)
        event->it -= 10;
    if (keycode == 126)
		event->mvy -= 0.03;
	if (keycode == 125)
		event->mvy += 0.03;
	if (keycode == 124)
		event->mvx += 0.03;
	if (keycode == 123)
		event->mvx -= 0.03;
    erase_img(event->img.data);
    draw(event->img.data, *event);
    mlx_put_image_to_window(event->ptr.mlx, event->ptr.win, event->img.ptr, 0, 0);
    return (0);
}
int         mouse_press(int code, int x, int y, void *param)
{
    t_event *event;
    t_zoom  z;
    static int i = 0;
   
    event = (t_event*)param;
    if (code == 5)
    {
        z.cx = x / event->zoom;
        z.cy = y / event->zoom;
        event->zoom -= 10;
        z.nx = x / event->zoom;
        z.ny = y / event->zoom;
        event->mvx -= z.nx - z.cx;
        event->mvy -= z.ny - z.cy;
    }
    if(code == 4)
    {
        z.cx = x / event->zoom;
        z.cy = y / event->zoom;
        event->zoom += (10 + (2 * i));
        z.nx = x / event->zoom;
        z.ny = y / event->zoom;
        event->mvx -= z.nx - z.cx;
        event->mvy -= z.ny - z.cy;
        i += 20;
    }
    erase_img(event->img.data);
    draw(event->img.data, *event);
    mlx_put_image_to_window(event->ptr.mlx, event->ptr.win, event->img.ptr, 0, 0);
    return(0);
}