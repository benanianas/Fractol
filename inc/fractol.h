/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <abenani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:12:13 by abenani           #+#    #+#             */
/*   Updated: 2019/11/28 16:21:17 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>

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
}               t_msg;

#endif