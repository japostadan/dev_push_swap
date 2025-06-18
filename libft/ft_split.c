/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:20:58 by japostad          #+#    #+#             */
/*   Updated: 2025/06/12 11:21:04 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char ***split)
{
	int	i;

	if (!*split)
		return ;
	i = -1;
	while ((*split)[++i])
		free((*split)[i]);
	free(*split);
}

static int	words_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		while (ft_instr("\n\t ", str[i]))
			++i;
		if (str[i] && !ft_instr("\n\t ", str[i]))
		{
			++count;
			while (str[i] && !ft_instr("\n\t ", str[i]))
				++i;
		}
	}
	return (count);
}

static int	fill(char **split, char *str, int start, int len)
{
	*split = ft_strncpy(str, start, len);
	if (!(*split))
		return (0);
	return (1);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		ind;
	char	**split;

	split = (char **)malloc(sizeof(char *) * (words_count(str) + 1));
	if (!split)
		return (NULL);
	i = 0;
	ind = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && ft_instr("\t\n ", str[i]))
			++i;
		while (str[i + j] && !ft_instr("\t\n ", str[i + j]))
			++j;
		if (j > 0)
			if (!fill(&split[ind++], str, i, j))
				return (free_split(&split), NULL);
		i += j;
	}
	return (split[ind] = NULL, split);
}
