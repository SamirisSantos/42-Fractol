/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_snowflake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:13:40 by sade-ara          #+#    #+#             */
/*   Updated: 2025/09/01 16:13:40 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

// Implementação do algoritmo de Bresenham para desenhar uma linha
/*
Algoritmo de Bresenham
A reta de dois pontos (x1,y1) e (x2,y2)
y = y1 + m(x-x1);
m = (y2-y1)/(x2-x1)
copysign(1, valor) devolve +1 se valor for positivo e -1 se for negativo
*/
static void	init_line(t_line *bresenham, t_point p1, t_point p2)
{
	bresenham->dist_x = ft_abs(p2.x - p1.x);
	bresenham->dist_y = -(ft_abs(p2.y - p1.y));
	bresenham->step_x = 1;
	if (p1.x > p2.x)
		bresenham->step_x = -1;
	bresenham->step_y = 1;
	if (p1.y > p2.y)
		bresenham->step_y = -1;
	bresenham->err = bresenham->dist_x - bresenham->dist_y;
}

void	draw_line_bresenham(t_img *img, t_point start, t_point end, int color)
{
	t_line	b;
	int		x;
	int		y;
	int		i;

	init_line(&b, start, end);
	i = 0;
	while (i++ <= (b.dist_x + b.dist_y))
	{
		ft_pixel_put(start.x, start.y, img, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		b.e2 = 2 * b.err;
		if (b.e2 > -b.dist_y)
		{
			b.err -= b.dist_y;
			start.x += b.step_x;
		}
		if (b.e2 < b.dist_x)
		{
			b.err += b.dist_x;
			start.y += b.step_y;
		}
	}
}

