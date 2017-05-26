/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:41:48 by vtymchen          #+#    #+#             */
/*   Updated: 2016/12/21 18:29:58 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*ft_new_tetri(char **pos, char alpha)
{
	t_tetri *t;

	t = (t_tetri *)malloc(sizeof(t_tetri));
	if (!t || !pos)
		return (NULL);
	t->alpha = alpha;
	t->tetrimino = pos;
	return (t);
}

t_map		*ft_new_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->size = size;
	map->map = (char **)malloc(sizeof(char *) * size);
	while (i < size)
		map->map[i++] = ft_strnew(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map->map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}
