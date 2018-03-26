/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adveres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:10:52 by adveres           #+#    #+#             */
/*   Updated: 2018/01/25 15:01:52 by adveres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_3d **coord, t_config *conf)
{
	static	t_mlx	mlx;
	t_data			im;

	init(&mlx);
	mlx.i = 0;
	im.img = mlx_new_image(mlx.mlx, WIDTHIMG, HEIGHTIMG);
	im.data = mlx_get_data_addr(im.img, &im.bpp, &im.size_line, &im.endian);
	while (mlx.i < conf->rows)
	{
		mlx.j = 0;
		while (mlx.j < conf->cols)
		{
			if (mlx.j < conf->cols - 1)
				line(coord[mlx.i][mlx.j], coord[mlx.i][mlx.j + 1], &im);
			if (mlx.i < conf->rows - 1)
				line(coord[mlx.i][mlx.j], coord[mlx.i + 1][mlx.j], &im);
			mlx.j++;
		}
		mlx.i++;
	}
	conf->tab = coord;
	conf->img = &im;
	mlx_put_image_to_window(mlx.mlx, mlx.win, im.img, 0, 0);
	mlx_key_hook(mlx.win, keys, conf);
	mlx_loop(mlx.mlx);
}
