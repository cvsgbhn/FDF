/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:25:09 by vdanilo           #+#    #+#             */
/*   Updated: 2019/11/21 21:02:49 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int		ft_count_words(char const *s, char c)
{
	int counter;
	int index;
	int	in_word;

	counter = 0;
	index = 0;
	in_word = 0;
	while (s[index])
	{
		if (s[index] == c || s[index] == '\n')
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			counter++;
		}
		index++;
	}
	return (counter);
}
