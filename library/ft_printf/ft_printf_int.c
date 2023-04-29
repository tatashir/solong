/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:51:42 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/21 21:34:10 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_int(int *len, int num)
{
	long	lnum;

	ft_putnbr_fd(num, 1);
	lnum = (long)num;
	if (lnum <= 0)
	{
		*len += 1;
		lnum *= -1;
	}
	while (lnum)
	{
		lnum /= 10;
		*len += 1;
	}
}
