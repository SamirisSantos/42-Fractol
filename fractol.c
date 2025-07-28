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

int	main()
{
	t_mlx_data	data;
	t_data	img;

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
	mlx_key_hook(data.win_ptr, handle_input,&data);
	mlx_hook(data.win_ptr, 17, 0, close, &data);
	
	mlx_loop(data.mlx_ptr);
}
