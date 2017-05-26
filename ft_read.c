/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:27:35 by vtymchen          #+#    #+#             */
/*   Updated: 2016/12/21 18:22:58 by vtymchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_get_fd(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error(2);
		exit(2);
	}
	return (fd);
}

char		*ft_read_in_str(int fd)
{
	char	*s;
	char	*tmp;
	char	buff[BUFF_SIZE];
	size_t	in;

	s = ft_strnew(0);
	tmp = ft_strnew(0);
	while ((in = read(fd, buff, BUFF_SIZE)) > 0)
	{
		tmp = ft_strdup(s);
		s = ft_strnew(ft_strlen(s) + ft_strlen(buff));
		ft_strcpy(s, tmp);
		ft_strncat(s, buff, in);
	}
	close(fd);
	free(tmp);
	if ((ft_strlen(s) + 1) % 21 != 0)
	{
		ft_print_error(2);
		exit(2);
	}
	return (s);
}

t_tetri		**ft_get_all(char *s)
{
	t_tetri	**tetri;
	char	alpha;
	size_t	count;
	char	*str;
	int		index;

	index = 0;
	count = ft_get_count(s);
	alpha = 'A';
	tetri = (t_tetri **)malloc(sizeof(t_tetri *) * count + 1);
	if (tetri == NULL)
		return (NULL);
	while ((str = ft_get_next_tetri(s)) != NULL)
	{
		tetri[index++] = ft_new_tetri(ft_strsplit(str, '\n'), alpha++);
		s += 21;
	}
	tetri[index] = NULL;
	return (tetri);
}

size_t		ft_get_count(char *s)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		if (*s == '\n' && *(s + 1) == '\n')
		{
			size++;
		}
		s++;
	}
	return (size + 1);
}

char		*ft_get_next_tetri(char *s)
{
	char	*str;

	str = ft_strnew(20);
	if (!str)
		return (NULL);
	if (*s)
	{
		return (ft_strncpy(str, s, 20));
	}
	else
		return (NULL);
}
