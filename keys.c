/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adveres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:47:47 by adveres           #+#    #+#             */
/*   Updated: 2018/01/26 17:21:05 by adveres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keys(int key, t_config *conf)
{
	if (key == 126)
		conf->move_y -= 10;
	else if (key == 125)
		conf->move_y += 10;
	else if (key == 123)
		conf->move_x -= 10;
	else if (key == 124)
		conf->move_x += 10;
	else if (key == 69)
		conf->spacing += 5;
	else if (key == 78)
	{
		if (conf->spacing - 5 > 0)
			conf->spacing -= 5;
	}
	return (keys_p2(key, conf));
}

int		keys_p2(int key, t_config *conf)
{
	if (key == 53)
		exit(0);
	else if (key == 13 || key == 1)
	{
		if (key == 13)
			conf->unghi += 10;
		else
			conf->unghi -= 10;
		conf->angle = conf->unghi * M_PI / 180;
	}
	else if (key == 35)
		conf->hight += 0.05;
	else if (key == 27)
		conf->hight -= 0.05;
	else if (key == 6)
		g_k = -1 * g_k;
	clean_version(conf->tab, conf);
	return (0);
}
