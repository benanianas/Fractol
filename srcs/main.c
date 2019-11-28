/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <abenani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:55:08 by abenani           #+#    #+#             */
/*   Updated: 2019/11/28 17:06:00 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

// void draw(int *tab)
// {
//     double x1= -2.1,x2=0.6, y1= -1.2, y2 = 1.2;
//     int image_x = 700;
//     int image_y = 700;
//     int it = 500;

//     double zoom_x = image_x/ (x2 - x1);
//     double zoom_y = image_y/ (y2 -y1) ;
    
//     int y = 0;
//     while (y < image_y)
//     {
//         int x = 0;
        
//         while(x < image_x)
//         {
//             double cr = x / zoom_x + x1;
//             double ci = y / zoom_y + y1;
//             double zr = 0;
//             double zi = 0;
//             int i = 0;
//             double tmp;
//             while (zr*zr+zi*zi < 4 && i < it)
//             {
//                 tmp = zr;
//                 zr = zr*zr - zi*zi + cr;
//                 zi = 2 * zi * tmp + ci;
//                 i++;
//             }
//             if (i < it)
//             tab[x+y*700] = 0x78FF00 * (i / 2);
//             x++;
//         }
//         y++;
//     }

// }
void    draw1(int *tab)
{
    int i = 0;

    while (i < 700*700)
    {
        if (i % 4 == 0)
            tab[i] = 0xff0000;
        i++;
    }
}
void    draw2(int *tab)
{
    int i = 0;

    while (i < 700*700)
    {
        if (i % 10 == 0)
            tab[i] = 0x0011ff;
        i++;
    }
}
int     key_press(int keycode, void *param)
{
    t_msg *msg;

    msg = (t_msg*)param;
    if(keycode == 53)
        exit(0);
    if(keycode == 83)
        draw1(msg->img.data);
    if(keycode == 84)
        draw2(msg->img.data);
    mlx_put_image_to_window(msg->ptr.mlx, msg->ptr.win, msg->img.ptr, 0, 0);
    return (0);
}
int main()
{
    t_ptr ptr;
    t_img img;
    t_msg *msg;
    msg = malloc(sizeof(t_msg));

    ptr.mlx = mlx_init();
    ptr.win = mlx_new_window(ptr.mlx, 1000, 700, "Fractol");
    img.ptr = mlx_new_image(ptr.mlx, 700, 700);
    img.data = (int*)mlx_get_data_addr(img.ptr, &img.bpp, &img.sl, &img.end);
    msg->ptr = ptr;
    msg->img = img;
    draw1(img.data);
    mlx_put_image_to_window(ptr.mlx, ptr.win, img.ptr, 0, 0);
    mlx_hook(ptr.win, 2, 0, key_press, (void*)msg);
    mlx_loop(ptr.mlx);
}