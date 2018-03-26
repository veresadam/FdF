/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adveres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:11:22 by adveres           #+#    #+#             */
/*   Updated: 2018/01/26 16:53:53 by adveres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		nr_elem(char *s)
{
	int nr;
	int i;

	nr = 0;
	i = 0;
	if (is_clean(s) == 0)
		error("invalid file\n");
	while (s[i])
	{
		if (i == 0 && s[i] != ' ')
			nr++;
		else if (i > 0 && s[i - 1] == ' ' && s[i] != ' ')
			nr++;
		i++;
	}
	return (nr);
}

int		getdata_fromfile(char *s, t_lc *lc, t_3d **mat)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (lc->lin == 0)
			lc->col = nr_elem(line);
		else if (lc->col != nr_elem(line))
			return (0);
		lc->lin++;
	}
	close(fd);
	return (1);
}

void	get_data_ints(t_lc *ij, t_lc *lc, char *line)
{
	ij->lin = 0;
	lc->lin = 0;
	lc->col = -1;
	line = NULL;
}

t_3d	**get_data(char *s, t_lc *lc)
{
	t_3d	**mat;
	t_lc	ij;
	int		fd;
	char	*line;

	get_data_ints(&ij, lc, line);
	if (getdata_fromfile(s, lc, mat) == 0)
		error("invalid file");
	mat = (t_3d **)malloc(sizeof(t_3d *) * (lc->lin + 10));
	fd = open(s, O_RDONLY);
	while (ij.lin < lc->lin)
	{
		get_next_line(fd, &line);
		mat[ij.lin] = (t_3d *)malloc(sizeof(t_3d) * (lc->col + 10));
		ij.col = 0;
		while (ij.col < lc->col)
		{
			mat[ij.lin][ij.col] = getpoint_fromstr(line, &ij);
			ij.col++;
		}
		ij.lin++;
	}
	return (mat);
}
