/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:54:03 by vtymchen          #+#    #+#             */
/*   Updated: 2016/12/22 12:39:03 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	*s;
	t_tetri **tetri;
	t_map	*map;

	if (ac != 2)
	{
		ft_print_error(1);
		exit(2);
	}
	s = ft_read_in_str(ft_get_fd(av[1]));
	if (!ft_check_string(s))
	{
		ft_print_error(2);
		exit(2);
	}
	tetri = ft_get_all(s);
	ft_check_all(tetri);
	map = ft_map_solve(tetri, s);
	ft_print_map(map);
	free(s);
	ft_del(tetri, map);
	return (0);
}
