/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:51:42 by tatashir          #+#    #+#             */
/*   Updated: 2023/04/21 21:34:50 by tatashir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_uint(int *len, unsigned int num)
{
	if (num == 0)
	{
		ft_printf_char(len, '0');
		return ;
	}
	if (num >= 10)
	{
		ft_printf_uint(len, num / 10);
		ft_printf_uint(len, num % 10);
	}
	else
		ft_printf_char(len, num + '0');
}
