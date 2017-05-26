/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:45:08 by dbessmer          #+#    #+#             */
/*   Updated: 2016/12/21 18:28:07 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_col(char **field)
{
	int i;
	int j;
	int cnt;

	i = 0;
	cnt = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i != 3 && field[i][j] == '#' && field[i + 1][j] == '#')
				cnt++;
			if (i != 0 && field[i][j] == '#' && field[i - 1][j] == '#')
				cnt++;
			j++;
		}
		i++;
	}
	return (cnt);
}

static int		ft_check_row(char **field)
{
	int i;
	int j;
	int cnt;

	i = 0;
	cnt = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (j != 3 && field[i][j] == '#' && field[i][j + 1] == '#')
				cnt++;
			if (j != 0 && field[i][j] == '#' && field[i][j - 1] == '#')
				cnt++;
			j++;
		}
		i++;
	}
	return (cnt);
}

int				ft_check_figure(char **field)
{
	int i;
	int j;
	int cnt;
	int sum;

	i = 0;
	cnt = 0;
	sum = ft_check_col(field) + ft_check_row(field);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (field[i][j++] == '#')
				cnt++;
		}
		i++;
	}
	if (cnt == 4 && sum >= 6)
		return (1);
	return (0);
}

int				ft_check_all(t_tetri **t)
{
	int i;

	i = 0;
	while (t[i])
	{
		if (!ft_check_figure(t[i]->tetrimino))
		{
			ft_print_error(2);
			exit(2);
		}
		i++;
	}
	return (1);
}

int				ft_check_string(char *str)
{
	int i;
	int cnt;

	i = 0;
	while (str[i])
	{
		cnt = 1;
		while (cnt < 21 && str[i])
		{
			if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
				return (0);
			if (i > 0 && str[i] != '\n' && cnt % 5 == 0)
				return (0);
			if (str[i] == '\n' && cnt % 5 != 0)
				return (0);
			i++;
			cnt++;
		}
		if (cnt == 21 && str[i] == '\0')
			return (1);
		if (cnt == 21 && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
