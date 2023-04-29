/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:55:17 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/29 17:03:01 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movelog(t_solong *sl)
{
	ft_printf("movecount: %d\n", ++sl->m_cnt);
}

void	error_ftprintf(char const *message)
{
	ft_printf("ERROR\n --> %s\n", message);
}
