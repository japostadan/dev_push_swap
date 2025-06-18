/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: japostad <japostad@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:18:31 by japostad          #+#    #+#             */
/*   Updated: 2025/06/12 11:18:32 by japostad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>

/*libft functions*/
int		ft_atoi(char *str);
int		ft_instr(char *str, char c);
int		ft_strlen(char *str);
int		ft_strcmp(char *str1, char *str2);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isspace(char c);
int		ft_atoi_check(char *str);

char	*ft_strdup(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*get_strjoin(char *str1, char *str2);
char	*ft_strncpy(char *str, int start, int end);
char	**ft_split(char *str);
char	*ft_substr(char *str, unsigned int start, size_t len);
char	*ft_strchr(char *str, int c);

/*get next line*/
char	*get_next_line(int fd);

#endif
