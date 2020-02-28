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
}