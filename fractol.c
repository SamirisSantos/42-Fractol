/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:55:23 by sade-ara          #+#    #+#             */
/*   Updated: 2025/07/22 16:55:23 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	menu_helps(void)
{
	ft_putstr("Choose a fractol:\n");
	ft_putstr("Mandelbrot: ./fractol mandelbrot\n");
	ft_putstr("Julia:      ./fractol julia <re> <im>\n");
	ft_putstr("Koch: ./fractol koch\n");
	exit(EXIT_FAILURE);
}

void	render(t_fractol *f)
{
	if (ft_strcmp(f->name, "Mandelbrot") == 0)
		mandel_render(f);
	else if (ft_strcmp(f->name, "Julia") == 0)
		render_julia(f);
	// else if (ft_strcmp(f->name, "Koch") == 0)
	// 	render_koch(f);
}

static void	init_fractal_type(int argc, char **argv, t_fractol *fractal)
{
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
		fractal->name = "Mandelbrot";
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		fractal->name = "Julia";
		fractal->julia.real_nbr = atod(argv[2]);
		fractal->julia.im_nbr = atod(argv[3]);
	}
	else if (argc == 2 && ft_strcmp(argv[1], "koch") == 0)
		fractal->name = "Koch";
	else
		menu_helps();
}

int	main(int argc, char **argv)
{
	t_fractol	fractal;

	if (argc == 2 || argc == 4)
	{
		init_fractal_type(argc, argv, &fractal);
		fractol_init(&fractal);
		render(&fractal);
		events_init(&fractal);
	}
	else
		menu_helps();
	return (0);
}
