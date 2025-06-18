/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:31:32 by japostad          #+#    #+#             */
/*   Updated: 2025/06/12 11:31:33 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	has_spaces(char *set, char *str);
static int	has_duplicates(char **str);
static int	has_alpha(char *str);

int	is_valid_arg(char **str, int len)
{
	int		i;
	t_line	l;

	l.join = join_args(len, str);
	if (!l.join)
		return (0);
	l.sp = ft_split(l.join);
	free(l.join);
	i = -1;
	while (l.sp[++i])
	{
		if (!ft_atoi_check(l.sp[i]))
			return (ft_error(l.sp), 0);
		else if (has_alpha(l.sp[i]))
			return (ft_error(l.sp), 0);
	}
	if (has_duplicates(l.sp))
		return (ft_error(l.sp), 0);
	return (free_split(&l.sp), 1);
}

static int	has_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (1);
		++i;
	}
	return (0);
}

static int	has_duplicates(char **str)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (str[i] != NULL)
	{
		num = ft_atoi(str[i]);
		j = 0;
		while (j < i)
		{
			if (num == ft_atoi(str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	has_spaces(char *set, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_instr(set, str[i]))
			return (0);
		++i;
	}
	return (1);
}

char	*join_args(int argc, char **argv)
{
	int		i;
	char	*tmp;
	char	*join;

	i = 0;
	join = NULL;
	while (++i < argc)
	{
		if (has_spaces("\t\n ", argv[i]) || (ft_strcmp("", argv[i]) == 0))
			return (free(join), NULL);
		if (!join)
			join = ft_strdup(argv[i]);
		else
		{
			tmp = ft_strjoin(join, " ");
			free(join);
			if (!tmp)
				return (NULL);
			join = ft_strjoin(tmp, argv[i]);
			free(tmp);
		}
		if (!join)
			return (NULL);
	}
	return (join);
}
