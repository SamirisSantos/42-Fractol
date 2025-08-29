/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:47:07 by sade-ara          #+#    #+#             */
/*   Updated: 2025/08/29 16:24:41 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	events_init(t_fractol *f)
{
	mlx_key_hook(f->win_ptr, handle_input, f);
	mlx_hook(f->win_ptr, CLOSE, 0, handle_close, f);
	mlx_mouse_hook(f->win_ptr, handle_mouse, f);
	mlx_loop(f->mlx_ptr);
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
	else if (keysym == O_KEY)
		f->color_mode = 0;
	else if (keysym == P_KEY)
		f->color_mode = 1;
	else if (keysym == I_KEY)
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
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		mouse_re = (map(x, -2, 2, WIN_WIDTH) * f->zoom) + f->offset_x;
		mouse_im = (map(y, 2, -2, WIN_HEIGHT) * f->zoom) + f->offset_y;
		if (button == SCROLL_UP)
		{
			zoom_factor = 0.95;
			ft_putstr("Zoom in\n");
		}
		else
		{
			zoom_factor = 1.05;
			ft_putstr("Zoom out\n");
		}
		f->zoom *= zoom_factor;
		f->offset_x = mouse_re - (map(x, -2, 2, WIN_WIDTH) * f->zoom);
		f->offset_y = mouse_im - (map(y, 2, -2, WIN_HEIGHT) * f->zoom);
		render(f);
	}
	return (0);
}
