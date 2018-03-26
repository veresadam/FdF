/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adveres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:57:33 by adveres           #+#    #+#             */
/*   Updated: 2018/01/26 17:19:50 by adveres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(t_3d a, t_3d b, t_3d c)
{
	float	dist;
	int		col;

	dist = fabs(a.new_x - b.new_x);
	if (g_k == 1)
		col = abs((int)(fabs((a.z + 10) * fabs((dist - c.new_x) / dist))) %
				255 * 255 * 65536 + (int)(fabs((dist + c.new_x) / dist) *
					fabs(b.z + 10)) % 255);
	else
		col = abs(255 * 65536 * ((int)(a.z + fabs(a.z - b.z) * fabs(c.new_x -
							b.new_x)) % 255) + (int)((b.z + fabs(a.z - b.z) *
							fabs(b.new_x + c.new_x))) % 255 * 20);
	if (col == 0)
		col = 16751001;
	return (col);
}

void	put_pixel(char *img, int sln, t_3d z, int col)
{
	int		offset;
	t_col	colo;

	offset = (int)z.new_x * 4;
	offset += (int)z.new_y * sln;
	*(int *)(img + offset) = col;
}

void	init_line(t_pstuff *st, t_3d u, t_3d z)
{
	st->a = z;
	st->b = u;
	st->dx = abs((int)u.new_x - (int)z.new_x);
	st->sx = z.new_x < u.new_x ? 1 : -1;
	st->dy = abs((int)u.new_y - (int)z.new_y);
	st->sy = z.new_y < u.new_y ? 1 : -1;
	st->err = (st->dx > st->dy ? st->dx : -st->dy) / 2;
}

void	line(t_3d z, t_3d u, t_data *img)
{
	t_pstuff	st;

	init_line(&st, u, z);
	while (42)
	{
		if (z.new_x < WIDTHIMG && z.new_x > 1 && z.new_y < HEIGHTIMG &&
				z.new_y > 1)
			put_pixel(img->data, img->size_line, z,
					get_color(st.a, st.b, z));
		else
			break ;
		if ((int)z.new_x == (int)u.new_x && (int)z.new_y == (int)u.new_y)
			break ;
		st.e2 = st.err;
		if (st.e2 > -st.dx)
		{
			st.err -= st.dy;
			z.new_x += st.sx;
		}
		if (st.e2 < st.dy)
		{
			st.err += st.dx;
			z.new_y += st.sy;
		}
	}
}
