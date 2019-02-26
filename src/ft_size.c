/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 08:29:48 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/26 08:47:12 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

int		resize(int col, int row, t_arg *node)
{
	int		word_count;
	int		max_len;
	int		l;

	word_count = 1;
	max_len = 0;
	if (node == node->next)
		return ();
	while (node->is_begin != 1)
		node = node->next;
	while (node->next->is_begin != 1)
	{
		if (max_len < (l = ft_strlen(node->name)))
			max_len = l;
		word_count++;
	}
	if ()
}