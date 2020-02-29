/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:21:35 by vdanilo           #+#    #+#             */
/*   Updated: 2019/11/21 21:02:49 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static	int		ft_word_len(char const *str, char c)
{
    int		i;
    int		len;

    i = 0;
    len = 0;
    while (str[i] == c)
        i++;
    while (str[i] != c && str[i] != '\0')
    {
        i++;
        len++;
    }
    return (len);
}

char			**ft_strsplit(char const *s, char c)
{
    int		i;
    int		j;
    int		k;
    char	**s2;

    if (!s || !(s2 = (char **)malloc(sizeof(*s2) * (ft_count_words(s, c) + 1))))
        return (NULL);
    i = -1;
    j = 0;
    while (++i < ft_count_words(s, c))
    {
        k = 0;
        if (!(s2[i] = ft_strnew(ft_word_len(&s[j], c) + 1)))
            s2[i] = NULL;
        while (s[j] == c)
            j++;
        while (s[j] != c && s[j])
            s2[i][k++] = s[j++];
        s2[i][k] = '\0';
    }
    s2[i] = 0;
    return (s2);
}*/

static size_t	ft_countwords(char const *s, char c)
{
	size_t words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static char		*ft_get_word(char *word, char c)
{
	char *start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

static void		ft_free_words(char **words, size_t i)
{
	while (i--)
		ft_strdel(&(words[i]));
	free(*words);
}

static char		**ft_get_words(char *s, char c, size_t words_count)
{
	char	**words;
	char	*word;
	size_t	i;

	i = 0;
	if ((words = (char **)ft_memalloc(sizeof(char *) * (words_count + 1))))
	{
		while (i < words_count)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				if (!(word = ft_get_word(s, c)))
				{
					ft_free_words(words, i);
					return (NULL);
				}
				words[i++] = word;
				s += (ft_strlen(word) + 1);
			}
		}
		words[i] = NULL;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*line;

	if (!s || !(line = ft_strdup((char *)s)))
		return (NULL);
	words = ft_get_words(line, c, ft_countwords(line, c));
	free(line);
	return (words);
}