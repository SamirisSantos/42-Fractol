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
	t_fractol	data;
	// teste de imagem
	char	*relative_path = "./minilibx-linux/test/open30.xpm";
	int		img_width;
	int		img_height;
	void	*img;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	data.color = 0xFF0000;
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
 		free(data.mlx_ptr);
		return (MLX_ERROR);
	}

	img = mlx_xpm_file_to_image(data.mlx_ptr, relative_path, &img_width, &img_height);
	if (!img)
	{
		printf("Erro ao carregar imagem: %s\n", relative_path);
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		free(data.mlx_ptr);
		return (1);
	}

	// Coloca a imagem na janela, na posição (100, 100)
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, 100, 100);

	mlx_string_put(data.mlx_ptr, data.win_ptr, (WIN_WIDTH/2) - 90, (WIN_HEIGHT/2), data.color, "Hello world");
	mlx_key_hook(data.win_ptr, handle_input,&data);	
	mlx_hook(data.win_ptr, 17, 0, handle_close, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
