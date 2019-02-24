/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 07:54:43 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/24 22:46:28 by ghazrak-         ###   ########.fr       */
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
	
	char *test1=tgetstr("cl",0);
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
	return (arg);
}