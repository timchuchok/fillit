/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:17:09 by vtymchen          #+#    #+#             */
/*   Updated: 2016/12/21 18:39:14 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int n)
{
	int	size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

int		ft_i(t_tetri *t, int n, int k)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t->tetrimino[i][j] == '#')
				return (k + n - i);
			j++;
		}
		i++;
	}
	return (-1);
}

int		ft_j(t_tetri *t, int m, int l)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t->tetrimino[i][j] == '#')
				return (l + m - j);
			j++;
		}
		i++;
	}
	return (-1);
}

int		ft_ij(int i, int j, int size)
{
	if (i >= 0 && i < size && j >= 0 && j < size)
		return (1);
	else
		return (0);
}

void	ft_del(t_tetri **tetri, t_map *map)
{
	int i;

	i = 0;
	while (tetri[i])
	{
		ft_memdel((void **)tetri[i]->tetrimino);
		ft_memdel((void **)&tetri[i++]);
	}
	ft_memdel((void **)&map);
	ft_memdel((void **)tetri);
}
