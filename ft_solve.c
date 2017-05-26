/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:52:09 by vtymchen          #+#    #+#             */
/*   Updated: 2016/12/22 12:19:37 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_can_place(t_map *map, t_tetri *t, int i, int j)
{
	int n;
	int m;

	n = 0;
	m = 0;
	while (n < 4)
	{
		m = 0;
		while (m < 4)
		{
			if (t->tetrimino[n][m] == '#')
			{
				if (!ft_ij(ft_i(t, n, i), ft_j(t, m, j), map->size))
					return (0);
				if (map->map[ft_i(t, n, i)][ft_j(t, m, j)] != '.')
					return (0);
			}
			m++;
		}
		n++;
	}
	return (1);
}

void		ft_place(t_map *map, t_tetri *t, int i, int j)
{
	int n;
	int m;

	n = 0;
	m = 0;
	while (n < 4)
	{
		m = 0;
		while (m < 4)
		{
			if (t->tetrimino[n][m] == '#')
				map->map[ft_i(t, n, i)][ft_j(t, m, j)] = t->alpha;
			m++;
		}
		n++;
	}
}

int			ft_solve(t_map *map, t_tetri **tetri)
{
	int i;
	int j;

	i = 0;
	if (*tetri == NULL)
		return (1);
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (ft_can_place(map, *tetri, i, j))
			{
				ft_place(map, *tetri, i, j);
				if (ft_solve(map, tetri + 1))
					return (1);
				ft_clear(map, (*tetri)->alpha);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void		ft_clear(t_map *map, char alpha)
{
	int i;
	int j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (map->map[i][j] == alpha)
				map->map[i][j] = '.';
			j++;
		}
		i++;
	}
}

t_map		*ft_map_solve(t_tetri **t, char *s)
{
	size_t	size;
	t_map	*map;

	size = (size_t)ft_sqrt((int)ft_get_count(s) * 4);
	map = ft_new_map(size);
	while (!ft_solve(map, t))
	{
		ft_memdel((void**)&map);
		map = ft_new_map(++size);
	}
	return (map);
}
