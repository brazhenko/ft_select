/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 08:29:48 by ghazrak-          #+#    #+#             */
/*   Updated: 2019/02/26 16:37:24 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** col_params[0] - col_count;
** coordinates - [0] - row, [1] - col
*/

int		t_arg_resize(t_arg *node)
{
	int				word_count;
	int				maxln;
	int				col_params[2];
	int				coordinates[2];
	struct ttysize	ts;

	ioctl(0, TIOCGSIZE, &ts);
	word_count = 0;
	maxln = 0;
	coordinates[0] = 0;
	coordinates[1] = 0;
	if (!node)
		return (0);
	node = to_first_arg(node);
	maxln = maxln < ft_strlen(node->name) ? ft_strlen(node->name) : maxln;
	word_count++;
	node = node->next;
	while (node->is_begin != 1)
	{
		maxln = maxln < ft_strlen(node->name) ? ft_strlen(node->name) : maxln;
		word_count++;
		node = node->next;
	}
	col_params[0] = ts.ts_cols / maxln;
	if (col_params[0] * ts.ts_lines <= word_count)
		return (0);
	node->col = coordinates[1] * (maxln + 1);
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
		node->col = coordinates[1] * (maxln + 1);
		node->row = coordinates[0];
		node = node->next;
	}
	return (1);
}
