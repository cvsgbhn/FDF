/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:03:02 by vdanilo           #+#    #+#             */
/*   Updated: 2020/01/22 19:04:11 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

d_list	*ft_doubly_linked_lstnew(void const *content, size_t content_size)
{
	d_list	*newlist;
	size_t	copy_size;
	int     counter;

	copy_size = content_size;
	counter = -1;
	newlist = (d_list*)malloc(sizeof(struct s2_list));
	if (!newlist)
	{
		free(newlist);
		return (NULL);
	}
	if (!content)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		newlist->content = ft_strdup((void*)content);
		newlist->content_size = copy_size;
	}
	newlist->next = NULL;
	newlist->previous = NULL;
	while(counter++ < 4)
    {
	    newlist->x_coords[counter] = 0;
	    newlist->y_coords[counter] = 0;
    }
	return (newlist);
}
