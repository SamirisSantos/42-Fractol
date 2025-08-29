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

static void	render(t_fractol *f)
{
	if (ft_strcmp(f->name, "Mandelbrot") == 0)
		mandel_render(f);
	else if (ft_strcmp(f->name, "Julia") == 0)
		render_julia(f);
}

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
		fractol_destroy(f);
	else if (keysym == LEFT || keysym == A_KEY)
		f->offset_x += (0.5 * f->zoom);
	else if (keysym == RIGHT || keysym == D_KEY)
		f->offset_x -= (0.5 * f->zoom);
	else if (keysym == UP || keysym == S_KEY)
		f->offset_y -= (0.5 * f->zoom);
	else if (keysym == DOWN || keysym == W_KEY)
		f->offset_y += (0.5 * f->zoom);
	else if (keysym == PLUS || keysym == 61)
		f->defined_img += 10;
	else if (keysym == MINUS)
		f->defined_img -= 10;
	else if (keysym == O_KEY) // Cor original
		f->color_mode = 0;
	else if (keysym == P_KEY) // Cor psicodélico
		f->color_mode = 1;
	else if (keysym == I_KEY) // Cor outro
		f->color_mode = 2;
	render(f);
	printf("The %d key has been pressed\n", keysym);
	return (0);
}

int	handle_close(t_fractol *f)
{
	ft_putstr("Window close (X) pressed. Exiting.\n");
	fractol_destroy(f);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP)
	{
		f->zoom *= 0.95;
		ft_putstr("Zoom in\n");
	}
	else if (button == SCROLL_DOWN)
	{
		f->zoom *= 1.05;
		ft_putstr("Zoom out\n");
	}
	render(f);
	return (0);
}

// int	mouse_julia(int x, int y, t_fractol *f)
// {
// 	if(ft_strcmp(f->name, "julia") == 0)
// 	{
// 		f->julia.real_nbr = map(x, -2)
// 	}
// }