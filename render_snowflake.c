/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_snowflake.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:49:06 by sade-ara          #+#    #+#             */
/*   Updated: 2025/08/29 16:49:06 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Floco de Neve de Koch (Koch Snowflake)

Podemos imaginar a sua construção a partir de um segmento de reta 
que será submetido a alterações recorrentes (iterações), 
como a seguir se descreve:

Divide-se o segmento de recta em três segmentos de igual comprimento.
Desenha-se um triângulo equilátero 
(fazendo um ângulo de π/3 radianos (60 graus)), 
em que o segmento central, referido no primeiro passo, servirá de base.
Apaga-se o segmento que serviu de base ao triângulo do segundo passo.

*/

static void handle_koch_pixel(int x, int y, t_fractol *fractol)
{

}

void	render_koch(t_fractol *fractol)
{

}