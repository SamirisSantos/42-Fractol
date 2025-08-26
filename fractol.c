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
	exit(EXIT_FAILURE);
}

static void	events_init(t_fractol *f)
{
	mlx_key_hook(f->win_ptr, handle_input,f);	
	mlx_hook(f->win_ptr, CLOSE, 0, handle_close, f);
	mlx_mouse_hook(f->win_ptr, handle_mouse,f);
	mlx_loop(f->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_fractol	fractal;

	if(argc == 2 || argc == 4)
	{
		if(ft_strcmp(argv[1], "mandelbrot") == 0)
		{
			fractal.name = "Mandelbrot";
			fractol_init(&fractal);
			mandel_render(&fractal);
			events_init(&fractal);
		}
		else if(ft_strcmp(argv[1], "julia") == 0)
		{
			fractal.name = "Julia";
			fractol_init(&fractal);
			// render_julia(&fractal);
			events_init(&fractal);
		}else
			menu_helps();
	}
	return (0);
}
