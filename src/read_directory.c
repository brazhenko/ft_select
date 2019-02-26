/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 07:54:43 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/26 07:33:23 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

t_arg 		*read_directory(char *path)
{
	DIR			*fd;
	t_dirent	*ret;
	char		**new;
	int			i;
	t_arg		*arg;

	i = 0;
	char *test1 = tgetstr("cl",0);
	printf("%s\n", test1);
	new = (char**)malloc(sizeof(char*) * 1000);
	if (!(fd = opendir(path)))
		exit(EXIT_FAILURE);
	while ((ret = readdir(fd)))
	{
		if (ft_strncmp(ret->d_name, ".", 1) != 0)
		{
			new[i] = ft_strdup(ret->d_name);
			i++;
		}
	}
	arg = make_t_arg_lst(new, NULL);
	print_all_args(arg);
	closedir(fd);
	return (arg);
}

void	return_value(t_arg *arg)
{
	char	*tmp;

	char *test1 = tgetstr("cl",0);
	printf("%s\n", test1);
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