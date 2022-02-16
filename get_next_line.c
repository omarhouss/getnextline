/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohoussai <ohoussai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:22:53 by ohoussai          #+#    #+#             */
/*   Updated: 2022/02/16 16:28:04 by ohoussai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (0);
}

char	*get_line(int fd, char saved)
{
	int		i;
	char	*s;

	i = 1;
	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s)
		return (NULL);
	while (!check_line(saved) && i)
	{
		i = read(fd, s, BUFFER_SIZE);
		if (i == -1)
		{
			free (s);
			return (NULL);
		}
		s[i] = '\0';
		saved = ft_strjoin (saved, s);
	}
	free(s);
	return (saved);
}

char	*bf_(char *s)
{
	int	i;

	if (!s[0])
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	s = ft_substr(s, 0, i + 1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (0);
	s = get_line (fd, s);
	if (!s)
		return (NULL);
	line = bf_line(s);
}