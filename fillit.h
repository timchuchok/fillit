/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:15:45 by vtymchen          #+#    #+#             */
/*   Updated: 2016/12/22 12:15:45 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 10

void			ft_print_error(int err);
char			*ft_read_in_str(int fd);
int				ft_get_fd(char *filename);
int				ft_sqrt(int n);
typedef	struct	s_tetri
{
	char		alpha;
	char		**tetrimino;
}				t_tetri;
typedef	struct	s_map
{
	char		**map;
	int			size;
}				t_map;
t_map			*ft_new_map(int size);
t_tetri			**ft_get_all(char *s);
size_t			ft_get_count(char *s);
t_tetri			*ft_new_tetri(char **pos, char alpha);
char			*ft_get_next_tetri(char *s);
void			ft_place(t_map *map, t_tetri *tetri, int i, int j);
void			ft_clear(t_map *map, char alpha);
int				ft_solve(t_map *map, t_tetri **tetri);
void			ft_print_map(t_map *map);
t_map			*ft_map_solve(t_tetri **t, char *s);
int				ft_i(t_tetri *t, int n, int k);
int				ft_j(t_tetri *t, int m, int l);
int				ft_ij(int i, int j, int size);
int				ft_check_figure(char **field);
int				ft_check_all(t_tetri **t);
int				ft_check_string(char *s);
void			ft_del(t_tetri **t, t_map *map);
int				ft_can_place(t_map *map, t_tetri *t, int i, int j);
#endif
