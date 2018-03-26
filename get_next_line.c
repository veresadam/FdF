/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adveres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:41:11 by adveres           #+#    #+#             */
/*   Updated: 2018/01/26 15:41:20 by adveres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_size(char *str)
{
	int				i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_realloc(char **line, char *buff)
{
	char			*aux;
	int				i;
	int				j;

	i = 0;
	j = 0;
	aux = (char *)malloc(sizeof(char) * (ft_size(*line) + ft_size(buff) + 1));
	if ((*line) != NULL)
		while ((*line)[i] != '\0')
		{
			aux[i] = (*line)[i];
			i++;
		}
	while (buff[j] != '\0' && buff[j] != '\n' && buff[j] != '\0')
	{
		aux[i] = buff[j];
		j++;
		i++;
	}
	aux[i] = '\0';
	*line = aux;
	if (buff[j] == '\0')
		return (2);
	else
		return (0);
}

void	ft_prelucrare(char **buff, char **line, int *ok)
{
	*ok = ft_realloc(line, *buff);
	if (*ok == 2)
		(*buff) = NULL;
}

char	*ft_trunc(char *buff)
{
	int				i;
	int				j;
	char			*aux;

	i = 0;
	j = 0;
	aux = NULL;
	aux = (char *)malloc(sizeof(char) * (ft_size(buff) + 1));
	while ((buff[i] != '\n') && (buff[i] != '\0') && (buff[i] != '\0'))
	{
		i++;
	}
	i++;
	while ((buff[i] != '\0') && (buff[i] != '\0'))
	{
		aux[j] = buff[i];
		i++;
		j++;
	}
	if (aux != NULL)
	{
		aux[j] = '\0';
	}
	return (aux);
}

int		get_next_line(int const fd, char **line)
{
	int				ok;
	static char		*buff;

	ok = 1;
	(*line) = NULL;
	while (ok != 0)
	{
		if (!(buff))
		{
			buff = (char *)malloc(sizeof(char) * ((BUFF_SIZE) + 1));
			if (read(fd, buff, BUFF_SIZE) <= 0)
			{
				if (ft_size(*line) != 0)
					return (0);
				else
					return (-1);
			}
			buff[ft_size(buff)] = '\0';
		}
		else
			buff = ft_trunc(buff);
		ft_prelucrare(&(buff), &(*line), &ok);
	}
	return (1);
}
