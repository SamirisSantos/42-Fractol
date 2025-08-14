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
	t_fractol	data;
	// teste de imagem
	//char	*relative_path = "./minilibx-linux/test/open30.xpm";
	int		img_width;
	int		img_height;
	void	*img;
	t_fractol	fractal;
	data.color = 0xFF0000;


	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
 		free(data.mlx_ptr);
		return (MLX_ERROR);
	}

	if(argc == 2 || argc == 4)
	{
		if(ft_strcmp(argv[1], "mandelbrot") == 0)
		{
			mlx_string_put(data.mlx_ptr, data.win_ptr, (WIN_WIDTH/2) - 90, (WIN_HEIGHT/2), data.color, "Mandelbrot");
			fractol_init(&fractol);
			render_mand(&fractol);
		}
		else if(ft_strcmp(argv[1], "julia") == 0)
		{
			mlx_string_put(data.mlx_ptr, data.win_ptr, (WIN_WIDTH/2) - 90, (WIN_HEIGHT/2), data.color, "Julia");
			fractol_init(&fractol);
			render_julia(&fratol);
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
		

	mlx_key_hook(data.win_ptr, handle_input,&data);	
	mlx_hook(data.win_ptr, 17, 0, handle_close, &data);
	mlx_mouse_hook(data.win_ptr, handle_mouse, NULL);
	mlx_loop(data.mlx_ptr);
	return (0);
}
