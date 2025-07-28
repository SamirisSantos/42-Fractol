/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:55:13 by sade-ara          #+#    #+#             */
/*   Updated: 2025/07/22 16:55:13 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_ERROR	1
#define MLX_ERROR	1
// Tamanho da janela
#define WIN_WIDTH	800
#define WIN_HEIGHT	600

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		color;
}	t_mlx_data;

int	handle_close(t_mlx_data *data);
int	handle_input(int keysym, t_mlx_data *data);

#endif