/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:55:13 by sade-ara          #+#    #+#             */
/*   Updated: 2025/08/25 14:43:12 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define MALLOC_ERROR	"Memory error"
// Window size
# define WIN_WIDTH	800
# define WIN_HEIGHT	800

// KEYS 
# define ESC_KEY		XK_Escape
# define UP 			XK_Up //65362
# define DOWN 		XK_Down //65364
# define LEFT		XK_Left //65361
# define RIGHT		XK_Right //65363
# define PLUS		XK_plus 
# define MINUS		XK_minus
# define CLOSE		17
# define W_KEY		XK_w
# define S_KEY		XK_s
# define D_KEY		XK_d
# define A_KEY		XK_a
# define O_KEY		XK_o
# define P_KEY		XK_p
# define I_KEY		XK_i

// MOUSE
# define SCROLL_UP	4
# define SCROLL_DOWN	5

// JULIA SET DEFAULT - STARFISH (https://mandel.gart.nz/)
# define JULIA_STARFISH_REAL		-0.3740
# define JULIA_STARFISH_IMAG		-0.6597

//COLORS
# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF

typedef struct s_complex
{
	//      x-axis
	double	real_nbr;
	//      y-axis
	double	im_nbr;
}	t_complex;

typedef struct s_img
{
	// points for image
	void	*img_ptr; //pointer to image struct
	char	*img_data; //pointer to the actual pixels poixels_ptr
	//informaçao da imagem
	int		bpp; //bits por pixel
	int		line_len; //bytes por linha
	int		endian; //endianess da imagem dados em multi-bytes
}	t_img;

typedef struct s_fractol
{
	char		*name;
	void		*mlx_ptr; // mlx_init()
	void		*win_ptr; // mlx_new_window()
	t_img		img;
	// gama de cores
	int			max_iter;
	int			color_mode; // 0 para original e 1 para psicoderico
	// Zoom, eixo x e y
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		not_valid; // hipotenusa
	int			defined_img; // rending quality image iterartions_defintion
	//fractal
	t_complex	julia;
}	t_fractol;

void		fractol_init(t_fractol *f);
void		mandel_render(t_fractol *fractol);
void		render_julia(t_fractol *fractol);
void		ft_pixel_put(int x, int y, t_img *img, int color);

int			handle_close(t_fractol *data);
int			handle_input(int keysym, t_fractol *data);
int			handle_mouse(int button, int x, int y, t_fractol *f);

int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr(char *s);
double		atod(char *s);

t_complex	square_nbr(t_complex z);
t_complex	sum_nbr(t_complex z1, t_complex z2);
double		map(double unscaled_num, double new_min,
				double new_max, double old_max);

int			get_color(int iter, int max_iter, int mode);

#endif