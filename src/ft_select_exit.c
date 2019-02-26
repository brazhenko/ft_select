/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghazrak- <ghazrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 07:48:36 by lreznak-          #+#    #+#             */
/*   Updated: 2019/02/26 17:45:00 by lreznak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_select_interrupt(int exit_param)
{
	init_window(0);
	set_keypress(0);
}

void			ft_select_exit(int exit_param)
{
	init_window(0);
	set_keypress(0);
	exit(EXIT_SUCCESS);
}
