/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 07:48:36 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/26 06:17:27 by ghazrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_select.h"

void			ft_select_exit(void)
{
	char buf[1024];
	char *termtype = getenv("TERM");
	int ok = tgetent(buf,termtype);
	char *test1 = tgetstr("cl",0); /* очистка экрана */
	char *test2 = tgetstr("ve",0);
	char *test3 = tgetstr("te",0);
	printf("%s%s%s", test2, test3, test1);
	exit(EXIT_SUCCESS);
}