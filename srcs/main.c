/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <abenani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:55:08 by abenani           #+#    #+#             */
/*   Updated: 2019/12/07 16:35:25 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	draw(int *tab, t_event event, int num)
{
	if (num == 1)
		mandelbrot_set(tab, event);
	if (num == 2)
		julia_set(tab, event);
	if (num == 3)
		burning_ship_set(tab, event);
	if (num == 4)
		mandelbrot_set(tab, event);
	if (num == 5)
		multibrot1_set(tab, event);
	if (num == 6)
		multibrot2_set(tab, event);
	mlx_put_image_to_window(event.ptr.mlx, event.ptr.win, event.img.ptr, 0, 0);
}

void	usage(void)
{
	ft_putchar('\n');
	ft_putendl("   usage : ./fractol [fractal name]");
	ft_putchar('\n');
	ft_putendl(" - Mandelbrot");
	ft_putendl(" - Julia");
	ft_putendl(" - BurningShip");
	ft_putendl(" - Tricorn");
	ft_putendl(" - Multibrot1");
	ft_putendl(" - Multibrot2");
	exit(0);
}

void	choose_fractal(char *s, t_event *event)
{
	if (!ft_strcmp(s, "Mandelbrot"))
		call_the_fractal(1, event);
	else if (!ft_strcmp(s, "Julia"))
		call_the_fractal(2, event);
	else if (!ft_strcmp(s, "BurningShip"))
		call_the_fractal(3, event);
	else if (!ft_strcmp(s, "Tricorn"))
		call_the_fractal(4, event);
	else if (!ft_strcmp(s, "Multibrot1"))
		call_the_fractal(5, event);
	else if (!ft_strcmp(s, "Multibrot2"))
		call_the_fractal(6, event);
	else
		usage();
}

void	the_key(t_ptr ptr)
{
	int	x;
	int	y;

	x = 599;
	while (++x < WIDTH + 300)
	{
		y = -1;
		while (++y < HEIGHT)
			mlx_pixel_put(ptr.mlx, ptr.win, x, y, 0xDBDBDB);
	}
	mlx_string_put(ptr.mlx, ptr.win, 620, 10, 0, "Press ESC to exit");
	mlx_string_put(ptr.mlx, ptr.win, 620, 70, 0, "M : Mandelbrot");
	mlx_string_put(ptr.mlx, ptr.win, 620, 100, 0, "J : Julia");
	mlx_string_put(ptr.mlx, ptr.win, 620, 130, 0, "T : Tricorn");
	mlx_string_put(ptr.mlx, ptr.win, 620, 160, 0, "A : Multibrot n=3");
	mlx_string_put(ptr.mlx, ptr.win, 620, 190, 0, "Z : Multibrot n=-2");
	mlx_string_put(ptr.mlx, ptr.win, 620, 250, 0, "Scroll up to Zoom IN");
	mlx_string_put(ptr.mlx, ptr.win, 620, 280, 0, "Scroll down to Zoom Out");
	mlx_string_put(ptr.mlx, ptr.win, 620, 340, 0, "Use Arrows to move the map");
	mlx_string_put(ptr.mlx, ptr.win, 620, 400, 0, "1 -> 6 to change colors");
}

int		main(int argc, char **argv)
{
	t_ptr	ptr;
	t_img	img;
	t_event	event;

	if (argc != 2)
		usage();
	choose_fractal(argv[1], &event);
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WIDTH + 300, HEIGHT, "Fractol");
	img.ptr = mlx_new_image(ptr.mlx, WIDTH, HEIGHT);
	the_key(ptr);
	img.data = (int*)mlx_get_data_addr(img.ptr, &img.bpp, &img.sl, &img.end);
	event.ptr = ptr;
	event.img = img;
	draw(img.data, event, event.num);
	mlx_hook(ptr.win, 2, 0, key_press, (void*)&event);
	mlx_hook(ptr.win, 4, 0, mouse_press, (void*)&event);
	mlx_hook(ptr.win, 6, 0, mouse_move, (void*)&event);
	mlx_hook(ptr.win, 17, 0, call_closer, (void*)&event);
	mlx_loop(ptr.mlx);
}
