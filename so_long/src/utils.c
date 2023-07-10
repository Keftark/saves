/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpothin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:06:24 by cpothin           #+#    #+#             */
/*   Updated: 2023/06/04 11:09:48 by cpothin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	unsigned int	j;
	char			*out_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = -1;
	out_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!out_str)
		return (NULL);
	while (s1[i])
	{
		out_str[i] = s1[i];
		i++;
	}
	while (s2[++j])
		out_str[i++] = s2[j];
	out_str[i] = '\0';
	return (out_str);
}

static int	count_words(const char *str)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if ((*str != '\0' || *str == '\n') && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == '\n' || *str == '\0')
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != '\n' && s[i] != '\0' && index < 0)
			index = i;
		else if ((s[i] == '\n' || s[i] == '\0'
				|| i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
