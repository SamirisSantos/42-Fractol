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

int	menu_helps(void)
{
	ft_putstr("Choose a fractol:\n");
	ft_putstr("Mandelbrot: ./fractol mandelbrot\n");
	ft_putstr("Julia:      ./fractol julia <re> <im>\n");
	exit(EXIT_FAILURE);
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
			// mandel_render(&fractal);
		}
		else if(ft_strcmp(argv[1], "julia") == 0)
		{
			fractal.name = "Julia";
			fractol_init(&fractal);
			// render_julia(&fractal);
		}else
			menu_helps();


		t_complex	z;
		t_complex	c;
		double		temp_real;

		z.real_nbr = 0;
		z.im_nbr = 0;

		c.real_nbr = 0.25;
		c.im_nbr = 0.4;

		for( int i = 0; i < 10; ++i)
		{
			// Formula do Fractal Julia -> Z(n+1) = Z(n)^2 + C
			temp_real = (z.real_nbr * z.real_nbr) - (z.im_nbr * z.im_nbr);
			z.im_nbr = 2 * z.real_nbr * z.im_nbr;
			z.real_nbr = temp_real;

			z.real_nbr = z.real_nbr + c.real_nbr;
			z.im_nbr = z.im_nbr + c.im_nbr;
		}
	}else
		menu_helps();
		

	mlx_key_hook(fractal.win_ptr, handle_input,&fractal);	
	mlx_hook(fractal.win_ptr, 17, 0, handle_close, &fractal);
	mlx_mouse_hook(fractal.win_ptr, handle_mouse, NULL);
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
