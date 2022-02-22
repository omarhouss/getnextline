/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohoussai <ohoussai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:43:09 by ohoussai          #+#    #+#             */
/*   Updated: 2022/02/22 22:40:18 by ohoussai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*re;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	re = malloc (sizeof(char) * (ft_strlen(s1) + 1 + ft_strlen(s2)));
	if (!re)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		re[i++] = s1[j++];
	j = 0;
	while (s2[j])
		re[i++] = s2[j++];
	re[i] = '\0';
	free(s1);
	return (re);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*x;
	int		i;
	int		j;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	i = 0;
	j = 0;
	while (i < len && s[i])
		i++;
	x = malloc(i + 1);
	if (!x)
		return (NULL);
	while (j < i)
		x[j++] = s[start++];
	x[i] = '\0';
	return (x);
}
