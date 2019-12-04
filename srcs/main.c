/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <abenani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:55:08 by abenani           #+#    #+#             */
/*   Updated: 2019/12/04 11:55:51 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"



void draw(int *tab , t_event event)
{
   int x,y;
   double zr,zi,cr,ci,tmp;
   int i;
   y = 0;
   while (y < 600)
   {
       x = 0;
       while (x < 600)
       {
           cr = (double)x / (event.zoom) + event.mvx;
           ci = (double)y / (event.zoom) + event.mvy;
           
           zr = 0;
           zi = 0;
           i = 0;
           while (zr*zr+zi*zi < 4 && i < event.it)
            {
                tmp = zr;
                zr = zr*zr - zi*zi + cr;
                zi = 2 * zi * tmp + ci;
                i++;
            }
            if (i < event.it)
            tab[x+y*600] = 0x8fd5f9 * i;
           x++;
       }
       y++;
   }
}

int main()
{
    t_ptr ptr;
    t_img img;
    t_event *event;
    event = malloc(sizeof(t_event));

    event->zoom = 200;
    event->it = 50;
    event->mvx = 0;
    event->mvy = 0;
    event->mvx = -2;
    event->mvy = -1.24;

    ptr.mlx = mlx_init();
    ptr.win = mlx_new_window(ptr.mlx, 600, 600, "Fractol");
    img.ptr = mlx_new_image(ptr.mlx, 600, 600);
    img.data = (int*)mlx_get_data_addr(img.ptr, &img.bpp, &img.sl, &img.end);
    event->ptr = ptr;
    event->img = img;
    draw(img.data, *event);
    mlx_put_image_to_window(ptr.mlx, ptr.win, img.ptr, 0, 0);
    mlx_hook(ptr.win, 2, 0, key_press, (void*)event);
    mlx_hook(ptr.win, 4, 0, mouse_press, (void*)event);
    mlx_loop(ptr.mlx);
}