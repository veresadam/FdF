/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpoint_fromstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adveres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:19:32 by adveres           #+#    #+#             */
/*   Updated: 2018/01/22 16:20:33 by adveres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_3d	getpoint_fromstr(char *s, t_lc *ij)
{
	t_3d	point;
	char	**array;

	array = ft_split_whitespaces(s, ' ');
	point.z = getnbr(array[ij->col]);
	point.x = ij->lin;
	point.y = ij->col;
	return (point);
}
