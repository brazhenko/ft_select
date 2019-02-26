/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 08:29:48 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/26 16:32:55 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		t_arg_resize(t_arg *node)
{
	int		word_count;
	int		max_len;
	int 	col_params[2]; /* col_params[0] - col_count; */
	int 	coordinates[2]; /* [0] - row, [1] - col */
	struct ttysize ts;

	ioctl(0, TIOCGSIZE, &ts);
	word_count = 0;
	max_len = 0;
	coordinates[0] = 0;
	coordinates[1] = 0;
	if (!node)
		return (0);
	node = to_first_arg(node);
	max_len = max_len < ft_strlen(node->name) ? ft_strlen(node->name) : max_len;

	word_count++;
	node = node->next;
	while (node->is_begin != 1)
	{
		max_len = max_len < ft_strlen(node->name) ? ft_strlen(node->name) : max_len;
		word_count++;
		node = node->next;
	}
	col_params[0] = ts.ts_cols / max_len;
	if (col_params[0] * ts.ts_lines <= word_count)
		return (0);
	node->col = coordinates[1] * (max_len + 1);
	node->row = coordinates[0];
	node = node->next;
	while (node->is_begin != 1)
	{
		if (coordinates[0] >= ts.ts_lines - 1)
		{
			coordinates[0] = 0;
			coordinates[1]++;
		}
		else
			coordinates[0]++;
		node->col = coordinates[1] * (max_len + 1);
		node->row = coordinates[0];
		node = node->next;
	}
	return (1);
}
