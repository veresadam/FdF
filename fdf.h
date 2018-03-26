/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adveres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 12:21:40 by adveres           #+#    #+#             */
/*   Updated: 2018/01/26 17:44:24 by adveres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WHITE 16777215
# define WIDTH 1000
# define HEIGHT 1000
# define WIDTHIMG 1000
# define HEIGHTIMG 1000
# define ANGLE 45

int				g_k;

typedef struct	s_3d
{
	double		x;
	double		y;
	double		z;
	float		new_x;
	float		new_y;
}				t_3d;

typedef struct	s_pct
{
	int x;
	int y;
}				t_pct;

typedef	struct	s_ij
{
	int i;
	int j;
}				t_ij;

typedef	struct	s_lc
{
	int	lin;
	int col;
}				t_lc;

typedef struct	s_pstuff
{
	t_3d	a;
	t_3d	b;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}				t_pstuff;

typedef	struct	s_data
{
	int		size_line;
	int		endian;
	int		bpp;
	void	*img;
	char	*data;
}				t_data;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		i;
	int		j;
}				t_mlx;

typedef struct	s_col
{
	int r;
	int g;
	int b;
}				t_col;

typedef struct	s_config
{
	float	cols;
	float	spacing;
	float	rows;
	float	unghi;
	float	angle;
	float	move_x;
	float	move_y;
	t_3d	**tab;
	t_data	*img;
	float	hight;
}				t_config;

t_config		get_config(int lin, int col);
void			clean_version(t_3d **tab, t_config *conf);
t_3d			getpoint_fromstr(char *s, t_lc *ij);
int				is_clean(char *s);
void			error(char *s);
t_3d			**get_data(char *s, t_lc *lc);
void			init(t_mlx *c);
int				getnbr(char *s);
char			**ft_split_whitespaces(char *str, char c);
void			verif(char *t);
int				ft_strlen(char *s);
void			err(char n);
void			ft_putstr(char *s);
void			put_pixel(char *img, int sln, t_3d z, int col);
void			line(t_3d z, t_3d u, t_data *img);
void			draw(t_3d **c, t_config *conf);
int				keys(int key, t_config *conf);
void			var_inits(t_ij *x);
int				keys_p2(int key, t_config *conf);

#endif
