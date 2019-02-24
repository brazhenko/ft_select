/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:41:53 by lreznak-          #+#    #+#             */
/*   Updated: 2018/12/07 20:23:05 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew_unsafe(void const *content, size_t content_size)
{
	t_list *new;

	if ((new = (t_list *)malloc(sizeof(t_list))))
	{
		new->content = (void *)content;
		new->content_size = content_size;
		new->next = NULL;
		return (new);
	}
	else
		return (NULL);
}
