/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqouri <zqouri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:24:48 by zqouri            #+#    #+#             */
/*   Updated: 2024/06/10 16:25:11 by zqouri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (c == s[i])
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && c != s[i])
			i++;
	}
	return (count);
}

char	*ft_word(char const *s, char c, size_t *idx)
{
	int		i;
	int		word_len;
	char	*str;

	i = 0;
	word_len = 0;
	while (s[*idx] && s[*idx] == c)
		(*idx)++;
	if (s[*idx])
	{
		i = *idx;
		while (s[*idx] && s[*idx] != c)
		{
			(*idx)++;
			word_len++;
		}
	}
	str = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!str)
		return (NULL);
	word_len = 0;
	while (s[i] && s[i] != c)
		str[word_len++] = s[i++];
	str[word_len] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	idx;
	char	**dest;
	int		count;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_count_word(s, c);
	dest = (char **)malloc(sizeof(char *) * (count + 1));
	if (!dest)
		return (NULL);
	idx = 0;
	while (i < count)
	{
		dest[i] = ft_word(s, c, &idx);
		if (dest[i] == NULL)
			return (ft_free(dest), NULL);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
