/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_toend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:01:18 by vdanilo           #+#    #+#             */
/*   Updated: 2019/11/21 21:02:49 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_doubly_linked_lstadd_toend(d_list** head_ref, d_list *new_node)
{
    d_list* last = *head_ref;

    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->previous = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node; 
    new_node->previous = last;
    return;
}
