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

int	handle_input(int keysym, t_fractol *data)
{
	if (keysym == XK_Escape)
	{
		printf("The %d key pressed. Exiting.\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("The %d key has been pressed\n", keysym);
	return (0);
}

int	handle_close(t_fractol *data)
{
	printf("Window close (X) pressed. Exiting.\n");
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;

	if(button == 4)
	{
		
		printf("Zoom in\n");
	}
	else if (button == 5)
	{
		 printf("Zoom out\n");
	}
	return (0);
}