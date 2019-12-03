/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <abenani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:55:08 by abenani           #+#    #+#             */
/*   Updated: 2019/12/03 15:33:52 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"



void draw(int *tab , t_msg msg)
{
   int x,y;
   double zr,zi,cr,ci,tmp;
   double x1= -2.1,x2=0.6, y1= -1.2, y2 = 1.2;
   double thex = (x2 - x1) / 600;
   double they = (y2 - y1) / 600;
   int i;
   y = 0;
   while (y < 600)
   {
       x = 0;
       while (x < 600)
       {
           cr = ((x+msg.mvx) * thex + x1) / msg.zoom - msg.zmvx;
           ci = ((y+msg.mvy) * they + y1) / msg.zoom - msg.zmvy;
           
           zr = 0;
           zi = 0;
           i = 0;
           while (zr*zr+zi*zi < 4 && i < msg.it)
            {
                tmp = zr;
                zr = zr*zr - zi*zi + cr;
                zi = 2 * zi * tmp + ci;
                i++;
            }
            if (i < msg.it)
            tab[x+y*600] = 0x8fd5f9 * i;
           x++;
       }
       y++;
   }
}

void    erase_img(int *tab)
{
    int i;

    i = 0;
    while (i < 600*600)
    {
        tab[i] = 0x000000;
        i++;
    }
}

int     key_press(int keycode, void *param)
{
    t_msg *msg;
    
    msg = (t_msg*)param;
    if(keycode == 53)
    {
        free(msg->img.data);
        exit(0);
    }
    if(keycode == 69)
        msg->it += 10;
    if(keycode == 78 && msg->it != 10)
        msg->it -= 10;
    if (keycode == 126)
		msg->mvy -= 8;
	if (keycode == 125)
		msg->mvy += 8;
	if (keycode == 124)
		msg->mvx += 8;
	if (keycode == 123)
		msg->mvx -= 8;
    erase_img(msg->img.data);
    draw(msg->img.data, *msg);
    mlx_put_image_to_window(msg->ptr.mlx, msg->ptr.win, msg->img.ptr, 0, 0);
    return (0);
}
int         mouse_press(int code, int x, int y, void *param)
{
    t_msg *msg;
   
    msg = (t_msg*)param;
    double x1= -2.1,x2=0.6, y1= -1.2, y2 = 1.2;
   double thex = (x2 - x1) / 600;
   double they = (y2 - y1) / 600;
   double nx,ny,cx,cy,xx,yy;
    if (code == 5)
    {
        cx = (x * thex + x1) / msg->zoom;
       cy = (y * they + y1) / msg->zoom;
       msg->zoom -= 0.1;
       nx = (x * thex + x1) / msg->zoom;
       ny = (y * they + y1) / msg->zoom;
       xx = nx - cx;
       yy = ny - cy;
       msg->zmvx += xx;
       msg->zmvy += yy;
      
        
    }
    if(code == 4)
    {
       cx = (x * thex + x1) / msg->zoom;
       cy = (y * they + y1) / msg->zoom;
       msg->zoom += 0.1;
       nx = (x * thex + x1) / msg->zoom;
       ny = (y * they + y1) / msg->zoom;
       xx = nx - cx;
       yy = ny - cy;
       msg->zmvx += xx;
       msg->zmvy += yy;
      
    }
    erase_img(msg->img.data);
    draw(msg->img.data, *msg);
    mlx_put_image_to_window(msg->ptr.mlx, msg->ptr.win, msg->img.ptr, 0, 0);
    return(0);
}
int main()
{
    t_ptr ptr;
    t_img img;
    t_msg *msg;
    msg = malloc(sizeof(t_msg));

    msg->zoom = 1;
    msg->it = 50;
    msg->mvx = 0;
    msg->
    mvy = 0;
    msg->zmvx = 0;
    msg->zmvy = 0;

    ptr.mlx = mlx_init();
    ptr.win = mlx_new_window(ptr.mlx, 600, 600, "Fractol");
    img.ptr = mlx_new_image(ptr.mlx, 600, 600);
    img.data = (int*)mlx_get_data_addr(img.ptr, &img.bpp, &img.sl, &img.end);
    msg->ptr = ptr;
    msg->img = img;
    draw(img.data, *msg);
    mlx_put_image_to_window(ptr.mlx, ptr.win, img.ptr, 0, 0);
    mlx_hook(ptr.win, 2, 0, key_press, (void*)msg);
    mlx_hook(ptr.win, 4, 0, mouse_press, (void*)msg);
    mlx_loop(ptr.mlx);
}