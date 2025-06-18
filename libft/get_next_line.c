/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:24:37 by japostad          #+#    #+#             */
/*   Updated: 2025/06/12 11:24:39 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	parse_buff(char **ln, char **tmp)
{
	char	*n_ln;
	char	*temp;

	n_ln = ft_strchr(*tmp, '\n');
	if (n_ln)
	{
		if (*ln)
			*ln = get_strjoin(*ln, ft_substr(*tmp, 0, (n_ln - *tmp) + 1));
		else
			*ln = ft_substr(*tmp, 0, (n_ln - *tmp + 1));
		if (*(n_ln + 1))
			temp = ft_strdup(n_ln + 1);
		else
			temp = NULL;
		free(*tmp);
		*tmp = ft_strdup(temp);
		free (temp);
	}
	else
	{
		*ln = get_strjoin(*ln, *tmp);
		free(*tmp);
		*tmp = NULL;
	}
}

static char	*read_line(int fd, char **tmp)
{
	char	*buff;
	int		size;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	size = 1;
	while (!ft_strchr(*tmp, '\n') && size > 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == 0)
			break ;
		if (size < 0)
		{
			free(*tmp);
			free(buff);
			return (NULL);
		}
		buff[size] = '\0';
		*tmp = get_strjoin(*tmp, buff);
	}
	free(buff);
	return (*tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	line = NULL;
	tmp = read_line(fd, &tmp);
	if (!tmp)
		return (NULL);
	parse_buff(&line, &tmp);
	return (line);
}
