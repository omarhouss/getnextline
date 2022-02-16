/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohoussai <ohoussai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:43:09 by ohoussai          #+#    #+#             */
/*   Updated: 2022/02/16 16:09:55 by ohoussai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*re;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	re = (char *)malloc (sizeof(char) * ft_strlen(s1) + 1 + ft_strlen(s2));
	if (!re)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		re[i++] = s1[j++];
	j = 0;
	while (s2[i])
		re[i++] = s2[j++];
	re[i] = '\0';
	free(s1);
	return (re);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	while (i < len && s[i + start])
		i++;
	sub = malloc(i + 1 * sizeof(char));
	if (!sub)
		return (NULL);
	while (i > j)
	{
		sub[j++] = s[start++];
	}
	sub[i] = '\0';
	return (sub);
}
