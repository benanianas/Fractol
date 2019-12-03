/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <abenani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:12:13 by abenani           #+#    #+#             */
/*   Updated: 2019/12/03 10:38:25 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# define width 600
# define height 600

typedef struct  s_ptr
{
    void        *mlx;
    void        *win;
}               t_ptr;
typedef struct s_img
{
    int         bpp;
    int         sl;
    int         end;
    void        *ptr;
    int         *data;
}               t_img;
typedef struct  s_msg
{
    t_ptr       ptr;
    t_img       img;
    int         x;
    int         y;
    double      zoom;
    int         it;
    int         mvx;
    int         mvy;
    double      zmvx;
    double      zmvy;
}               t_msg;


#endif