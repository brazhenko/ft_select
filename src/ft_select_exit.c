/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lreznak- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 07:48:36 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/24 07:50:13 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_select_exit(void)
{
	char buf[1024];
	char *termtype=getenv("TERM");
	int ok=tgetent(buf,termtype);
	char *test1=tgetstr("cl",0); /* очистка экрана */
	printf("%s", test1);
	exit(EXIT_SUCCESS);
}