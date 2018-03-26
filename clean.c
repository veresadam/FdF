/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adveres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:39:48 by adveres           #+#    #+#             */
/*   Updated: 2018/01/26 17:51:56 by adveres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_x(t_3d a, t_config *conf)
{
	float	x;

	x = (a.x - conf->rows / 2) * conf->spacing * (-1 * cos(conf->angle)) +
		(a.y - conf->cols / 2) * conf->spacing * cos(conf->angle) +
		WIDTHIMG / 2 + conf->move_x;
	return (x);
}

float	get_y(t_3d a, t_config *conf)
{
	float	y;

	y = (a.x - conf->rows / 2) * conf->spacing * sin(conf->angle) -
		(a.y - conf->cols / 2) * conf->spacing * (-1 * sin(conf->angle)) -
		conf->hight * a.z * conf->spacing + HEIGHTIMG / 2 + conf->move_y;
	return (y);
}

void	clean_version(t_3d **tab, t_config *conf)
{
	t_lc ij;

	ij.lin = 0;
	while (ij.lin < conf->rows)
	{
		ij.col = 0;
		while (ij.col < conf->cols)
		{
			tab[ij.lin][ij.col].new_x = get_x(tab[ij.lin][ij.col], conf);
			tab[ij.lin][ij.col].new_y = get_y(tab[ij.lin][ij.col], conf);
			ij.col++;
		}
		ij.lin++;
	}
	draw(tab, conf);
}

void	var_inits(t_ij *s)
{
	s->i = 0;
	s->j = 0;
}
