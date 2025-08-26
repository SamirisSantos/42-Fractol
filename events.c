/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:47:07 by sade-ara          #+#    #+#             */
/*   Updated: 2025/08/08 16:47:32 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractol_destroy(t_fractol *f)
{
	if (f->img.img_ptr)
		mlx_destroy_image(f->mlx_ptr, f->img.img_ptr);
	if (f->win_ptr)
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	if (f->mlx_ptr)
	{
		mlx_destroy_display(f->mlx_ptr);
		free(f->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
}

int	handle_input(int keysym, t_fractol *f)
{
	if (keysym == ESC_KEY)
	{
		printf("The %d key pressed. Exiting.\n", keysym);
		fractol_destroy(f);
	}
	else if (keysym == LEFT)
			f->offset_x += 0.5; // f->zoom;
	else if (keysym == RIGHT)
			f->offset_x -= 0.5; // f->zoom;
	else if (keysym == UP)
			f->offset_y -= 0.5; // f->zoom;
	else if (keysym == DOWN)
			f->offset_y += 0.5; // f->zoom;
	else if (keysym == PLUS || keysym == 61)
			f->defined_img += 10;
	else if (keysym == MINUS)
			f->defined_img -= 10;
	mandel_render(f);
	printf("The %d key has been pressed\n", keysym);
	return (0);
}

int	handle_close(t_fractol *f)
{
	printf("Window close (X) pressed. Exiting.\n");
	fractol_destroy(f);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	// intervalo fractal  Mandelbrot e Julia: [-2, 2]
	if(button == SCROLL_UP)
	{
		f->zoom *= 0.95;
		printf("Zoom in\n");
	}
	else if (button == SCROLL_DOWN)
	{
		f->zoom *= 1.05;
		printf("Zoom out\n");
	}
	mandel_render(f);
	return (0);
}
