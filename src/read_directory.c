/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 07:54:43 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/26 12:08:40 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char 		**read_directory(char *path)
{
	DIR			*fd;
	t_dirent	*ret;
	char		**new;
	int			i;
	t_arg		*arg;

	i = 0;
	new = (char**)malloc(sizeof(char*) * 1000);
	if (!(fd = opendir(path)))
		exit(EXIT_FAILURE);
	while ((ret = readdir(fd)))
	{
		if (!ft_strnequ(ret->d_name, ".", 1))
		{
			new[i] = ft_strdup(ret->d_name);
			i++;
		}
	}
	return (new);
}

void	return_value(t_arg *arg)
{
	char	*tmp;

	if (!arg)
		return ;
	init_window(0);
	set_keypress(0);
	while (arg->is_begin != 1)
		arg = arg->next;
	tmp = arg->name;
	while(ft_strcmp(tmp, arg->next->name) != 0)
	{
		if (arg->is_selected)
			printf("%s ", arg->name);
		arg = arg->next;
	}
}