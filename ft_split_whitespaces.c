/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adveres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:14:50 by adveres           #+#    #+#             */
/*   Updated: 2018/01/26 17:38:59 by adveres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*clean_special_chars(char *str)
{
	int		i;
	char	*aux;

	i = 0;
	aux = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i])
	{
		if (str[i] == '\t')
			aux[i] = ' ';
		else
			aux[i] = str[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

char	*clean(char *str, char deli)
{
	t_ij	x;
	char	*aux;

	x.i = 0;
	x.j = 0;
	if (deli == ' ')
		str = clean_special_chars(str);
	while (str[x.i] == deli)
		x.i++;
	str += x.i;
	x.i = 0;
	aux = (char	*)malloc(sizeof(char) * (ft_strlen(str)));
	while (str[x.i])
	{
		if (str[x.i] == deli && (str[x.i + 1] == '\0' || str[x.i + 1] == deli))
			x.i++;
		else
		{
			aux[x.j] = str[x.i];
			x.j++;
			x.i++;
		}
	}
	aux[x.j] = '\0';
	return (aux);
}

int		ft_words(char *s, char delim)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == delim)
			count++;
		i++;
	}
	return (count + 2);
}

char	**ft_split_whitespaces(char *str, char delim)
{
	t_ij	x;
	char	**words;
	int		ind;

	var_inits(&x);
	ind = 0;
	str = clean(str, delim);
	words = (char **)malloc(sizeof(char *) * (ft_words(str, delim) + 2));
	while (str[x.i])
	{
		x.j = 0;
		words[ind] = (char *)malloc(sizeof(char) * (ft_strlen(str + x.i) + 2));
		while (str[x.i] && str[x.i] != delim)
		{
			words[ind][x.j] = str[x.i];
			x.i++;
			x.j++;
		}
		if (str[x.i])
			x.i++;
		words[ind][x.j] = '\0';
		if (x.j != 0)
			ind++;
	}
	return (words);
}
