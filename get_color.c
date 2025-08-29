/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:09:28 by sade-ara          #+#    #+#             */
/*   Updated: 2025/08/29 12:09:28 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
MODE ZERO COLOR BLE
r = (iter * 5) % 255; 
g = (iter * 7) % 255; 
b = (iter * 11) % 255; 

RETURN FUNCIONS
return ((r << 16) | (g << 8) | b); -> 0xRRGGBB

static int	mode_one(int iter) resultado entre 1 e 255
static int	mode_two(int iter, double t) Função polinomial - smooth coloring

*/

static int	mode_zero(int iter)
{
	int	r;
	int	g;
	int	b;

	r = (iter * 5) % 255;
	g = (iter * 2) % 55;
	b = (iter * 11) % 255;
	return ((r << 16) | (g << 8) | b);
}

static int	mode_one(int iter)
{
	int	r;
	int	g;
	int	b;

	r = (int)(128 + 127 * sin(0.16 * iter));
	g = (int)(128 + 127 * sin(0.10 * iter + 2));
	b = (int)(128 + 127 * sin(0.12 * iter + 4));
	return ((r << 16) | (g << 8) | b);
}

static int	mode_two(int iter, double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	get_color(int iter, int max_iter, int mode)
{
	double	t;

	if (iter == max_iter)
		return (BLACK);
	t = (double)iter / (double)max_iter;
	if (mode == 0)
		return (mode_zero(iter));
	else if (mode == 1)
		return (mode_one(iter));
	else if (mode == 2)
		return (mode_two(iter, t));
	return (BLACK);
}
